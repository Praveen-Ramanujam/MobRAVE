/*
 * qtosg.h
 *
 *  Created on: 28 janv. 2009
 *      Author: gustavo
 */

#ifndef QTOSG_H_
#define QTOSG_H_

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

/// functions that allow plugins to program for the RAVE simulator
#include <assert.h>
#include <cstdio>
#include <cmath>

// include boost for vc++ only (to get typeof working)
#ifdef _MSC_VER
#include <boost/typeof/std/string.hpp>
#include <boost/typeof/std/vector.hpp>
#include <boost/typeof/std/list.hpp>
#include <boost/typeof/std/map.hpp>
#include <boost/typeof/std/set.hpp>
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
#include <set>
#include <string>

#define FOREACH(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); (it)++)
#define FOREACH_NOINC(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); )

#define FOREACHC FOREACH
#define FOREACHC_NOINC FOREACH_NOINC

#endif

#include <stdint.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

#include <sys/timeb.h>    // ftime(), struct timeb

#ifndef _WIN32
#include <sys/time.h>
#define Sleep(milli) usleep(1000*milli)
#else
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#endif

//#pragma warning(disable:4996) // 'function': was declared deprecated
//#pragma warning(disable:4267) // conversion from 'size_t' to 'type', possible loss of data
//#pragma warning(disable:4018) // '<' : signed/unsigned mismatch

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

#include <boost/bind.hpp>
#include <boost/assert.hpp>
#include <boost/thread/condition.hpp>
#include <boost/version.hpp>

#ifndef ARRAYSIZE
#define ARRAYSIZE(x) (sizeof(x)/(sizeof( (x)[0] )))
#endif

#ifndef C_ASSERT
#define C_ASSERT(e) typedef char __C_ASSERT__[(e)?1:-1]
#endif

inline int RANDOM_INT(int maximum)
{
#if defined(__IRIX__)
    return (random() % maximum);
#else
    return (rand() % maximum);
#endif
}

inline float RANDOM_FLOAT()
{
#if defined(__IRIX__)
    return drand48();
#else
    return rand()/((float)RAND_MAX);
#endif
}

inline float RANDOM_FLOAT(float maximum)
{
#if defined(__IRIX__)
    return (drand48() * maximum);
#else
    return (RANDOM_FLOAT() * maximum);
#endif
}


#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include <QtGui/QTreeWidget>

#include <rave/rave.h>
#include <pthread.h>


using namespace OpenRAVE;
using namespace std;

#ifdef _WIN32

#define WCSTOK(str, delim, ptr) wcstok(str, delim)

// define wcsicmp for MAC OS X
#elif defined(__APPLE_CC__)

#define WCSTOK(str, delim, ptr) wcstok(str, delim, ptr);

#define strnicmp strncasecmp
#define stricmp strcasecmp

inline int wcsicmp(const string& s1, const string& s2)
{
  char str1[128], str2[128];
  sprintf(str1, "%S", s1);
  sprintf(str2, "%S", s2);
  return stricmp(str1, str2);
}

#else

#define WCSTOK(str, delim, ptr) wcstok(str, delim, ptr)

#define strnicmp strncasecmp
#define stricmp strcasecmp
#define wcsnicmp wcsncasecmp
#define wcsicmp wcscasecmp

#endif

inline char* _ravestrdup(const char* pstr)
{
    if( pstr == NULL ) return NULL;
    size_t len = strlen(pstr);
    char* p = new char[len+1];
    memcpy(p, pstr, len*sizeof(char));
    p[len] = 0;
    return p;
}

inline std::wstring _ravembstowcs(const char* pstr)
{
    size_t len = mbstowcs(NULL, pstr, 0);
    std::wstring w; w.resize(len);
    mbstowcs(&w[0], pstr, len);
    return w;
}

#define FORIT(it, v) for(it = (v).begin(); it != (v).end(); (it)++)

