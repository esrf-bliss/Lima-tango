//=============================================================================
//
// file :         Andor3Class.h
//
// description :  Include for the Andor3Class root class.
//                This class is the singleton class for
//                the Andor3 device class.
//                It contains all properties and methods which the 
//                Andor3 requires only once e.g. the commands.
//			
// project :      TANGO Device Server
//
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// SVN only:
// $HeadURL: $
//
// CVS only:
// $Source:  $
// $Log:  $
//
// copyleft :     European Synchrotron Radiation Facility
//                BP 220, Grenoble 38043
//                FRANCE
//
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================

#ifndef _ANDOR3CLASS_H
#define _ANDOR3CLASS_H

#include <tango.h>
#include <Andor3.h>


namespace Andor3_ns
{//=====================================
//	Define classes for attributes
//=====================================
class serialNumberAttrib: public Tango::Attr
{
public:
	serialNumberAttrib():Attr("serialNumber", Tango::DEV_STRING, Tango::READ) {};
	~serialNumberAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_serialNumber(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_serialNumber_allowed(ty);}
};

class readoutTimeAttrib: public Tango::Attr
{
public:
	readoutTimeAttrib():Attr("readoutTime", Tango::DEV_DOUBLE, Tango::READ) {};
	~readoutTimeAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_readoutTime(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_readoutTime_allowed(ty);}
};

class imageSizeAttrib: public Tango::Attr
{
public:
	imageSizeAttrib():Attr("imageSize", Tango::DEV_DOUBLE, Tango::READ) {};
	~imageSizeAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_imageSize(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_imageSize_allowed(ty);}
};

class fullRoiControlAttrib: public Tango::Attr
{
public:
	fullRoiControlAttrib():Attr("fullRoiControl", Tango::DEV_BOOLEAN, Tango::READ) {};
	~fullRoiControlAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_fullRoiControl(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_fullRoiControl_allowed(ty);}
};

class maxFrameRateTransferAttrib: public Tango::Attr
{
public:
	maxFrameRateTransferAttrib():Attr("maxFrameRateTransfer", Tango::DEV_DOUBLE, Tango::READ) {};
	~maxFrameRateTransferAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_maxFrameRateTransfer(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_maxFrameRateTransfer_allowed(ty);}
};

class frameRateMinAttrib: public Tango::Attr
{
public:
	frameRateMinAttrib():Attr("frameRateMin", Tango::DEV_DOUBLE, Tango::READ) {};
	~frameRateMinAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_frameRateMin(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_frameRateMin_allowed(ty);}
};

class frameRateMaxAttrib: public Tango::Attr
{
public:
	frameRateMaxAttrib():Attr("frameRateMax", Tango::DEV_DOUBLE, Tango::READ) {};
	~frameRateMaxAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_frameRateMax(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_frameRateMax_allowed(ty);}
};

class frameRateAttrib: public Tango::Attr
{
public:
	frameRateAttrib():Attr("frameRate", Tango::DEV_DOUBLE, Tango::READ) {};
	~frameRateAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_frameRate(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_frameRate_allowed(ty);}
};

class firmwareVersionAttrib: public Tango::Attr
{
public:
	firmwareVersionAttrib():Attr("firmwareVersion", Tango::DEV_STRING, Tango::READ) {};
	~firmwareVersionAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_firmwareVersion(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_firmwareVersion_allowed(ty);}
};

class bytesPerPixelAttrib: public Tango::Attr
{
public:
	bytesPerPixelAttrib():Attr("bytesPerPixel", Tango::DEV_DOUBLE, Tango::READ) {};
	~bytesPerPixelAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_bytesPerPixel(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_bytesPerPixel_allowed(ty);}
};

class spuriousNoiseFilterAttrib: public Tango::Attr
{
public:
	spuriousNoiseFilterAttrib():Attr("spuriousNoiseFilter", Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~spuriousNoiseFilterAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_spuriousNoiseFilter(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Andor3 *>(dev))->write_spuriousNoiseFilter(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_spuriousNoiseFilter_allowed(ty);}
};

class syncTriggeringAttrib: public Tango::Attr
{
public:
	syncTriggeringAttrib():Attr("syncTriggering", Tango::DEV_BOOLEAN, Tango::READ) {};
	~syncTriggeringAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_syncTriggering(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_syncTriggering_allowed(ty);}
};

class overlapAttrib: public Tango::Attr
{
public:
	overlapAttrib():Attr("overlap", Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~overlapAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_overlap(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Andor3 *>(dev))->write_overlap(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_overlap_allowed(ty);}
};

class bufferOverflowAttrib: public Tango::Attr
{
public:
	bufferOverflowAttrib():Attr("bufferOverflow", Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~bufferOverflowAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_bufferOverflow(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Andor3 *>(dev))->write_bufferOverflow(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_bufferOverflow_allowed(ty);}
};

class fanSpeedStrAttrib: public Tango::Attr
{
public:
	fanSpeedStrAttrib():Attr("fanSpeedStr", Tango::DEV_STRING, Tango::READ) {};
	~fanSpeedStrAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_fanSpeedStr(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_fanSpeedStr_allowed(ty);}
};

class fanSpeedAttrib: public Tango::Attr
{
public:
	fanSpeedAttrib():Attr("fanSpeed", Tango::DEV_USHORT, Tango::READ_WRITE) {};
	~fanSpeedAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_fanSpeed(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Andor3 *>(dev))->write_fanSpeed(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_fanSpeed_allowed(ty);}
};

class coolingStatusAttrib: public Tango::Attr
{
public:
	coolingStatusAttrib():Attr("coolingStatus", Tango::DEV_STRING, Tango::READ) {};
	~coolingStatusAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_coolingStatus(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_coolingStatus_allowed(ty);}
};

class coolerAttrib: public Tango::Attr
{
public:
	coolerAttrib():Attr("cooler", Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~coolerAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_cooler(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Andor3 *>(dev))->write_cooler(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_cooler_allowed(ty);}
};

class temperatureAttrib: public Tango::Attr
{
public:
	temperatureAttrib():Attr("temperature", Tango::DEV_DOUBLE, Tango::READ) {};
	~temperatureAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_temperature(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_temperature_allowed(ty);}
};

class temperatureSPAttrib: public Tango::Attr
{
public:
	temperatureSPAttrib():Attr("temperatureSP", Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~temperatureSPAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_temperatureSP(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Andor3 *>(dev))->write_temperatureSP(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_temperatureSP_allowed(ty);}
};

class electronicShutterModeStrAttrib: public Tango::Attr
{
public:
	electronicShutterModeStrAttrib():Attr("electronicShutterModeStr", Tango::DEV_STRING, Tango::READ) {};
	~electronicShutterModeStrAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_electronicShutterModeStr(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_electronicShutterModeStr_allowed(ty);}
};

class electronicShutterModeAttrib: public Tango::Attr
{
public:
	electronicShutterModeAttrib():Attr("electronicShutterMode", Tango::DEV_USHORT, Tango::READ_WRITE) {};
	~electronicShutterModeAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_electronicShutterMode(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Andor3 *>(dev))->write_electronicShutterMode(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_electronicShutterMode_allowed(ty);}
};

class adcRateStrAttrib: public Tango::Attr
{
public:
	adcRateStrAttrib():Attr("adcRateStr", Tango::DEV_STRING, Tango::READ) {};
	~adcRateStrAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_adcRateStr(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_adcRateStr_allowed(ty);}
};

class adcRateAttrib: public Tango::Attr
{
public:
	adcRateAttrib():Attr("adcRate", Tango::DEV_USHORT, Tango::READ_WRITE) {};
	~adcRateAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_adcRate(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Andor3 *>(dev))->write_adcRate(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_adcRate_allowed(ty);}
};

class simpleGainStrAttrib: public Tango::Attr
{
public:
	simpleGainStrAttrib():Attr("simpleGainStr", Tango::DEV_STRING, Tango::READ) {};
	~simpleGainStrAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_simpleGainStr(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_simpleGainStr_allowed(ty);}
};

class simpleGainAttrib: public Tango::Attr
{
public:
	simpleGainAttrib():Attr("simpleGain", Tango::DEV_USHORT, Tango::READ_WRITE) {};
	~simpleGainAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_simpleGain(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Andor3 *>(dev))->write_simpleGain(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_simpleGain_allowed(ty);}
};

class adcGainStrAttrib: public Tango::Attr
{
public:
	adcGainStrAttrib():Attr("adcGainStr", Tango::DEV_STRING, Tango::READ) {};
	~adcGainStrAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_adcGainStr(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_adcGainStr_allowed(ty);}
};

class adcGainAttrib: public Tango::Attr
{
public:
	adcGainAttrib():Attr("adcGain", Tango::DEV_USHORT, Tango::READ_WRITE) {};
	~adcGainAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Andor3 *>(dev))->read_adcGain(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Andor3 *>(dev))->write_adcGain(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Andor3 *>(dev))->is_adcGain_allowed(ty);}
};

//=========================================
//	Define classes for commands
//=========================================
//
// The Andor3Class singleton definition
//

class
#ifdef WIN32
	__declspec(dllexport)
#endif
	Andor3Class : public Tango::DeviceClass
{
public:
//	properties member data

//	add your own data members here
//------------------------------------

public:
	Tango::DbData	cl_prop;
	Tango::DbData	cl_def_prop;
	Tango::DbData	dev_def_prop;

//	Method prototypes
	static Andor3Class *init(const char *);
	static Andor3Class *instance();
	~Andor3Class();
	Tango::DbDatum	get_class_property(string &);
	Tango::DbDatum	get_default_device_property(string &);
	Tango::DbDatum	get_default_class_property(string &);
	
protected:
	Andor3Class(string &);
	static Andor3Class *_instance;
	void command_factory();
	void get_class_property();
	void attribute_factory(vector<Tango::Attr *> &);
	void write_class_property();
	void set_default_property();
	string get_cvstag();
	string get_cvsroot();

private:
	void device_factory(const Tango::DevVarStringArray *);
};


}	//	namespace Andor3_ns

#endif // _ANDOR3CLASS_H
