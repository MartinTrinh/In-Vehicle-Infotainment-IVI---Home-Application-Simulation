/****************************************************************************
** Meta object code from reading C++ file 'climate_data_adaptor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "climate_data_adaptor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'climate_data_adaptor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClimateAdaptor_t {
    QByteArrayData data[22];
    char stringdata0[1561];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClimateAdaptor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClimateAdaptor_t qt_meta_stringdata_ClimateAdaptor = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ClimateAdaptor"
QT_MOC_LITERAL(1, 15, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 31, 13), // "local.Climate"
QT_MOC_LITERAL(3, 45, 19), // "D-Bus Introspection"
QT_MOC_LITERAL(4, 65, 1267), // "  <interface name=\"local.Cli..."
QT_MOC_LITERAL(5, 1210, 11), // "dataChanged"
QT_MOC_LITERAL(6, 1222, 0), // ""
QT_MOC_LITERAL(7, 1223, 12), // "getAuto_mode"
QT_MOC_LITERAL(8, 1236, 18), // "getDriverWind_mode"
QT_MOC_LITERAL(9, 1255, 12), // "getFan_speed"
QT_MOC_LITERAL(10, 1268, 21), // "getPassengerWind_mode"
QT_MOC_LITERAL(11, 1290, 12), // "getSync_mode"
QT_MOC_LITERAL(12, 1303, 14), // "getTemp_driver"
QT_MOC_LITERAL(13, 1318, 17), // "getTemp_passenger"
QT_MOC_LITERAL(14, 1336, 7), // "setData"
QT_MOC_LITERAL(15, 1344, 11), // "temp_driver"
QT_MOC_LITERAL(16, 1356, 14), // "temp_passenger"
QT_MOC_LITERAL(17, 1371, 9), // "fan_speed"
QT_MOC_LITERAL(18, 1381, 16), // "driver_wind_mode"
QT_MOC_LITERAL(19, 1398, 19), // "passenger_wind_mode"
QT_MOC_LITERAL(20, 1418, 9), // "auto_mode"
QT_MOC_LITERAL(21, 1428, 9) // "sync_mode"

    },
    "ClimateAdaptor\0D-Bus Interface\0"
    "local.Climate\0D-Bus Introspection\0"
    "  <interface name=\"local.Climate\">\n    <signal name=\"dataChanged\""
    "/>\n    <method name=\"getAuto_mode\">\n      <arg direction=\"out\" t"
    "ype=\"i\"/>\n    </method>\n    <method name=\"getDriverWind_mode\">\n"
    "      <arg direction=\"out\" type=\"i\"/>\n    </method>\n    <method "
    "name=\"getFan_speed\">\n      <arg direction=\"out\" type=\"i\"/>\n   "
    " </method>\n    <method name=\"getPassengerWind_mode\">\n      <arg di"
    "rection=\"out\" type=\"i\"/>\n    </method>\n    <method name=\"getSyn"
    "c_mode\">\n      <arg direction=\"out\" type=\"i\"/>\n    </method>\n "
    "   <method name=\"getTemp_driver\">\n      <arg direction=\"out\" type"
    "=\"d\"/>\n    </method>\n    <method name=\"getTemp_passenger\">\n    "
    "  <arg direction=\"out\" type=\"d\"/>\n    </method>\n    <method name"
    "=\"setData\">\n      <arg direction=\"in\" type=\"d\" name=\"temp_driv"
    "er\"/>\n      <arg direction=\"in\" type=\"d\" name=\"temp_passenger\""
    "/>\n      <arg direction=\"in\" type=\"i\" name=\"fan_speed\"/>\n     "
    " <arg direction=\"in\" type=\"i\" name=\"driver_wind_mode\"/>\n      <"
    "arg direction=\"in\" type=\"i\" name=\"passenger_wind_mode\"/>\n      "
    "<arg direction=\"in\" type=\"i\" name=\"auto_mode\"/>\n      <arg dire"
    "ction=\"in\" type=\"i\" name=\"sync_mode\"/>\n    </method>\n  </inter"
    "face>\n\0"
    "dataChanged\0\0getAuto_mode\0getDriverWind_mode\0"
    "getFan_speed\0getPassengerWind_mode\0"
    "getSync_mode\0getTemp_driver\0"
    "getTemp_passenger\0setData\0temp_driver\0"
    "temp_passenger\0fan_speed\0driver_wind_mode\0"
    "passenger_wind_mode\0auto_mode\0sync_mode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClimateAdaptor[] = {

 // content:
       8,       // revision
       0,       // classname
       2,   14, // classinfo
       9,   18, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // signals: name, argc, parameters, tag, flags
       5,    0,   63,    6, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   64,    6, 0x0a /* Public */,
       8,    0,   65,    6, 0x0a /* Public */,
       9,    0,   66,    6, 0x0a /* Public */,
      10,    0,   67,    6, 0x0a /* Public */,
      11,    0,   68,    6, 0x0a /* Public */,
      12,    0,   69,    6, 0x0a /* Public */,
      13,    0,   70,    6, 0x0a /* Public */,
      14,    7,   71,    6, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   15,   16,   17,   18,   19,   20,   21,

       0        // eod
};

void ClimateAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClimateAdaptor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataChanged(); break;
        case 1: { int _r = _t->getAuto_mode();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->getDriverWind_mode();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->getFan_speed();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->getPassengerWind_mode();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->getSync_mode();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { double _r = _t->getTemp_driver();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 7: { double _r = _t->getTemp_passenger();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->setData((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClimateAdaptor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClimateAdaptor::dataChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ClimateAdaptor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractAdaptor::staticMetaObject>(),
    qt_meta_stringdata_ClimateAdaptor.data,
    qt_meta_data_ClimateAdaptor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ClimateAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClimateAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClimateAdaptor.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int ClimateAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
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
void ClimateAdaptor::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
