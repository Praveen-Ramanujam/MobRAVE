// -*- coding: utf-8 -*-
// Copyright (C) 2006-2011 Rosen Diankov <rosen.diankov@gmail.com>
//
// This file is part of OpenRAVE.
// OpenRAVE is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
/** \file environment.h
    \brief Definition of the EnvironmentBase interface used for managing all objects in an environment.
 */
#ifndef  OPENRAVE_ENVIRONMENTBASE_H
#define  OPENRAVE_ENVIRONMENTBASE_H

namespace OpenRAVE {

typedef boost::recursive_try_mutex EnvironmentMutex;

/** \brief Maintains a world state, which serves as the gateway to all functions offered through %OpenRAVE. See \ref arch_environment.
 */
class OPENRAVE_API EnvironmentBase : public boost::enable_shared_from_this<EnvironmentBase>
{
public:
    EnvironmentBase();
    virtual ~EnvironmentBase();

    /// \brief Releases all environment resources, should be always called when environment stops being used.
    ///
    /// Removing all environment pointer might not be enough to destroy the environment resources.
    virtual void Destroy()=0;

    /// \brief Resets all objects of the scene (preserves all problems, planners). <b>[multi-thread safe]</b>
    ///
    /// Do not call inside a SimulationStep call
    virtual void Reset()=0;

    /// \brief set user data
    virtual void SetUserData(UserDataPtr data) {
        __pUserData = data;
    }
    /// \brief return the user custom data
    virtual UserDataPtr GetUserData() const {
        return __pUserData;
    }

    /// \brief Returns the OpenRAVE global state, used for initializing plugins
    virtual UserDataPtr GlobalState() = 0;

    /// \brief Environment will own the interface until EnvironmentBase::Destroy is called.
    virtual void OwnInterface(InterfaceBasePtr pinterface) = 0;

    /// \brief Remove ownership of the interface.
    virtual void DisownInterface(InterfaceBasePtr pinterface) = 0;

    /// \brief Create and return a clone of the current environment.
    ///
    /// Clones do not share any memory or resource between each other.
    /// or their parent making them ideal for performing separte planning experiments while keeping
    /// the parent environment unchanged.
    /// By default a clone only copies the collision checkers and physics engine.
    /// When bodies are cloned, the unique ids are preserved across environments (each body can be referenced with its id in both environments). The attached and grabbed bodies of each body/robot are also copied to the new environment.
    /// \param options A set of \ref CloningOptions describing what is actually cloned.
    /// \return An environment of the same type as this environment containing the copied information.
    virtual EnvironmentBasePtr CloneSelf(int options) = 0;

    /// \brief Each function takes an optional pointer to a CollisionReport structure and returns true if collision occurs. <b>[multi-thread safe]</b>
    ///
    /// \name Collision specific functions.
    /// \anchor env_collision_checking
    //@{
    /// set the global environment collision checker
    virtual bool SetCollisionChecker(CollisionCheckerBasePtr pchecker)=0;
    virtual CollisionCheckerBasePtr GetCollisionChecker() const =0;

    /// \see CollisionCheckerBase::CheckCollision(KinBodyConstPtr,CollisionReportPtr)
    virtual bool CheckCollision(KinBodyConstPtr pbody1, CollisionReportPtr report = CollisionReportPtr())=0;

    /// \see CollisionCheckerBase::CheckCollision(KinBodyConstPtr,KinBodyConstPtr,CollisionReportPtr)
    virtual bool CheckCollision(KinBodyConstPtr pbody1, KinBodyConstPtr pbody2, CollisionReportPtr report = CollisionReportPtr())=0;

    /// \see CollisionCheckerBase::CheckCollision(KinBody::LinkConstPtr,CollisionReportPtr)
    virtual bool CheckCollision(KinBody::LinkConstPtr plink, CollisionReportPtr report = CollisionReportPtr())=0;

    /// \see CollisionCheckerBase::CheckCollision(KinBody::LinkConstPtr,KinBody::LinkConstPtr,CollisionReportPtr)
    virtual bool CheckCollision(KinBody::LinkConstPtr plink1, KinBody::LinkConstPtr plink2, CollisionReportPtr report = CollisionReportPtr())=0;

