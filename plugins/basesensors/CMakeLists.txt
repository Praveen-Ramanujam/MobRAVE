###########################################
# basesensors openrave plugin
###########################################


add_library(basesensors SHARED basesensors.cpp basecamera.h  baseflashlidar3d.h  baselaser.h plugindefs.h)
add_library(nxtsensors SHARED touchsensor.cpp touchsensor.h plugindefs.h)
target_link_libraries(basesensors libopenrave)
target_link_libraries(nxtsensors libopenrave)
set_target_properties(nxtsensors PROPERTIES COMPILE_FLAGS "${PLUGIN_COMPILE_FLAGS}" LINK_FLAGS "${PLUGIN_LINK_FLAGS}")
set_target_properties(basesensors PROPERTIES COMPILE_FLAGS "${PLUGIN_COMPILE_FLAGS}" LINK_FLAGS "${PLUGIN_LINK_FLAGS}")
install(TARGETS basesensors DESTINATION ${OPENRAVE_PLUGINS_INSTALL_DIR} COMPONENT ${PLUGINS_BASE})
install(TARGETS nxtsensors DESTINATION ${OPENRAVE_PLUGINS_INSTALL_DIR} COMPONENT ${PLUGINS_BASE})
