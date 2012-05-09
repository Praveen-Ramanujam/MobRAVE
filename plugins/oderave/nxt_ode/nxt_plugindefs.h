// This file is a modified version of the similar file contained in the 
// openrave software, see below license details

// Copyright (c) 2010, CSIRO Autonomous Systems Lab, Nick Hillier

// Copyright (c) 2009-2010 Rosen Diankov
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
//
// \author Rosen Diankov
#ifndef CSIRO_OPENRAVE_PLUGINDEFS_H
#define CSIRO_OPENRAVE_PLUGINDEFS_H

#include <rave/rave.h>

#include <cstdio>
#include <cmath>
#include <cstdlib>

// include boost for vc++ only (to get typeof working)
#ifdef _MSC_VER
#include <boost/typeof/std/string.hpp>
#include <boost/typeof/std/vector.hpp>
#include <boost/typeof/std/list.hpp>
#include <boost/typeof/std/map.hpp>
#include <boost/typeof/std/string.hpp>

#define FOREACH(it, v) for(BOOST_TYPEOF(v)::iterator it = (v).begin(); it != (v).end(); (it)++)
#define FOREACH_NOINC(it, v) for(BOOST_TYPEOF(v)::iterator it = (v).begin(); it != (v).end(); )

#define FOREACHC(it, v) for(BOOST_TYPEOF(v)::const_iterator it = (v).begin(); it != (v).end(); (it)++)
#define FOREACHC_NOINC(it, v) for(BOOST_TYPEOF(v)::const_iterator it = (v).begin(); it != (v).end(); )
#define RAVE_REGISTER_BOOST
#else

#include <string>
#include <vector>
#include <list>
#include <map>
#include <string>

#define FOREACH(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); (it)++)
#define FOREACH_NOINC(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); )

#define FOREACHC FOREACH
#define FOREACHC_NOINC FOREACH_NOINC

#endif

#include <stdint.h>
#include <fstream>
#include <iostream>

#include <boost/assert.hpp>
#include <boost/bind.hpp>

using namespace std;

#include <sys/timeb.h>    // ftime(), struct timeb

#ifndef _WIN32
#include <sys/time.h>
#define Sleep(milli) usleep(1000*milli)
#else
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#endif

template<class T>
inline T CLAMP_ON_RANGE(T value, T min, T max)
{
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

inline uint32_t timeGetTime()
{
#ifdef _WIN32
    _timeb t;
    _ftime(&t);
#else
    timeb t;
    ftime(&t);
#endif

    return (uint32_t)(t.time*1000+t.millitm);
}

#define FORIT(it, v) for(it = (v).begin(); it != (v).end(); (it)++)

inline uint64_t GetMicroTime()
{
#ifdef _WIN32
    LARGE_INTEGER count, freq;
    QueryPerformanceCounter(&count);
    QueryPerformanceFrequency(&freq);
    return (count.QuadPart * 1000000) / freq.QuadPart;
#else
    struct timeval t;
    gettimeofday(&t, NULL);
    return (uint64_t)t.tv_sec*1000000+t.tv_usec;
#endif
}

// OpenRAVE includes a dReal typedef which could cause conflict with ODEs, so don't include it
using OpenRAVE::BaseXMLReader;
using OpenRAVE::BaseXMLReaderPtr;
using OpenRAVE::EnvironmentBase;
using OpenRAVE::EnvironmentBasePtr;
using OpenRAVE::KinBody;
using OpenRAVE::KinBodyPtr;
using OpenRAVE::KinBodyWeakPtr;
using OpenRAVE::KinBodyConstPtr;
using OpenRAVE::RaveTransform;
using OpenRAVE::RaveTransformMatrix;
using OpenRAVE::RaveVector;
using OpenRAVE::Vector;
using OpenRAVE::Transform;
using OpenRAVE::TransformMatrix;
using OpenRAVE::CollisionReport;
using OpenRAVE::CollisionReportPtr;
using OpenRAVE::RAY;
using OpenRAVE::InterfaceType;
using OpenRAVE::InterfaceBase;
using OpenRAVE::InterfaceBasePtr;
using OpenRAVE::InterfaceBaseConstPtr;
using OpenRAVE::PLUGININFO;
using OpenRAVE::openrave_exception;
using OpenRAVE::EnvironmentMutex;
using OpenRAVE::RaveFabs;
using OpenRAVE::ControllerBase;
using OpenRAVE::RobotBasePtr;
using OpenRAVE::TrajectoryBaseConstPtr;
using OpenRAVE::ControllerBase;


// define ODE_LIB for static linking
#include <ode/ode.h>

// needed for ODE 0.10+
#if defined(NEED_DTRIINDEX_TYPEDEF)
typedef int dTriIndex;
#endif

template <class T> boost::shared_ptr<T> sptr_from(boost::weak_ptr<T> const& wpt)
{
    return boost::shared_ptr<T>(wpt); // throws on wpt.expired()
}

#endif
