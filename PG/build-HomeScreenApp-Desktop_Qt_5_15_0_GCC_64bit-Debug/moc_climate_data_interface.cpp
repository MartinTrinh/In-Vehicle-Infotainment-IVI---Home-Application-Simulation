/****************************************************************************
** Meta object code from reading C++ file 'climate_data_interface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "climate_data_interface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'climate_data_interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LocalClimateInterface_t {
    QByteArrayData data[21];
    char stringdata0[319];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LocalClimateInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LocalClimateInterface_t qt_meta_stringdata_LocalClimateInterface = {
    {
QT_MOC_LITERAL(0, 0, 21), // "LocalClimateInterface"
QT_MOC_LITERAL(1, 22, 11), // "dataChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 12), // "getAuto_mode"
QT_MOC_LITERAL(4, 48, 22), // "QDBusPendingReply<int>"
QT_MOC_LITERAL(5, 71, 18), // "getDriverWind_mode"
QT_MOC_LITERAL(6, 90, 12), // "getFan_speed"
QT_MOC_LITERAL(7, 103, 21), // "getPassengerWind_mode"
QT_MOC_LITERAL(8, 125, 12), // "getSync_mode"
QT_MOC_LITERAL(9, 138, 14), // "getTemp_driver"
QT_MOC_LITERAL(10, 153, 25), // "QDBusPendingReply<double>"
QT_MOC_LITERAL(11, 179, 17), // "getTemp_passenger"
QT_MOC_LITERAL(12, 197, 7), // "setData"
QT_MOC_LITERAL(13, 205, 19), // "QDBusPendingReply<>"
QT_MOC_LITERAL(14, 225, 11), // "temp_driver"
QT_MOC_LITERAL(15, 237, 14), // "temp_passenger"
QT_MOC_LITERAL(16, 252, 9), // "fan_speed"
QT_MOC_LITERAL(17, 262, 16), // "driver_wind_mode"
QT_MOC_LITERAL(18, 279, 19), // "passenger_wind_mode"
QT_MOC_LITERAL(19, 299, 9), // "auto_mode"
QT_MOC_LITERAL(20, 309, 9) // "sync_mode"

    },
    "LocalClimateInterface\0dataChanged\0\0"
    "getAuto_mode\0QDBusPendingReply<int>\0"
    "getDriverWind_mode\0getFan_speed\0"
    "getPassengerWind_mode\0getSync_mode\0"
    "getTemp_driver\0QDBusPendingReply<double>\0"
    "getTemp_passenger\0setData\0QDBusPendingReply<>\0"
    "temp_driver\0temp_passenger\0fan_speed\0"
    "driver_wind_mode\0passenger_wind_mode\0"
    "auto_mode\0sync_mode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LocalClimateInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x0a /* Public */,
       5,    0,   61,    2, 0x0a /* Public */,
       6,    0,   62,    2, 0x0a /* Public */,
       7,    0,   63,    2, 0x0a /* Public */,
       8,    0,   64,    2, 0x0a /* Public */,
       9,    0,   65,    2, 0x0a /* Public */,
      11,    0,   66,    2, 0x0a /* Public */,
      12,    7,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    0x80000000 | 4,
    0x80000000 | 4,
    0x80000000 | 4,
    0x80000000 | 4,
    0x80000000 | 4,
    0x80000000 | 10,
    0x80000000 | 10,
    0x80000000 | 13, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   16,   17,   18,   19,   20,

       0        // eod
};

void LocalClimateInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LocalClimateInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataChanged(); break;
        case 1: { QDBusPendingReply<int> _r = _t->getAuto_mode();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<int>*>(_a[0]) = std::move(_r); }  break;
        case 2: { QDBusPendingReply<int> _r = _t->getDriverWind_mode();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<int>*>(_a[0]) = std::move(_r); }  break;
        case 3: { QDBusPendingReply<int> _r = _t->getFan_speed();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<int>*>(_a[0]) = std::move(_r); }  break;
        case 4: { QDBusPendingReply<int> _r = _t->getPassengerWind_mode();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<int>*>(_a[0]) = std::move(_r); }  break;
        case 5: { QDBusPendingReply<int> _r = _t->getSync_mode();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<int>*>(_a[0]) = std::move(_r); }  break;
        case 6: { QDBusPendingReply<double> _r = _t->getTemp_driver();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<double>*>(_a[0]) = std::move(_r); }  break;
        case 7: { QDBusPendingReply<double> _r = _t->getTemp_passenger();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<double>*>(_a[0]) = std::move(_r); }  break;
        case 8: { QDBusPendingReply<> _r = _t->setData((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LocalClimateInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LocalClimateInterface::dataChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LocalClimateInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractInterface::staticMetaObject>(),
    qt_meta_stringdata_LocalClimateInterface.data,
    qt_meta_data_LocalClimateInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LocalClimateInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LocalClimateInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LocalClimateInterface.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int LocalClimateInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void LocalClimateInterface::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