    /// \see CollisionCheckerBase::CheckCollision(KinBody::LinkConstPtr,KinBodyConstPtr,CollisionReportPtr)
    virtual bool CheckCollision(KinBody::LinkConstPtr plink, KinBodyConstPtr pbody, CollisionReportPtr report = CollisionReportPtr())=0;

    /// \see CollisionCheckerBase::CheckCollision(KinBody::LinkConstPtr,const std::vector<KinBodyConstPtr>&,const std::vector<KinBody::LinkConstPtr>&,CollisionReportPtr)
    virtual bool CheckCollision(KinBody::LinkConstPtr plink, const std::vector<KinBodyConstPtr>& vbodyexcluded, const std::vector<KinBody::LinkConstPtr>& vlinkexcluded, CollisionReportPtr report = CollisionReportPtr())=0;

    /// \see CollisionCheckerBase::CheckCollision(KinBodyConstPtr,const std::vector<KinBodyConstPtr>&,const std::vector<KinBody::LinkConstPtr>&,CollisionReportPtr)
    virtual bool CheckCollision(KinBodyConstPtr pbody, const std::vector<KinBodyConstPtr>& vbodyexcluded, const std::vector<KinBody::LinkConstPtr>& vlinkexcluded, CollisionReportPtr report = CollisionReportPtr())=0;

    /// \see CollisionCheckerBase::CheckCollision(const RAY&,KinBody::LinkConstPtr,CollisionReportPtr)
    virtual bool CheckCollision(const RAY& ray, KinBody::LinkConstPtr plink, CollisionReportPtr report = CollisionReportPtr()) = 0;

    /// \see CollisionCheckerBase::CheckCollision(const RAY&,KinBodyConstPtr,CollisionReportPtr)
    virtual bool CheckCollision(const RAY& ray, KinBodyConstPtr pbody, CollisionReportPtr report = CollisionReportPtr()) = 0;

    /// \see CollisionCheckerBase::CheckCollision(const RAY&,CollisionReportPtr)
    virtual bool CheckCollision(const RAY& ray, CollisionReportPtr report = CollisionReportPtr()) = 0;

    /// \see CollisionCheckerBase::CheckSelfCollision
    virtual bool CheckSelfCollision(KinBodyConstPtr pbody, CollisionReportPtr report = CollisionReportPtr()) = 0;

    typedef boost::function<CollisionAction(CollisionReportPtr,bool)> CollisionCallbackFn;

    /// Register a collision callback.
    ///
    /// Whenever a collision is detected between between bodies during a CheckCollision call or physics simulation, the callback is called.
    /// The callback should return an action specifying how the collision should be handled:
    /// <b>action = callback(CollisionReport,bool IsCalledFromPhysicsEngine)</b>
    /// \return a handle to the registration, once the handle loses scope, the callback is unregistered
    virtual boost::shared_ptr<void> RegisterCollisionCallback(const CollisionCallbackFn& callback) = 0;
    virtual bool HasRegisteredCollisionCallbacks() const = 0;
    virtual void GetRegisteredCollisionCallbacks(std::list<CollisionCallbackFn>&) const = 0;
    //@}

    /// \name Physics and Simulation
    //@{
    /// set the physics engine, disabled by default
    /// \param physics the engine to set, if NULL, environment sets an dummy physics engine
    virtual bool SetPhysicsEngine(PhysicsEngineBasePtr physics) = 0;
    virtual PhysicsEngineBasePtr GetPhysicsEngine() const = 0;

    /// \brief Makes one simulation time step. <b>[multi-thread safe]</b>
    ///
    /// Can be called manually by the user inside planners. Keep in mind that the internal simulation thread also calls this function periodically. See \ref arch_simulation for more about the simulation thread.
    virtual void StepSimulation(dReal timeStep) = 0;

    /** \brief Start the internal simulation thread. <b>[multi-thread safe]</b>

        Resets simulation time to 0. See \ref arch_simulation for more about the simulation thread.

        \param fDeltaTime the delta step to take in simulation
        \param bRealTime if false will call SimulateStep as fast as possible, otherwise will time the simulate step calls so that simulation progresses with real system time.
     */
    virtual void StartSimulation(dReal fDeltaTime, bool bRealTime=true) = 0;

    /// \brief Stops the internal physics loop, stops calling SimulateStep for all modules. <b>[multi-thread safe]</b>
    ///
    /// See \ref arch_simulation for more about the simulation thread.
    virtual void StopSimulation() = 0;

