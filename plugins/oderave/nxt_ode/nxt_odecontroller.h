// Minimally modified version of the standard odecontroller.h to include
// with the csiro_odephysics plugin, see below license details

// Copyright (c) 2010, CSIRO Autonomous Systems Lab, Nick Hillier

// Copyright (c) 2008-2010 Rosen Diankov (rosen.diankov@gmail.com), Juan Gonzalez
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/// A simple openrave plugin that registers a custom XML reader. This allows users
/// to extend the XML files to add their own tags. 
/// Once the plugin is compiled, cd to where the plugin was installed and open customreader.env.xml with openrave
#ifndef NXT_OPENRAVE_ODE_CONTROLLER
#define NXT_OPENRAVE_ODE_CONTROLLER


class ODEVelocityController : public ControllerBase
{
public:
 ODEVelocityController(EnvironmentBasePtr penv) : ControllerBase(penv)
    {
        __description = ":Interface Authors: Juan Gonzalez and Rosen Diankov\nODE Velocity controller.";
    }

    virtual bool Init(RobotBasePtr robot, const std::vector<int>& dofindices, int nControlTransformation)
    {
        _probot = robot;
        _dofindices = dofindices;
        if( nControlTransformation ) {
            RAVELOG_WARN("odevelocity controller cannot control transformation\n");
        }
        Reset(0);
        return true;
    }

    virtual void Reset(int options)
    {
        if( !!_probot ) {
            EnvironmentMutex::scoped_lock lock(GetEnv()->GetMutex());
            ODESpace::KinBodyInfoPtr pinfo = GetODESpace();
            if( !!pinfo ) {
                boost::shared_ptr<ODESpace> odespace(pinfo->_odespace);
                FOREACHC(it, _dofindices) {
                    KinBody::JointConstPtr pjoint = _probot->GetJointFromDOFIndex(*it);
                    dJointID jointid = pinfo->vjoints.at(pjoint->GetJointIndex());
                    int index = *it-pjoint->GetJointIndex();
                    BOOST_ASSERT(index>=0);
                    odespace->_jointset[dJointGetType(jointid)](jointid,dParamFMax+dParamGroup*index, 0);
                }
            }
        }
        _bVelocityMode = false;
    }

    virtual const std::vector<int>& GetControlDOFIndices() const { return _dofindices; }
    virtual int IsControlTransformation() const { return 0; }

    virtual bool SetDesired(const std::vector<OpenRAVE::dReal>& values, OpenRAVE::TransformConstPtr trans) {
        Reset(0);
        return false;
    }
    virtual bool SetPath(TrajectoryBaseConstPtr ptraj) {
        Reset(0);
        return false;
    }
    virtual void SimulationStep(OpenRAVE::dReal fTimeElapsed) {}
    virtual bool IsDone() { return !_bVelocityMode; }
    virtual OpenRAVE::dReal GetTime() const { return 0; }
    virtual RobotBasePtr GetRobot() const { return _probot; }

    virtual ODESpace::KinBodyInfoPtr GetODESpace() {
        return boost::dynamic_pointer_cast<ODESpace::KinBodyInfo>(_probot->GetPhysicsData());
    }

    bool SendCommand(std::ostream& os, std::istream& is)
    {
        string cmd;
        is >> cmd;
        std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

        if( cmd == "setvelocity" ) {
            vector<OpenRAVE::dReal> velocities(_dofindices.size());
            for(size_t i = 0; i < velocities.size(); ++i) {
                is >> velocities[i];
                if( !is ) {
                    return false;
                }
            }

            EnvironmentMutex::scoped_lock lock(GetEnv()->GetMutex());
            ODESpace::KinBodyInfoPtr pinfo = GetODESpace();
            if( !pinfo ) {
                RAVELOG_WARN("need to set ode physics engine\n");
                return false;
            }
            boost::shared_ptr<ODESpace> odespace(pinfo->_odespace);
            int dofindex = 0;
            FOREACHC(it, _dofindices) {
                KinBody::JointConstPtr pjoint = _probot->GetJointFromDOFIndex(*it);
                dJointID jointid = pinfo->vjoints.at(pjoint->GetJointIndex());
                int jindex = *it-pjoint->GetJointIndex();
                BOOST_ASSERT(jindex>=0);
                odespace->_jointset[dJointGetType(jointid)](jointid,dParamFMax+dParamGroup*jindex, pjoint->GetMaxTorque());
                odespace->_jointset[dJointGetType(jointid)](jointid,dParamVel+dParamGroup*jindex, velocities.at(dofindex++));
            }
            _bVelocityMode = true;
            return true;
        }

        throw openrave_exception(str(boost::format("command %s supported")%cmd),OpenRAVE::ORE_CommandNotSupported);
        return false;
    }
    
protected:
    RobotBasePtr _probot;
    std::vector<int> _dofindices;
    bool _bVelocityMode;
};

#endif
