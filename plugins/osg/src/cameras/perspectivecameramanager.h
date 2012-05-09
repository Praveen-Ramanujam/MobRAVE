#ifndef __PERSPECTIVE_CAMERA_MANAGER_H__
#define __PERSPECTIVE_CAMERA_MANAGER_H__

#include "cameramanager.h"
#include <common/config.h>

class CAMERAS_EXPORT PerspectiveCameraManager: public CameraManager {
public:
	PerspectiveCameraManager();

	virtual osg::Matrixd getViewMatrix();

	virtual osg::Matrixd getProjectionMatrix();

	virtual void zoom(double ratio);

	virtual void pan(osg::Vec2 vector);

	virtual void orbit(osg::Vec2 radians);

	virtual std::string getName() { return "User"; }

	virtual void resetToBound(const osg::BoundingSphere &bs);

protected:
	void makeProjection();

	osg::Quat makeOrbitQuat();
private:
	osg::Matrixd _view;
	osg::Matrixd _projection;

	osg::Vec3d _focus; ///< Camera focus point
	double _distance; ///< Distance to focus point
    double _heading; ///< Heading angle
    double _pitch; ///< Pitch angle
};

#endif//__PERSPECTIVE_CAMERA_MANAGER_H__