    /// \brief Return true if inner simulation loop is executing. <b>[multi-thread safe]</b>
    ///
    /// See \ref arch_simulation for more about the simulation thread.
    virtual bool IsSimulationRunning() const = 0;

    /// \brief Return simulation time since the start of the environment (in microseconds). <b>[multi-thread safe]</b>
    ///
    /// See \ref arch_simulation for more about the simulation thread.
    virtual uint64_t GetSimulationTime() = 0;
    //@}

    /// \name File Loading and Parsing
    /// \anchor env_loading
    //@{

    /// \brief A set of options used to select particular parts of the scene
    enum SelectionOptions
    {
        SO_NoRobots = 1,               ///< everything but robots
        TO_Obstacles = 1,               ///< everything but robots
        SO_Robots = 2,                  ///< all robots
        TO_Robots = 2,                  ///< all robots
        SO_Everything = 3,              ///< all bodies and robots everything
        TO_Everything = 3,              ///< all bodies and robots everything
        SO_Body = 4,                    ///< only triangulate robot/kinbody
        TO_Body = 4,                    ///< only triangulate robot/kinbody
        SO_AllExceptBody = 5,             ///< select everything but the robot/kinbody
        TO_AllExceptBody = 5,             ///< select everything but the robot/kinbody
        SO_BodyList = 6,                 ///< provide a list of body names
    };
    typedef SelectionOptions TriangulateOptions;

    /// \brief Loads a scene from a file and adds all objects in the environment. <b>[multi-thread safe]</b>
    virtual bool Load(const std::string& filename, const AttributesList& atts = AttributesList()) = 0;

    /// \brief Loads a scene from in-memory data and adds all objects in the environment. <b>[multi-thread safe]</b>
    virtual bool LoadData(const std::string& data, const AttributesList& atts = AttributesList()) = 0;

    virtual bool LoadXMLData(const std::string& data, const AttributesList& atts = AttributesList()) {
        return LoadData(data,atts);
    }

    /// \brief Saves a scene depending on the filename extension. Default is in COLLADA format
    ///
    /// \param filename the filename to save the results at
    /// \param options controls what to save
    /// \param selectname
    /// \throw openrave_exception Throw if failed to save anything
    virtual void Save(const std::string& filename, SelectionOptions options=SO_Everything, const std::string& selectname="") = 0;

    /** \brief Initializes a robot from a resource file. The robot is not added to the environment when calling this function. <b>[multi-thread safe]</b>

        \param robot If a null pointer is passed, a new robot will be created, otherwise an existing robot will be filled
        \param filename the name of the resource file, its extension determines the format of the file. See \ref supported_formats.
        \param atts The attribute/value pair specifying loading options. Defined in \ref arch_robot.
     */
    virtual RobotBasePtr ReadRobotURI(RobotBasePtr robot, const std::string& filename, const AttributesList& atts = AttributesList()) = 0;
    virtual RobotBasePtr ReadRobotXMLFile(RobotBasePtr robot, const std::string& filename, const AttributesList& atts = AttributesList()) {
        return ReadRobotURI(robot,filename,atts);
    }

    /// \brief Creates a new robot from a file with no extra load options specified. <b>[multi-thread safe]</b>
    virtual RobotBasePtr ReadRobotURI(const std::string& filename) {
        return ReadRobotURI(RobotBasePtr(),filename,AttributesList());
    }
    virtual RobotBasePtr ReadRobotXMLFile(const std::string& filename) {
        return ReadRobotURI(filename);
    }

    /** \brief Initialize a robot from in-memory data. <b>[multi-thread safe]</b>

        The robot should not be added the environment when calling this function.
        \param robot If a null pointer is passed, a new robot will be created, otherwise an existing robot will be filled
        \param atts The attribute/value pair specifying loading options. Defined in \ref arch_robot.
     */
    virtual RobotBasePtr ReadRobotData(RobotBasePtr robot, const std::string& data, const AttributesList& atts = AttributesList()) = 0;
    virtual RobotBasePtr ReadRobotXMLData(RobotBasePtr robot, const std::string& data, const AttributesList& atts = AttributesList()) {
        return ReadRobotData(robot,data,atts);
    }

