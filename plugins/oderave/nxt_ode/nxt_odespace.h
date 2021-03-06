// This file is a modified version of the odespace.h contained in the 
// openrave software, see below license details

// Copyright (c) 2010, CSIRO Autonomous Systems Lab, Nick Hillier

// Copyright (C) 2006-2009 Rosen Diankov (rdiankov@cs.cmu.edu)
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
#ifndef NXT_OPENRAVE_ODE_SPACE
#define NXT_OPENRAVE_ODE_SPACE

#include "nxt_plugindefs.h"

// manages a space of ODE objects
class ODESpace : public boost::enable_shared_from_this<ODESpace>
{
    static void DummySetParam(dJointID id, int param, dReal)
    {
        cerr << "failed to set param to dummy " << dJointGetType(id) << endl;
    }

    inline boost::weak_ptr<ODESpace> weak_space() { return shared_from_this(); }

    class ODEResources
    {
    public:
        ODEResources() {
#ifdef ODE_HAVE_ALLOCATE_DATA_THREAD
            dAllocateODEDataForThread(dAllocateMaskAll);
#endif
            world = dWorldCreate();
            space = dHashSpaceCreate(0);
            contactgroup = dJointGroupCreate(0);
        }
        virtual ~ODEResources() {
            if( contactgroup )
                dJointGroupDestroy(contactgroup);
            if( space )
                dSpaceDestroy(space);
            if( world )
                dWorldDestroy(world);
            //dCloseODE(); // should only be one instance of this class per running physics engine, so ok to call this? COMMENTED OUT - possibly multpile parrallel simulations (clones)
        }
        dWorldID world;  ///< the dynamics world
        dSpaceID space;  ///< the collision sub-space in the world
        dJointGroupID contactgroup;
    };

public:
    // information about the kinematics of the body
    class KinBodyInfo : public boost::enable_shared_from_this<KinBodyInfo>, public OpenRAVE::UserData
    {
    public:
        struct LINK
        {
        LINK() : body(NULL), geom(NULL) {}

            dBodyID body;
            dGeomID geom;

            void Enable(bool bEnable)
            {
                if( body ) {
                    if( bEnable) dBodyEnable(body);
                    else dBodyDisable(body);
                }
    
                dGeomID curgeom = geom;
                while(curgeom != NULL ) {
        
                    if( bEnable ) dGeomEnable(curgeom);
                    else dGeomDisable(curgeom);
        
                    if( dGeomGetClass(curgeom) == dGeomTransformClass ) {
                        if( bEnable ) dGeomEnable(dGeomTransformGetGeom(curgeom));
                        else dGeomDisable(dGeomTransformGetGeom(curgeom));
                    }
        
                    curgeom = dGeomGetBodyNext(curgeom);
                }
            }


            list<dTriIndex*> listtrimeshinds;
            list<dReal*> listvertices;
            KinBody::LinkPtr plink;
        };

    KinBodyInfo(boost::shared_ptr<ODEResources> ode) : _ode(ode)
        {
            jointgroup = dJointGroupCreate(0);
            space = dHashSpaceCreate(_ode->space);
            nLastStamp = 0;
        }

        virtual ~KinBodyInfo() {
            EnvironmentMutex::scoped_lock lock(pbody->GetEnv()->GetMutex()); // protected ode calls
            Reset();
            dSpaceClean(space);
            dJointGroupEmpty(jointgroup);
            
            dSpaceDestroy(space);
            dJointGroupDestroy(jointgroup);
        }

        void Reset()
        {
            FOREACH(itlink, vlinks) {
                dGeomID curgeom = (*itlink)->geom;
                while(curgeom) {
                    dGeomID pnextgeom = dGeomGetBodyNext(curgeom);
                    if( dGeomGetClass(curgeom) == dGeomTransformClass ) {
                        dGeomID childgeom = dGeomTransformGetGeom(curgeom);
                        if( childgeom != NULL && dGeomGetClass(childgeom) == dTriMeshClass ) {
                            if( dGeomTriMeshGetData(childgeom) != 0 ) {
                                dGeomTriMeshDataDestroy(dGeomTriMeshGetData(childgeom));
                            }
                        }
                    }
                    else if( dGeomGetClass(curgeom) == dTriMeshClass ) {
                        if( dGeomTriMeshGetData(curgeom) != 0 )
                            dGeomTriMeshDataDestroy(dGeomTriMeshGetData(curgeom));
                    }
                    dGeomDestroy(curgeom);
                    curgeom = pnextgeom;
                }

                if( (*itlink)->body )
                    dBodyDestroy((*itlink)->body);

                FOREACH(itind, (*itlink)->listtrimeshinds)
                    delete *itind;
                FOREACH(itind, (*itlink)->listvertices)
                    delete *itind;
            }
            vlinks.resize(0);

            FOREACH(itjoint, vjoints) {
                if( *itjoint )
                    dJointDestroy(*itjoint);
            }
            vjoints.resize(0);

            _geometrycallback.reset();
        }

