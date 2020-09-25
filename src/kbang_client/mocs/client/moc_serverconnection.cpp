/****************************************************************************
** Meta object code from reading C++ file 'serverconnection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../serverconnection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_client__ServerConnection_t {
    QByteArrayData data[53];
    char stringdata0[678];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_client__ServerConnection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_client__ServerConnection_t qt_meta_stringdata_client__ServerConnection = {
    {
QT_MOC_LITERAL(0, 0, 24), // "client::ServerConnection"
QT_MOC_LITERAL(1, 25, 13), // "statusChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 10), // "logMessage"
QT_MOC_LITERAL(4, 51, 7), // "message"
QT_MOC_LITERAL(5, 59, 12), // "incomingData"
QT_MOC_LITERAL(6, 72, 12), // "outgoingData"
QT_MOC_LITERAL(7, 85, 19), // "incomingChatMessage"
QT_MOC_LITERAL(8, 105, 8), // "senderId"
QT_MOC_LITERAL(9, 114, 10), // "senderName"
QT_MOC_LITERAL(10, 125, 13), // "enterGameMode"
QT_MOC_LITERAL(11, 139, 6), // "gameId"
QT_MOC_LITERAL(12, 146, 8), // "gameName"
QT_MOC_LITERAL(13, 155, 10), // "ClientType"
QT_MOC_LITERAL(14, 166, 12), // "exitGameMode"
QT_MOC_LITERAL(15, 179, 16), // "gameCanBeStarted"
QT_MOC_LITERAL(16, 196, 12), // "canBeStarted"
QT_MOC_LITERAL(17, 209, 17), // "eventCardMovement"
QT_MOC_LITERAL(18, 227, 16), // "CardMovementData"
QT_MOC_LITERAL(19, 244, 15), // "connectToServer"
QT_MOC_LITERAL(20, 260, 10), // "serverHost"
QT_MOC_LITERAL(21, 271, 10), // "serverPort"
QT_MOC_LITERAL(22, 282, 20), // "disconnectFromServer"
QT_MOC_LITERAL(23, 303, 10), // "createGame"
QT_MOC_LITERAL(24, 314, 14), // "CreateGameData"
QT_MOC_LITERAL(25, 329, 16), // "CreatePlayerData"
QT_MOC_LITERAL(26, 346, 8), // "joinGame"
QT_MOC_LITERAL(27, 355, 8), // "playerId"
QT_MOC_LITERAL(28, 364, 12), // "gamePassword"
QT_MOC_LITERAL(29, 377, 9), // "leaveGame"
QT_MOC_LITERAL(30, 387, 9), // "startGame"
QT_MOC_LITERAL(31, 397, 15), // "sendChatMessage"
QT_MOC_LITERAL(32, 413, 8), // "drawCard"
QT_MOC_LITERAL(33, 422, 8), // "playCard"
QT_MOC_LITERAL(34, 431, 6), // "cardId"
QT_MOC_LITERAL(35, 438, 18), // "playCardWithPlayer"
QT_MOC_LITERAL(36, 457, 16), // "playCardWithCard"
QT_MOC_LITERAL(37, 474, 11), // "otherCardId"
QT_MOC_LITERAL(38, 486, 25), // "playCardWithCardAndPlayer"
QT_MOC_LITERAL(39, 512, 17), // "playCardWithCards"
QT_MOC_LITERAL(40, 530, 10), // "QList<int>"
QT_MOC_LITERAL(41, 541, 7), // "cardIds"
QT_MOC_LITERAL(42, 549, 19), // "playCardWithPlayers"
QT_MOC_LITERAL(43, 569, 9), // "playerIds"
QT_MOC_LITERAL(44, 579, 10), // "useAbility"
QT_MOC_LITERAL(45, 590, 5), // "cards"
QT_MOC_LITERAL(46, 596, 7), // "endTurn"
QT_MOC_LITERAL(47, 604, 4), // "pass"
QT_MOC_LITERAL(48, 609, 11), // "discardCard"
QT_MOC_LITERAL(49, 621, 9), // "connected"
QT_MOC_LITERAL(50, 631, 12), // "disconnected"
QT_MOC_LITERAL(51, 644, 18), // "recievedServerInfo"
QT_MOC_LITERAL(52, 663, 14) // "ServerInfoData"

    },
    "client::ServerConnection\0statusChanged\0"
    "\0logMessage\0message\0incomingData\0"
    "outgoingData\0incomingChatMessage\0"
    "senderId\0senderName\0enterGameMode\0"
    "gameId\0gameName\0ClientType\0exitGameMode\0"
    "gameCanBeStarted\0canBeStarted\0"
    "eventCardMovement\0CardMovementData\0"
    "connectToServer\0serverHost\0serverPort\0"
    "disconnectFromServer\0createGame\0"
    "CreateGameData\0CreatePlayerData\0"
    "joinGame\0playerId\0gamePassword\0leaveGame\0"
    "startGame\0sendChatMessage\0drawCard\0"
    "playCard\0cardId\0playCardWithPlayer\0"
    "playCardWithCard\0otherCardId\0"
    "playCardWithCardAndPlayer\0playCardWithCards\0"
    "QList<int>\0cardIds\0playCardWithPlayers\0"
    "playerIds\0useAbility\0cards\0endTurn\0"
    "pass\0discardCard\0connected\0disconnected\0"
    "recievedServerInfo\0ServerInfoData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client__ServerConnection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  179,    2, 0x06 /* Public */,
       3,    1,  180,    2, 0x06 /* Public */,
       5,    1,  183,    2, 0x06 /* Public */,
       6,    1,  186,    2, 0x06 /* Public */,
       7,    3,  189,    2, 0x06 /* Public */,
      10,    3,  196,    2, 0x06 /* Public */,
      14,    0,  203,    2, 0x06 /* Public */,
      15,    1,  204,    2, 0x06 /* Public */,
      17,    1,  207,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    2,  210,    2, 0x0a /* Public */,
      22,    0,  215,    2, 0x0a /* Public */,
      23,    2,  216,    2, 0x0a /* Public */,
      26,    4,  221,    2, 0x0a /* Public */,
      29,    0,  230,    2, 0x0a /* Public */,
      30,    0,  231,    2, 0x0a /* Public */,
      31,    1,  232,    2, 0x0a /* Public */,
      32,    0,  235,    2, 0x0a /* Public */,
      33,    1,  236,    2, 0x0a /* Public */,
      35,    2,  239,    2, 0x0a /* Public */,
      36,    2,  244,    2, 0x0a /* Public */,
      38,    3,  249,    2, 0x0a /* Public */,
      39,    2,  256,    2, 0x0a /* Public */,
      42,    2,  261,    2, 0x0a /* Public */,
      44,    0,  266,    2, 0x0a /* Public */,
      44,    1,  267,    2, 0x0a /* Public */,
      44,    1,  270,    2, 0x0a /* Public */,
      44,    2,  273,    2, 0x0a /* Public */,
      46,    0,  278,    2, 0x0a /* Public */,
      47,    0,  279,    2, 0x0a /* Public */,
      48,    1,  280,    2, 0x0a /* Public */,
      49,    0,  283,    2, 0x08 /* Private */,
      50,    0,  284,    2, 0x08 /* Private */,
      51,    1,  285,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    8,    9,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 13,   11,   12,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, 0x80000000 | 18,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   20,   21,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 24, 0x80000000 | 25,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, 0x80000000 | 25,   11,   27,   28,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   34,   27,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   34,   37,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   34,   37,   27,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 40,   34,   41,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 40,   34,   43,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, 0x80000000 | 40,   45,
    QMetaType::Void, 0x80000000 | 40, QMetaType::Int,   45,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 52,    2,

       0        // eod
};

