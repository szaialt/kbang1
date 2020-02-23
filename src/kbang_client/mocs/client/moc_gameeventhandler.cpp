/****************************************************************************
** Meta object code from reading C++ file 'gameeventhandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gameeventhandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameeventhandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_client__GameEventHandler_t {
    QByteArrayData data[20];
    char stringdata0[319];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_client__GameEventHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_client__GameEventHandler_t qt_meta_stringdata_client__GameEventHandler = {
    {
QT_MOC_LITERAL(0, 0, 24), // "client::GameEventHandler"
QT_MOC_LITERAL(1, 25, 19), // "onCardMovementEvent"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 16), // "CardMovementData"
QT_MOC_LITERAL(4, 63, 24), // "onGameContextChangeEvent"
QT_MOC_LITERAL(5, 88, 15), // "GameContextData"
QT_MOC_LITERAL(6, 104, 15), // "onGameSyncEvent"
QT_MOC_LITERAL(7, 120, 12), // "GameSyncData"
QT_MOC_LITERAL(8, 133, 23), // "onLifePointsChangeEvent"
QT_MOC_LITERAL(9, 157, 8), // "playerId"
QT_MOC_LITERAL(10, 166, 10), // "lifePoints"
QT_MOC_LITERAL(11, 177, 17), // "onPlayerDiedEvent"
QT_MOC_LITERAL(12, 195, 10), // "PlayerRole"
QT_MOC_LITERAL(13, 206, 4), // "role"
QT_MOC_LITERAL(14, 211, 19), // "onPlayerJoinedEvent"
QT_MOC_LITERAL(15, 231, 16), // "PublicPlayerData"
QT_MOC_LITERAL(16, 248, 19), // "onPlayerLeavedEvent"
QT_MOC_LITERAL(17, 268, 19), // "onPlayerUpdateEvent"
QT_MOC_LITERAL(18, 288, 18), // "onGameMessageEvent"
QT_MOC_LITERAL(19, 307, 11) // "GameMessage"

    },
    "client::GameEventHandler\0onCardMovementEvent\0"
    "\0CardMovementData\0onGameContextChangeEvent\0"
    "GameContextData\0onGameSyncEvent\0"
    "GameSyncData\0onLifePointsChangeEvent\0"
    "playerId\0lifePoints\0onPlayerDiedEvent\0"
    "PlayerRole\0role\0onPlayerJoinedEvent\0"
    "PublicPlayerData\0onPlayerLeavedEvent\0"
    "onPlayerUpdateEvent\0onGameMessageEvent\0"
    "GameMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client__GameEventHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    1,   62,    2, 0x0a /* Public */,
       6,    1,   65,    2, 0x0a /* Public */,
       8,    2,   68,    2, 0x0a /* Public */,
      11,    2,   73,    2, 0x0a /* Public */,
      14,    1,   78,    2, 0x0a /* Public */,
      16,    1,   81,    2, 0x0a /* Public */,
      17,    1,   84,    2, 0x0a /* Public */,
      18,    1,   87,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 12,    9,   13,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 19,    2,

       0        // eod
};

void client::GameEventHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameEventHandler *_t = static_cast<GameEventHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onCardMovementEvent((*reinterpret_cast< const CardMovementData(*)>(_a[1]))); break;
        case 1: _t->onGameContextChangeEvent((*reinterpret_cast< const GameContextData(*)>(_a[1]))); break;
        case 2: _t->onGameSyncEvent((*reinterpret_cast< const GameSyncData(*)>(_a[1]))); break;
        case 3: _t->onLifePointsChangeEvent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->onPlayerDiedEvent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< PlayerRole(*)>(_a[2]))); break;
        case 5: _t->onPlayerJoinedEvent((*reinterpret_cast< const PublicPlayerData(*)>(_a[1]))); break;
        case 6: _t->onPlayerLeavedEvent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->onPlayerUpdateEvent((*reinterpret_cast< const PublicPlayerData(*)>(_a[1]))); break;
        case 8: _t->onGameMessageEvent((*reinterpret_cast< const GameMessage(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject client::GameEventHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_client__GameEventHandler.data,
      qt_meta_data_client__GameEventHandler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *client::GameEventHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *client::GameEventHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_client__GameEventHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int client::GameEventHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