        KinBodyPtr pbody; ///< body associated with this structure
        int nLastStamp;
        
        vector<boost::shared_ptr<LINK> > vlinks; ///< if body is disabled, then geom is static (it can't be connected to a joint!)
        ///< the pointer to this Link is the userdata
        vector<dJointID> vjoints;
        boost::shared_ptr<void> _geometrycallback;
        boost::weak_ptr<ODESpace> _odespace;

        dSpaceID space;                     ///< space that contains all the collision objects of this KinBody
        dJointGroupID jointgroup;

    private:
        boost::shared_ptr<ODEResources> _ode;
    };

    typedef boost::shared_ptr<KinBodyInfo> KinBodyInfoPtr;
    typedef boost::shared_ptr<KinBodyInfo const> KinBodyInfoConstPtr;
    typedef boost::function<OpenRAVE::UserDataPtr(KinBodyConstPtr)> GetInfoFn;
    typedef boost::function<void(KinBodyInfoPtr)> SynchornizeCallbackFn;
    
 ODESpace(EnvironmentBasePtr penv, const GetInfoFn& infofn, bool bCreateJoints) : _penv(penv), GetInfo(infofn), _bCreateJoints(bCreateJoints)
    {
        printf("Creating new ODE space\n");
        static bool s_bIsODEInitialized = false;
        if( !s_bIsODEInitialized ) {
            s_bIsODEInitialized = true;
            dInitODE();
        }

        memset(_jointset, 0, sizeof(_jointset));
        _jointset[dJointTypeBall] = DummySetParam;
        _jointset[dJointTypeHinge] = dJointSetHingeParam;
        _jointset[dJointTypeSlider] = dJointSetSliderParam;
        _jointset[dJointTypeUniversal] = dJointSetUniversalParam;
        _jointset[dJointTypeHinge2] = dJointSetHinge2Param;
    }

    virtual ~ODESpace() {}

    bool InitEnvironment()
    {
        RAVELOG_VERBOSEA("init ode (collision or physics) environment\n");
        _ode.reset(new ODEResources());
        return true;
    }

    void DestroyEnvironment()
    {
        RAVELOG_VERBOSEA("destroying ode (collision or physics) environment\n");
        _ode.reset();
    }
    
    bool IsInitialized() { return !!_ode; }

