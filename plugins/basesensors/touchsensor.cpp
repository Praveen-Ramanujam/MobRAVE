#include <openrave/plugin.h>
#include "plugindefs.h"
#include "touchsensor.h"
using namespace OpenRAVE;


// called to create a new plugin
static list< boost::shared_ptr<void> >* s_listRegisteredReaders=NULL;
InterfaceBasePtr CreateInterfaceValidated(InterfaceType type, const std::string& interfacename, std::istream& sinput, EnvironmentBasePtr penv)
{
	if( !s_listRegisteredReaders) {
        s_listRegisteredReaders = new list< boost::shared_ptr<void> >();
        s_listRegisteredReaders->push_back(RaveRegisterXMLReader(OpenRAVE::PT_Sensor,"touchsensor", TouchSensor::CreateXMLReader));
	cout << "Reading whether Touch Sensor is present"<<endl;
    }
    if( type == PT_Sensor && interfacename == "touchsensor" ) {
        return InterfaceBasePtr(new TouchSensor(penv));
    }

    return InterfaceBasePtr();
}

// called to query available plugins
void GetPluginAttributesValidated(PLUGININFO& info)
{
info.interfacenames[PT_Sensor].push_back("Touch");
    
}

// called before plugin is terminated
OPENRAVE_PLUGIN_API void DestroyPlugin()
{
    delete s_listRegisteredReaders;
    s_listRegisteredReaders = NULL;
}

