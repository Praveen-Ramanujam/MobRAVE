/*
 * objecttree.h
 *
 *  Created on: 12-ene-2009
 *      Author: al052640
 */

#ifndef OBJECTTREE_H_
#define OBJECTTREE_H_

#include <QTreeView>

#include <osgGA/GUIActionAdapter>
#include <osgGA/EventQueue>
#include <osgGA/EventVisitor>
#include <osgUtil/SceneView>
#include <osg/Timer>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osg/observer_ptr>
#include <osg/Object>
#include <osg/Referenced>
#include <osg/ref_ptr>



class ObjectTree : public QTreeView {
public:
	ObjectTree();
	virtual ~ObjectTree();

	void setRoot(osg::Object *obj);
protected:
	void on_selection_changed();
	void refresh();

private:
	class ModelColumns{
	public:
		ModelColumns(){}
	};

	class OsgTreeModel{
	public:
		OsgTreeModel();
		static OsgTreeModel *create();

		ModelColumns _columns;

	};
	OsgTreeModel *model;
};

#endif /* OBJECTTREE_H_ */
