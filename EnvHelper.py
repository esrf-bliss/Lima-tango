############################################################################
# This file is part of LImA, a Library for Image Acquisition
#
# Copyright (C) : 2009-2011
# European Synchrotron Radiation Facility
# BP 220, Grenoble 38043
# FRANCE
#
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, see <http://www.gnu.org/licenses/>.
############################################################################
import time
import os, tempfile, re, imp
from subprocess import Popen, PIPE

import PyTango

ModDepend = ['Core', 'Espia']
Debug = 0
LimaDir = None
StrictVersionPolicy = None
EnvVersionDepth = {'MAJOR': 1, 'MINOR': 2, 'FULL': 3}

def get_server_name(argv):
    """
    Returns full server name <server_type>/<server_instance>.
    (ex: LimaCCDs/basler01)
    """
    full_exec_name = argv[0]
    exec_name = os.path.split(full_exec_name)[-1]
    exec_name = os.path.splitext(exec_name)[0]
    return "/".join((exec_name, argv[1]))

def get_device_class_map(server):
    """
    Retuns a dict of devices for the given server.
    The dict key is a tango class name and the value is a list of
    devices of that tango class name.

    :param server: full server name (ex: LimaCCDs/basler01)
    :type server: str
    :return: Returns dict<tango class name : list of device names>
    :rtype: dict
    """
    db = PyTango.Database()
    dev_list = db.get_device_class_list(server)
    dev_map = {}
    for class_name, dev_name in zip(dev_list[1::2], dev_list[::2]):
        dev_names = dev_map.get(class_name)
        if dev_names is None:
            dev_map[class_name] = dev_names = []
        dev_names.append(dev_name)
    return dev_map

def get_lima_device_name(server):
    """
    Returns LimaCCDs device name for the given server

    :param server: full server name (ex: LimaCCDs/basler01)
    :type server: str
    :return: LimaCCDs tango device name for the given server
    :rtype: str
    """
    return get_device_class_map(server)['LimaCCDs'][0]

def get_lima_camera_type(server):
    """
    Returns the Lima camera type for the given server

    :param server: full server name (ex: LimaCCDs/basler01)
    :type server: str
    :return: the lima camera type for the given server (Ex: Basler)
    :rtype: str
    """
    lima_dev_name = get_lima_device_name(server)
    db = PyTango.Database()
    prop_dict = db.get_device_property(lima_dev_name, 'LimaCameraType')
    camera_type = prop_dict['LimaCameraType']
    if not camera_type:
        raise ValueError("LimaCameraType property not set")
    return camera_type[0]

def setup_lima_env(argv):
    if not check_args(argv):
        return
    if not check_link_strict_version():
        return
    server_name = get_server_name(argv)
    lima_camera_type = get_lima_camera_type(server_name)
    cdir = os.path.join(os.path.dirname(__file__), 'camera')
    cfile_name = os.path.join(cdir, lima_camera_type + '.py')
    cfile = open(cfile_name, 'rt')
    h = '^[ \t]*'
    p = '(?P<plugin>[A-Za-z0-9_]+)'
    s1 = h + 'import[ ]+Lima\\.' + p
    s2 = h + 'from[ ]+Lima[ ]+import[ ]+' + p
    s3 = h + 'from[ ]+Lima\\.' + p + '(\\.([A-Za-z0-9_]+))*[ ]+import[ ]+'
    o1, o2, o3 = re.compile(s1), re.compile(s2), re.compile(s3)
    vers = {}
    for l in cfile.readlines():
        m = o1.match(l) or o2.match(l) or o3.match(l)
        if not m:
            continue
        pname = m.group('plugin')
        print_debug('Found %s import in %s' % (pname, cfile_name))
        if pname not in ['Core']:
            setup_env(pname)
    for k, v in os.environ.items():
        if 'LIMA_' in k and '_VERSION' in k and \
               k not in ['LIMA_LINK_STRICT_VERSION']:
            print_debug('Env: %s=%s' % (k, v))
    return lima_camera_type

def check_args(argv):
    global Debug
    for arg in argv:
        if arg.startswith('-v'):
            try:
                Debug = max(0, int(arg[2:]) - 1)
            except:
                pass
    return 1

def check_link_strict_version():
    global StrictVersionPolicy

    cmd = 'from Lima import Core; '
    cmd += 'import os; print os.environ["LIMA_LINK_STRICT_VERSION"]'
    args = ['python', '-c', cmd]
    pobj = Popen(args, stdout=PIPE)
    strict_link = pobj.stdout.readline().strip().upper()
    print_debug('LIMA_LINK_STRICT_VERSION=%s' % strict_link)
    StrictVersionPolicy = None
    pobj.wait()
    if strict_link and strict_link != 'NONE':
        StrictVersionPolicy = strict_link
    return StrictVersionPolicy

def setup_env(mod):
    pvers = find_dep_vers(mod)
    all_vers = list(pvers.keys())
    all_vers.sort(version_cmp)
    env_var_name = 'LIMA_%s_VERSION' % mod.upper()
    if env_var_name in os.environ:
        ver = os.environ[env_var_name]
        if ver[0] != 'v':
            ver = 'v' + ver
        filt_vers = [set_env_version_depth(x) for x in all_vers]
        if ver not in filt_vers:
            print 'Warning: could not find %s=%s' % (env_var_name, ver)
            return
    else:
        ver = all_vers[-1]
        os.environ[env_var_name] = set_env_version_depth(ver[1:])
    for full_ver, deps in pvers.items():
        if set_env_version_depth(full_ver) == set_env_version_depth(ver):
            break
    for dname, dver in deps.items():
        env_var_name = 'LIMA_%s_VERSION' % dname.upper()
        os.environ[env_var_name] = set_env_version_depth(dver)
        if dname != 'Core':
            setup_env(dname)

def find_dep_vers(mod):
    vers = {}
    vre_str = 'v[0-9]+\.[0-9]+\.[0-9]+'
    vre_obj = re.compile(vre_str)
    pdir = os.path.join(check_lima_dir(), mod)
    for vdir in os.listdir(pdir):
        if vre_obj.match(vdir):
            for dep in ModDepend:
                vname = os.path.join(pdir, vdir, '%s_VERSION' % dep.upper())
                if os.path.exists(vname):
                    vfile = open(vname, 'rt')
                    ver = vfile.readline().strip()
                    if vdir not in vers:
                        vers[vdir] = {}
                    vers[vdir][dep] = ver
    print_debug('%s vers=%s' % (mod, vers))
    return vers

def set_env_version_depth(v):
    hasv = (v[0] == 'v')
    depth = EnvVersionDepth[StrictVersionPolicy]
    env_code = version_code(v)[:depth]
    env_str = '.'.join(map(str, env_code))
    if hasv:
        env_str = 'v' + env_str
    return env_str

def check_lima_dir():
    global LimaDir
    if LimaDir is not None:
        return LimaDir
    args = ['python', '-c', 'from Lima import Core; print Core.__file__']
    pobj = Popen(args, stdout=PIPE)
    core_init_dir = pobj.stdout.readline().strip()
    core_dir = os.path.dirname(core_init_dir)
    LimaDir = os.path.dirname(core_dir)
    pobj.wait()
    return LimaDir

def version_code(s):
    return map(int, s.strip('v').split('.'))

def version_cmp(x, y):
    return cmp(version_code(x), version_code(y))

def print_debug(msg):
    if Debug:
        print msg
