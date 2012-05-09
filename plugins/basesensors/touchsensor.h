// -*- coding: utf-8 -*-
// Copyright (C) 2006-2010 Rosen Diankov (rdiankov@cs.cmu.edu)
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
#ifndef OPENRAVE_BASETOUCH_H
#define OPENRAVE_BASETOUCH_H


class TouchSensor : public SensorBase
{
protected:
    class TouchSensorXMLReader : public BaseXMLReader
    {
public:
        TouchSensorXMLReader(boost::shared_ptr<TouchSensor> psensor) : _psensor(psensor) {
        } 

        virtual ProcessElement startElement(const std::string& name, const AttributesList& atts)
        {
            if( !!_pcurreader ) {
                if( _pcurreader->startElement(name,atts) == PE_Support )
                    return PE_Support;
                return PE_Ignore;
            }
            static boost::array<string, 16> tags = { { "sensor", "minangle", "min_angle", "maxangle", "max_angle", "maxrange", "max_range", "minrange", "min_range", "scantime", "color", "time_scan", "time_increment", "power","resolution"}};
            if( find(tags.begin(),tags.end(),name) == tags.end() ) {
                return PE_Pass;
            }
            ss.str("");
            return PE_Support;
        }

        virtual bool endElement(const std::string& name)
        {
            if( !!_pcurreader ) {
                if( _pcurreader->endElement(name) ) {
                    _pcurreader.reset();
                }
                return false;
            }
            else if( name == "sensor" ) {
                return true;
            }
            else if( name == "power" ) {
                ss >> _psensor->_bPower;
            }
            else if((name == "minangle")||(name == "min_angle")) {
                ss >> _psensor->_pgeom->min_angle[0];
                if( !!ss ) {
                    _psensor->_pgeom->min_angle[0] *= PI/180.0f;         // convert to radians
                }
            }
            else if((name == "maxangle")||(name == "max_angle")) {
                ss >> _psensor->_pgeom->max_angle[0];
                if( !!ss ) {
                    _psensor->_pgeom->max_angle[0] *= PI/180.0f;         // convert to radians
                }
            }
            else if( name == "resolution" ) {
                ss >> _psensor->_pgeom->resolution[0];
                if( !!ss ) {
                    _psensor->_pgeom->resolution[0] *= PI/180.0f;         // convert to radians
                }
            }
            else if((name == "maxrange")||(name == "max_range")) {
                ss >> _psensor->_pgeom->max_range;
            }
            else if((name == "minrange")||(name == "min_range")) {
                ss >> _psensor->_pgeom->min_range;
            }
            else if((name == "scantime")||(name == "time_scan")) {
                ss >> _psensor->_pgeom->time_scan;
            }
            else if( name == "time_increment" ) {
                ss >> _psensor->_pgeom->time_increment;
            }
            else if( name == "color" ) {
                ss >> _psensor->_vColor.x >> _psensor->_vColor.y >> _psensor->_vColor.z;
                // ok if not everything specified
                if( !ss ) {
                    ss.clear();
                }
            }
            else {
                RAVELOG_WARN(str(boost::format("bad tag: %s")%name));
            }
            if( !ss ) {
                RAVELOG_WARN(str(boost::format("error parsing %s\n")%name));
            }
            return false;
        }

        virtual void characters(const std::string& ch)
        {
            if( !!_pcurreader )
                _pcurreader->characters(ch);
            else {
                ss.clear();
                ss << ch;
            }
        }

protected:
        BaseXMLReaderPtr _pcurreader;
        boost::shared_ptr<TouchSensor> _psensor;
        stringstream ss;
    };

public:
    static BaseXMLReaderPtr CreateXMLReader(InterfaceBasePtr ptr, const AttributesList& atts)
    {
        return BaseXMLReaderPtr(new TouchSensorXMLReader(boost::dynamic_pointer_cast<TouchSensor>(ptr)));
    }

    TouchSensor(EnvironmentBasePtr penv) : SensorBase(penv) {
 
       
        _pgeom.reset(new TouchGeomData());
        _pdata.reset(new TouchSensorData());
        _pgeom->min_angle[0] = -PI/2; _pgeom->min_angle[1] = 0;
        _pgeom->max_angle[0] = PI/2; _pgeom->max_angle[1] = 0;
        _pgeom->resolution[0] = 0.01f; _pgeom->resolution[1] = 0;
        _pgeom->min_range = 0.03;
        _pgeom->max_range = 100;
        _fTimeToScan = 0;
        _vColor = RaveVector<float>(0.5f,0.5f,1,1);
        _report.reset(new CollisionReport());
        _bPower = false;
        _bRenderData = false;
        _bRenderGeometry = true;
        _Reset();
    }