    /** \brief Initializes a kinematic body from a resource file. The body is not added to the environment when calling this function. <b>[multi-thread safe]</b>

        \param filename the name of the resource file, its extension determines the format of the file. See \ref supported_formats.
        \param body If a null pointer is passed, a new body will be created, otherwise an existing robot will be filled
        \param atts The attribute/value pair specifying loading options. Defined in \ref arch_kinbody.
     */
    virtual KinBodyPtr ReadKinBodyURI(KinBodyPtr body, const std::string& filename, const AttributesList& atts = AttributesList()) = 0;
    virtual KinBodyPtr ReadKinBodyXMLFile(KinBodyPtr body, const std::string& filename, const AttributesList& atts = AttributesList()) {
        return ReadKinBodyURI(body,filename,atts);
    }

    /// \brief Creates a new kinbody from an XML file with no extra load options specified. <b>[multi-thread safe]</b>
    virtual KinBodyPtr ReadKinBodyURI(const std::string& filename) {
        return ReadKinBodyURI(KinBodyPtr(),filename,AttributesList());
    }
    virtual KinBodyPtr ReadKinBodyXMLFile(const std::string& filename) {
        return ReadKinBodyURI(filename);
    }

    /** \brief Initializes a kinematic body from in-memory data. <b>[multi-thread safe]</b>

        The body should not be added to the environment when calling this function.
        \param body If a null pointer is passed, a new body will be created, otherwise an existing robot will be filled
        \param atts The attribute/value pair specifying loading options. Defined in \ref arch_kinbody.
     */
    virtual KinBodyPtr ReadKinBodyData(KinBodyPtr body, const std::string& data, const AttributesList& atts = AttributesList()) = 0;
    virtual KinBodyPtr ReadKinBodyXMLData(KinBodyPtr body, const std::string& data, const AttributesList& atts = AttributesList()) {
        return ReadKinBodyData(body,data,atts);
    }

    /** \brief Initializes an interface from a resource file. <b>[multi-thread safe]</b>

        \param pinterface If a null pointer is passed, a new interface will be created, otherwise an existing interface will be filled
        \param filename the name of the resource file, its extension determines the format of the file. See \ref supported_formats.
        \param atts The attribute/value pair specifying loading options. See the individual interface descriptions at \ref interface_concepts.
     */
    virtual InterfaceBasePtr ReadInterfaceURI(InterfaceBasePtr pinterface, InterfaceType type, const std::string& filename, const AttributesList& atts = AttributesList()) = 0;
    virtual InterfaceBasePtr ReadInterfaceXMLFile(InterfaceBasePtr pinterface, InterfaceType type, const std::string& filename, const AttributesList& atts = AttributesList()) {
        return ReadInterfaceURI(pinterface,type,filename,atts);
    }

    virtual InterfaceBasePtr ReadInterfaceURI(const std::string& filename, const AttributesList& atts = AttributesList()) = 0;
    virtual InterfaceBasePtr ReadInterfaceXMLFile(const std::string& filename, const AttributesList& atts = AttributesList()) {
        return ReadInterfaceURI(filename,atts);
    }

    /** \brief Initializes an interface from in-memory data. <b>[multi-thread safe]</b>

        \param pinterface If a null pointer is passed, a new interface will be created, otherwise an existing interface will be filled
        \param data string containing data
        \param atts The attribute/value pair specifying loading options. See the individual interface descriptions at \ref interface_concepts.
     */
    virtual InterfaceBasePtr ReadInterfaceData(InterfaceBasePtr pinterface, InterfaceType type, const std::string& data, const AttributesList& atts = AttributesList()) = 0;
    virtual InterfaceBasePtr ReadInterfaceXMLData(InterfaceBasePtr pinterface, InterfaceType type, const std::string& data, const AttributesList& atts = AttributesList()) {
        return ReadInterfaceData(pinterface,type,data,atts);
    }

