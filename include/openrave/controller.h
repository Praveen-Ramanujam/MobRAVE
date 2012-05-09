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
/** \file controller.h
    \brief Controller related definitions.
 */
#ifndef OPENRAVE_CONTROLLER_H
#define OPENRAVE_CONTROLLER_H

namespace OpenRAVE {

/** \brief <b>[interface]</b> Abstract base class to encapsulate a local controller. <b>If not specified, method is not multi-thread safe.</b> See \ref arch_controller.
    \ingroup interfaces
 */
class OPENRAVE_API ControllerBase : public InterfaceBase
{
public:
    ControllerBase(EnvironmentBasePtr penv) : InterfaceBase(PT_Controller, penv) {
    }
    virtual ~ControllerBase() {
    }

    /// \brief return the static interface type this class points to (used for safe casting)
    static inline InterfaceType GetInterfaceTypeStatic() {
        return PT_Controller;
    }

    /// \brief Initializes the controller
    /// \param robot the robot that uses the controller
    /// \param args extra arguments that the controller takes.
    /// \return true on successful initialization
    virtual bool Init(RobotBasePtr robot, const std::string& args) RAVE_DEPRECATED {
        if( !robot ) {
            return false;
        }
        std::vector<int> dofindices;
        for(int i = 0; i < robot->GetDOF(); ++i) {
            dofindices.push_back(i);
        }
        return Init(robot,dofindices,true);
    }

    /// \brief initializes the controller and specifies the controlled dof
    /// \param robot the robot that uses the controller
    /// \param dofindices the indices that controller will have exclusive access to
    /// \param nControlTransformation \see IsControlTransformation
    /// \return true on successful initialization
    virtual bool Init(RobotBasePtr robot, const std::vector<int>& dofindices, int nControlTransformation) = 0;

    /// \brief returns the dof indices controlled
    virtual const std::vector<int>& GetControlDOFIndices() const = 0;

    /// \brief returns non-zero value if base affine transformation is controlled.
    ///
    /// Only one controller can modify translation and orientation per robot. For now, the two cannot be divided.
    virtual int IsControlTransformation() const = 0;

    virtual RobotBasePtr GetRobot() const = 0;

    /// \brief Resets the current controller trajectories and any other state associated with the robot
    /// \param options - specific options that can be used to control what to reset
    virtual void Reset(int options) = 0;

    /// \brief go to a specific position in configuration space. <b>[multi-thread safe]</b>
    /// \param values the final configuration in the control dofs
    /// \param trans the transformation of the base. If not specified will use the current robot transformation. Ignored if controller does not use it
    /// \return true if position operation successful.
    virtual bool SetDesired(const std::vector<dReal>& values, TransformConstPtr trans=TransformConstPtr()) = 0;

    /// \brief Follow a path in configuration space, adds to the queue of trajectories already in execution. <b>[multi-thread safe]</b>
    /// \param ptraj - the trajectory
    /// \return true if trajectory operation successful
    virtual bool SetPath(TrajectoryBaseConstPtr ptraj) = 0;

    /// \brief Simulate one step forward for controllers running in the simulation environment
    /// \param fTimeElapsed - time elapsed in simulation environment since last frame
    virtual void SimulationStep(dReal fTimeElapsed) = 0;

    /// \brief Return true when goal reached.
    ///
    /// If a trajectory was set, return only when
    /// trajectory is done. If SetDesired was called, return only when robot is
    /// is at the desired location. If SendCommand sent, returns true when the command
    /// was completed by the hand.
    virtual bool IsDone() = 0;

    /// \brief return the time along the current command
    virtual dReal GetTime() const OPENRAVE_DUMMY_IMPLEMENTATION;

    /// \brief get velocity of the controlled DOFs
    ///
    /// \param vel [out] - current velocity of robot from the dof
    virtual void GetVelocity(std::vector<dReal>& vel) const OPENRAVE_DUMMY_IMPLEMENTATION;