void client::ServerConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ServerConnection *_t = static_cast<ServerConnection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->statusChanged(); break;
        case 1: _t->logMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->incomingData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 3: _t->outgoingData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->incomingChatMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 5: _t->enterGameMode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const ClientType(*)>(_a[3]))); break;
        case 6: _t->exitGameMode(); break;
        case 7: _t->gameCanBeStarted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->eventCardMovement((*reinterpret_cast< const CardMovementData(*)>(_a[1]))); break;
        case 9: _t->connectToServer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->disconnectFromServer(); break;
        case 11: _t->createGame((*reinterpret_cast< const CreateGameData(*)>(_a[1])),(*reinterpret_cast< const CreatePlayerData(*)>(_a[2]))); break;
        case 12: _t->joinGame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const CreatePlayerData(*)>(_a[4]))); break;
        case 13: _t->leaveGame(); break;
        case 14: _t->startGame(); break;
        case 15: _t->sendChatMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->drawCard(); break;
        case 17: _t->playCard((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->playCardWithPlayer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 19: _t->playCardWithCard((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 20: _t->playCardWithCardAndPlayer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 21: _t->playCardWithCards((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<int>(*)>(_a[2]))); break;
        case 22: _t->playCardWithPlayers((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<int>(*)>(_a[2]))); break;
        case 23: _t->useAbility(); break;
        case 24: _t->useAbility((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->useAbility((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        case 26: _t->useAbility((*reinterpret_cast< QList<int>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 27: _t->endTurn(); break;
        case 28: _t->pass(); break;
        case 29: _t->discardCard((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->connected(); break;
        case 31: _t->disconnected(); break;
        case 32: _t->recievedServerInfo((*reinterpret_cast< const ServerInfoData(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 25:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ServerConnection::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerConnection::statusChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerConnection::logMessage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerConnection::incomingData)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerConnection::outgoingData)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)(int , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerConnection::incomingChatMessage)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)(int , const QString & , const ClientType & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerConnection::enterGameMode)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerConnection::exitGameMode)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerConnection::gameCanBeStarted)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)(const CardMovementData & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerConnection::eventCardMovement)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject client::ServerConnection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_client__ServerConnection.data,
      qt_meta_data_client__ServerConnection,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *client::ServerConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *client::ServerConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_client__ServerConnection.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int client::ServerConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    }
    return _id;
}

// SIGNAL 0
void client::ServerConnection::statusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void client::ServerConnection::logMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void client::ServerConnection::incomingData(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void client::ServerConnection::outgoingData(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void client::ServerConnection::incomingChatMessage(int _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void client::ServerConnection::enterGameMode(int _t1, const QString & _t2, const ClientType & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void client::ServerConnection::exitGameMode()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void client::ServerConnection::gameCanBeStarted(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void client::ServerConnection::eventCardMovement(const CardMovementData & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
