###########################################
# oderave openrave plugin
###########################################
include(${CMAKE_CURRENT_SOURCE_DIR}/FindODE.cmake)
if(ODE_LIBRARY_FOUND)
  link_directories(${OPENRAVE_LINK_DIRS} ${ODE_LINK_DIRS})

  # doesn't work
  #  set(CMAKE_REQUIRED_INCLUDES ${ODE_INCLUDE_DIRS})
  #  set(CMAKE_REQUIRED_FLAGS "${ODE_CXXFLAGS}")
  #  set(CMAKE_REQUIRED_LIBRARIES ${ODE_LIBRARY})
  #  message(STATUS "ode lib: ${ODE_LIBRARY}")
  #  check_function_exists(dAllocateODEDataForThread ODE_HAVE_ALLOCATE_DATA_THREAD)
  if( ODE_HAVE_ALLOCATE_DATA_THREAD )
    add_definitions("-DODE_HAVE_ALLOCATE_DATA_THREAD")
  endif()

  include_directories(${ODE_INCLUDE_DIRS})
  add_library(oderave SHARED oderave.cpp odecollision.h odephysics.h odespace.h odecontroller.h plugindefs.h) 
  add_library(nxtoderave SHARED nxt_ode/nxt_oderave.cpp nxt_ode/nxt_odephysics.h nxt_ode/nxt_odespace.h nxt_ode/nxt_odecontroller.h nxt_ode/nxt_plugindefs.h)
  
  # test for ode version 0.10
  set(CMAKE_REQUIRED_INCLUDES ${ODE_INCLUDE_DIRS})
  set(CMAKE_REQUIRED_FLAGS "${ODE_CXXFLAGS}")
  check_cxx_source_compiles("
    #include <ode/ode.h>

    typedef int dTriIndex;
    int main()
    {
      return 0;
    }"
    NEED_TRIINDEX)
  set(CMAKE_REQUIRED_FLAGS)
  set(CMAKE_REQUIRED_INCLUDES)
  
  if( NEED_TRIINDEX )
    set(ODE_CXXFLAGS "${ODE_CXXFLAGS} -DNEED_DTRIINDEX_TYPEDEF")
  endif()

  message(STATUS "ODE found, building oderave plugin, precision=${ODE_PRECISION}")

  target_link_libraries(oderave libopenrave ${ODE_LIBRARY})
  set_target_properties(oderave PROPERTIES COMPILE_FLAGS "${PLUGIN_COMPILE_FLAGS} ${ODE_CXXFLAGS}" LINK_FLAGS "${PLUGIN_LINK_FLAGS}")
  install(TARGETS oderave DESTINATION ${OPENRAVE_PLUGINS_INSTALL_DIR} COMPONENT ${COMPONENT_PREFIX}plugin-oderave)
  set(CPACK_COMPONENT_${COMPONENT_PREFIX_UPPER}PLUGIN-ODERAVE_DISPLAY_NAME "Plugin for Open Dyanmics Engine (ode) Physics/Collision" PARENT_SCOPE)
  set(PLUGIN_COMPONENT ${COMPONENT_PREFIX}plugin-oderave PARENT_SCOPE)
  
  if( MSVC )
    # have to install the DLLs
    install(DIRECTORY "${ODE_LINK_DIRS}/" DESTINATION bin COMPONENT ${COMPONENT_PREFIX}plugin-oderave FILES_MATCHING PATTERN "*-${MSVC_PREFIX}-*.dll")
  endif()
else()
  message(STATUS "Could not find ODE. Please install ODE (http://www.ode.org)")
endif()

# restore the link dirs
link_directories(${OPENRAVE_LINK_DIRS})
