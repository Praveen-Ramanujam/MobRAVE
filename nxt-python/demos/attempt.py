#!/usr/bin/env python

import nxt
import openrave
import sys


#Argument variable to handle communication when connected to hardware.Plays no role in simulation
arg = "effort"   

def handle():
	global arg
	#Handles simulation
	if sys.argv[1] == "openrave" :
		print "User choice is Simulation"
		nt = openrave
		arg = "openrave"
	#Handles Hardware depending upon the second argument via bluetooth or USB
	elif sys.argv[1] == "nxt" :
		if len(sys.argv) != 3:	
			print "Insuffecient arguments\nPlease try again"
			sys.exit()
		if sys.argv[2] == "usb":
			print "USB choice"
                        arg = "usb"
		elif sys.argv[2] == "pyblue":
			print "Bluetooth choice"
			arg = "pyblue"
		else :
			print "Options for communication are\n1.nxt pyblue\n2.nxt usb"
			print "Please enter the correct options and try again\n"
			sys.exit()
		nt = nxt
	#Handles exception as an else statement
	else :
		print "Enter the correct arguments and try again"
		sys.exit()
	return nt


if __name__=="__main__":
	
	#nt = handle()
	nt = openrave      
	lego = nt.Control()
	lego.init(arg)
	while (1):
	 	pass
