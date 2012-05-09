// This file is a modified version of the odephysics.h contained in the 
// openrave software, see below license details

// Copyright (c) 2010, CSIRO Autonomous Systems Lab, Nick Hillier

// Copyright (C) 2006-2008 Rosen Diankov (rdiankov@cs.cmu.edu)
//
// This program is free software: you can redistribute it and/or modify
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
#ifndef NXT_RAVE_PHYSICSENGINE_ODE
#define NXT_RAVE_PHYSICSENGINE_ODE

#include "nxt_odespace.h"

#ifdef USE_PARALLEL
#include <parallel_quickstep/parallel_quickstep.h>
#endif

using namespace std;
//using namespace OpenRAVE; // causes dReal ambiguity - left as a comment so I know not to add it in!

struct collision_props {
    int FrictionModel;
    dReal mu;
    dReal erp;
    dReal cfm;
};

struct disable_props {
    bool AutoDisableFlag;
    dReal AutoDisableLinearThreshold;
    dReal AutoDisableAngularThreshold;
    dReal AutoDisableTime;
};

void makeStringHash(string string1, string string2, string & hash_string){
    // order the name strings alphabetically and create hash ID
    locale loc; // "C" locale for collate
    const collate<char>& coll = use_facet<collate<char> >(loc); // get collate facet
    if (coll.compare(string1.data(),string1.data()+string1.length(),
                string2.data(),string2.data()+string2.length()) < 0) {
        hash_string = string1;
        hash_string += string2;
    } else {
        hash_string = string2;
        hash_string += string1;
    }
    //cout << hash_string << endl;
};

class CustomODEPhysics : public OpenRAVE::PhysicsEngineBase
{
    // ODE joint helper fns
    static dReal DummyGetParam(dJointID id, int param)
    {
        return 0;
    }

    static void DummyAddForce(dJointID id, const dReal* vals)
    {
        RAVELOG_ERROR(str(boost::format("failed to add force to dummy %d")%dJointGetType(id)));
    }

    static void dJointAddHingeTorque_(dJointID id, const dReal* vals) {
        dJointAddHingeTorque(id, vals[0]);
    }
    static void dJointAddSliderForce_(dJointID id, const dReal* vals) {
        dJointAddSliderForce(id, vals[0]);
    }
    static void dJointAddUniversalTorques_(dJointID id, const dReal* vals) {
        dJointAddUniversalTorques(id, vals[0], vals[1]);
    }
    static void dJointAddHinge2Torques_(dJointID id, const dReal* vals) {
        dJointAddHinge2Torques(id, vals[0], vals[1]);
    }

    static dReal dJointGetHinge2Angle2_(dJointID id) {
        return 0;
    }

    static dReal JointGetBallVelocityX(dJointID) {
        return 0;
    }
    static dReal JointGetBallVelocityY(dJointID) {
        return 0;
    }
    static dReal JointGetBallVelocityZ(dJointID) {
        return 0;
    }

    inline boost::shared_ptr<CustomODEPhysics> shared_physics() {
        return boost::static_pointer_cast<CustomODEPhysics>(shared_from_this());
    }
    inline boost::shared_ptr<CustomODEPhysics const> shared_physics_const() const { 
        return boost::static_pointer_cast<CustomODEPhysics const>(shared_from_this());
    }

    class CustomODEXMLReader : public BaseXMLReader
    {
    public:
    CustomODEXMLReader(boost::shared_ptr<CustomODEPhysics> physics, const std::list<std::pair<std::string,std::string> >& atts) : _physics(physics) {
            _bProcessContact = false;
            _bProcessDefault = false;
        }