template<class T>
inline T CLAMP_ON_RANGE(T value, T min, T max)
{
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

// declaring variables with stdcall can be a little complex
#ifdef _MSC_VER

#define DECLPTR_STDCALL(name, paramlist) (__stdcall *name)paramlist

#else

#ifdef __x86_64__
#define DECLPTR_STDCALL(name, paramlist) (*name) paramlist
#else
#define DECLPTR_STDCALL(name, paramlist) (__attribute__((stdcall)) *name) paramlist
#endif

#endif // _MSC_VER

#include <pthread.h>

class MutexLock
{
public:
    MutexLock(pthread_mutex_t* pmutex) : _pmutex(pmutex) { pthread_mutex_lock(_pmutex); }
    ~MutexLock() { pthread_mutex_unlock(_pmutex); }
    pthread_mutex_t* _pmutex;
};

// OSG includes
#include <osg/MatrixTransform>
#include <osg/BlendColor>
#include <osg/Switch>

/// returns the Transform from a Coin3D SoTransform object
inline RaveTransform<float> GetRaveTransform(const osg::MatrixTransform* ptrans)
{
  //    Debug
//  RAVELOG_INFO("\t\tGetRaveTransform(ptrans)\n");

  osg::Matrix	m;
  osg::Quat	q;
  osg::Vec3d	v;
  osg::Vec4d  qua;

  //  Review Quaternion assign
  RaveTransform<float> t;
  assert( ptrans != NULL );

  m = ptrans->getMatrix();
  q = m.getRotate();

  //  Normalize quat prevents Core crash
  qua = q.asVec4();
  qua.normalize();
  q.set(qua);

  t.rot = Vector(q[3], q[0], q[1], q[2]);
//  t.rot = Vector(q[0], q[1], q[2],q[3]);
  v = m.getTrans();
  t.trans = Vector(v[0], v[1], v[2]);
  return t;
}


/// sets the transform of a Coin3D SoTransform object
inline void SetMatrixTransform(osg::MatrixTransform* ptrans, const RaveTransform<float>& t)
{
  //    Debug
//  RAVELOG_INFO("\t\tSetMatrixTransform(ptrans,t)\n");

  osg::Matrix	mR,mT;
  mR.makeRotate(osg::Quat(t.rot.y, t.rot.z, t.rot.w,t.rot.x));
  mT.makeTranslate(t.trans.x, t.trans.y, t.trans.z);

  ptrans->preMult(mT);
  ptrans->preMult(mR);
}

//@{ video recording
bool START_AVI(const char* file_name, int _frameRate, int width, int height, int bits);
bool ADD_FRAME_FROM_DIB_TO_AVI(void* pdata);
bool STOP_AVI();
//@}

class QtOSGViewer;

#include <osg/NodeVisitor>
#include <osg/Node>
#include <osg/Material>
#include <osg/ShapeDrawable>
#include <osg/Camera>
#include <QtGui>
#include <osgDB/ReadFile>
#include <osgUtil/Optimizer>
#include <osgViewer/View>
#include <osgViewer/ViewerEventHandlers>

#include <osgManipulator/Dragger>

#include <osgGA/TrackballManipulator>
#include <osgGA/FlightManipulator>
#include <osgGA/DriveManipulator>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgGA/StateSetManipulator>
#include <osgGA/AnimationPathManipulator>
#include <osgGA/TerrainManipulator>

#include <osgText/Text>

// Derive a class from NodeVisitor to find a node with a
//   specific name.
class FindNode : public osg::NodeVisitor
{
public:
    FindNode( osg::Node* node )
      : osg::NodeVisitor( // Traverse all children.
                osg::NodeVisitor::TRAVERSE_ALL_CHILDREN ),
        _nodeToFind( node ),_node(NULL) {}
    // This method gets called for every node in the scene
    //   graph. Check each node to see if its name matches
    //   our target. If so, save the node's address.
    virtual void apply( osg::Node* node )
    {
        if (_nodeToFind == node)
            _node = node;
        // Keep traversing the rest of the scene graph.
        traverse( *node );
    }
    osg::Node* getNode() { return _node; }
protected:
    osg::Node*  _nodeToFind;
    osg::Node*  _node;
};

class QtOSGViewer;
typedef boost::shared_ptr<QtOSGViewer> QtOSGViewerPtr;
typedef boost::shared_ptr<QtOSGViewer const> QtOSGViewerConstPtr;

#include "Item.h"
#include "qtosgviewer.h"

#endif /* QTOSG_H_ */
