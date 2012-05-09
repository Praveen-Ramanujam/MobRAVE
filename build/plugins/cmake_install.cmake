# Install script for directory: /home/praveen/Work/openrave/plugins

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
    SET(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
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

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/praveen/Work/openrave/build/plugins/basecontrollers/cmake_install.cmake")
  INCLUDE("/home/praveen/Work/openrave/build/plugins/baserobots/cmake_install.cmake")
  INCLUDE("/home/praveen/Work/openrave/build/plugins/basesamplers/cmake_install.cmake")
  INCLUDE("/home/praveen/Work/openrave/build/plugins/basesensors/cmake_install.cmake")
  INCLUDE("/home/praveen/Work/openrave/build/plugins/bulletrave/cmake_install.cmake")
  INCLUDE("/home/praveen/Work/openrave/build/plugins/dualmanipulation/cmake_install.cmake")
  INCLUDE("/home/praveen/Work/openrave/build/plugins/grasper/cmake_install.cmake")
  INCLUDE("/home/praveen/Work/openrave/build/plugins/ikfastsolvers/cmake_install.cmake")
  INCLUDE("/home/praveen/Work/openrave/build/plugins/logging/cmake_install.cmake")
  INCLUDE("/home/praveen/Work/openrave/build/plugins/oderave/cmake_install.cmake")
  INCLUDE("/home/praveen/Work/openrave/build/plugins/pqprave/cmake_install.cmake")
  INCLUDE("/home/praveen/Work/openrave/build/plugins/qtcoinrave/cmake_install.cmake")
  INCLUDE("/home/praveen/Work/openrave/build/plugins/rmanipulation/cmake_install.cmake")
  INCLUDE("/home/praveen/Work/openrave/build/plugins/rplanners/cmake_install.cmake")
  INCLUDE("/home/praveen/Work/openrave/build/plugins/textserver/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

