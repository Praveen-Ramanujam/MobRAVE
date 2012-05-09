
from openravepy import *
from numpy import*
import numpy as np
import signal
import time
import scipy as Sci
import scipy.linalg
RaveInitialize()

'''class CameraViewerGUI(threading.Thread):
    class Container:
        pass
    def __init__(self,sensor,title='Camera Viewer'):
        threading.Thread.__init__(self)
        self.sensor = sensor
        self.title = title
        self.lastid = -1
        self.imagelck = threading.Lock()

    def updateimage(self):
        data = self.sensor.GetSensorData()
        if data is not None and not self.lastid == data.stamp:
            width = data.imagedata.shape[1]
            height = data.imagedata.shape[0]
            self.imagelck.acquire()
            self.image = Image.frombuffer('RGB',[width,height], data.imagedata.tostring(), 'raw','RGB',0,1)
            self.imagelck.release()

            photo = ImageTk.PhotoImage(self.image)
            if self.container is None:
                self.container = self.Container()
                self.container.width = width
                self.container.height = height
                self.container.main = self.main
                self.container.canvas = Canvas(self.main, width=width, height=height)
                self.container.canvas.pack(expand=1, fill=BOTH)#side=TOP,fill=X)#
                self.container.obr = None

            self.container.canvas.create_image(self.container.width/2, self.container.height/2, image=photo)
            self.container.obr = photo
            self.lastid = data.stamp
        self.main.after(100,self.updateimage)

    def saveimage(self,filename):
        self.imagelck.acquire()
        self.image.save(filename)
        self.imagelck.release()

    def run(self):
        self.main = Tk()
        self.main.title(self.title)      # window title
        self.main.resizable(width=True, height=True)
        self.container = None
        self.main.after(0,self.updateimage)
        self.main.mainloop()

class OpenRAVEScene:
    def __init__(self,env,scenefilename,robotname=None):
        self.orenv = env
        if not self.orenv.Load(scenefilename):
            raise ValueError('failed to open %s openrave file'%scenefilename)
        if len(self.orenv.GetRobots()) == 0:
            raise ValueError('no robots found in scene %s'%scenefilename)

        with env:
            if robotname is None:
                self.robot = self.orenv.GetRobots()[0]
            else:
                self.robot = [r for r in self.orenv.GetRobots() if r.GetName()==robotname][0]

            # create a camera viewer for every camera sensor
            self.viewers = []
            for attachedsensor in self.robot.GetAttachedSensors():
                if attachedsensor.GetSensor() is not None:
                    sensordata = attachedsensor.GetSensor().GetSensorData()
                    if sensordata is not None and sensordata.type == Sensor.Type.Camera:
                        attachedsensor.GetSensor().SendCommand('power 1')
                        title = attachedsensor.GetName()
                        if len(title) == 0:
                            title = attachedsensor.GetSensor().GetName()
                            if len(title) == 0:
                                title = 'Camera Sensor'
                        self.viewers.append(CameraViewerGUI(sensor=attachedsensor.GetSensor(),title=title))
        print 'found %d camera sensors on robot %s'%(len(self.viewers),self.robot.GetName())
        for viewer in self.viewers:
            viewer.start()
        self.prevaction = signal.signal(signal.SIGINT,lambda x,y: self.sighandle(x,y))

    def sighandle(self,x,y):
        self.quitviewers()
        self.prevaction(x,y)

    def quitviewers(self):
        for viewer in self.viewers:
            viewer.main.quit()
    def __del__(self):
        self.quitviewers()
        self.orenv.Destroy()'''

def run(args=None):
    env = Environment()
    # optionally attach viewer
    env.SetViewer('qtcoin') # attaching a viewer seems to stuff up the timesteps, so we set them AFTER attaching the viewer
    env.StopSimulation()
    env.Load('1.xml') 
    dn = 0
    steer = 0.5
   

    with env:
        robot = env.GetRobots()[0]
        cont = RaveCreateController(env,"car_combinedcontroller")
	print robot.GetAttachedSensors()[0]
	robot.SetController(cont)
	T = eye(4)
	T[0:3,3] = array((-23,-23,1.5))
	robot.SetTransform(T)
	#env.StartSimulation(timestep=dt,realtime=True) # limits the simulation to running at, or slower, than realtime.
        env.StopSimulation()
        env.StartSimulation(timestep=0.001)

    robot.GetAttachedSensors()[0].GetSensor().Configure(Sensor.ConfigureCommand.PowerOn)
    robot.GetAttachedSensors()[0].GetSensor().Configure(Sensor.ConfigureCommand.RenderDataOn) 
	    
    while(True):
	time.sleep(5)
        with env:
        	#Get data from camera sensor. Data comes in as a 640 x 480 x 3 matrix of rgb values 0-255.
        	data = array(robot.GetAttachedSensors()[0].GetData().imagedata)
        
        #Convert camera data from rgb to greyscale in row 100
        dataGrey = ones(640)
        for col in range (640):
            r = data[100,col,0]
            g = data[100,col,1]
            b = data[100,col,2]
            brightness = int(round(0.299*r + 0.587*g + 0.114*b))
            dataGrey[col] = brightness 

        #Find midpoint of the line (i.e. midpoint between first and last black pixel)
        first = 0
        last = 0
        for i in range(640):
            if dataGrey[i] < 100:
                first = i
                for j in range(first,640):
                    if dataGrey[j] < 100:
                        last = j
                break
        mid = (first+last)/2

        #Print midpoint value to the terminal
        print 'mid found: ', mid

        #sensativity value
        sen = 120 

        if mid < 320-sen:
            print 'right'
            #lock the enviroment
            with env:
                #execute a right turn
                #robot.GetController().SendCommand('setvelocity 0 -2')
		cont.SetDesired(([dn*steer, 0, dn*steer, 0, 0, -2]))                
		time.sleep(.25)
                #Confirm that controler recieved velocites by printing to the terminal
                #print robot.GetJoint('wheelL').GetVelocities(), robot.GetJoint('wheelR').GetVelocities()
        elif mid > 320+sen:
            print 'left'
            #lock the enviroment
            with env:
                #execute a left trun
                #robot.GetController().SendCommand('setvelocity 2 0')
		cont.SetDesired(([dn*steer, 0, dn*steer, 0, 2, 0]))                
		time.sleep(.25)
                #Confirm that controler recieved velocites by printing to the terminal
                #print robot.GetJoint('wheelL').GetVelocities(), robot.GetJoint('wheelR').GetVelocities()
        else:
            print 'forward'
            #lock the enviroment
            with env:
                #execute drive forwards
                #robot.GetController().SendCommand('setvelocity 1.5 -1.5')
		cont.SetDesired(([dn*steer, 0, dn*steer, 0, 1.5, 1.5]))
                #Confirm that controler recieved velocites by printing to the terminal
                #print robot.GetJoint('wheelL').GetVelocities(), robot.GetJoint('wheelR').GetVelocities()
        time.sleep(.5)
if __name__=='__main__':
    run()

