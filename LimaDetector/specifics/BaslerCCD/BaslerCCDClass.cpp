static const char *ClassId    = "$Id:  $";
static const char *TagName    = "$Name:  $";
static const char *CvsPath    = "$Source:  $";
static const char *SvnPath    = "$HeadURL: $";
static const char *HttpServer = "http://www.esrf.fr/computing/cs/tango/tango_doc/ds_doc/";
//+=============================================================================
//
// file :        BaslerCCDClass.cpp
//
// description : C++ source for the BaslerCCDClass. A singleton
//               class derived from DeviceClass. It implements the
//               command list and all properties and methods required
//               by the BaslerCCD once per process.
//
// project :     TANGO Device Server
//
// $Author:  $
//
// $Revision:  $
//
// $Log:  $
//
// copyleft :   European Synchrotron Radiation Facility
//              BP 220, Grenoble 38043
//              FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================

#ifdef WIN32
#include "tango.h"
#endif

#include <BaslerCCD.h>
#include <BaslerCCDClass.h>

#ifndef WIN32
#include "tango.h"
#endif

//+----------------------------------------------------------------------------
/**
 *	Create BaslerCCDClass singleton and return it in a C function for Python usage
 */
//+----------------------------------------------------------------------------
extern "C" {
#ifdef WIN32

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_BaslerCCD_class(const char *name) {
		return BaslerCCD_ns::BaslerCCDClass::init(name);
	}
}


namespace BaslerCCD_ns
{


//
//----------------------------------------------------------------
//	Initialize pointer for singleton pattern
//----------------------------------------------------------------
//
BaslerCCDClass *BaslerCCDClass::_instance = NULL;

//+----------------------------------------------------------------------------
//
// method : 		BaslerCCDClass::BaslerCCDClass(string &s)
// 
// description : 	constructor for the BaslerCCDClass
//
// in : - s : The class name
//
//-----------------------------------------------------------------------------
BaslerCCDClass::BaslerCCDClass(string &s):DeviceClass(s)
{

	cout2 << "Entering BaslerCCDClass constructor" << endl;
	set_default_property();
	get_class_property();
	write_class_property();
	
	cout2 << "Leaving BaslerCCDClass constructor" << endl;

}
//+----------------------------------------------------------------------------
//
// method : 		BaslerCCDClass::~BaslerCCDClass()
// 
// description : 	destructor for the BaslerCCDClass
//
//-----------------------------------------------------------------------------
BaslerCCDClass::~BaslerCCDClass()
{
	_instance = NULL;
}

//+----------------------------------------------------------------------------
//
// method : 		BaslerCCDClass::instance
// 
// description : 	Create the object if not already done. Otherwise, just
//			return a pointer to the object
//
// in : - name : The class name
//
//-----------------------------------------------------------------------------
BaslerCCDClass *BaslerCCDClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new BaslerCCDClass(s);
		}
		catch (bad_alloc)
		{
			throw;
		}		
	}		
	return _instance;
}

BaslerCCDClass *BaslerCCDClass::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}

//+----------------------------------------------------------------------------
//
// method : 		BaslerCCDClass::command_factory
// 
// description : 	Create the command object(s) and store them in the 
//			command list
//
//-----------------------------------------------------------------------------
void BaslerCCDClass::command_factory()
{

	//	add polling if any
	for (unsigned int i=0 ; i<command_list.size(); i++)
	{
	}
}