    OpenRAVE::UserDataPtr InitKinBody(KinBodyPtr pbody, KinBodyInfoPtr pinfo = KinBodyInfoPtr()) {
        EnvironmentMutex::scoped_lock lock(pbody->GetEnv()->GetMutex());

        // create all ode bodies and joints
        if( !pinfo )
            pinfo.reset(new KinBodyInfo(_ode));
        pinfo->Reset();
        pinfo->pbody = pbody;
        pinfo->_odespace = weak_space();
        pinfo->vlinks.reserve(pbody->GetLinks().size());
        pinfo->vjoints.reserve(pbody->GetJoints().size()+pbody->GetPassiveJoints().size());
        dGeomSetData((dGeomID)pinfo->space, &pinfo->pbody); // so that the kinbody can be retreived from the space
        
        pinfo->vlinks.reserve(pbody->GetLinks().size());
        FOREACHC(itlink, pbody->GetLinks()) {
            boost::shared_ptr<KinBodyInfo::LINK> link(new KinBodyInfo::LINK());
            link->body = dBodyCreate(GetWorld());

            // add all the correct geometry objects
            FOREACHC(itgeom, (*itlink)->GetGeometries()) {
                dGeomID geom = NULL;
                switch(itgeom->GetType()) {
                case KinBody::Link::GEOMPROPERTIES::GeomBox:
                    geom = dCreateBox(0,itgeom->GetBoxExtents().x*2.0f,itgeom->GetBoxExtents().y*2.0f,itgeom->GetBoxExtents().z*2.0f);
                    break;
                case KinBody::Link::GEOMPROPERTIES::GeomSphere:
                    geom = dCreateSphere(0,itgeom->GetSphereRadius());
                    break;
                case KinBody::Link::GEOMPROPERTIES::GeomCylinder:
                    geom = dCreateCylinder(0,itgeom->GetCylinderRadius(),itgeom->GetCylinderHeight());
                    break;
                case KinBody::Link::GEOMPROPERTIES::GeomTrimesh:
                    if( itgeom->GetCollisionMesh().indices.size() > 0 ) {
                        dTriIndex* pindices = new dTriIndex[itgeom->GetCollisionMesh().indices.size()];
                        for(size_t i = 0; i < itgeom->GetCollisionMesh().indices.size(); ++i)
                            pindices[i] = itgeom->GetCollisionMesh().indices[i];
                        
                        dReal* pvertices = new dReal[4*itgeom->GetCollisionMesh().vertices.size()];
                        for(size_t i = 0; i < itgeom->GetCollisionMesh().vertices.size(); ++i) {
                            Vector v = itgeom->GetCollisionMesh().vertices[i];
                            pvertices[4*i+0] = v.x; pvertices[4*i+1] = v.y; pvertices[4*i+2] = v.z;
                        }
                
                        dTriMeshDataID id = dGeomTriMeshDataCreate();
                        dGeomTriMeshDataBuildSimple(id, pvertices, itgeom->GetCollisionMesh().vertices.size(), pindices,
                                                    itgeom->GetCollisionMesh().indices.size());
                        geom = dCreateTriMesh(0, id, NULL, NULL, NULL);
                        link->listtrimeshinds.push_back(pindices);
                    }
                    break;
                default:
                    RAVELOG_WARN("ode doesn't support geom type %d\n", itgeom->GetType());
                    break;
                }

                if( geom == NULL ) {
                    RAVELOG_DEBUG("ode doesn't support geom type %d\n", itgeom->GetType());
                    continue;
                }

                dGeomID geomtrans = dCreateGeomTransform(pinfo->space);
                dGeomTransformSetCleanup(geomtrans, 1);
                dGeomTransformSetGeom(geomtrans, geom);
                dGeomSetData(geom, (void*)&(*itgeom));

                // set the transformation
                RaveTransform<dReal> t = itgeom->GetTransform();
                dGeomSetQuaternion(geom,t.rot);
                dGeomSetPosition(geom,t.trans.x, t.trans.y, t.trans.z);
            
                // finally set the geom to the ode body
                dGeomSetBody(geomtrans, link->body);
                link->geom = geomtrans;
            }
        
            if( (*itlink)->IsStatic() ){
                //dBodyDisable(link->body);
                dBodySetKinematic(link->body);
            } else {
                dMass mass;
                dMassSetZero(&mass);
                if (((*itlink)->GetGeometries().front().GetType() == KinBody::Link::GEOMPROPERTIES::GeomBox) && ((*itlink)->GetGeometries().size() == 1)){ // special handling for single box geoms
                    //printf("single box geom mass assignment\n");
                    
                    OpenRAVE::KinBody::Link::GEOMPROPERTIES geom = (*itlink)->GetGeometries().front();//(*itlink)->GetGeometries().end();
                    dReal volume = geom.GetBoxExtents().x*geom.GetBoxExtents().y*geom.GetBoxExtents().z*2.0f;
                    dMassSetBox(&mass,(*itlink)->GetMass()/volume,geom.GetBoxExtents().x*2.0f,geom.GetBoxExtents().y*2.0f,geom.GetBoxExtents().z*2.0f);   
                    dMassAdjust(&mass,(*itlink)->GetMass());
                } else {
                    // set the mass
                    RaveTransformMatrix<dReal> I = (*itlink)->GetInertia();
                    
                    mass.mass = (*itlink)->GetMass();
                    mass.I[0] = I.m[0]; mass.I[1] = I.m[1]; mass.I[2] = I.m[2];
                    mass.I[4] = I.m[4]; mass.I[5] = I.m[5]; mass.I[6] = I.m[6];
                    mass.I[8] = I.m[8]; mass.I[9] = I.m[9]; mass.I[10] = I.m[10];
                    // ignore center of mass for now (ode doesn't like it when it is non-zero)
                    //mass.c = I.trans;
                    if (I.trans[0] != 0 || I.trans[1] != 0 || I.trans[2] != 0) {
                        RAVELOG_ERRORA("ode doesn't support offset Centre of Mass, ignoring com\n");
                    }
                }
                dBodySetMass(link->body, &mass);
            }
        
            link->plink = *itlink;
            // set the transformation
            RaveTransform<dReal> t = (*itlink)->GetTransform();
            dBodySetPosition(link->body,t.trans.x, t.trans.y, t.trans.z);
            dBodySetQuaternion(link->body,t.rot);
            dBodySetData(link->body, &link->plink); // so that the link can be retreived from the body

            pinfo->vlinks.push_back(link);
        }

        if( _bCreateJoints ) {
            vector<KinBody::JointPtr> vbodyjoints = pbody->GetJoints();
            vbodyjoints.insert(vbodyjoints.end(),pbody->GetPassiveJoints().begin(),pbody->GetPassiveJoints().end());
            FOREACHC(itjoint, vbodyjoints) {
                //bool bPassive = (*itjoint)->GetJointIndex()<0;
                RaveVector<dReal> anchor = (*itjoint)->GetAnchor();
                RaveVector<dReal> axis0 = -(*itjoint)->GetAxis(0); // -ve?
                RaveVector<dReal> axis1 = -(*itjoint)->GetAxis(1); // -ve?
                dBodyID body0 = (!!(*itjoint)->GetFirstAttached() && !(*itjoint)->GetFirstAttached()->IsStatic()) ? pinfo->vlinks[(*itjoint)->GetFirstAttached()->GetIndex()]->body : NULL;
                dBodyID body1 = (!!(*itjoint)->GetSecondAttached() && !(*itjoint)->GetSecondAttached()->IsStatic()) ? pinfo->vlinks[(*itjoint)->GetSecondAttached()->GetIndex()]->body : NULL;

                dJointID joint = NULL;
                switch((*itjoint)->GetType()) {
                case KinBody::Joint::JointHinge:
                    joint = dJointCreateHinge(GetWorld(), pinfo->jointgroup);
                    break;
                case KinBody::Joint::JointSlider:
                    joint = dJointCreateSlider(GetWorld(), pinfo->jointgroup);
                    break;
                case KinBody::Joint::JointUniversal:
                    joint = dJointCreateUniversal(GetWorld(), pinfo->jointgroup);
                    break;
                case KinBody::Joint::JointHinge2:
                    joint = dJointCreateHinge2(GetWorld(), pinfo->jointgroup);
                    break;
                case KinBody::Joint::JointSpherical:
                    joint = dJointCreateBall(GetWorld(),pinfo->jointgroup);
                    break;
                default:
                    break;
                }

                if( joint == NULL ) {
                    RAVELOG_WARN("ode failed to create joint type %d\n", (*itjoint)->GetType());
                    continue;
                }

                dJointAttach(joint, body0, body1);
				if( (*itjoint)->GetSecondAttached()->IsStatic() ) {
					axis0 = -axis0;
					axis1 = -axis1;
				}

                switch((*itjoint)->GetType()) {
                case KinBody::Joint::JointHinge:
                    dJointSetHingeAnchor(joint,anchor.x,anchor.y,anchor.z);
                    dJointSetHingeAxis(joint,axis0.x,axis0.y,axis0.z);
                    break;
                case KinBody::Joint::JointSlider:
                    dJointSetSliderAxis(joint,axis0.x,axis0.y,axis0.z);
                    break;
                case KinBody::Joint::JointUniversal:
                    dJointSetUniversalAnchor(joint,anchor.x,anchor.y,anchor.z);
                    dJointSetUniversalAxis1(joint,axis0.x,axis0.y,axis0.z);
                    dJointSetUniversalAxis2(joint,axis1.x,axis1.y,axis1.z);
                    break;
                case KinBody::Joint::JointHinge2:
                    dJointSetHinge2Anchor(joint,anchor.x,anchor.y,anchor.z);
                    dJointSetHinge2Axis1(joint,axis0.x,axis0.y,axis0.z);
                    dJointSetHinge2Axis2(joint,axis1.x,axis1.y,axis1.z);
                    break;
                case KinBody::Joint::JointSpherical:
                    dJointSetBallAnchor(joint,anchor.x,anchor.y,anchor.z);
                    break;
                default:
                    break;
                }

                // set the joint limits
                vector<OpenRAVE::dReal> vlower, vupper;
                (*itjoint)->GetLimits(vlower,vupper);
                for(int i = 0; i < (*itjoint)->GetDOF(); ++i) {
//                    if( (*itjoint)->GetMimicJointIndex() < 0 && !bPassive )
//                        // setting this makes every joint add like a motor, which is not desired
//                        _jointset[dJointGetType(joint)](joint,dParamFMax+dParamGroup*i,(*itjoint)->GetMaxTorque());
                    if( (*itjoint)->GetType() == KinBody::Joint::JointSpherical ) {
                        continue;
                    }
                    if( (*itjoint)->IsCircular(i) ) {
                        _jointset[dJointGetType(joint)](joint,dParamLoStop+dParamGroup*i,-dInfinity);
                        _jointset[dJointGetType(joint)](joint,dParamHiStop+dParamGroup*i,dInfinity);
                    }
                    else {
                        _jointset[dJointGetType(joint)](joint,dParamLoStop+dParamGroup*i,vlower[i]);
                        _jointset[dJointGetType(joint)](joint,dParamHiStop+dParamGroup*i,vupper[i]);
                    }
                }
            
                pinfo->vjoints.push_back(joint);
            }
        }

        pinfo->_geometrycallback = pbody->RegisterChangeCallback(KinBody::Prop_LinkGeometry, boost::bind(&ODESpace::GeometryChangedCallback,boost::bind(&sptr_from<ODESpace>, weak_space()),KinBodyWeakPtr(pbody)));

        Synchronize(pinfo);
        return pinfo;
    }

