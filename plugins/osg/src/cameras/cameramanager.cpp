#include <common/config.h>
#include "cameramanager.h"

#define UP_MODE "_upMode"

class EnumUpMode: public Enum<CameraManager::UpMode> {
public:
	EnumUpMode() {
		add("Z Up", CameraManager::Z_UP);
		add("Y Up", CameraManager::Y_UP);
	}
};

osg::ref_ptr< ValuedEnumProperty<CameraManager::UpMode> > CameraManager::_upMode =
  new ValuedEnumProperty<CameraManager::UpMode>(UP_MODE, EnumUpMode(), CameraManager::Z_UP);

CameraManager::CameraManager() {
	try {
		osgedit::Config::instance()->registerProperty(_upMode.get());
	} catch (osgedit::Config::DuplicatedPropertyException&) {}
}

osg::Vec3 CameraManager::getUpVectorDefault() {
	switch (_upMode->getValue()) {
	case Z_UP: return osg::Vec3(0,0,1);
	case Y_UP: return osg::Vec3(0,1,0);
	default: return osg::Vec3(0,0,0);
	}
}

osg::Vec3 CameraManager::getFrontVectorDefault() {
	switch (_upMode->getValue()) {
	case Z_UP: return osg::Vec3(0,1,0);
	case Y_UP: return osg::Vec3(0,0,-1);
	default: return osg::Vec3(0,0,0);
	}
}

osg::Vec3 CameraManager::getRightVectorDefault() {
	switch (_upMode->getValue()) {
	case Z_UP: return osg::Vec3(1,0,0);
	case Y_UP: return osg::Vec3(1,0,0);
	default: return osg::Vec3(0,0,0);
	}
}
