/****************************************************************************
** Meta object code from reading C++ file 'myglwidget.h'
**
** Created: Mon Apr 23 21:09:37 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../myglwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myglwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyGLWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      48,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      21,   11,   11,   11, 0x05,
      32,   11,   11,   11, 0x05,
      42,   11,   11,   11, 0x05,
      55,   11,   11,   11, 0x05,
      68,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      81,   11,   11,   11, 0x0a,
      88,   11,   11,   11, 0x0a,
      95,   11,   11,   11, 0x0a,
     113,   11,   11,   11, 0x0a,
     139,   11,   11,   11, 0x0a,
     166,   11,   11,   11, 0x0a,
     194,   11,   11,   11, 0x0a,
     208,   11,   11,   11, 0x0a,
     223,   11,   11,   11, 0x0a,
     239,   11,   11,   11, 0x0a,
     249,   11,   11,   11, 0x0a,
     259,   11,   11,   11, 0x0a,
     269,   11,   11,   11, 0x0a,
     284,   11,   11,   11, 0x0a,
     303,   11,   11,   11, 0x0a,
     315,   11,   11,   11, 0x0a,
     334,   11,   11,   11, 0x0a,
     358,   11,   11,   11, 0x0a,
     369,   11,   11,   11, 0x0a,
     380,   11,   11,   11, 0x0a,
     393,   11,   11,   11, 0x0a,
     406,   11,   11,   11, 0x0a,
     419,   11,   11,   11, 0x0a,
     436,   11,   11,   11, 0x0a,
     442,   11,   11,   11, 0x0a,
     457,   11,   11,   11, 0x0a,
     469,   11,   11,   11, 0x0a,
     481,   11,   11,   11, 0x0a,
     492,   11,   11,   11, 0x0a,
     512,   11,   11,   11, 0x0a,
     532,   11,   11,   11, 0x0a,
     551,   11,   11,   11, 0x0a,
     570,   11,   11,   11, 0x0a,
     589,   11,   11,   11, 0x0a,
     598,   11,   11,   11, 0x0a,
     607,   11,   11,   11, 0x0a,
     616,   11,   11,   11, 0x0a,
     629,   11,   11,   11, 0x0a,
     642,   11,   11,   11, 0x0a,
     655,   11,   11,   11, 0x0a,
     664,   11,   11,   11, 0x0a,
     675,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyGLWidget[] = {
    "MyGLWidget\0\0red(int)\0green(int)\0"
    "blue(int)\0xsig(double)\0ysig(double)\0"
    "zsig(double)\0play()\0stop()\0mousemodetoggle()\0"
    "setCurr(QListWidgetItem*)\0"
    "setCurr2(QListWidgetItem*)\0"
    "setCurrHE(QListWidgetItem*)\0colorRed(int)\0"
    "colorBlue(int)\0colorGreen(int)\0x(double)\0"
    "y(double)\0z(double)\0deleteVertex()\0"
    "quadtwotriangles()\0addVertex()\0"
    "edgeBtwnTwoFaces()\0updateFilename(QString)\0"
    "loadFile()\0saveFile()\0getXDiv(int)\0"
    "getYDiv(int)\0getZDiv(int)\0moveEverything()\0"
    "ffd()\0toggleDeform()\0twistmesh()\0"
    "taperMesh()\0bendMesh()\0setTwistval(double)\0"
    "setTaperval(double)\0setBendval(double)\0"
    "setBendMin(double)\0setBendMax(double)\0"
    "twistX()\0twistY()\0twistZ()\0lightsX(int)\0"
    "lightsY(int)\0lightsZ(int)\0focusV()\0"
    "loadFrag()\0unitCube()\0"
};

const QMetaObject MyGLWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_MyGLWidget,
      qt_meta_data_MyGLWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyGLWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyGLWidget))
        return static_cast<void*>(const_cast< MyGLWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int MyGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: red((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: green((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: blue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: xsig((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: ysig((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: zsig((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: play(); break;
        case 7: stop(); break;
        case 8: mousemodetoggle(); break;
        case 9: setCurr((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: setCurr2((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 11: setCurrHE((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 12: colorRed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: colorBlue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: colorGreen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: x((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: z((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: deleteVertex(); break;
        case 19: quadtwotriangles(); break;
        case 20: addVertex(); break;
        case 21: edgeBtwnTwoFaces(); break;
        case 22: updateFilename((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: loadFile(); break;
        case 24: saveFile(); break;
        case 25: getXDiv((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: getYDiv((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: getZDiv((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: moveEverything(); break;
        case 29: ffd(); break;
        case 30: toggleDeform(); break;
        case 31: twistmesh(); break;
        case 32: taperMesh(); break;
        case 33: bendMesh(); break;
        case 34: setTwistval((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 35: setTaperval((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 36: setBendval((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 37: setBendMin((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 38: setBendMax((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 39: twistX(); break;
        case 40: twistY(); break;
        case 41: twistZ(); break;
        case 42: lightsX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: lightsY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: lightsZ((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: focusV(); break;
        case 46: loadFrag(); break;
        case 47: unitCube(); break;
        default: ;
        }
        _id -= 48;
    }
    return _id;
}

// SIGNAL 0
void MyGLWidget::red(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGLWidget::green(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyGLWidget::blue(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyGLWidget::xsig(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyGLWidget::ysig(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyGLWidget::zsig(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
