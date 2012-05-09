/*
 * osgpick.h
 *
 *  Created on: 14 Sep 2010
 *      Author: gustavo
 */

#ifndef OSGPICK_H_
#define OSGPICK_H_

class ViewerWidget;

#include <osgUtil/Optimizer>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osgViewer/CompositeViewer>

#include <osgGA/TerrainManipulator>
#include <osgGA/StateSetManipulator>
#include <osgGA/AnimationPathManipulator>
#include <osgGA/TrackballManipulator>
#include <osgGA/FlightManipulator>
#include <osgGA/DriveManipulator>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgGA/StateSetManipulator>
#include <osgGA/AnimationPathManipulator>
#include <osgGA/TerrainManipulator>

#include <osg/Material>
#include <osg/Geode>
#include <osg/BlendFunc>
#include <osg/Depth>
#include <osg/Projection>
#include <osg/MatrixTransform>
#include <osg/Camera>
#include <osg/io_utils>
#include <osg/ShapeDrawable>

#include <sstream>

// class to handle events with a pick
class PickHandler : public osgGA::GUIEventHandler {
public:

    PickHandler(ViewerWidget* viewer):
        _viewer(viewer),_select(false) {}

    ~PickHandler() {}

    bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa)
    {
        switch(ea.getEventType())
        {
            case(osgGA::GUIEventAdapter::DOUBLECLICK):
            {
              doubleClick();
              return false;
            }
            case(osgGA::GUIEventAdapter::PUSH):
            {
                osgViewer::View* view = dynamic_cast<osgViewer::View*>(&aa);
                if (view) pick(view,ea);
                return false;
            }
            case(osgGA::GUIEventAdapter::KEYDOWN):
            {
                if (ea.getKey()=='c')
                {
                    osgViewer::View* view = dynamic_cast<osgViewer::View*>(&aa);
                    osg::ref_ptr<osgGA::GUIEventAdapter> event = new osgGA::GUIEventAdapter(ea);
                    event->setX((ea.getXmin()+ea.getXmax())*0.5);
                    event->setY((ea.getYmin()+ea.getYmax())*0.5);
                    if (view) pick(view,*event);
                }
                return false;
            }
            default:
                return false;
        }
    }

    virtual void pick(osgViewer::View* view, const osgGA::GUIEventAdapter& ea);

    //  Active selection
    void activeSelect(bool active);

    //  Double click
    void doubleClick();

protected:
        bool          _select;
        ViewerWidget  *_viewer;
};




#endif /* OSGPICK_H_ */
