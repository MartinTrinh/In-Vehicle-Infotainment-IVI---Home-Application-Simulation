/****************************************************************************
** Meta object code from reading C++ file 'screencontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../HomeScreenAutomotive/src/controller/screencontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screencontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScreenController_t {
    QByteArrayData data[8];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScreenController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScreenController_t qt_meta_stringdata_ScreenController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ScreenController"
QT_MOC_LITERAL(1, 17, 10), // "pushScreen"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 3), // "url"
QT_MOC_LITERAL(4, 33, 13), // "replaceScreen"
QT_MOC_LITERAL(5, 47, 8), // "screenId"
QT_MOC_LITERAL(6, 56, 9), // "popScreen"
QT_MOC_LITERAL(7, 66, 9) // "popToRoot"

    },
    "ScreenController\0pushScreen\0\0url\0"
    "replaceScreen\0screenId\0popScreen\0"
    "popToRoot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScreenController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x02 /* Public */,
       4,    1,   37,    2, 0x02 /* Public */,
       6,    0,   40,    2, 0x02 /* Public */,
       7,    0,   41,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ScreenController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScreenController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pushScreen((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->replaceScreen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->popScreen(); break;
        case 3: _t->popToRoot(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ScreenController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ScreenController.data,
    qt_meta_data_ScreenController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ScreenController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScreenController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScreenController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ScreenController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