    /** \brief reads in the rigid geometry of a resource file into a TRIMESH structure

        \param filename the name of the resource file, its extension determines the format of the file. Complex meshes and articulated meshes are all triangulated appropriately. See \ref supported_formats.
        \param options Options to control the parsing process.
     */
    virtual boost::shared_ptr<KinBody::Link::TRIMESH> ReadTrimeshURI(boost::shared_ptr<KinBody::Link::TRIMESH> ptrimesh, const std::string& filename, const AttributesList& atts = AttributesList()) = 0;
    virtual boost::shared_ptr<KinBody::Link::TRIMESH> ReadTrimeshFile(boost::shared_ptr<KinBody::Link::TRIMESH> ptrimesh, const std::string& filename, const AttributesList& atts = AttributesList()) {
        return ReadTrimeshURI(ptrimesh,filename,atts);
    }

    /// \deprecated (10/09/30) see \ref RaveRegisterXMLReader
    virtual UserDataPtr RegisterXMLReader(InterfaceType type, const std::string& xmltag, const CreateXMLReaderFn& fn) RAVE_DEPRECATED = 0;

    /// \brief Parses a file for OpenRAVE XML formatted data.
    virtual bool ParseXMLFile(BaseXMLReaderPtr preader, const std::string& filename) RAVE_DEPRECATED = 0;

    /** \brief Parses a data file for XML data.

        \param pdata The data of the buffer
        \param len the number of bytes valid in pdata
     */
    virtual bool ParseXMLData(BaseXMLReaderPtr preader, const std::string& data) RAVE_DEPRECATED = 0;
    //@}

    /// \name Object Setting and Querying
    /// \anchor env_objects
    //@{

    /// \brief Add a body to the environment
    ///
    /// \param[in] body the pointer to an initialized body
    /// \param[in] bAnonymous if true and there exists a body/robot with the same name, will make body's name unique
    /// \throw openrave_exception Throw if body is invalid or already added
    virtual void AddKinBody(KinBodyPtr body, bool bAnonymous=false) = 0;

    /// \brief add a robot to the environment
    ///
    /// \param[in] robot the pointer to an initialized robot
    /// \param[in] bAnonymous if true and there exists a body/robot with the same name, will make robot's name unique
    /// \throw openrave_exception Throw if robot is invalid or already added
    virtual void AddRobot(RobotBasePtr robot, bool bAnonymous=false) = 0;

    /// \brief registers the sensor with the environment and turns its power on.
    ///
    /// \param[in] sensor the pointer to an initialized sensor
    /// \param[in] bAnonymous if true and there exists a sensor with the same name, will make sensor's name unique
    /// \throw openrave_exception Throw if sensor is invalid or already added
    virtual void AddSensor(SensorBasePtr sensor, bool bAnonymous=false) = 0;

    /// \brief Fill an array with all sensors loaded in the environment. <b>[multi-thread safe]</b>
    ///
    /// The sensors come from the currently loaded robots and the explicitly added sensors
    virtual void GetSensors(std::vector<SensorBasePtr>& sensors) const = 0;

    /// \deprecated (10/09/15) see \ref EnvironmentBase::Remove
    virtual bool RemoveKinBody(KinBodyPtr body) RAVE_DEPRECATED = 0;

    /// \brief Removes a currently loaded interface from the environment. <b>[multi-thread safe]</b>
    ///
    /// The function removes currently loaded bodies, robots, sensors, problems from the actively used
    /// interfaces of the environment. This does not destroy the interface, but it does remove all
    /// references managed. Some interfaces like problems have destroy methods that are called to signal
    /// unloading. Note that the active interfaces are different from the owned interfaces.
    /// \param[in] obj interface to remove
    /// \return true if the interface was successfully removed from the environment.
    virtual bool Remove(InterfaceBasePtr obj) = 0;

    /// \brief Query a body from its name. <b>[multi-thread safe]</b>
    /// \return first KinBody (including robots) that matches with name
    virtual KinBodyPtr GetKinBody(const std::string& name) const =0;

    /// \brief Query a sensor from its name. <b>[multi-thread safe]</b>
    /// \return first sensor that matches with name, note that sensors attached to robots have the robot name as a prefix.
    virtual SensorBasePtr GetSensor(const std::string& name) const =0;

    /// \brief Query a robot from its name. <b>[multi-thread safe]</b>
    /// \return first Robot that matches the name
    virtual RobotBasePtr GetRobot(const std::string& name) const =0;

    /// \brief Get all bodies loaded in the environment (including robots). <b>[multi-thread safe]</b>
    /// \param[out] bodies filled with all the bodies
    virtual void GetBodies(std::vector<KinBodyPtr>& bodies) const = 0;

