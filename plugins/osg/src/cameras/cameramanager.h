#ifndef __CAMERA_MANAGER_H__
#define __CAMERA_MANAGER_H__

#include <reflection/propertyreflection.h>
#include <osg/Referenced>
#include <osg/Matrixd>
#include <osg/Vec2>
#include <vector>
#include <string>
#include <osg/BoundingSphere>
#include "export.h"

class CAMERAS_EXPORT CameraManager: public osg::Referenced {
public:
	typedef enum { Z_UP, Y_UP } UpMode;

	typedef std::vector< osg::ref_ptr<CameraManager> > Vector;

	virtual osg::Matrixd getViewMatrix() = 0;

	virtual osg::Matrixd getProjectionMatrix() = 0;

    // -1 .. 1
	virtual void zoom(double ratio) {}

	// (-inf,-inf) .. (inf, inf)
	virtual void pan(osg::Vec2 vector) {}

    // (-PI, -PI) .. (PI, PI)
	virtual void orbit(osg::Vec2 radians) {}

	virtual std::string getName() = 0;

    /// Makes the camera to "look" at a specific bounding sphere
	virtual void resetToBound(const osg::BoundingSphere &bs) = 0;

    /// Sets the aspect ratio as width/height
	virtual void setAspectRatio(float ratio) { _aspectRatio = ratio; }
protected:
    CameraManager();

	static osg::Vec3 getUpVectorDefault();
	static osg::Vec3 getFrontVectorDefault();
	static osg::Vec3 getRightVectorDefault();

	float _aspectRatio; ///< Aspect ratio of the rendering area as width/height

	static osg::ref_ptr< ValuedEnumProperty<UpMode> > _upMode;
};

#endif//__CAMERA_MANAGER_H__