        virtual ProcessElement startElement(const std::string& name, const std::list<std::pair<std::string,std::string> >& atts) {
            if( name == "contact" ) {
                _bProcessContact = true;
                _BodyCount = 0;
                temp_ColProps.FrictionModel = 0;
                temp_ColProps.mu = (dReal)1.0;
                temp_ColProps.erp = (dReal)0.96; ///< between 0 and 1. 1 is correct all errors per timestep, but likely to be unstable.
                temp_ColProps.cfm = (dReal)0.0001; ///< smaller is "harder", 0 is solve constraints exactly
                
                FOREACHC(itatt,atts) {
                    if( itatt->first == "body0" ) {
                        _BodyCount++;
                        tempBody1 = itatt->second;
                    } 
                    if( itatt->first == "body1" ) {
                        _BodyCount++;
                        tempBody2 = itatt->second;
                    }
                    
                    //if (_BodyCount > 2) { // the xml parser should handle this for us with attribute redefinition
                    //    std::string dump = itatt->second;
                    //    RAVELOG_ERRORA("Maximum of two bodies allowed per friction characterisation. %s will be ignored\n", dump.c_str());
                    //}
                }
                if (_BodyCount == 0){
                    _bProcessDefault = true;
                } else {
                    _bProcessDefault = false;
                }
                //RAVELOG_INFO("_BodyCount = %d\n", _BodyCount);
                ss.str("");
                return PE_Support;
            } else if (name=="friction"||name=="erp"||name=="cfm"||name=="model"||name=="gravity"||name=="selfcollision"||name=="solver"||name=="autodisable"||name=="linearthreshold"||name=="angularthreshold"||name=="disabletime") {
                ss.str("");
                return PE_Support;
            }
            ss.str(""); 
            return PE_Pass;            
        }
        
