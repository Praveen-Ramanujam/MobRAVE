# Install script for directory: /home/praveen/Work/openrave/octave_matlab/matlab

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

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-matlab")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openrave-0.5/matlab" TYPE FILE FILES
    "/home/praveen/Work/openrave/octave_matlab/orcreate.cpp"
    "/home/praveen/Work/openrave/octave_matlab/socketconnect.h"
    "/home/praveen/Work/openrave/octave_matlab/orread.cpp"
    "/home/praveen/Work/openrave/octave_matlab/orwrite.cpp"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-matlab")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-matlab")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openrave-0.5/matlab" TYPE FILE FILES
    "/home/praveen/Work/openrave/octave_matlab/orProblemSendCommand.m"
    "/home/praveen/Work/openrave/octave_matlab/orBodyGetLinks.m"
    "/home/praveen/Work/openrave/octave_matlab/orSetCommunication.m"
    "/home/praveen/Work/openrave/octave_matlab/orRobotSetDOFValues.m"
    "/home/praveen/Work/openrave/octave_matlab/orBodyGetAABB.m"
    "/home/praveen/Work/openrave/octave_matlab/orEnvDestroyProblem.m"
    "/home/praveen/Work/openrave/octave_matlab/orEnvWait.m"
    "/home/praveen/Work/openrave/octave_matlab/orEnvLoadScene.m"
    "/home/praveen/Work/openrave/octave_matlab/orEnvPlot.m"
    "/home/praveen/Work/openrave/octave_matlab/orRobotSetActiveManipulator.m"
    "/home/praveen/Work/openrave/octave_matlab/orRobotCheckSelfCollision.m"
    "/home/praveen/Work/openrave/octave_matlab/orRobotControllerSet.m"
    "/home/praveen/Work/openrave/octave_matlab/orRobotSetActiveDOFs.m"
    "/home/praveen/Work/openrave/octave_matlab/orBodyEnable.m"
    "/home/praveen/Work/openrave/octave_matlab/orEnvClose.m"
    "/home/praveen/Work/openrave/octave_matlab/orEnvRayCollision.m"
    "/home/praveen/Work/openrave/octave_matlab/orRobotSensorGetData.m"
    "/home/praveen/Work/openrave/octave_matlab/orRobotSensorSend.m"
    "/home/praveen/Work/openrave/octave_matlab/orBodyGetAABBs.m"
    "/home/praveen/Work/openrave/octave_matlab/orRobotGetDOFValues.m"
    "/home/praveen/Work/openrave/octave_matlab/orBodySetJointValues.m"
    "/home/praveen/Work/openrave/octave_matlab/orRobotGetAttachedSensors.m"
    "/home/praveen/Work/openrave/octave_matlab/orEnvGetRobots.m"
    "/home/praveen/Work/openrave/octave_matlab/orBodySetTransform.m"
    "/home/praveen/Work/openrave/octave_matlab/orBodySetJointTorques.m"
    "/home/praveen/Work/openrave/octave_matlab/orEnvStepSimulation.m"
    "/home/praveen/Work/openrave/octave_matlab/orEnvGetBodies.m"
    "/home/praveen/Work/openrave/octave_matlab/orBodyGetJointValues.m"
    "/home/praveen/Work/openrave/octave_matlab/orRobotStartActiveTrajectory.m"
    "/home/praveen/Work/openrave/octave_matlab/orEnvGetBody.m"
    "/home/praveen/Work/openrave/octave_matlab/orEnvCreateModule.m"
    "/home/praveen/Work/openrave/octave_matlab/orRobotSensorConfigure.m"
    "/home/praveen/Work/openrave/octave_matlab/orRobotGetManipulators.m"
    "/home/praveen/Work/openrave/octave_matlab/orBodyGetDOF.m"
    "/home/praveen/Work/openrave/octave_matlab/orEnvCreateKinBody.m"
    "/home/praveen/Work/openrave/octave_matlab/orRobotControllerSend.m"
    "/home/praveen/Work/openrave/octave_matlab/orRobotGetDOFLimits.m"
    "/home/praveen/Work/openrave/octave_matlab/orBodyGetTransform.m"
    "/home/praveen/Work/openrave/octave_matlab/orEnvCreateProblem.m"
    "/home/praveen/Work/openrave/octave_matlab/orRobotGetActiveDOF.m"
    "/home/praveen/Work/openrave/octave_matlab/orEnvLoadPlugin.m"
    "/home/praveen/Work/openrave/octave_matlab/orBodyDestroy.m"
    "/home/praveen/Work/openrave/octave_matlab/orCommunicator.m"
    "/home/praveen/Work/openrave/octave_matlab/orEnvCreateRobot.m"
    "/home/praveen/Work/openrave/octave_matlab/orEnvCheckCollision.m"
    "/home/praveen/Work/openrave/octave_matlab/orEnvTriangulate.m"
    "/home/praveen/Work/openrave/octave_matlab/orEnvSetOptions.m"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-matlab")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-matlab")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openrave-0.5/matlab" TYPE DIRECTORY FILES "/home/praveen/Work/openrave/octave_matlab/examples" REGEX "/\\.svn$" EXCLUDE)
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-matlab")