    /// \brief Fill an array with all robots loaded in the environment. <b>[multi-thread safe]</b>
    virtual void GetRobots(std::vector<RobotBasePtr>& robots) const = 0;

    /// \brief adds a viewer to the environment
    ///
    /// \throw openrave_exception Throw if body is invalid or already added
    virtual void AddViewer(ViewerBasePtr pviewer) = 0;

    /// \deprecated (11/06/13) see AddViewer
    virtual bool AttachViewer(ViewerBasePtr pnewviewer) RAVE_DEPRECATED {
        AddViewer(pnewviewer); return true;
    }

    /// \brief Return a viewer with a particular name.
    ///
    /// When no name is specified, the first loaded viewer is returned.
    virtual ViewerBasePtr GetViewer(const std::string& name="") const = 0;

    /// \brief Returns a list of loaded viewers with a pointer to a lock preventing the list from being modified.
    ///
    /// As long as the lock is held, the problems are guaranteed to stay loaded in the environment.
    /// \return returns a pointer to a Lock. Destroying the shared_ptr will release the lock
    virtual boost::shared_ptr<boost::mutex::scoped_lock> GetViewers(std::list<ViewerBasePtr>& listViewers) const = 0;


    /// \brief Retrieve published bodies, completes even if environment is locked. <b>[multi-thread safe]</b>
    ///
    /// Note that the pbody pointer might become invalid as soon as GetPublishedBodies returns.
    virtual void GetPublishedBodies(std::vector<KinBody::BodyState>& vbodies) = 0;

    /// updates the published bodies that viewers and other programs listening in on the environment see.
    /// For example, calling this function inside a planning loop allows the viewer to update the environment
    /// reflecting the status of the planner.
    /// Assumes that the physics are locked.
    virtual void UpdatePublishedBodies() = 0;

    /// Get the corresponding body from its unique network id
    virtual KinBodyPtr GetBodyFromEnvironmentId(int id) = 0;

    /// \brief Triangulation of the body including its current transformation. trimesh will be appended the new data.  <b>[multi-thread safe]</b>
    ///
    /// \param[out] trimesh - The output triangle mesh
    /// \param[in] body body the triangulate
    /// \throw openrave_exception Throw if failed to add anything
    virtual void Triangulate(KinBody::Link::TRIMESH& trimesh, KinBodyConstPtr pbody) = 0;

    /// \brief General triangulation of the whole scene. <b>[multi-thread safe]</b>
    ///
    /// \param[out] trimesh - The output triangle mesh. The new triangles are appended to the existing triangles!
    /// \param[in] options - Controlls what to triangulate.
    /// \param[in] selectname - name of the body used in options
    /// \throw openrave_exception Throw if failed to add anything
    virtual void TriangulateScene(KinBody::Link::TRIMESH& trimesh, SelectionOptions options, const std::string& selectname) = 0;
    //@}

    /// \brief Load a new module, need to Lock if calling outside simulation thread
    virtual int AddModule(ModuleBasePtr module, const std::string& cmdargs) = 0;

    virtual int LoadProblem(ModuleBasePtr module, const std::string& cmdargs) {
        return AddModule(module,cmdargs);
    }

    /// \deprecated (10/09/15) see \ref EnvironmentBase::Remove
    virtual bool RemoveProblem(ModuleBasePtr prob) RAVE_DEPRECATED = 0;

    /// \brief Returns a list of loaded problems with a pointer to a lock preventing the list from being modified.
    ///
    /// As long as the lock is held, the problems are guaranteed to stay loaded in the environment.
    /// \return returns a pointer to a Lock. Destroying the shared_ptr will release the lock
    virtual boost::shared_ptr<void> GetModules(std::list<ModuleBasePtr>& listModules) const = 0;

    virtual boost::shared_ptr<void> GetLoadedProblems(std::list<ModuleBasePtr>& listModules) const {
        return GetModules(listModules);
    }

    /// \brief Return the global environment mutex used to protect environment information access in multi-threaded environments.
    ///
    /// Accessing environment body information and adding/removing bodies
    /// or changing any type of scene property should have the environment lock acquired. Once the environment
    /// is locked, the user is guaranteed that nnothing will change in the environment.
    virtual EnvironmentMutex& GetMutex() const = 0;