        virtual bool endElement(const std::string& name)
        {
            if( name == "csiro_odeproperties") {
                //printf("csiro_odeproperties tag has been read\n");
                return true;
            }

            if(_bProcessContact){
                if( name == "contact" ) { // reached the end of this tag set
                    if (!_bProcessDefault) {
                        if (_BodyCount == 1) { // this is for contact properties for one body against everything else
                            RAVELOG_INFO("Setting contact properties for one body against everything else is not yet supported, contacts will use default properties\n");
                        } else {
                            string hashString;
                            makeStringHash(tempBody1, tempBody2, hashString);
                            // add this col props set to the map of all custom props for the simulation
                            _physics->_ColProps[hashString] = temp_ColProps;
                        }
                    }
                    _bProcessContact = false;
                }
                else if( name == "friction") {
                    int count = 0;
                    while(!ss.eof() && (count < 1)) {
                        dReal f;
                        ss >> f;
                        if( !ss ) {
                            break;
                        }
                        if(_bProcessDefault){
                            _physics->_defaults.mu = f;
//                            printf("setting default mu to %f\n",f);
                        } else {
                            temp_ColProps.mu = f;
                            //printf("mu is = %f\n",f);
                        }
                        count++;
                    }
                    
                }
                else if( name == "erp") {
                    int count = 0;
                    while(!ss.eof() && (count < 1)) {
                        dReal f;
                        ss >> f;
                        if( !ss ) {
                            break;
                        }
                        if(_bProcessDefault){
                            _physics->_defaults.erp = f;
                        } else {
                            temp_ColProps.erp = f;
                        }
                        count++;
                    }
                }
                else if( name == "cfm") {
                    int count = 0;
                    while(!ss.eof() && (count < 1)) {
                        dReal f;
                        ss >> f;
                        if( !ss ) {
                            break;
                        }
                        if(_bProcessDefault){
                            _physics->_defaults.cfm = f;
                        } else {
                            temp_ColProps.cfm = f;
                        }
                        count++;
                    }
                }
                else if( name == "model") {
                    int fricmodel;
                    if (_bProcessDefault){
                        fricmodel = _physics->_defaults.FrictionModel;
                    } else {
                        fricmodel = temp_ColProps.FrictionModel;
                    }
                    std::string dump;
                    while(!ss.eof()) {
                        ss >> dump;
                        if( strcmp((const char*)dump.c_str(), "Approx1") == 0) {
                            fricmodel = fricmodel | dContactApprox1;
                            //printf("adding dContactApprox1\n");
                        } else if( strcmp((const char*)dump.c_str(), "SoftCFM") == 0) {
                            fricmodel = fricmodel | dContactSoftCFM;
                            //printf("adding dContactSoftCFM\n");
                        } else if( strcmp((const char*)dump.c_str(), "SoftERP") == 0) {
                            fricmodel = fricmodel | dContactSoftERP;
                            //printf("adding dContactSoftERP\n");
                        } else {
                            RAVELOG_WARN("model %s not supported (Currently support Approx1, SoftCFM, SoftERP)\n",ss.str().c_str());
                        }
                    }
                    //printf("model is: %d\n",fricmodel);
                    if(_bProcessDefault){
                       // printf("setting default model\n");
                        _physics->_defaults.FrictionModel = fricmodel;
                    } else {
                        temp_ColProps.FrictionModel = fricmodel;
                    }
                }
                else {
                    RAVELOG_ERRORA("unknown field %s within friction\n", name.c_str());
                }
            }
            else if( name == "gravity" ) {
                Vector v;
                ss >> v.x >> v.y >> v.z;
                if( !!ss ) {
                    _physics->SetGravity(v);
		        }
            }
            else if(name == "selfcollision" ) {
                while(!ss.eof()) {
                    std::string dump;
                    ss >> dump;
                    if( (strcmp((const char*)dump.c_str(), "true") == 0) || (strcmp((const char*)dump.c_str(), "1") == 0)) {
                        _physics->SetPhysicsOptions(OpenRAVE::PEO_SelfCollisions);
                    } else if( (strcmp((const char*)dump.c_str(), "false") == 0) || (strcmp((const char*)dump.c_str(), "0") == 0)) {
                        _physics->SetPhysicsOptions(0);
                    }
                    
                }
            }
            else if( name == "solver") { // if compiled with the USE_PARALLEL definition, QuickStep will use the ParallelQuickStep solver found in ROS.
                while(!ss.eof()) {
                    std::string dump;
                    ss >> dump; 
                    if( strcmp((const char*)dump.c_str(), "QuickStep") == 0) {
                        _physics->_bQuickStep = true;
                    } else if(strcmp((const char*)dump.c_str(), "NormalStep") == 0) {
                        _physics->_bQuickStep = false;
                    } else {
                        RAVELOG_ERRORA("unknown solver value: %s (QuickStep and NormalStep are supported)\n", dump.c_str());
                    }
                }
            }
            else if( name == "autodisable") {
                while(!ss.eof()) {
                    std::string dump;
                    ss >> dump; 
                    if( (strcmp((const char*)dump.c_str(), "true") == 0) || (strcmp((const char*)dump.c_str(), "1") == 0)) {
                        DisableProps.AutoDisableFlag = true;
                        _physics->SetAutoDisable(DisableProps);
                    }            
                }
            }
            else if( name == "linearthreshold" ) {
                int count = 0;
                while(!ss.eof() && (count < 1)) {
                    dReal f;
                    ss >> f;
                    if( !ss ) {
                        f = 0.0;
                    }
                    DisableProps.AutoDisableLinearThreshold = f;
                    _physics->SetAutoDisable(DisableProps);
                    count++;
                }
            }
            else if( name == "angularthreshold" ) {
                int count = 0;
                while(!ss.eof() && (count < 1)) {
                    dReal f;
                    ss >> f;
                    if( !ss ) {
                        f = 0.0;
                    }
                    DisableProps.AutoDisableAngularThreshold = f;
                    _physics->SetAutoDisable(DisableProps);
                    count++;
                }
            }
            else if( name == "disabletime") {
                int count = 0;
                while(!ss.eof() && (count < 1)) {
                    dReal f;
                    ss >> f;
                    if( !ss ) {
                        f = 0.0;
                    }
                    DisableProps.AutoDisableTime = f;
                    _physics->SetAutoDisable(DisableProps);
                    count++;
                }
            } else {
                RAVELOG_ERRORA("unknown field %s\n", name.c_str());
            }
            if( !ss ) {
                RAVELOG_WARNA("CustomODEXMLReader: error parsing %s\n", name.c_str());
                cout << "***" << ss << "***" << endl;
            }

            return false;
        }

        virtual void characters(const std::string& ch)
        {
            ss.clear();
            ss.str(ch);
        }

    protected:
        boost::shared_ptr<CustomODEPhysics> _physics;
        stringstream ss;
        bool _bProcessContact;
        bool _bProcessDefault;
        int _BodyCount;
        collision_props temp_ColProps;
        string tempBody1,tempBody2;
        disable_props DisableProps;
    };

 public:
    static BaseXMLReaderPtr CreateXMLReader(InterfaceBasePtr ptr, const std::list<std::pair<std::string,std::string> >& atts)
    {
        return BaseXMLReaderPtr(new CustomODEXMLReader(boost::dynamic_pointer_cast<CustomODEPhysics>(ptr),atts));
    }