    virtual int Configure(ConfigureCommand command, bool blocking)
    {
        switch(command) {
        case CC_PowerOn:
            _bPower = true;
            _Reset();
            return _bPower;
        case CC_PowerOff:
            _bPower = false;
            _Reset();
            return _bPower;
        case CC_PowerCheck:
            return _bPower;
        case CC_RenderDataOn:
            _bRenderData = true;
            return _bRenderData;
        case CC_RenderDataOff: {
            boost::mutex::scoped_lock lock(_mutexdata);
            _listGraphicsHandles.clear();
            _bRenderData = false;
            return _bRenderData;
        }
        case CC_RenderDataCheck:
            return _bRenderData;
        case CC_RenderGeometryOn:
            _bRenderGeometry = true;
            _RenderGeometry();
            return _bRenderData;
        case CC_RenderGeometryOff: {
            boost::mutex::scoped_lock lock(_mutexdata);
            _graphgeometry.reset();
            _bRenderGeometry = false;
            return _bRenderData;
        }
        case CC_RenderGeometryCheck:
            return _bRenderGeometry;
        }
        throw openrave_exception(str(boost::format("SensorBase::Configure: unknown command 0x%x")%command));
    }

    virtual bool SimulationStep(dReal fTimeElapsed)
    {
        _RenderGeometry();
        _fTimeToScan -= fTimeElapsed;
        if( _bPower &&( _fTimeToScan <= 0) ) {
            _fTimeToScan = _pgeom->time_scan;
            Vector rotaxis(0,0,1);
            RAY r;

            GetEnv()->GetCollisionChecker()->SetCollisionOptions(CO_Distance);
            Transform t;

            {
                // Lock the data mutex and fill with the range data (get all in one timestep)
                boost::mutex::scoped_lock lock(_mutexdata);
                _pdata->__trans = GetTransform();
                _pdata->__stamp = GetEnv()->GetSimulationTime();
                t = GetTouchPlaneTransform();
                _pdata->positions.at(0) = t.trans;
                size_t index = 0;
                
                    
                Vector vdir(t.rotate(quatRotate(quatFromAxisAngle(rotaxis, (dReal)0),Vector(1,0,0))));
                r.pos = t.trans+_pgeom->min_range*vdir;
                r.dir = (_pgeom->max_range-_pgeom->min_range)*vdir;

                 if( GetEnv()->CheckCollision(r, _report)) {
                      _pdata->ranges[index] = vdir*(_report->minDistance+_pgeom->min_range);
                       _pdata->intensity[index] = 1;
                       // store the colliding bodies
                        KinBody::LinkConstPtr plink = !!_report->plink1 ? _report->plink1 : _report->plink2;
                        if( !!plink ) {
                            _databodyids[index] = plink->GetParent()->GetEnvironmentId();
                        }
                    }
                    else {
                        _databodyids[index] = 0;
                        _pdata->ranges[index] = vdir*_pgeom->max_range;
                        _pdata->intensity[index] = 0;
                    }
                
            }

            GetEnv()->GetCollisionChecker()->SetCollisionOptions(0);

            if( _bRenderData ) {
                // If can render, check if some time passed before last update
                list<GraphHandlePtr> listhandles;
                int N = 0;
                vector<RaveVector<float> > vpoints;
                vector<int> vindices;

                {
                    // Lock the data mutex and fill the arrays used for rendering
                    boost::mutex::scoped_lock lock(_mutexdata);
                    N = (int)_pdata->ranges.size();
                    vpoints.resize(N+1);
                    for(int i = 0; i < N; ++i) {
                        vpoints[i] = _pdata->ranges[i] + t.trans;
                    }
                    vpoints[N] = t.trans;
                }

                // render the transparent fan
                vindices.resize(3*(N-1));

                for(int i = 0; i < N-1; ++i) {
                    vindices[3*i+0] = i;
                    vindices[3*i+1] = i+1;
                    vindices[3*i+2] = N;
                }

                _vColor.w = 1;
                
                listhandles.push_back(GetEnv()->plot3(&vpoints[0].x, N, sizeof(vpoints[0]), 5.0f, _vColor));

                _vColor.w = 0.2f;
                listhandles.push_back(GetEnv()->drawtrimesh(vpoints[0], sizeof(vpoints[0]), &vindices[0], N-1, _vColor));

                // close the old graphs last to avoid flickering
                _listGraphicsHandles.swap(listhandles);

            }
            else {
                _listGraphicsHandles.clear();
            }

            _report->Reset();
        }

        return true;
    }

    virtual SensorGeometryPtr GetSensorGeometry(SensorType type)
    {
        if(( type == ST_Invalid) ||( type == ST_Touch) ) {
            TouchGeomData* pgeom = new TouchGeomData();
            *pgeom = *_pgeom;
            return SensorGeometryPtr(pgeom);
        }
        return SensorGeometryPtr();
    }