    /// \name 3D plotting methods.
    /// \anchor env_plotting
    //@{

    /// \deprecated (10/11/05)
    typedef OpenRAVE::GraphHandlePtr GraphHandlePtr RAVE_DEPRECATED;

    /// \brief Plot a point cloud with one color. <b>[multi-thread safe]</b>
    ///
    /// \param ppoints array of points
    /// \param numPoints number of points to plot
    /// \param stride stride in bytes to next point, ie: nextpoint = (float*)((char*)ppoints+stride)
    /// \param fPointSize size of a point in pixels
    /// \param color the rgb color of the point. The last component of the color is used for alpha blending
    /// \param drawstyle if 0 will draw pixels. if 1, will draw 3D spheres
    /// \return handle to plotted points, graph is removed when handle is destroyed (goes out of scope). This requires the user to always store the handle in a persistent variable if the plotted graphics are to remain on the viewer.
    virtual OpenRAVE::GraphHandlePtr plot3(const float* ppoints, int numPoints, int stride, float fPointSize, const RaveVector<float>& color = RaveVector<float>(1,0.5,0.5,1), int drawstyle = 0) = 0;

    /// \brief. Plots 3D points with individual colors. <b>[multi-thread safe]</b>
    ///
    /// Arguments same as plot3 with one color, except has an individual color for every point
    /// \param colors An array of rgb colors of size numPoints where each channel is in [0,1].
    ///               colors+(bhasalpha?4:3) points to the second color.
    /// \param stride stride in bytes to next point, ie: nextpoint = (float*)((char*)ppoints+stride)
    /// \param drawstyle if 0 will draw pixels. if 1, will draw 3D spherse
    /// \param bhasalpha if true, then each color consists of 4 values with the last value being the alpha of the point (1 means opaque). If false, then colors is 3 values.
    /// \return handle to plotted points, graph is removed when handle is destroyed (goes out of scope). This requires the user to always store the handle in a persistent variable if the plotted graphics are to remain on the viewer.
    virtual OpenRAVE::GraphHandlePtr plot3(const float* ppoints, int numPoints, int stride, float fPointSize, const float* colors, int drawstyle = 0, bool bhasalpha = false) = 0;

    /// \brief Draws a series of connected lines with one color. <b>[multi-thread safe]</b>
    ///
    /// \param stride stride in bytes to next point, ie: nextpoint = (float*)((char*)ppoints+stride)
    /// \param color the rgb color of the point. The last component of the color is used for alpha blending
    /// \return handle to plotted points, graph is removed when handle is destroyed (goes out of scope). This requires the user to always store the handle in a persistent variable if the plotted graphics are to remain on the viewer.
    virtual OpenRAVE::GraphHandlePtr drawlinestrip(const float* ppoints, int numPoints, int stride, float fwidth, const RaveVector<float>& color = RaveVector<float>(1,0.5,0.5,1)) = 0;

    /// \brief Draws a series of connected lines with individual colors. <b>[multi-thread safe]</b>
    ///
    /// \param stride stride in bytes to next point, ie: nextpoint = (float*)((char*)ppoints+stride)
    /// \return handle to plotted points, graph is removed when handle is destroyed (goes out of scope). This requires the user to always store the handle in a persistent variable if the plotted graphics are to remain on the viewer.
    virtual OpenRAVE::GraphHandlePtr drawlinestrip(const float* ppoints, int numPoints, int stride, float fwidth, const float* colors) = 0;

    /// \brief Draws a list of individual lines, each specified by a succeeding pair of points. <b>[multi-thread safe]</b>
    ///
    /// \param stride stride in bytes to next point, ie: nextpoint = (float*)((char*)ppoints+stride)
    /// \param color the rgb color of the point. The last component of the color is used for alpha blending.
    /// \return handle to plotted points, graph is removed when handle is destroyed (goes out of scope). This requires the user to always store the handle in a persistent variable if the plotted graphics are to remain on the viewer.
    virtual OpenRAVE::GraphHandlePtr drawlinelist(const float* ppoints, int numPoints, int stride, float fwidth, const RaveVector<float>& color = RaveVector<float>(1,0.5,0.5,1)) = 0;