 CustomODEPhysics(OpenRAVE::EnvironmentBasePtr penv) : OpenRAVE::PhysicsEngineBase(penv), odespace(new ODESpace(penv, GetPhysicsInfo, true)) {
        //printf("customODEPhysics Constructor called\n");
        if( !odespace->IsInitialized() ){
            //printf("CustomODEPhysics Const re-init\n");
            _defaults.FrictionModel = 0;
            for (int i=0;i<3;i++){
                _gravity[i] = 0;
            }
            SetPhysicsOptions(0);
            _defaults.FrictionModel = 0;
            _defaults.mu = (dReal)1.0;
            _defaults.erp = (dReal)0.96; ///< between 0 and 1. 1 is correct all errors per timestep, but likely to be unstable.
            _defaults.cfm = (dReal)0.0001; ///< smaller is "harder", 0 is solve constraints exactly
            _bQuickStep = true;
            
            _firstPQ = true;

			memset(_jointadd, 0, sizeof(_jointadd));
            _jointadd[dJointTypeBall] = DummyAddForce;
            _jointadd[dJointTypeHinge] = dJointAddHingeTorque_;
            _jointadd[dJointTypeSlider] = dJointAddSliderForce_;
            _jointadd[dJointTypeUniversal] = dJointAddUniversalTorques_;
            _jointadd[dJointTypeHinge2] = dJointAddHinge2Torques_;

            _jointgetvel[dJointTypeBall].push_back(JointGetBallVelocityX);
            _jointgetvel[dJointTypeBall].push_back(JointGetBallVelocityY);
            _jointgetvel[dJointTypeBall].push_back(JointGetBallVelocityZ);
            _jointgetvel[dJointTypeHinge].push_back(dJointGetHingeAngleRate);
            _jointgetvel[dJointTypeSlider].push_back(dJointGetSliderPositionRate);
            _jointgetvel[dJointTypeUniversal].push_back(dJointGetUniversalAngle1Rate);
            _jointgetvel[dJointTypeUniversal].push_back(dJointGetUniversalAngle2Rate);
            _jointgetvel[dJointTypeHinge2].push_back(dJointGetHinge2Angle1Rate);
            _jointgetvel[dJointTypeHinge2].push_back(dJointGetHinge2Angle2Rate);
        }
    }
    
    virtual bool InitEnvironment()
    {
        _report.reset(new OpenRAVE::CollisionReport());

        odespace->SetSynchornizationCallback(boost::bind(&CustomODEPhysics::_SyncCallback, shared_physics(),_1));
        if( !odespace->IsInitialized() ){
            //printf("CustomODEPhysics initEnv re-init\n");
            if( !odespace->InitEnvironment() ){
                return false;
            }
            vector<KinBodyPtr> vbodies;
            GetEnv()->GetBodies(vbodies);
            FOREACHC(itbody, vbodies){
                InitKinBody(*itbody);
            }
        }
        SetGravity(_gravity);
        SetAutoDisable(_DisableProps);
        return true;
    }


    virtual void DestroyEnvironment()
    {
        _listcallbacks.clear();
        _report.reset();
        odespace->DestroyEnvironment();
    }
    
    virtual bool InitKinBody(KinBodyPtr pbody)
    {
        OpenRAVE::UserDataPtr pinfo = odespace->InitKinBody(pbody);
        //ODESpace::KinBodyInfoPtr pinfo = _odespace->InitKinBody(pbody);
        SetPhysicsData(pbody, pinfo);
        return !!pinfo;
    }

    virtual bool SetPhysicsOptions(int physicsoptions)
    {
        _options = physicsoptions;
        return true;
    }

    virtual int GetPhysicsOptions() const
    {
        return _options;
    }

    virtual bool SetPhysicsOptions(std::ostream& sout, std::istream& sinput)
    {
        return false;
    }

    virtual bool SetLinkVelocity(KinBody::LinkPtr plink, const Vector& _linearvel, const Vector& angularvel)
    {
        odespace->Synchronize(plink->GetParent());
        dBodyID body = odespace->GetLinkBody(plink);
        if( !body ) {
            return false;
        }
		// set link velocity in frame of the link defined in OpenRAVE, not about its COM.
        Vector linearvel = _linearvel + angularvel.cross(plink->GetTransform()*plink->GetCOMOffset() - plink->GetTransform().trans);
        dBodySetLinearVel(body, linearvel.x, linearvel.y, linearvel.z);
        dBodySetAngularVel(body, angularvel.x, angularvel.y, angularvel.z);
        return true;
    }

