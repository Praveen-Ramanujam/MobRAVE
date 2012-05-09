#include "orthocameramanager.h"

OrthoCameraManager::OrthoCameraManager(Side side): _side(side), _zoom(5) {
}

void OrthoCameraManager::zoom(double ratio) {
    _zoom *= (1+ratio);
}

void OrthoCameraManager::pan(osg::Vec2 vector) {
	osg::Vec3 rightV;
	osg::Vec3 upV;
	switch (_side) {
	case FRONT:
		rightV = getRightVectorDefault();
		upV = getUpVectorDefault();
		break;
	case BACK:
		rightV = -getRightVectorDefault();
		upV = getUpVectorDefault();
		break;
	case LEFT:
		rightV = -getFrontVectorDefault();
		upV = getUpVectorDefault();
		break;
	case RIGHT:
		rightV = getFrontVectorDefault();
		upV = getUpVectorDefault();
		break;
	case TOP:
		rightV = getRightVectorDefault();
		upV = getFrontVectorDefault();
		break;
	case BOTTOM:
		rightV = getRightVectorDefault();
		upV = -getFrontVectorDefault();
		break;
	}

	_focus += (rightV * vector.x() + upV * vector.y())*_zoom/2;
}

std::string OrthoCameraManager::getName() {
	switch (_side) {
	case FRONT: return "Front";
	case BACK: return "Back";
	case LEFT: return "Left";
	case RIGHT: return "Right";
	case TOP: return "Top";
	case BOTTOM: return "Bottom";
	default: return "Unknown";
	}
    
}

void OrthoCameraManager::resetToBound(const osg::BoundingSphere &bs) {
    _focus = bs._center;
    _zoom = bs._radius * 1.25f;
}

osg::Matrixd OrthoCameraManager::getViewMatrix() {
	osg::Vec3d dirV;
	osg::Vec3d upV;
	switch (_side) {
	case FRONT:
		dirV = getFrontVectorDefault();
		upV = getUpVectorDefault();
		break;
	case BACK:
		dirV = -getFrontVectorDefault();
		upV = getUpVectorDefault();
		break;
	case LEFT:
		dirV = getRightVectorDefault();
		upV = getUpVectorDefault();
		break;
	case RIGHT:
		dirV = -getRightVectorDefault();
		upV = getUpVectorDefault();
		break;
	case TOP:
		dirV = -getUpVectorDefault();
		upV = getFrontVectorDefault();
		break;
	case BOTTOM:
		dirV = getUpVectorDefault();
		upV = -getFrontVectorDefault();
		break;
	}

	return osg::Matrixd::lookAt(_focus-dirV, _focus, upV);
}

osg::Matrixd OrthoCameraManager::getProjectionMatrix() {
	return osg::Matrixd::ortho2D(-_zoom*_aspectRatio, _zoom*_aspectRatio, -_zoom, _zoom);
}
