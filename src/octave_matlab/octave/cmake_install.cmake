# Install script for directory: /home/raman/openrave/octave_matlab/octave

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

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-octave")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openrave-0.5/octave" TYPE FILE FILES "/home/raman/openrave/src/octave_matlab/octave/orcreate.mex")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-octave")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-octave")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openrave-0.5/octave" TYPE FILE FILES "/home/raman/openrave/src/octave_matlab/octave/orread.mex")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-octave")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-octave")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openrave-0.5/octave" TYPE FILE FILES "/home/raman/openrave/src/octave_matlab/octave/orwrite.mex")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-octave")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-octave")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openrave-0.5/octave" TYPE FILE FILES
    "/home/raman/openrave/octave_matlab/orEnvCreateModule.m"
    "/home/raman/openrave/octave_matlab/orEnvRayCollision.m"
    "/home/raman/openrave/octave_matlab/orEnvGetRobots.m"
    "/home/raman/openrave/octave_matlab/orBodySetJointTorques.m"
    "/home/raman/openrave/octave_matlab/orEnvCreateKinBody.m"
    "/home/raman/openrave/octave_matlab/orEnvCheckCollision.m"
    "/home/raman/openrave/octave_matlab/orRobotControllerSend.m"
    "/home/raman/openrave/octave_matlab/orRobotCheckSelfCollision.m"
    "/home/raman/openrave/octave_matlab/orRobotGetAttachedSensors.m"
    "/home/raman/openrave/octave_matlab/orRobotSensorGetData.m"
    "/home/raman/openrave/octave_matlab/orRobotSetActiveDOFs.m"
    "/home/raman/openrave/octave_matlab/orRobotSensorConfigure.m"
    "/home/raman/openrave/octave_matlab/orBodyGetAABB.m"
    "/home/raman/openrave/octave_matlab/orEnvWait.m"
    "/home/raman/openrave/octave_matlab/orEnvCreateProblem.m"
    "/home/raman/openrave/octave_matlab/orEnvClose.m"
    "/home/raman/openrave/octave_matlab/orBodyGetTransform.m"
    "/home/raman/openrave/octave_matlab/orBodySetTransform.m"
    "/home/raman/openrave/octave_matlab/orEnvDestroyProblem.m"
    "/home/raman/openrave/octave_matlab/orSetCommunication.m"
    "/home/raman/openrave/octave_matlab/orBodySetJointValues.m"
    "/home/raman/openrave/octave_matlab/orRobotGetActiveDOF.m"
    "/home/raman/openrave/octave_matlab/orBodyGetJointValues.m"
    "/home/raman/openrave/octave_matlab/orRobotSetDOFValues.m"
    "/home/raman/openrave/octave_matlab/orRobotSensorSend.m"
    "/home/raman/openrave/octave_matlab/orEnvGetBody.m"
    "/home/raman/openrave/octave_matlab/orEnvLoadPlugin.m"
    "/home/raman/openrave/octave_matlab/orCommunicator.m"
    "/home/raman/openrave/octave_matlab/orBodyGetLinks.m"
    "/home/raman/openrave/octave_matlab/orBodyDestroy.m"
    "/home/raman/openrave/octave_matlab/orEnvPlot.m"
    "/home/raman/openrave/octave_matlab/orRobotStartActiveTrajectory.m"
    "/home/raman/openrave/octave_matlab/orEnvTriangulate.m"
    "/home/raman/openrave/octave_matlab/orProblemSendCommand.m"
    "/home/raman/openrave/octave_matlab/orRobotSetActiveManipulator.m"
    "/home/raman/openrave/octave_matlab/orRobotControllerSet.m"
    "/home/raman/openrave/octave_matlab/orBodyGetAABBs.m"
    "/home/raman/openrave/octave_matlab/orEnvStepSimulation.m"
    "/home/raman/openrave/octave_matlab/orRobotGetManipulators.m"
    "/home/raman/openrave/octave_matlab/orEnvLoadScene.m"
    "/home/raman/openrave/octave_matlab/orEnvCreateRobot.m"
    "/home/raman/openrave/octave_matlab/orBodyGetDOF.m"
    "/home/raman/openrave/octave_matlab/orEnvGetBodies.m"
    "/home/raman/openrave/octave_matlab/orRobotGetDOFLimits.m"
    "/home/raman/openrave/octave_matlab/orEnvSetOptions.m"
    "/home/raman/openrave/octave_matlab/orBodyEnable.m"
    "/home/raman/openrave/octave_matlab/orRobotGetDOFValues.m"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-octave")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-octave")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openrave-0.5/octave" TYPE DIRECTORY FILES "/home/raman/openrave/octave_matlab/examples" REGEX "/\\.svn$" EXCLUDE)
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "openrave0.5-dp-octave")