    bool Enable(KinBodyConstPtr pbody, bool bEnable)
    {
        KinBodyInfoPtr pinfo = boost::dynamic_pointer_cast<KinBodyInfo>(GetInfo(pbody));
        BOOST_ASSERT( pinfo->pbody == pbody );
        FOREACH(it, pinfo->vlinks)
            (*it)->Enable(bEnable);
        return true;
    }

    bool EnableLink(KinBody::LinkConstPtr plink, bool bEnable)
    {
        KinBodyInfoPtr pinfo = boost::dynamic_pointer_cast<KinBodyInfo>(GetInfo(plink->GetParent()));
        BOOST_ASSERT( pinfo->pbody == plink->GetParent() );
        BOOST_ASSERT( plink->GetIndex() >= 0 && plink->GetIndex() < (int)pinfo->vlinks.size());
        pinfo->vlinks[plink->GetIndex()]->Enable(bEnable);
        return true;
    }

    void Synchronize()
    {
#ifdef ODE_HAVE_ALLOCATE_DATA_THREAD
        dAllocateODEDataForThread(dAllocateMaskAll);
#endif
        vector<KinBodyPtr> vbodies;
        _penv->GetBodies(vbodies);
        FOREACHC(itbody, vbodies) {
            KinBodyInfoPtr pinfo = boost::dynamic_pointer_cast<KinBodyInfo>(GetInfo(*itbody));
            BOOST_ASSERT( pinfo->pbody == *itbody );
            if( pinfo->nLastStamp != (*itbody)->GetUpdateStamp() )
                Synchronize(pinfo);
        }
    }