    /// \brief Draws a list of individual lines, each specified by a succeeding pair of points. <b>[multi-thread safe]</b>
    ///
    /// \param stride stride in bytes to next point, ie: nextpoint = (float*)((char*)ppoints+stride)
    /// \return handle to plotted points, graph is removed when handle is destroyed (goes out of scope). This requires the user to always store the handle in a persistent variable if the plotted graphics are to remain on the viewer.
    virtual OpenRAVE::GraphHandlePtr drawlinelist(const float* ppoints, int numPoints, int stride, float fwidth, const float* colors) = 0;

    /// \brief Draws an arrow p1 is start, p2 is finish. <b>[multi-thread safe]</b>
    ///
    /// \param color the rgb color of the point. The last component of the color is used for alpha blending.
    /// \return handle to plotted points, graph is removed when handle is destroyed (goes out of scope). This requires the user to always store the handle in a persistent variable if the plotted graphics are to remain on the viewer.
    virtual OpenRAVE::GraphHandlePtr drawarrow(const RaveVector<float>& p1, const RaveVector<float>& p2, float fwidth, const RaveVector<float>& color = RaveVector<float>(1,0.5,0.5,1)) = 0;

    /// \brief Draws a box. <b>[multi-thread safe]</b>
    ///
    /// extents are half the width, height, and depth of the box
    /// \return handle to plotted points, graph is removed when handle is destroyed (goes out of scope). This requires the user to always store the handle in a persistent variable if the plotted graphics are to remain on the viewer.
    virtual OpenRAVE::GraphHandlePtr drawbox(const RaveVector<float>& vpos, const RaveVector<float>& vextents) = 0;

    /// \brief Draws a textured plane. <b>[multi-thread safe]</b>
    ///
    /// \param tplane describes the center of the plane. the zaxis of this coordinate is the normal of the plane
    /// \param vextents the extents of the plane along the x and y directions (z is ignored)
    /// \param vtexture a 3D array specifying height x width x color (the color dimension can be 1, 3, or 4 (for alpha blending))
    /// \return handle to plotted points, graph is removed when handle is destroyed (goes out of scope). This requires the user to always store the handle in a persistent variable if the plotted graphics are to remain on the viewer.
    virtual OpenRAVE::GraphHandlePtr drawplane(const RaveTransform<float>& tplane, const RaveVector<float>& vextents, const boost::multi_array<float,3>& vtexture) = 0;

    virtual OpenRAVE::GraphHandlePtr drawtrimesh(const float* ppoints, int stride, const int* pIndices, int numTriangles, const RaveVector<float>& color) = 0;

    /// \brief Draws a triangle mesh, each vertices of each triangle should be counter-clockwise. <b>[multi-thread safe]</b>
    ///
    /// \param ppoints - array of 3D points
    /// \param stride stride in bytes to next point, ie: nextpoint = (float*)((char*)ppoints+stride)
    /// \param pIndices If not NULL, zero-based indices into the points for every triangle. pIndices
    /// should be of size numTriangles. If pIndices is NULL, ppoints is assumed to contain numTriangles*3
    /// points and triangles will be rendered in list order.
    /// \param color The color of the triangle. The last component of the color is used for alpha blending
    /// \return handle to plotted points, graph is removed when handle is destroyed (goes out of scope). This requires the user to always store the handle in a persistent variable if the plotted graphics are to remain on the viewer.
    virtual OpenRAVE::GraphHandlePtr drawtrimesh(const float* ppoints, int stride, const int* pIndices, int numTriangles, const boost::multi_array<float,2>& colors) = 0;
    //@}

    /// \deprecated (10/09/23) see \ref RaveGetHomeDirectory
    virtual const std::string& GetHomeDirectory() const RAVE_DEPRECATED = 0;

    //@{ debug/global commands

    /// sets the debug level
    /// \param level 0 for no debug, 1 - to print all debug messeges. Default
    ///             value for release builds is 0, for debug builds it is 1
    /// declaring variables with stdcall can be a little complex
    virtual void SetDebugLevel(uint32_t level) = 0;
    virtual uint32_t GetDebugLevel() const = 0;
    //@}

protected:
    virtual const char* GetHash() const {
        return OPENRAVE_ENVIRONMENT_HASH;
    }
private:
    UserDataPtr __pUserData;         ///< \see GetUserData
    int __nUniqueId;         ///< \see GetId
};

} // end namespace OpenRAVE

#endif
