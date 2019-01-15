/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Client_t {
    QByteArrayData data[29];
    char stringdata0[420];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Client_t qt_meta_stringdata_Client = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Client"
QT_MOC_LITERAL(1, 7, 12), // "disconnected"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "clientId"
QT_MOC_LITERAL(4, 30, 18), // "onActionCreateGame"
QT_MOC_LITERAL(5, 49, 14), // "CreateGameData"
QT_MOC_LITERAL(6, 64, 16), // "CreatePlayerData"
QT_MOC_LITERAL(7, 81, 16), // "onActionJoinGame"
QT_MOC_LITERAL(8, 98, 6), // "gameId"
QT_MOC_LITERAL(9, 105, 8), // "playerId"
QT_MOC_LITERAL(10, 114, 12), // "gamePassword"
QT_MOC_LITERAL(11, 127, 17), // "onActionLeaveGame"
QT_MOC_LITERAL(12, 145, 17), // "onActionStartGame"
QT_MOC_LITERAL(13, 163, 16), // "onActionDrawCard"
QT_MOC_LITERAL(14, 180, 16), // "onActionPlayCard"
QT_MOC_LITERAL(15, 197, 18), // "ActionPlayCardData"
QT_MOC_LITERAL(16, 216, 18), // "onActionUseAbility"
QT_MOC_LITERAL(17, 235, 20), // "ActionUseAbilityData"
QT_MOC_LITERAL(18, 256, 15), // "onActionEndTurn"
QT_MOC_LITERAL(19, 272, 12), // "onActionPass"
QT_MOC_LITERAL(20, 285, 15), // "onActionDiscard"
QT_MOC_LITERAL(21, 301, 6), // "cardId"
QT_MOC_LITERAL(22, 308, 19), // "onActionChatMessage"
QT_MOC_LITERAL(23, 328, 17), // "onQueryServerInfo"
QT_MOC_LITERAL(24, 346, 11), // "QueryResult"
QT_MOC_LITERAL(25, 358, 6), // "result"
QT_MOC_LITERAL(26, 365, 15), // "onQueryGameInfo"
QT_MOC_LITERAL(27, 381, 19), // "onQueryGameInfoList"
QT_MOC_LITERAL(28, 401, 18) // "onParserTerminated"

    },
    "Client\0disconnected\0\0clientId\0"
    "onActionCreateGame\0CreateGameData\0"
    "CreatePlayerData\0onActionJoinGame\0"
    "gameId\0playerId\0gamePassword\0"
    "onActionLeaveGame\0onActionStartGame\0"
    "onActionDrawCard\0onActionPlayCard\0"
    "ActionPlayCardData\0onActionUseAbility\0"
    "ActionUseAbilityData\0onActionEndTurn\0"
    "onActionPass\0onActionDiscard\0cardId\0"
    "onActionChatMessage\0onQueryServerInfo\0"
    "QueryResult\0result\0onQueryGameInfo\0"
    "onQueryGameInfoList\0onParserTerminated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   97,    2, 0x0a /* Public */,
       7,    4,  102,    2, 0x0a /* Public */,
      11,    0,  111,    2, 0x0a /* Public */,
      12,    0,  112,    2, 0x0a /* Public */,
      13,    0,  113,    2, 0x0a /* Public */,
      14,    1,  114,    2, 0x0a /* Public */,
      16,    1,  117,    2, 0x0a /* Public */,
      18,    0,  120,    2, 0x0a /* Public */,
      19,    0,  121,    2, 0x0a /* Public */,
      20,    1,  122,    2, 0x0a /* Public */,
      22,    1,  125,    2, 0x0a /* Public */,
      23,    1,  128,    2, 0x0a /* Public */,
      26,    2,  131,    2, 0x0a /* Public */,
      27,    1,  136,    2, 0x0a /* Public */,
      28,    0,  139,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 6,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, 0x80000000 | 6,    8,    9,   10,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 24,    8,   25,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void,

       0        // eod
};

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Client *_t = static_cast<Client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->disconnected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onActionCreateGame((*reinterpret_cast< const CreateGameData(*)>(_a[1])),(*reinterpret_cast< const CreatePlayerData(*)>(_a[2]))); break;
        case 2: _t->onActionJoinGame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< const CreatePlayerData(*)>(_a[4]))); break;
        case 3: _t->onActionLeaveGame(); break;
        case 4: _t->onActionStartGame(); break;
        case 5: _t->onActionDrawCard(); break;
        case 6: _t->onActionPlayCard((*reinterpret_cast< const ActionPlayCardData(*)>(_a[1]))); break;
        case 7: _t->onActionUseAbility((*reinterpret_cast< const ActionUseAbilityData(*)>(_a[1]))); break;
        case 8: _t->onActionEndTurn(); break;
        case 9: _t->onActionPass(); break;
        case 10: _t->onActionDiscard((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->onActionChatMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->onQueryServerInfo((*reinterpret_cast< QueryResult(*)>(_a[1]))); break;
        case 13: _t->onQueryGameInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QueryResult(*)>(_a[2]))); break;
        case 14: _t->onQueryGameInfoList((*reinterpret_cast< QueryResult(*)>(_a[1]))); break;
        case 15: _t->onParserTerminated(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Client::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::disconnected)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Client::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Client.data,
      qt_meta_data_Client,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Client.stringdata0))
        return static_cast<void*>(const_cast< Client*>(this));
    if (!strcmp(_clname, "GameEventListener"))
        return static_cast< GameEventListener*>(const_cast< Client*>(this));
    return QObject::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Client::disconnected(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