//+----------------------------------------------------------------------------
//
// method : 		BaslerCCDClass::get_class_property
// 
// description : 	Get the class property for specified name.
//
// in :		string	name : The property name
//
//+----------------------------------------------------------------------------
Tango::DbDatum BaslerCCDClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}
//+----------------------------------------------------------------------------
//
// method : 		BaslerCCDClass::get_default_device_property()
// 
// description : 	Return the default value for device property.
//
//-----------------------------------------------------------------------------
Tango::DbDatum BaslerCCDClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//+----------------------------------------------------------------------------
//
// method : 		BaslerCCDClass::get_default_class_property()
// 
// description : 	Return the default value for class property.
//
//-----------------------------------------------------------------------------
Tango::DbDatum BaslerCCDClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}
//+----------------------------------------------------------------------------
//
// method : 		BaslerCCDClass::device_factory
// 
// description : 	Create the device object(s) and store them in the 
//			device list
//
// in :		Tango::DevVarStringArray *devlist_ptr : The device name list
//
//-----------------------------------------------------------------------------
void BaslerCCDClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{

	//	Create all devices.(Automatic code generation)
	//-------------------------------------------------------------
	for (unsigned long i=0 ; i < devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
						
		// Create devices and add it into the device list
		//----------------------------------------------------
		device_list.push_back(new BaslerCCD(this, (*devlist_ptr)[i]));							 

		// Export device to the outside world
		// Check before if database used.
		//---------------------------------------------
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(device_list.back());
		else
			export_device(device_list.back(), (*devlist_ptr)[i]);
	}
	//	End of Automatic code generation
	//-------------------------------------------------------------

}
//+----------------------------------------------------------------------------
//	Method: BaslerCCDClass::attribute_factory(vector<Tango::Attr *> &att_list)
//-----------------------------------------------------------------------------
void BaslerCCDClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	//	Attribute : frameRate
	frameRateAttrib	*frame_rate = new frameRateAttrib();
	Tango::UserDefaultAttrProp	frame_rate_prop;
	frame_rate_prop.set_unit("Frames/s");
	frame_rate_prop.set_standard_unit("Frames/s");
	frame_rate_prop.set_display_unit("Frames/s");
	frame_rate_prop.set_description("Display the current frame rate (nb frames/s)<br>");
	frame_rate->set_default_properties(frame_rate_prop);
	att_list.push_back(frame_rate);

	//	Attribute : dataRate
	dataRateAttrib	*data_rate = new dataRateAttrib();
	Tango::UserDefaultAttrProp	data_rate_prop;
	data_rate_prop.set_unit("MB/s");
	data_rate_prop.set_standard_unit("MB/s");
	data_rate_prop.set_display_unit("MB/s");
	data_rate_prop.set_description("Display the current data rate (MB/s)<br>");
	data_rate->set_default_properties(data_rate_prop);
	att_list.push_back(data_rate);

	//	Attribute : temperature
	temperatureAttrib	*temperature = new temperatureAttrib();
	Tango::UserDefaultAttrProp	temperature_prop;
	temperature_prop.set_unit("Celcius");
	temperature_prop.set_standard_unit("Celsius");
	temperature_prop.set_display_unit("°");
	temperature_prop.set_format("%4.1f");
	temperature_prop.set_description("Display the current temperature of the BoardSensor.");
	temperature->set_default_properties(temperature_prop);
	att_list.push_back(temperature);

	//	Attribute : packetSize
	packetSizeAttrib	*packet_size = new packetSizeAttrib();
	Tango::UserDefaultAttrProp	packet_size_prop;
	packet_size_prop.set_unit("Bytes");
	packet_size_prop.set_standard_unit("Bytes");
	packet_size_prop.set_display_unit("Bytes");
	packet_size_prop.set_description("The packet size for the selected steam channel of the Transport Layer. (in bytes)<br>");
	packet_size->set_default_properties(packet_size_prop);
	packet_size->set_disp_level(Tango::EXPERT);
	att_list.push_back(packet_size);

	//	Attribute : interPacketDelay
	interPacketDelayAttrib	*inter_packet_delay = new interPacketDelayAttrib();
	Tango::UserDefaultAttrProp	inter_packet_delay_prop;
	inter_packet_delay_prop.set_description("Define the delay between transmission of each packet for the selected stream channel. (in ticks)<br> ");
	inter_packet_delay->set_default_properties(inter_packet_delay_prop);
	inter_packet_delay->set_disp_level(Tango::EXPERT);
	inter_packet_delay->set_memorized();
	inter_packet_delay->set_memorized_init(false);
	att_list.push_back(inter_packet_delay);

	//	Attribute : bandwidthAssigned
	bandwidthAssignedAttrib	*bandwidth_assigned = new bandwidthAssignedAttrib();
	Tango::UserDefaultAttrProp	bandwidth_assigned_prop;
	bandwidth_assigned_prop.set_description("This value indicates the base bandwidth that will be used by the camera to transmit (image+chunk) data and to handle resends and control transmissions. (in Bytes/s)");
	bandwidth_assigned->set_default_properties(bandwidth_assigned_prop);
	bandwidth_assigned->set_disp_level(Tango::EXPERT);
	att_list.push_back(bandwidth_assigned);

	//	Attribute : maxThroughput
	maxThroughputAttrib	*max_throughput = new maxThroughputAttrib();
	Tango::UserDefaultAttrProp	max_throughput_prop;
	max_throughput_prop.set_description("This value indicates the maximum amount of data that the camera could generate given its current settings and ideal conditions. (in Bytes/s)");
	max_throughput->set_default_properties(max_throughput_prop);
	max_throughput->set_disp_level(Tango::EXPERT);
	att_list.push_back(max_throughput);

	//	Attribute : currentThroughput
	currentThroughputAttrib	*current_throughput = new currentThroughputAttrib();
	Tango::UserDefaultAttrProp	current_throughput_prop;
	current_throughput_prop.set_description("This value indicates the actual bandwidth that the camera will use to transmit (image+chunk) data given the curent AOIsettings, ... (in Bytes/s)");
	current_throughput->set_default_properties(current_throughput_prop);
	current_throughput->set_disp_level(Tango::EXPERT);
	att_list.push_back(current_throughput);

	//	Attribute : statisticsFailedBufferCount
	statisticsFailedBufferCountAttrib	*statistics_failed_buffer_count = new statisticsFailedBufferCountAttrib();
	Tango::UserDefaultAttrProp	statistics_failed_buffer_count_prop;
	statistics_failed_buffer_count_prop.set_unit(" ");
	statistics_failed_buffer_count_prop.set_standard_unit(" ");
	statistics_failed_buffer_count_prop.set_display_unit(" ");
	statistics_failed_buffer_count_prop.set_format("%d");
	statistics_failed_buffer_count->set_default_properties(statistics_failed_buffer_count_prop);
	statistics_failed_buffer_count->set_disp_level(Tango::EXPERT);
	att_list.push_back(statistics_failed_buffer_count);

	//	End of Automatic code generation
	//-------------------------------------------------------------
}