    virtual bool SetLinkVelocities(KinBodyPtr pbody, const std::vector<std::pair<Vector,Vector> >& velocities)
    {
        bool bsuccess = true;
        odespace->Synchronize(pbody);
        FOREACHC(itlink, pbody->GetLinks()) {
            dBodyID body = odespace->GetLinkBody(*itlink);
            if( body ) {
                Vector angularvel = velocities.at((*itlink)->GetIndex()).second;
                dBodySetAngularVel(body, angularvel.x, angularvel.y, angularvel.z);
                Vector linearvel = velocities.at((*itlink)->GetIndex()).first;
                linearvel += angularvel.cross((*itlink)->GetTransform()*(*itlink)->GetCOMOffset() - (*itlink)->GetTransform().trans);
                dBodySetLinearVel(body, linearvel.x,linearvel.y,linearvel.z);
            }
            else {
                bsuccess = false;
            }
        }
        return bsuccess;
    }

    virtual bool GetLinkVelocity(KinBody::LinkConstPtr plink, Vector& linearvel, Vector& angularvel)
    {
        odespace->Synchronize(KinBodyConstPtr(plink->GetParent()));
        dBodyID body = odespace->GetLinkBody(plink);
        if( body ) {
            const dReal* p = dBodyGetAngularVel(body);
            angularvel = Vector(p[0], p[1], p[2]);
            p = dBodyGetLinearVel(body);
            linearvel = Vector(p[0], p[1], p[2]);
            linearvel -= angularvel.cross(plink->GetTransform()*plink->GetCOMOffset() - plink->GetTransform().trans);
        }
        else {
            angularvel = linearvel = Vector(0,0,0);
        }
        return true;
    }

    virtual bool GetLinkVelocities(KinBodyConstPtr pbody, std::vector<std::pair<Vector,Vector> >& velocities)
    {
        odespace->Synchronize(pbody);
        velocities.resize(0);
        velocities.resize(pbody->GetLinks().size());
        FOREACHC(itlink, pbody->GetLinks()) {
            dBodyID body = odespace->GetLinkBody(*itlink);
            if( body ) {
                const dReal* pf = dBodyGetAngularVel(body);
                Vector angularvel(pf[0], pf[1], pf[2]);
                velocities.at((*itlink)->GetIndex()).second = angularvel;
                pf = dBodyGetLinearVel(body);
                velocities.at((*itlink)->GetIndex()).first = Vector(pf[0], pf[1], pf[2]) - angularvel.cross((*itlink)->GetTransform()*(*itlink)->GetCOMOffset() - (*itlink)->GetTransform().trans);
            }
        }
        return true;
    }

    virtual bool GetLinkForceTorque(KinBody::LinkConstPtr plink, Vector& force, Vector& torque) {
        odespace->Synchronize(KinBodyConstPtr(plink->GetParent()));
        dBodyID body = odespace->GetLinkBody(plink);
        if( body ) {
            const dReal* pf = dBodyGetForce(body);
            force = Vector(pf[0],pf[1],pf[2]);
            const dReal* pt = dBodyGetTorque(body);
            torque = Vector(pt[0],pt[1],pt[2]);
        }
        else {
            force = Vector(0,0,0);
            torque = Vector(0,0,0);
        }
        return true;
    }

    virtual bool GetJointVelocity(KinBody::JointConstPtr pjoint, std::vector<OpenRAVE::dReal>& vJointVelocity)
    {
        dJointID joint = odespace->GetJoint(pjoint);
        BOOST_ASSERT( joint != NULL );
        odespace->Synchronize(KinBodyConstPtr(pjoint->GetParent()));
        vector<JointGetFn>::iterator itfn;
        vJointVelocity.resize(pjoint->GetDOF());
        vector<OpenRAVE::dReal>::iterator itvel = vJointVelocity.begin();
        FORIT(itfn, _jointgetvel[dJointGetType(joint)]) {
            *itvel++ = (*itfn)(joint);
        }
        return true;
    }

    virtual bool SetBodyForce(KinBody::LinkPtr plink, const Vector& force, const Vector& position, bool bAdd)
    {
        dBodyID body = odespace->GetLinkBody(plink);
        if( body == NULL ) {
            return false;
        }
        odespace->Synchronize(KinBodyConstPtr(plink->GetParent()));
        if( !bAdd ) {
            dBodySetForce(body, 0, 0, 0);
        }
        dBodyAddForceAtPos(body, force.x, force.y, force.z, position.x, position.y, position.z);
        return true;
    }

