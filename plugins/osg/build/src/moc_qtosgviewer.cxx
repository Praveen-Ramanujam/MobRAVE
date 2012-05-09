/****************************************************************************
** Meta object code from reading C++ file 'qtosgviewer.h'
**
** Created: Thu Mar 1 15:24:57 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/qtosgviewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtosgviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtOSGViewer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      31,   12,   12,   12, 0x0a,
      51,   12,   12,   12, 0x0a,
      69,   12,   12,   12, 0x0a,
      83,   12,   12,   12, 0x0a,
      98,   12,   12,   12, 0x0a,
     108,   12,   12,   12, 0x0a,
     115,   12,   12,   12, 0x0a,
     123,   12,   12,   12, 0x0a,
     137,   12,   12,   12, 0x0a,
     149,   12,   12,   12, 0x0a,
     163,   12,   12,   12, 0x0a,
     177,  170,   12,   12, 0x0a,
     202,  170,   12,   12, 0x0a,
     236,  227,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QtOSGViewer[] = {
    "QtOSGViewer\0\0LoadEnvironment()\0"
    "ImportEnvironment()\0SaveEnvironment()\0"
    "multiWidget()\0simpleWidget()\0refresh()\0"
    "home()\0light()\0polygonMode()\0facesMode()\0"
    "boundingBox()\0axes()\0button\0"
    "pointerGroupClicked(int)\0"
    "draggerGroupClicked(int)\0item,num\0"
    "sceneListClicked(QTreeWidgetItem*,int)\0"
};

const QMetaObject QtOSGViewer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QtOSGViewer,
      qt_meta_data_QtOSGViewer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtOSGViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtOSGViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtOSGViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtOSGViewer))
        return static_cast<void*>(const_cast< QtOSGViewer*>(this));
    if (!strcmp(_clname, "ViewerBase"))
        return static_cast< ViewerBase*>(const_cast< QtOSGViewer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QtOSGViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: LoadEnvironment(); break;
        case 1: ImportEnvironment(); break;
        case 2: SaveEnvironment(); break;
        case 3: multiWidget(); break;
        case 4: simpleWidget(); break;
        case 5: refresh(); break;
        case 6: home(); break;
        case 7: light(); break;
        case 8: polygonMode(); break;
        case 9: facesMode(); break;
        case 10: boundingBox(); break;
        case 11: axes(); break;
        case 12: pointerGroupClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: draggerGroupClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: sceneListClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
