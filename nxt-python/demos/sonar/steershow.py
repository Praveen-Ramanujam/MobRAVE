
from openravepy import *
from numpy import*
import numpy as np
import signal
import time
import scipy as Sci
import scipy.linalg
RaveInitialize()

# initialise OpenRave
dt = 0.005 # Simulation Timestep
env = Environment()
# optionally attach viewer
env.SetViewer('qtcoin') # attaching a viewer seems to stuff up the timesteps, so we set them AFTER attaching the viewer
env.StopSimulation()
env.Load('test_ackerman_steer.env.xml') 
# get a reference to the test robot
testbot = env.GetRobots()[0]
# setup controller
cont = RaveCreateController(env,"car_combinedcontroller")
testbot.SetController(cont)
cont.SetDesired(([0, 0, 0, 0, 0, 0]))
attached=testbot.GetAttachedSensors()[0]
robot = testbot
collisionChecker = RaveCreateCollisionChecker(env,'bullet')
env.SetCollisionChecker(collisionChecker)

#start simulation
with env:
    T = eye(4)
    T[0:3,3] = array((-19,-22,2.5))
    testbot.SetTransform(T)
    env.StartSimulation(timestep=dt,realtime=True) # limits the simulation to running at, or slower, than realtime.
    

left_sonar = robot.GetAttachedSensors()[0]
right_sonar = robot.GetAttachedSensors()[1]
front_sonar = robot.GetAttachedSensors()[2]
#robot.GetAttachedSensors()[0].GetSensor().Configure(Sensor.ConfigureCommand.PowerOn)
#robot.GetAttachedSensors()[0].GetSensor().Configure(Sensor.ConfigureCommand.RenderDataOn)
#robot.GetAttachedSensors()[1].GetSensor().Configure(Sensor.ConfigureCommand.PowerOn)
#robot.GetAttachedSensors()[1].GetSensor().Configure(Sensor.ConfigureCommand.RenderDataOn)
robot.GetAttachedSensors()[2].GetSensor().Configure(Sensor.ConfigureCommand.PowerOn)
robot.GetAttachedSensors()[2].GetSensor().Configure(Sensor.ConfigureCommand.RenderDataOn)
steer = 0.25
wheels = 3
dn = 1.0
i = 0;
while(1):
    dn = 0
    time.sleep(1)
    if wheels == 0 :
    	with env :
		robot.GetLinks()[0].SetStatic(True)
    else :
	with env :
		robot.GetLinks()[0].SetStatic(False)
    with env:
    	T = testbot.GetTransform()
    	#ldata = left_sonar.GetData()
	#rdata = right_sonar.GetData()
	fdata = front_sonar.GetData()
        #print "left_sonar",ldata.intensity
        #print "right_sonar",rdata.intensity
        #print "front_sonar",fdata.intensity
    	
    	
    cont.SetDesired(([dn*steer, 0, dn*steer, 0, wheels, wheels]))
    
	
    
    
    