    virtual bool SetBodyTorque(KinBody::LinkPtr plink, const Vector& torque, bool bAdd)
    {
        dBodyID body = odespace->GetLinkBody(plink);
        if( body == NULL ) {
            return false;
        }
        odespace->Synchronize(KinBodyConstPtr(plink->GetParent()));

        if( !bAdd ) {
            dBodySetTorque(body, torque.x, torque.y, torque.z);
        }
        else {
            dBodyAddTorque(body, torque.x, torque.y, torque.z);
        }
        return true;
    }

    virtual bool AddJointTorque(KinBody::JointPtr pjoint, const std::vector<OpenRAVE::dReal>& pTorques)
    {
        dJointID joint = odespace->GetJoint(pjoint);
        BOOST_ASSERT( joint != NULL );
        odespace->Synchronize(KinBodyConstPtr(pjoint->GetParent()));
        std::vector<dReal> vtorques(pTorques.size());
        std::copy(pTorques.begin(),pTorques.end(),vtorques.begin());
        _jointadd[dJointGetType(joint)](joint, &vtorques[0]);
        return true;
    }

    virtual void SetGravity(const Vector& gravity)
    {
        _gravity = gravity;
        if( odespace->IsInitialized() ){
            dWorldSetGravity(odespace->GetWorld(),_gravity.x, _gravity.y, _gravity.z);
        }
    }

    virtual Vector GetGravity()
    {
        return _gravity;
    }

    virtual void SimulateStep(OpenRAVE::dReal fTimeElapsed)
    {
        odespace->Synchronize();

        bool bHasCallbacks = GetEnv()->HasRegisteredCollisionCallbacks();
        if( bHasCallbacks ) {
            GetEnv()->GetRegisteredCollisionCallbacks(_listcallbacks);
        }
        else {
            _listcallbacks.clear();
        }

        dSpaceCollide (odespace->GetSpace(),this,nearCallback);

        vector<KinBodyPtr> vbodies;
        GetEnv()->GetBodies(vbodies);

        if( _options & OpenRAVE::PEO_SelfCollisions ) {
            FOREACHC(itbody, vbodies) {
                if( (*itbody)->GetLinks().size() > 1 ) {
                    // more than one link, check collision
                    dSpaceCollide(odespace->GetBodySpace(*itbody), this, nearCallback);
                }
            }
        }

        if (_bQuickStep) {
#ifdef USE_PARALLEL
            if (_firstPQ){
                cout << "csiro_odephysics: using ParallelQuickStep()" << endl;
                _firstPQ=false;
            }
			dWorldParallelQuickStep(odespace->GetWorld(), fTimeElapsed);
#else
            //cout << "csiro_odephysics: using ODE's dWorldQuickStep() solver" << endl;
            dWorldQuickStep(odespace->GetWorld(), fTimeElapsed);

#endif
        } else {
            //cout << "csiro_odephysics: using ODE's default dWorldStep() solver" << endl;
            dWorldStep(odespace->GetWorld(), fTimeElapsed);
        }
        dJointGroupEmpty (odespace->GetContactGroup());

        // synchronize all the objects from the ODE world to the OpenRAVE world
        Transform t;
        FOREACHC(itbody, vbodies) {
            ODESpace::KinBodyInfoPtr pinfo = boost::dynamic_pointer_cast<ODESpace::KinBodyInfo>((*itbody)->GetPhysicsData());
            BOOST_ASSERT( pinfo->vlinks.size() == (*itbody)->GetLinks().size());
            for(size_t i = 0; i < pinfo->vlinks.size(); ++i) {
                t.rot = *(RaveVector<dReal>*)dBodyGetQuaternion(pinfo->vlinks[i]->body);
                t.trans = *(RaveVector<dReal>*)dBodyGetPosition(pinfo->vlinks[i]->body);
                (*itbody)->GetLinks()[i]->SetTransform(t);
            }

            pinfo->nLastStamp = (*itbody)->GetUpdateStamp();
        }

        _listcallbacks.clear();
    }