    void Synchronize(KinBodyConstPtr pbody)
    {
        KinBodyInfoPtr pinfo = boost::dynamic_pointer_cast<KinBodyInfo>(GetInfo(pbody));
        BOOST_ASSERT( pinfo->pbody == pbody );
        if( pinfo->nLastStamp != pbody->GetUpdateStamp() ){
            Synchronize(pinfo);
        }
    }

    dSpaceID GetBodySpace(KinBodyConstPtr pbody)
    {
        KinBodyInfoPtr pinfo = boost::dynamic_pointer_cast<KinBodyInfo>(GetInfo(pbody));
        BOOST_ASSERT(pinfo->pbody == pbody );
        return pinfo->space;
    }

    dBodyID GetLinkBody(KinBody::LinkConstPtr plink)
    {
        KinBodyInfoPtr pinfo = boost::dynamic_pointer_cast<KinBodyInfo>(GetInfo(plink->GetParent()));
        BOOST_ASSERT( pinfo->pbody == plink->GetParent() );
        BOOST_ASSERT( plink->GetIndex() >= 0 && plink->GetIndex() < (int)pinfo->vlinks.size());
        return pinfo->vlinks[plink->GetIndex()]->body;
    }


    dGeomID GetLinkGeom(KinBody::LinkConstPtr plink)
    {
        KinBodyInfoPtr pinfo = boost::dynamic_pointer_cast<KinBodyInfo>(GetInfo(plink->GetParent()));
        BOOST_ASSERT( pinfo->pbody == plink->GetParent() );
        BOOST_ASSERT( plink->GetIndex() >= 0 && plink->GetIndex() < (int)pinfo->vlinks.size());
        return pinfo->vlinks[plink->GetIndex()]->geom;
    }

