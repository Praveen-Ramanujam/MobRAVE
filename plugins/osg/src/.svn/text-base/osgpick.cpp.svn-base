#include "osgpick.h"
#include "osgviewerQtContext.h"

void PickHandler::pick(osgViewer::View* view, const osgGA::GUIEventAdapter& ea)
{
    osgUtil::LineSegmentIntersector::Intersections intersections;

    osg::ref_ptr<osg::Node> node;
    std::string gdlist="";
    float x = ea.getX();
    float y = ea.getY();
#if 0
    osg::ref_ptr< osgUtil::LineSegmentIntersector > picker = new osgUtil::LineSegmentIntersector(osgUtil::Intersector::WINDOW, x, y);
    osgUtil::IntersectionVisitor iv(picker.get());
    view->getCamera()->accept(iv);
    if (picker->containsIntersections())
    {
        intersections = picker->getIntersections();
#else
    if (view->computeIntersections(x,y,intersections))
    {
#endif
        for(osgUtil::LineSegmentIntersector::Intersections::iterator hitr = intersections.begin();
            hitr != intersections.end();
            ++hitr)
        {
            if (!hitr->nodePath.empty() && !(hitr->nodePath.back()->getName().empty()))
            {
              // the geodes are identified by name.
              gdlist  = hitr->nodePath.back()->getName();
              node = hitr->drawable->getParent(0);
              break;
            }
            else if (hitr->drawable.valid())
            {
              gdlist  = hitr->drawable->className();


            }
        }
    }

    //  If selection is activated
    if (_select)
    {
      _viewer->select(node);
    }
}

void PickHandler::doubleClick()
{
  if (_viewer->isSimpleView)
  {
    _viewer->setMultipleView();
  }
  else
  {
    _viewer->setSimpleView();
  }
}

//  Active joint selection
void PickHandler::activeSelect(bool active)
{
  _select = active;
}