    virtual SensorDataPtr CreateSensorData(SensorType type)
    {
        if(( type == ST_Invalid) ||( type == ST_Touch) ) {
            return SensorDataPtr(new TouchSensorData());
        }
        return SensorDataPtr();
    }

    virtual bool GetSensorData(SensorDataPtr psensordata)
    {
        if( psensordata->GetType() == ST_Touch ) {
            boost::mutex::scoped_lock lock(_mutexdata);
            *boost::dynamic_pointer_cast<TouchSensorData>(psensordata) = *_pdata;
            return true;
        }
        return false;
    }

    virtual bool Supports(SensorType type) {
        return type == ST_Touch;
    }

    bool _Render(ostream& sout, istream& sinput)
    {
        sinput >> _bRenderData;
        return !!sinput;
    }
    bool _CollidingBodies(ostream& sout, istream& sinput)
    {
        boost::mutex::scoped_lock lock(_mutexdata);
        FOREACH(it, _databodyids) {
            sout << *it << " ";
        }
        return true;
    }

    virtual void SetTransform(const Transform& trans)
    {
        _trans = trans;
    }

    virtual Transform GetTransform() {
        return _trans;
    }

    virtual void Clone(InterfaceBaseConstPtr preference, int cloningoptions)
    {
        SensorBase::Clone(preference,cloningoptions);
        boost::shared_ptr<TouchSensor const> r = boost::dynamic_pointer_cast<TouchSensor const>(preference);
        *_pgeom = *r->_pgeom;
        _vColor = r->_vColor;
        _trans = r->_trans;
        _fTimeToScan = r->_fTimeToScan;
        _bRenderGeometry = r->_bRenderGeometry;
        _bRenderData = r->_bRenderData;
        _bPower = r->_bPower;
        _Reset();
    }

protected:

    virtual Transform GetTouchPlaneTransform() {
        return _trans;
    }

    virtual void _Reset()
    {
        boost::mutex::scoped_lock lock(_mutexdata);
        int N = (int)( (_pgeom->max_angle[0]-_pgeom->min_angle[0])/_pgeom->resolution[0] + 0.5f)+1;
        _pdata->positions.resize(1);
        _pdata->ranges.resize(N);
        _pdata->intensity.resize(N);
        _databodyids.resize(N);
        FOREACH(it, _pdata->ranges) {
            *it = Vector(0,0,0);
        }
        FOREACH(it, _pdata->intensity) {
            *it = 0;
        }
        _fTimeToScan = 0;
        _listGraphicsHandles.clear();
        _graphgeometry.reset();
        _RenderGeometry();
    }

    void _RenderGeometry()
    {
        if( !_bRenderGeometry ) {
            return;
        }

        Transform t = GetTouchPlaneTransform();
        if( !_graphgeometry ) {
            vector<RaveVector<float> > viconpoints;
            vector<int> viconindices;
            int N = 10;
            viconpoints.resize(N+2);
            viconindices.resize(3*N);
            viconpoints[0] = Vector(0,0,0);

            for(int i = 0; i <= N; ++i) {
                dReal fang = _pgeom->min_angle[0] + (_pgeom->max_angle[0]-_pgeom->min_angle[0])*(float)i/(float)N;
                viconpoints[i+1] = quatRotate(quatFromAxisAngle(Vector(0,0,1), fang),Vector(_pgeom->min_range,0,0));

                if( i < N ) {
                    viconindices[3*i+0] = 0;
                    viconindices[3*i+1] = i+1;
                    viconindices[3*i+2] = i+2;
                }
            }

            RaveVector<float> vcolor = _vColor*0.5f;
            vcolor.w = 0.7f;
            _graphgeometry = GetEnv()->drawtrimesh(viconpoints[0], sizeof(viconpoints[0]), &viconindices[0], N, vcolor);
        }
        if( !!_graphgeometry ) {
            _graphgeometry->SetTransform(t);
        }
    }

    boost::shared_ptr<TouchGeomData> _pgeom;
    boost::shared_ptr<TouchSensorData> _pdata;
    vector<int> _databodyids;     ///< if non 0, for each point in _data, specifies the body that was hit
    CollisionReportPtr _report;

    // more geom stuff
    RaveVector<float> _vColor;

    Transform _trans;
    list<GraphHandlePtr> _listGraphicsHandles;
    GraphHandlePtr _graphgeometry;
    dReal _fTimeToScan;

    boost::mutex _mutexdata;
    bool _bRenderData, _bRenderGeometry, _bPower;

    friend class TouchSensorXMLReader;
};


#endif
