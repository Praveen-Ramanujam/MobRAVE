#include "qtosgviewer.h"
#include <openrave/plugin.h>

// for some reason windows complains when the prototypes are different
InterfaceBasePtr CreateInterfaceValidated(InterfaceType type, const std::string& interfacename, std::istream& sinput, EnvironmentBasePtr penv)
{
	//	Debug.
	RAVELOG_VERBOSE("Initiating QTOSGRave plugin...!!!!.\n");

	static int s_SoQtArgc = 0; // has to be static!!

  switch(type) {
  case PT_Viewer:
    if( interfacename == "qtosg" )
    {
      QApplication *app= new QApplication(s_SoQtArgc,NULL);

      return InterfaceBasePtr(new QtOSGViewer(penv,app));
    }
    break;
  default:
    break;
  }

    return InterfaceBasePtr();
}

void GetPluginAttributesValidated(PLUGININFO& info)
{
  //  Debug.
  RAVELOG_INFO("[GetPluginAttributesValidated]\n");

  info.interfacenames[PT_Viewer].push_back("qtosg");
}

OPENRAVE_PLUGIN_API void DestroyPlugin()
{
}
