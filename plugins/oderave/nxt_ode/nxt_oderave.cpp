#include <openrave/plugin.h>
#include <boost/bind.hpp>
#include "nxt_plugindefs.h"
#include "nxt_odephysics.h"
#include <rave/plugin.h>
using namespace OpenRAVE;

static list< boost::shared_ptr<void> >* s_listRegisteredReaders=NULL;
InterfaceBasePtr CreateInterfaceValidated(InterfaceType type, const std::string& interfacename, std::istream& sinput, EnvironmentBasePtr penv)
{
    if( !s_listRegisteredReaders) {
        s_listRegisteredReaders = new list< boost::shared_ptr<void> >();
        s_listRegisteredReaders->push_back(RaveRegisterXMLReader(OpenRAVE::PT_PhysicsEngine,"nxt_ode",CustomODEPhysics::CreateXMLReader));
    }

    if( type == PT_PhysicsEngine && interfacename == "nxt_ode" ) {
       return InterfaceBasePtr(new CustomODEPhysics(penv));
    }

    return InterfaceBasePtr();

    
}

void GetPluginAttributesValidated(PLUGININFO& info)
{
	info.interfacenames[OpenRAVE::PT_PhysicsEngine].push_back("NXT_ODE");
    
}

RAVE_PLUGIN_API void DestroyPlugin()
{
    delete s_listRegisteredReaders;
    s_listRegisteredReaders = NULL;
}


