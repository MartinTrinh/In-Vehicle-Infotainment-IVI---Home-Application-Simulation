/****************************************************************************
** Meta object code from reading C++ file 'appdefines.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../HomeScreenAutomotive/src/common/appdefines.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appdefines.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AppEnums_t {
    QByteArrayData data[14];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppEnums_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppEnums_t qt_meta_stringdata_AppEnums = {
    {
QT_MOC_LITERAL(0, 0, 8), // "AppEnums"
QT_MOC_LITERAL(1, 9, 9), // "SCREEN_ID"
QT_MOC_LITERAL(2, 19, 14), // "SCREEN_ID_HOME"
QT_MOC_LITERAL(3, 34, 13), // "SCREEN_ID_MAP"
QT_MOC_LITERAL(4, 48, 22), // "SCREEN_ID_VIDEO_PLAYER"
QT_MOC_LITERAL(5, 71, 22), // "SCREEN_ID_MUSIC_PLAYER"
QT_MOC_LITERAL(6, 94, 19), // "SCREEN_ID_TELEPHONE"
QT_MOC_LITERAL(7, 114, 15), // "SCREEN_ID_RADIO"
QT_MOC_LITERAL(8, 130, 17), // "SCREEN_ID_SETTING"
QT_MOC_LITERAL(9, 148, 17), // "SCREEN_ID_CLIMATE"
QT_MOC_LITERAL(10, 166, 8), // "LANGUAGE"
QT_MOC_LITERAL(11, 175, 2), // "EN"
QT_MOC_LITERAL(12, 178, 2), // "VN"
QT_MOC_LITERAL(13, 181, 2) // "KO"

    },
    "AppEnums\0SCREEN_ID\0SCREEN_ID_HOME\0"
    "SCREEN_ID_MAP\0SCREEN_ID_VIDEO_PLAYER\0"
    "SCREEN_ID_MUSIC_PLAYER\0SCREEN_ID_TELEPHONE\0"
    "SCREEN_ID_RADIO\0SCREEN_ID_SETTING\0"
    "SCREEN_ID_CLIMATE\0LANGUAGE\0EN\0VN\0KO"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppEnums[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       2,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    8,   24,
      10,   10, 0x0,    3,   40,

 // enum data: key, value
       2, uint(AppEnums::SCREEN_ID_HOME),
       3, uint(AppEnums::SCREEN_ID_MAP),
       4, uint(AppEnums::SCREEN_ID_VIDEO_PLAYER),
       5, uint(AppEnums::SCREEN_ID_MUSIC_PLAYER),
       6, uint(AppEnums::SCREEN_ID_TELEPHONE),
       7, uint(AppEnums::SCREEN_ID_RADIO),
       8, uint(AppEnums::SCREEN_ID_SETTING),
       9, uint(AppEnums::SCREEN_ID_CLIMATE),
      11, uint(AppEnums::EN),
      12, uint(AppEnums::VN),
      13, uint(AppEnums::KO),

       0        // eod
};

void AppEnums::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject AppEnums::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AppEnums.data,
    qt_meta_data_AppEnums,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AppEnums::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppEnums::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppEnums.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AppEnums::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