    void SetAutoDisable(const disable_props& props)
    {
        _DisableProps = props;
        if( odespace->IsInitialized() ){
            dWorldSetAutoDisableFlag (odespace->GetWorld(), _DisableProps.AutoDisableFlag);
            dWorldSetAutoDisableLinearThreshold (odespace->GetWorld(),_DisableProps.AutoDisableLinearThreshold);
            dWorldSetAutoDisableAngularThreshold (odespace->GetWorld(), _DisableProps.AutoDisableAngularThreshold);
            dWorldSetAutoDisableTime (odespace->GetWorld(), _DisableProps.AutoDisableTime);
        }
    }
    
 private:
    static OpenRAVE::UserDataPtr GetPhysicsInfo(KinBodyConstPtr pbody) { return pbody->GetPhysicsData(); }
    
    static void nearCallback(void *data, dGeomID o1, dGeomID o2)
    {
        ((CustomODEPhysics*)data)->_nearCallback(o1,o2);
    }

    void _nearCallback(dGeomID o1, dGeomID o2)
    {
        if( !dGeomIsEnabled(o1) || !dGeomIsEnabled(o2) ) {
            return; // disabled geoms don't interact with anything (things can pass through them)
        }
        if (dGeomIsSpace(o1) || dGeomIsSpace(o2)) {
            // colliding a space with something
            dSpaceCollide2(o1,o2,this, nearCallback);
            return;
        }

        dBodyID b1,b2;
        b1 = dGeomGetBody(o1);
        b2 = dGeomGetBody(o2);


        if(b1 == NULL || b2 == NULL) {   // if the geoms have no associated body properties, return
            return;
        }
		//if (!(_options & OpenRAVE::PEO_SelfCollisions) && dAreConnected (b1,b2)) { // allow us to turn on / off self collisions between adjacent links. Note use of MakeJoinedLinksAdjacent="0" XML tag on kinbodies
        //    return;
        //}

        if( (!dBodyIsEnabled(b1)) && (!dBodyIsEnabled(b2)) ){ // ignore collisions between two inactive bodies
            return;// both b1 and b2 are disabled, shouldn't be a collision anyway, but if bodies sit in mid air when bodies underneath them are removed, try commenting out this line
        }
        
        // This enable flag determines whether or not the link has physics enabled (or is just a render object to the physics engine). This is different to the ODE enable flag.
        KinBody::LinkPtr pkb1,pkb2;
        if(!!b1 && dBodyGetData(b1))
            pkb1 = *(KinBody::LinkPtr*)dBodyGetData(b1);
        if(!!b2 && dBodyGetData(b1))
            pkb2 = *(KinBody::LinkPtr*)dBodyGetData(b2);

        if( !!pkb1 && !pkb1->IsEnabled() )
            return;
        if( !!pkb2 && !pkb2->IsEnabled() )
            return;
        
        if((dBodyIsEnabled(b1) || dBodyIsEnabled(b2)) && (!dBodyIsEnabled(b1) || !dBodyIsEnabled(b2)) && !dBodyIsKinematic(b1) && !dBodyIsKinematic(b2)) {// collision between an enabled and disabled body, but neither is kinematic (static)
            //printf("re-enabling %ls, %ls\n",pkb1->GetName(), pkb2->GetName());
            if (!dBodyIsEnabled(b1)){
                dBodyEnable (b1);
            } else {
                dBodyEnable (b2);
            }
        }

        if( pkb1->GetParent() == pkb2->GetParent() ) {
            // check if links are adjacent
            int minindex = min(pkb1->GetIndex(), pkb2->GetIndex());
            int maxindex = max(pkb1->GetIndex(), pkb2->GetIndex());

            if( pkb1->GetParent()->GetAdjacentLinks().find(minindex|(maxindex<<16)) != pkb1->GetParent()->GetAdjacentLinks().end() )
                return;
        }

        const int N = 16;
        dContact contact[N];
        int n = dCollide (o1,o2,N,&contact[0].geom,sizeof(dContact));
        if( n <= 0 ){ 
                return; // no collisions
        }
        // check if there are custom defined collision call backs, and if so, deal with them appropriately.
        if( _listcallbacks.size() > 0 ) {
            // fill the collision report
            _report->Reset(OpenRAVE::CO_Contacts);
            _report->numCols = N;
            _report->plink1 = pkb1;
            _report->plink2 = pkb2;

            dGeomID checkgeom1 = dGeomGetClass(o1) == dGeomTransformClass ? dGeomTransformGetGeom(o1) : o1;
            for(int i = 0; i < n; ++i) {
                _report->contacts.push_back(OpenRAVE::CollisionReport::CONTACT(contact[i].geom.pos, checkgeom1 != contact[i].geom.g1 ? -Vector(contact[i].geom.normal) : Vector(contact[i].geom.normal), contact[i].geom.depth));
            }

            FOREACH(itfn, _listcallbacks) {
                OpenRAVE::CollisionAction action = (*itfn)(_report,true);
                if( action != OpenRAVE::CA_DefaultAction )
                    return;
            }
        }
        
        // setup link collision properties
        // Defaults
        int mode = _defaults.FrictionModel;
        dReal mu = _defaults.mu;
        dReal soft_erp = _defaults.erp;
        dReal soft_cfm = _defaults.cfm;
        // don't handle the below types yet
        //dReal mu2;
        //dReal bounce;
        //dReal bounce_vel;
        //dReal motion1, motion2, motionN;
        //dReal slip1, slip2;
        // process collisions
        for (int i=0; i<n; i++) 
        {
            string checkString;
            if (!(pkb1->GetName().empty()) && !(pkb1->GetName().empty())) { 
                makeStringHash(pkb1->GetName(), pkb2->GetName(), checkString); 
                // look it up and set properties
                map<string,collision_props>::iterator it;
                if ((it=_ColProps.find(checkString))!= _ColProps.end()){
                    mode = it->second.FrictionModel;
                    mu = it->second.mu;
                    soft_erp = it->second.erp;
                    soft_cfm = it->second.cfm;
                } //else {
                  //  RAVELOG_INFO("collision checkstring not found\n");
               // }
            }
//            if (checkString == "bucket_frontterrain"){
//                printf("Collision between %s, %s using mu = %f, mode = %d, soft_erp = %f, soft_cfm = %f\n",pkb1->GetName().c_str(), pkb2->GetName().c_str(), mu, mode, soft_erp, soft_cfm);
//            }
            
            contact[i].surface.mode = mode;
            contact[i].surface.mu = mu;
    //        contact[i].surface.mu2 = 100;
    //        contact[i].surface.slip1 = 0.7;
    //        contact[i].surface.slip2 = 0.7;
    //        contact[i].surface.mode = dContactSoftERP | dContactSoftCFM | dContactApprox1 | dContactSlip1 | dContactSlip2;
    //        contact[i].surface.mu = 50.0; // was: dInfinity
            contact[i].surface.soft_erp = soft_erp;
            contact[i].surface.soft_cfm = soft_cfm;
            dJointID c = dJointCreateContact (odespace->GetWorld(),odespace->GetContactGroup(),&contact[i]);

            // make sure that static objects are not enabled by adding a joint attaching them
            if( b1 ) b1 = dBodyIsEnabled(b1)?b1:0;
            if( b2 ) b2 = dBodyIsEnabled(b2)?b2:0;
            dJointAttach (c, b1, b2);

            //printf("intersection %s %s\n", ((KinBody::Link*)dBodyGetData(b1))->GetName(), ((KinBody::Link*)dBodyGetData(b2))->GetName());

        }
    }

