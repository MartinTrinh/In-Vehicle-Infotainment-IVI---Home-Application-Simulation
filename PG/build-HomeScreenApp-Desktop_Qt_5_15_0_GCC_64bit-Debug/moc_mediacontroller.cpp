/****************************************************************************
** Meta object code from reading C++ file 'mediacontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../HomeScreenAutomotive/src/controller/mediacontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mediacontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MediaController_t {
    QByteArrayData data[35];
    char stringdata0[435];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MediaController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MediaController_t qt_meta_stringdata_MediaController = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MediaController"
QT_MOC_LITERAL(1, 16, 16), // "duarationChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 18), // "currentTimeChanged"
QT_MOC_LITERAL(4, 53, 19), // "currentIndexChanged"
QT_MOC_LITERAL(5, 73, 13), // "volumeChanged"
QT_MOC_LITERAL(6, 87, 26), // "onMetaDataAvailableChanged"
QT_MOC_LITERAL(7, 114, 9), // "available"
QT_MOC_LITERAL(8, 124, 17), // "onDurationChanged"
QT_MOC_LITERAL(9, 142, 8), // "duration"
QT_MOC_LITERAL(10, 151, 17), // "onPositionChanged"
QT_MOC_LITERAL(11, 169, 8), // "position"
QT_MOC_LITERAL(12, 178, 17), // "onMetaDataChanged"
QT_MOC_LITERAL(13, 196, 3), // "key"
QT_MOC_LITERAL(14, 200, 5), // "value"
QT_MOC_LITERAL(15, 206, 11), // "getSongName"
QT_MOC_LITERAL(16, 218, 9), // "getSinger"
QT_MOC_LITERAL(17, 228, 14), // "continuePlayer"
QT_MOC_LITERAL(18, 243, 10), // "initPlayer"
QT_MOC_LITERAL(19, 254, 11), // "pausePlayer"
QT_MOC_LITERAL(20, 266, 11), // "setPosition"
QT_MOC_LITERAL(21, 278, 14), // "setCurrenIndex"
QT_MOC_LITERAL(22, 293, 5), // "index"
QT_MOC_LITERAL(23, 299, 16), // "checkPlayerState"
QT_MOC_LITERAL(24, 316, 9), // "setVolume"
QT_MOC_LITERAL(25, 326, 6), // "volume"
QT_MOC_LITERAL(26, 333, 9), // "getVolume"
QT_MOC_LITERAL(27, 343, 4), // "next"
QT_MOC_LITERAL(28, 348, 8), // "previous"
QT_MOC_LITERAL(29, 357, 18), // "switchModePlaylist"
QT_MOC_LITERAL(30, 376, 4), // "mode"
QT_MOC_LITERAL(31, 381, 14), // "duarationTotal"
QT_MOC_LITERAL(32, 396, 16), // "currentDuaration"
QT_MOC_LITERAL(33, 413, 9), // "totalTime"
QT_MOC_LITERAL(34, 423, 11) // "currentTime"

    },
    "MediaController\0duarationChanged\0\0"
    "currentTimeChanged\0currentIndexChanged\0"
    "volumeChanged\0onMetaDataAvailableChanged\0"
    "available\0onDurationChanged\0duration\0"
    "onPositionChanged\0position\0onMetaDataChanged\0"
    "key\0value\0getSongName\0getSinger\0"
    "continuePlayer\0initPlayer\0pausePlayer\0"
    "setPosition\0setCurrenIndex\0index\0"
    "checkPlayerState\0setVolume\0volume\0"
    "getVolume\0next\0previous\0switchModePlaylist\0"
    "mode\0duarationTotal\0currentDuaration\0"
    "totalTime\0currentTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MediaController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       5,  164, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  124,    2, 0x06 /* Public */,
       3,    0,  125,    2, 0x06 /* Public */,
       4,    0,  126,    2, 0x06 /* Public */,
       5,    0,  127,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,  128,    2, 0x0a /* Public */,
       8,    1,  131,    2, 0x0a /* Public */,
      10,    1,  134,    2, 0x0a /* Public */,
      12,    2,  137,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      15,    0,  142,    2, 0x02 /* Public */,
      16,    0,  143,    2, 0x02 /* Public */,
      17,    0,  144,    2, 0x02 /* Public */,
      18,    0,  145,    2, 0x02 /* Public */,
      19,    0,  146,    2, 0x02 /* Public */,
      20,    1,  147,    2, 0x02 /* Public */,
      21,    1,  150,    2, 0x02 /* Public */,
      23,    0,  153,    2, 0x02 /* Public */,
      24,    1,  154,    2, 0x02 /* Public */,
      26,    0,  157,    2, 0x02 /* Public */,
      27,    0,  158,    2, 0x02 /* Public */,
      28,    0,  159,    2, 0x02 /* Public */,
      29,    1,  160,    2, 0x02 /* Public */,
      29,    0,  163,    2, 0x22 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::LongLong,    9,
    QMetaType::Void, QMetaType::LongLong,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,   13,   14,

 // methods: parameters
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   11,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void,

 // properties: name, type, flags
      31, QMetaType::LongLong, 0x00495001,
      32, QMetaType::LongLong, 0x00495001,
      33, QMetaType::QString, 0x00495001,
      34, QMetaType::QString, 0x00495001,
      25, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       0,
       1,
       3,

       0        // eod
};

void MediaController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MediaController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->duarationChanged(); break;
        case 1: _t->currentTimeChanged(); break;
        case 2: _t->currentIndexChanged(); break;
        case 3: _t->volumeChanged(); break;
        case 4: _t->onMetaDataAvailableChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->onDurationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 6: _t->onPositionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 7: _t->onMetaDataChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 8: { QString _r = _t->getSongName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->getSinger();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->continuePlayer(); break;
        case 11: _t->initPlayer(); break;
        case 12: _t->pausePlayer(); break;
        case 13: _t->setPosition((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 14: _t->setCurrenIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: { bool _r = _t->checkPlayerState();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->setVolume((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 17: { qint32 _r = _t->getVolume();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = std::move(_r); }  break;
        case 18: _t->next(); break;
        case 19: _t->previous(); break;
        case 20: _t->switchModePlaylist((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->switchModePlaylist(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MediaController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaController::duarationChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MediaController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaController::currentTimeChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MediaController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaController::currentIndexChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MediaController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaController::volumeChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MediaController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qint64*>(_v) = _t->getDuarationTotal(); break;
        case 1: *reinterpret_cast< qint64*>(_v) = _t->getCurrentDuaration(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getTotalTime(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getCurrentTime(); break;
        case 4: *reinterpret_cast< qint32*>(_v) = _t->getVolume(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject MediaController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MediaController.data,
    qt_meta_data_MediaController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MediaController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MediaController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MediaController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MediaController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MediaController::duarationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MediaController::currentTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MediaController::currentIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MediaController::volumeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
