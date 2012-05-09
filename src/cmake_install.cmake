# Install script for directory: /home/raman/openrave

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-base")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES "/home/raman/openrave/src/openrave0.5-config")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-base")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave")
  execute_process(COMMAND /usr/bin/cmake -E make_directory ${CMAKE_INSTALL_PREFIX}/bin COMMAND /usr/bin/cmake -E make_directory ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig COMMAND /usr/bin/cmake -E make_directory ${CMAKE_INSTALL_PREFIX}/)
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave")
  execute_process(COMMAND /usr/bin/cmake -E create_symlink openrave0.5-config openrave-config WORKING_DIRECTORY ${CMAKE_INSTALL_PREFIX}/bin)
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-dev")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/openrave-0.5" TYPE FILE FILES
    "/home/raman/openrave/src/openrave-config.cmake"
    "/home/raman/openrave/src/openrave-config-version.cmake"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-dev")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-base")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openrave-0.5" TYPE FILE FILES "/home/raman/openrave/src/openrave_completion.bash")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-base")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-dev")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/raman/openrave/src/openrave0.5.pc")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-dev")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave")
  execute_process(COMMAND /usr/bin/cmake -E create_symlink openrave0.5.pc openrave.pc WORKING_DIRECTORY ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig)
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-dev")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/openrave-0.5/openrave" TYPE FILE FILES
    "/home/raman/openrave/include/openrave/geometry.h"
    "/home/raman/openrave/include/openrave/plugininfo.h"
    "/home/raman/openrave/include/openrave/sensorsystem.h"
    "/home/raman/openrave/include/openrave/physicsengine.h"
    "/home/raman/openrave/include/openrave/interface.h"
    "/home/raman/openrave/include/openrave/module.h"
    "/home/raman/openrave/include/openrave/kinbody.h"
    "/home/raman/openrave/include/openrave/environment.h"
    "/home/raman/openrave/include/openrave/trajectory.h"
    "/home/raman/openrave/include/openrave/spacesampler.h"
    "/home/raman/openrave/include/openrave/mathextra.h"
    "/home/raman/openrave/include/openrave/collisionchecker.h"
    "/home/raman/openrave/include/openrave/openrave.h"
    "/home/raman/openrave/include/openrave/planningutils.h"
    "/home/raman/openrave/include/openrave/plugin.h"
    "/home/raman/openrave/include/openrave/robot.h"
    "/home/raman/openrave/include/openrave/sensor.h"
    "/home/raman/openrave/include/openrave/controller.h"
    "/home/raman/openrave/include/openrave/viewer.h"
    "/home/raman/openrave/include/openrave/iksolver.h"
    "/home/raman/openrave/include/openrave/planner.h"
    "/home/raman/openrave/src/include/openrave/interfacehashes.h"
    "/home/raman/openrave/src/include/openrave/config.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-dev")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-dev")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/openrave-0.5/rave" TYPE FILE FILES
    "/home/raman/openrave/rave/rave.h"
    "/home/raman/openrave/rave/plugin.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-dev")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-base")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openrave-0.5" TYPE FILE FILES
    "/home/raman/openrave/COPYING"
    "/home/raman/openrave/LICENSE.lgpl"
    "/home/raman/openrave/LICENSE.apache"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-base")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/raman/openrave/src/cpp-gen-md5/cmake_install.cmake")
  INCLUDE("/home/raman/openrave/src/3rdparty/crlibm-1.0beta4/cmake_install.cmake")
  INCLUDE("/home/raman/openrave/src/3rdparty/minizip/cmake_install.cmake")
  INCLUDE("/home/raman/openrave/src/3rdparty/ivcon/cmake_install.cmake")
  INCLUDE("/home/raman/openrave/src/3rdparty/ann/cmake_install.cmake")
  INCLUDE("/home/raman/openrave/src/3rdparty/fparser-4.3/cmake_install.cmake")
  INCLUDE("/home/raman/openrave/src/3rdparty/convexdecomposition/cmake_install.cmake")
  INCLUDE("/home/raman/openrave/src/src/cmake_install.cmake")
  INCLUDE("/home/raman/openrave/src/octave_matlab/cmake_install.cmake")
  INCLUDE("/home/raman/openrave/src/python/cmake_install.cmake")
  INCLUDE("/home/raman/openrave/src/plugins/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/home/raman/openrave/src/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/home/raman/openrave/src/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
