#include <math.h>

#include "perspectivecameramanager.h"

#define DEFAULT_ANGLE 40.0

#define MAX_PITCH osg::inDegrees(89.0)

#include <iostream>

PerspectiveCameraManager::PerspectiveCameraManager():
	_focus(0,0,0), _distance(2.0), _heading(0.0), _pitch(0.0)
{}

void PerspectiveCameraManager::zoom(double ratio) {
	_distance *= (1+ratio);
}

void PerspectiveCameraManager::pan(osg::Vec2 vector) {
	osg::Vec3 panVector =
		getRightVectorDefault() * vector.x()
		+ getUpVectorDefault() * vector.y();

    panVector = makeOrbitQuat() * panVector;
    _focus += panVector * _distance/2;
}

void PerspectiveCameraManager::orbit(osg::Vec2 radians) {
	_heading += radians.x();
    _pitch -= radians.y();
	if (_pitch > MAX_PITCH) _pitch = MAX_PITCH;
    if (_pitch < -MAX_PITCH) _pitch = -MAX_PITCH;
}

osg::Matrixd PerspectiveCameraManager::getViewMatrix() {
	osg::Quat orbitQ = makeOrbitQuat();
	osg::Vec3d eyeV = orbitQ * getFrontVectorDefault();
	osg::Vec3d upV = orbitQ * getUpVectorDefault();
	return osg::Matrixd::lookAt(_focus - eyeV * _distance, _focus, upV);
}

osg::Matrixd PerspectiveCameraManager::getProjectionMatrix() {
	return osg::Matrixd::perspective(DEFAULT_ANGLE, _aspectRatio, 0.01, 1000);
}

osg::Quat PerspectiveCameraManager::makeOrbitQuat() {
	osg::Quat hQ = osg::Quat(-_heading, getUpVectorDefault());
	osg::Quat pQ = osg::Quat(-_pitch, getRightVectorDefault());
	return pQ * hQ;
}

void PerspectiveCameraManager::resetToBound(const osg::BoundingSphere &bs) {
    _focus = bs._center;
	_distance = bs._radius / tanf(osg::inDegrees(DEFAULT_ANGLE / 2.0));
}