    void _SyncCallback(ODESpace::KinBodyInfoConstPtr pinfo)
    {
        // reset dynamics
        FOREACHC(itlink, pinfo->vlinks) {
            if( (*itlink)->body != NULL ) {
                dBodySetAngularVel((*itlink)->body, 0, 0, 0);
                dBodySetLinearVel((*itlink)->body, 0, 0, 0);
                // not sure if should reset forces since sync call can happen much later
                //dBodySetForce((*itlink)->body, 0, 0, 0);
                //dBodySetTorque((*itlink)->body, 0, 0, 0);
            }
        }
    }

    boost::shared_ptr<ODESpace> odespace;
    Vector _gravity;
    int _options;
    map<string,collision_props> _ColProps;
    collision_props _defaults;
    bool _bQuickStep;
    bool _firstPQ;
    disable_props _DisableProps;
    
    typedef void (*JointSetFn)(dJointID, int param, dReal val);
    typedef dReal (*JointGetFn)(dJointID);
    typedef void (*JointAddForceFn)(dJointID, const dReal* vals);

    JointSetFn _jointset[12];
    JointAddForceFn _jointadd[12];
    vector<JointGetFn> _jointgetvel[12];
    std::list<EnvironmentBase::CollisionCallbackFn> _listcallbacks;
    CollisionReportPtr _report;
};

#endif
