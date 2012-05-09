
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
#cont = RaveCreateController(env,"car_combinedcontroller")
#testbot.SetController(cont)
#cont.SetDesired(([0, 0, 0, 0, 0, 0]))
attached=testbot.GetAttachedSensors()[0]
robot = testbot
#collisionChecker = RaveCreateCollisionChecker(env,'bullet')
#env.SetCollisionChecker(collisionChecker)

#start simulation
with env:
    T = eye(4)
    T[0:3,3] = array((-0.5,-0.5,2.5))
    testbot.SetTransform(T)
    env.StartSimulation(timestep=dt,realtime=True) # limits the simulation to running at, or slower, than realtime.
    

t = robot.GetAttachedSensors()[0]
robot.GetAttachedSensors()[0].GetSensor().Configure(Sensor.ConfigureCommand.PowerOn)
robot.GetAttachedSensors()[0].GetSensor().Configure(Sensor.ConfigureCommand.RenderDataOn)
steer = 0
wheels = 0
dn = 1.0
i = 0;
while(1):
    dn = 0
    time.sleep(1)
    with env:
    	T = testbot.GetTransform()
    	data = array(robot.GetAttachedSensors()[0].GetData().imagedata)
    for col in range (80):
            r = data[60,col,0]
            g = data[60,col,1]
            b = data[60,col,2]
            brightness = int(round(0.299*r + 0.587*g + 0.114*b))
    print "Intensity :",brightness
    print "Found Color:",data[60,80,:] 
    #print 'Red: ', r
    #print 'Green: ', g
    #print 'Blue: ', b 
    #cont.SetDesired(([dn*steer, 0, dn*steer, 0, wheels, wheels]))
    
    
    