//+----------------------------------------------------------------------------
//
// method : 		BaslerCCDClass::get_class_property()
// 
// description : 	Read the class properties from database.
//
//-----------------------------------------------------------------------------
void BaslerCCDClass::get_class_property()
{
	//	Initialize your default values here (if not done with  POGO).
	//------------------------------------------------------------------

	//	Read class properties from database.(Automatic code generation)
	//------------------------------------------------------------------

	//	Call database and extract values
	//--------------------------------------------
	if (Tango::Util::instance()->_UseDb==true)
		get_db_class()->get_property(cl_prop);
	Tango::DbDatum	def_prop;
	int	i = -1;


	//	End of Automatic code generation
	//------------------------------------------------------------------

}

//+----------------------------------------------------------------------------
//
// method : 	BaslerCCDClass::set_default_property
// 
// description: Set default property (class and device) for wizard.
//              For each property, add to wizard property name and description
//              If default value has been set, add it to wizard property and
//              store it in a DbDatum.
//
//-----------------------------------------------------------------------------
void BaslerCCDClass::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;

	vector<string>	vect_data;
	//	Set Default Class Properties
	//	Set Default Device Properties
	prop_name = "DetectorIP";
	prop_desc = "Ip Address of the Detector.";
	prop_def  = "127.0.0.1";
	vect_data.clear();
	vect_data.push_back("127.0.0.1");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "DetectorTimeout";
	prop_desc = "During acquisition, this is the time before declaring that is no available image returned by detector. (in ms)";
	prop_def  = "11000";
	vect_data.clear();
	vect_data.push_back("11000");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "DetectorPacketSize";
	prop_desc = "Define the packet size for the selected steam channel of the Transport Layer. (in bytes)<br>";
	prop_def  = "1500";
	vect_data.clear();
	vect_data.push_back("1500");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedInterPacketDelay";
	prop_desc = "Memorize/Define the interpacket Delay in ticks for the selected steam channel of the Transport Layer.<br>";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedGain";
	prop_desc = "Memorize/Define the  attribute  gain at Init device<br>";
	prop_def  = "0";
	vect_data.clear();
	vect_data.push_back("0");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

	prop_name = "MemorizedAutoGain";
	prop_desc = "Memorize/Define the  attribute  autoGain at Init device<br>";
	prop_def  = "False";
	vect_data.clear();
	vect_data.push_back("False");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);

}
//+----------------------------------------------------------------------------
//
// method : 		BaslerCCDClass::write_class_property
// 
// description : 	Set class description as property in database
//
//-----------------------------------------------------------------------------
void BaslerCCDClass::write_class_property()
{
	//	First time, check if database used
	//--------------------------------------------
	if (Tango::Util::_UseDb == false)
		return;

	Tango::DbData	data;
	string	classname = get_name();
	string	header;
	string::size_type	start, end;

	//	Put title
	Tango::DbDatum	title("ProjectTitle");
	string	str_title("");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("  ");
	description << str_desc;
	data.push_back(description);
		
	//	put cvs or svn location
	string	filename(classname);
	filename += "Class.cpp";
	
	// Create a string with the class ID to
	// get the string into the binary
	string	class_id(ClassId);
	
	// check for cvs information
	string	src_path(CvsPath);
	start = src_path.find("/");
	if (start!=string::npos)
	{
		end   = src_path.find(filename);
		if (end>start)
		{
			string	strloc = src_path.substr(start, end-start);
			//	Check if specific repository
			start = strloc.find("/cvsroot/");
			if (start!=string::npos && start>0)
			{
				string	repository = strloc.substr(0, start);
				if (repository.find("/segfs/")!=string::npos)
					strloc = "ESRF:" + strloc.substr(start, strloc.length()-start);
			}
			Tango::DbDatum	cvs_loc("cvs_location");
			cvs_loc << strloc;
			data.push_back(cvs_loc);
		}
	}
	// check for svn information
	else
	{
		string	src_path(SvnPath);
		start = src_path.find("://");
		if (start!=string::npos)
		{
			end = src_path.find(filename);
			if (end>start)
			{
				header = "$HeadURL: ";
				start = header.length();
				string	strloc = src_path.substr(start, (end-start));
				
				Tango::DbDatum	svn_loc("svn_location");
				svn_loc << strloc;
				data.push_back(svn_loc);
			}
		}
	}

	//	Get CVS or SVN revision tag
	
	// CVS tag
	string	tagname(TagName);
	header = "$Name: ";
	start = header.length();
	string	endstr(" $");
	
	end   = tagname.find(endstr);
	if (end!=string::npos && end>start)
	{
		string	strtag = tagname.substr(start, end-start);
		Tango::DbDatum	cvs_tag("cvs_tag");
		cvs_tag << strtag;
		data.push_back(cvs_tag);
	}
	
	// SVN tag
	string	svnpath(SvnPath);
	header = "$HeadURL: ";
	start = header.length();
	
	end   = svnpath.find(endstr);
	if (end!=string::npos && end>start)
	{
		string	strloc = svnpath.substr(start, end-start);
		
		string tagstr ("/tags/");
		start = strloc.find(tagstr);
		if ( start!=string::npos )
		{
			start = start + tagstr.length();
			end   = strloc.find(filename);
			string	strtag = strloc.substr(start, end-start-1);
			
			Tango::DbDatum	svn_tag("svn_tag");
			svn_tag << strtag;
			data.push_back(svn_tag);
		}
	}

	//	Get URL location
	string	httpServ(HttpServer);
	if (httpServ.length()>0)
	{
		Tango::DbDatum	db_doc_url("doc_url");
		db_doc_url << httpServ;
		data.push_back(db_doc_url);
	}

	//  Put inheritance
	Tango::DbDatum	inher_datum("InheritedFrom");
	vector<string> inheritance;
	inheritance.push_back("Device_4Impl");
	inher_datum << inheritance;
	data.push_back(inher_datum);

	//	Call database and and values
	//--------------------------------------------
	get_db_class()->put_property(data);
}

}	// namespace
