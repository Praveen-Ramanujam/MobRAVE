#ifndef __ORTHO_CAMERA_MANAGER_H__
#define __ORTHO_CAMERA_MANAGER_H__

#include "cameramanager.h"

class CAMERAS_EXPORT OrthoCameraManager: public CameraManager {
public:
	typedef enum {
		FRONT,
		BACK,
		LEFT,
		RIGHT,
		TOP,
        BOTTOM
	} Side;

	OrthoCameraManager(Side side);

	virtual osg::Matrixd getViewMatrix();

	virtual osg::Matrixd getProjectionMatrix();

	virtual void zoom(double ratio);
	virtual void pan(osg::Vec2 vector);

	virtual std::string getName();

	virtual void resetToBound(const osg::BoundingSphere &bs);

private:
	osg::Vec3d _focus; ///< Camera focus point
    Side _side; ///< Side of view
	double _zoom; ///< Scale of objects
};

#endif//__ORTHO_CAMERA_MANAGER_H__