    dJointID GetJoint(KinBody::JointConstPtr pjoint)
    {
        KinBodyInfoPtr pinfo = boost::dynamic_pointer_cast<KinBodyInfo>(GetInfo(pjoint->GetParent()));
        BOOST_ASSERT( pinfo->pbody == pjoint->GetParent() );
        BOOST_ASSERT( pjoint->GetParent()->GetJointFromDOFIndex(pjoint->GetDOFIndex()) == pjoint );
        BOOST_ASSERT( pjoint->GetJointIndex() >= 0);
        return pinfo->vjoints.at(pjoint->GetJointIndex());
    }

    dWorldID GetWorld() const { return _ode->world; }
    dSpaceID GetSpace() const { return _ode->space; }
    dJointGroupID GetContactGroup() const { return _ode->contactgroup; }

    void SetSynchornizationCallback(const SynchornizeCallbackFn& synccallback) { _synccallback = synccallback; }

    typedef void (*JointSetFn)(dJointID, int param, dReal val);
    JointSetFn _jointset[12];

private:
    void Synchronize(KinBodyInfoPtr pinfo)
    {
        vector<Transform> vtrans;
        pinfo->pbody->GetBodyTransformations(vtrans);
        pinfo->nLastStamp = pinfo->pbody->GetUpdateStamp();
        BOOST_ASSERT( vtrans.size() == pinfo->vlinks.size() );
        for(size_t i = 0; i < vtrans.size(); ++i) {
            RaveTransform<dReal> t = vtrans[i];
            dBodySetQuaternion(pinfo->vlinks[i]->body, t.rot);
            dBodySetPosition(pinfo->vlinks[i]->body, t.trans.x, t.trans.y, t.trans.z);
        }

        if( !!_synccallback )
            _synccallback(pinfo);
    }

    void GeometryChangedCallback(KinBodyWeakPtr _pbody)
    {
        EnvironmentMutex::scoped_lock lock(_penv->GetMutex());
        KinBodyPtr pbody(_pbody);
        KinBodyInfoPtr pinfo = boost::dynamic_pointer_cast<KinBodyInfo>(GetInfo(pbody));
        if( !pinfo )
            return;        
        BOOST_ASSERT(boost::shared_ptr<ODESpace>(pinfo->_odespace) == shared_from_this());
        BOOST_ASSERT(pinfo->pbody==pbody);
        InitKinBody(pbody,pinfo);
    }

    EnvironmentBasePtr _penv;
    boost::shared_ptr<ODEResources> _ode;
    GetInfoFn GetInfo;

    SynchornizeCallbackFn _synccallback;
    bool _bCreateJoints;
};

#ifdef RAVE_REGISTER_BOOST
#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()
BOOST_TYPEOF_REGISTER_TYPE(ODESpace)
BOOST_TYPEOF_REGISTER_TYPE(ODESpace::KinBodyInfo)
BOOST_TYPEOF_REGISTER_TYPE(ODESpace::KinBodyInfo::LINK)
BOOST_TYPEOF_REGISTER_TYPE(dJointID)
#endif

#endif