    /// get torque/current/strain values
    /// \param torque [out] - returns the current torque/current/strain exerted by each of the dofs from outside forces.
    /// The feedforward and friction terms should be subtracted out already
    virtual void GetTorque(std::vector<dReal>& torque) const OPENRAVE_DUMMY_IMPLEMENTATION;

    //        Specifies the controlled degrees of freedom used to control the robot through torque In the
    //        general sense, it is not always the case that there's a one-to-one mapping between a robot's
    //        joints and the motors used to control the robot. A good example of this is a
    //        differential-drive robot. If developers need such a robot, they should derive from RobotBase
    //        and override these methods. The function that maps control torques to actual movements of
    //        the robot should be put in SimulationStep.  As default, the control degrees of freedom are
    //        tied directly to the active degrees of freedom; the max torques for affine dofs are 0 in
    //        this case.
    //    virtual void GetControlMaxTorques(std::vector<dReal>& vmaxtorque) const;
    //    virtual void SetControlTorques(const std::vector<dReal>& pTorques);

private:
    virtual const char* GetHash() const {
        return OPENRAVE_CONTROLLER_HASH;
    }
};

/** \brief controller that manage multiple controllers, allows users to easily set multiple controllers for one robot.

    The class also make sure individual controllers do not have colliding DOF. It ignores the
 */
class OPENRAVE_API MultiController : public ControllerBase
{
public:
    MultiController(EnvironmentBasePtr penv);
    virtual ~MultiController();

    /// \brief removes all controllers. <b>[multi-thread safe]</b>
    virtual bool Init(RobotBasePtr robot, const std::vector<int>& dofindices, int nControlTransformation);
    virtual const std::vector<int>& GetControlDOFIndices() const;
    virtual int IsControlTransformation() const;
    virtual RobotBasePtr GetRobot() const;

    /// \brief initializes and adds a controller, must be called after being initialized. <b>[multi-thread safe]</b>
    ///
    /// \param controller the controller to init
    /// \param dofindices robot dof indices to control
    /// \throw openrave_exception if the controller dofs interfere with current set dofs, will throw an exception
    virtual bool AttachController(ControllerBasePtr controller, const std::vector<int>& dofindices, int nControlTransformation);

    /// \brief removes a controller from being managed. <b>[multi-thread safe]</b>
    virtual void RemoveController(ControllerBasePtr controller);

    /// \brief gets the controller responsible for dof (in the robot). If dof < 0, returns the transform controller. <b>[multi-thread safe]</b>
    virtual ControllerBasePtr GetController(int dof) const;

    virtual void Reset(int options);
    virtual bool SetDesired(const std::vector<dReal>& values, TransformConstPtr trans=TransformConstPtr());
    virtual bool SetPath(TrajectoryBaseConstPtr ptraj);
    virtual void SimulationStep(dReal fTimeElapsed);

    /// \brief returns true only if all controllers return true
    virtual bool IsDone();

    /// \brief return the maximum time
    virtual dReal GetTime() const;

    virtual void GetVelocity(std::vector<dReal>& vel) const;

    /// get torque/current/strain values
    /// \param torque [out] - returns the current torque/current/strain exerted by each of the dofs from outside forces.
    /// The feedforward and friction terms should be subtracted out already
    virtual void GetTorque(std::vector<dReal>& torque) const;

protected:
    RobotBasePtr _probot;
    std::vector<int> _dofindices, _dofreverseindices;
    int _nControlTransformation;
    std::list<ControllerBasePtr> _listcontrollers;
    std::vector<ControllerBasePtr> _vcontrollersbydofs;
    ControllerBasePtr _ptransformcontroller;
    TrajectoryBasePtr _ptraj;
    mutable boost::mutex _mutex;
};

typedef boost::shared_ptr<MultiController> MultiControllerPtr;
typedef boost::shared_ptr<MultiController const> MultiControllerConstPtr;

} // end namespace OpenRAVE

#endif
