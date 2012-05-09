#!/usr/bin/env python

from openravepy import *
from numpy import*
import numpy as np
import signal
import time
import scipy as Sci
import scipy.linalg

class Control:
	
	env = Environment()
	robot = 0	
	

	@classmethod
        def init(self,command):
		self.env.StopSimulation()
        	# optionally attach viewer
		self.env.SetViewer('qtcoin') # attaching a viewer seems to stuff up the timesteps, so we set them AFTER attaching the viewer
		self.env.Load('test_ackerman_steer.env.xml')
		robot = self.env.GetRobots()[0]
		cont = RaveCreateController(self.env,"car_combinedcontroller")
		robot.SetController(cont) 
		with self.env:
    			T = eye(4)
    			T[0:3,3] = array((-19,-22,2.5))
    			robot.SetTransform(T)
    			self.env.StartSimulation(0.5,realtime=True) # limits the simulation to running at, or slower, than realtime.
		
	
	@classmethod
	def rightwheelvelocity(self,command):
		print "..."
	
	@classmethod
	def leftwheelvelocity(self,command):
		print "..."

	@classmethod
	def readencoder(self,command):
		print "...."


	def readleftsonar(self,command):
		print "....."


	def readforwardsonar(self,command):
		print "...."


	def readtouchsensor(self,command):
		print "..."


	def initmotor(self):
		print "..."


	def initsensor(self):
		global env
		collisionChecker = RaveCreateCollisionChecker(env,'bullet')
		self.env.SetCollisionChecker(collisionChecker)


	def initcomm(self,command):
		print "..."
	
