/****************************************************************************
** Meta object code from reading C++ file 'parser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../parser/parser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Parser_t {
    QByteArrayData data[69];
    char stringdata0[1030];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Parser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Parser_t qt_meta_stringdata_Parser = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Parser"
QT_MOC_LITERAL(1, 7, 17), // "streamInitialized"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "terminated"
QT_MOC_LITERAL(4, 37, 12), // "incomingData"
QT_MOC_LITERAL(5, 50, 12), // "outgoingData"
QT_MOC_LITERAL(6, 63, 4), // "pong"
QT_MOC_LITERAL(7, 68, 7), // "latency"
QT_MOC_LITERAL(8, 76, 21), // "sigEventEnterGameMode"
QT_MOC_LITERAL(9, 98, 6), // "gameId"
QT_MOC_LITERAL(10, 105, 8), // "gameName"
QT_MOC_LITERAL(11, 114, 10), // "ClientType"
QT_MOC_LITERAL(12, 125, 20), // "sigEventExitGameMode"
QT_MOC_LITERAL(13, 146, 24), // "sigEventPlayerJoinedGame"
QT_MOC_LITERAL(14, 171, 16), // "PublicPlayerData"
QT_MOC_LITERAL(15, 188, 24), // "sigEventPlayerLeavedGame"
QT_MOC_LITERAL(16, 213, 8), // "playerId"
QT_MOC_LITERAL(17, 222, 20), // "sigEventPlayerUpdate"
QT_MOC_LITERAL(18, 243, 24), // "sigEventGameCanBeStarted"
QT_MOC_LITERAL(19, 268, 12), // "canBeStarted"
QT_MOC_LITERAL(20, 281, 23), // "sigEventGameStateChange"
QT_MOC_LITERAL(21, 305, 9), // "GameState"
QT_MOC_LITERAL(22, 315, 25), // "sigEventGameContextChange"
QT_MOC_LITERAL(23, 341, 15), // "GameContextData"
QT_MOC_LITERAL(24, 357, 16), // "sigEventGameSync"
QT_MOC_LITERAL(25, 374, 12), // "GameSyncData"
QT_MOC_LITERAL(26, 387, 24), // "sigEventLifePointsChange"
QT_MOC_LITERAL(27, 412, 10), // "lifePoints"
QT_MOC_LITERAL(28, 423, 18), // "sigEventPlayerDied"
QT_MOC_LITERAL(29, 442, 10), // "PlayerRole"
QT_MOC_LITERAL(30, 453, 4), // "role"
QT_MOC_LITERAL(31, 458, 20), // "sigEventCardMovement"
QT_MOC_LITERAL(32, 479, 16), // "CardMovementData"
QT_MOC_LITERAL(33, 496, 19), // "sigEventChatMessage"
QT_MOC_LITERAL(34, 516, 8), // "senderId"
QT_MOC_LITERAL(35, 525, 10), // "senderName"
QT_MOC_LITERAL(36, 536, 7), // "message"
QT_MOC_LITERAL(37, 544, 19), // "sigEventGameMessage"
QT_MOC_LITERAL(38, 564, 11), // "GameMessage"
QT_MOC_LITERAL(39, 576, 18), // "sigQueryServerInfo"
QT_MOC_LITERAL(40, 595, 11), // "QueryResult"
QT_MOC_LITERAL(41, 607, 20), // "sigQueryGameInfoList"
QT_MOC_LITERAL(42, 628, 16), // "sigQueryGameInfo"
QT_MOC_LITERAL(43, 645, 19), // "sigActionCreateGame"
QT_MOC_LITERAL(44, 665, 14), // "CreateGameData"
QT_MOC_LITERAL(45, 680, 16), // "CreatePlayerData"
QT_MOC_LITERAL(46, 697, 17), // "sigActionJoinGame"
QT_MOC_LITERAL(47, 715, 12), // "gamePassword"
QT_MOC_LITERAL(48, 728, 18), // "sigActionLeaveGame"
QT_MOC_LITERAL(49, 747, 18), // "sigActionStartGame"
QT_MOC_LITERAL(50, 766, 20), // "sigActionChatMessage"
QT_MOC_LITERAL(51, 787, 17), // "sigActionDrawCard"
QT_MOC_LITERAL(52, 805, 17), // "sigActionPlayCard"
QT_MOC_LITERAL(53, 823, 18), // "ActionPlayCardData"
QT_MOC_LITERAL(54, 842, 19), // "sigActionUseAbility"
QT_MOC_LITERAL(55, 862, 20), // "ActionUseAbilityData"
QT_MOC_LITERAL(56, 883, 16), // "sigActionEndTurn"
QT_MOC_LITERAL(57, 900, 13), // "sigActionPass"
QT_MOC_LITERAL(58, 914, 16), // "sigActionDiscard"
QT_MOC_LITERAL(59, 931, 6), // "cardId"
QT_MOC_LITERAL(60, 938, 12), // "attachSocket"
QT_MOC_LITERAL(61, 951, 10), // "QIODevice*"
QT_MOC_LITERAL(62, 962, 6), // "socket"
QT_MOC_LITERAL(63, 969, 12), // "detachSocket"
QT_MOC_LITERAL(64, 982, 9), // "terminate"
QT_MOC_LITERAL(65, 992, 4), // "ping"
QT_MOC_LITERAL(66, 997, 13), // "sendKeepAlive"
QT_MOC_LITERAL(67, 1011, 8), // "readData"
QT_MOC_LITERAL(68, 1020, 9) // "writeData"

    },
    "Parser\0streamInitialized\0\0terminated\0"
    "incomingData\0outgoingData\0pong\0latency\0"
    "sigEventEnterGameMode\0gameId\0gameName\0"
    "ClientType\0sigEventExitGameMode\0"
    "sigEventPlayerJoinedGame\0PublicPlayerData\0"
    "sigEventPlayerLeavedGame\0playerId\0"
    "sigEventPlayerUpdate\0sigEventGameCanBeStarted\0"
    "canBeStarted\0sigEventGameStateChange\0"
    "GameState\0sigEventGameContextChange\0"
    "GameContextData\0sigEventGameSync\0"
    "GameSyncData\0sigEventLifePointsChange\0"
    "lifePoints\0sigEventPlayerDied\0PlayerRole\0"
    "role\0sigEventCardMovement\0CardMovementData\0"
    "sigEventChatMessage\0senderId\0senderName\0"
    "message\0sigEventGameMessage\0GameMessage\0"
    "sigQueryServerInfo\0QueryResult\0"
    "sigQueryGameInfoList\0sigQueryGameInfo\0"
    "sigActionCreateGame\0CreateGameData\0"
    "CreatePlayerData\0sigActionJoinGame\0"
    "gamePassword\0sigActionLeaveGame\0"
    "sigActionStartGame\0sigActionChatMessage\0"
    "sigActionDrawCard\0sigActionPlayCard\0"
    "ActionPlayCardData\0sigActionUseAbility\0"
    "ActionUseAbilityData\0sigActionEndTurn\0"
    "sigActionPass\0sigActionDiscard\0cardId\0"
    "attachSocket\0QIODevice*\0socket\0"
    "detachSocket\0terminate\0ping\0sendKeepAlive\0"
    "readData\0writeData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Parser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      40,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      33,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  214,    2, 0x06 /* Public */,
       3,    0,  215,    2, 0x06 /* Public */,
       4,    1,  216,    2, 0x06 /* Public */,
       5,    1,  219,    2, 0x06 /* Public */,
       6,    1,  222,    2, 0x06 /* Public */,
       8,    3,  225,    2, 0x06 /* Public */,
      12,    0,  232,    2, 0x06 /* Public */,
      13,    1,  233,    2, 0x06 /* Public */,
      15,    1,  236,    2, 0x06 /* Public */,
      17,    1,  239,    2, 0x06 /* Public */,
      18,    1,  242,    2, 0x06 /* Public */,
      20,    1,  245,    2, 0x06 /* Public */,
      22,    1,  248,    2, 0x06 /* Public */,
      24,    1,  251,    2, 0x06 /* Public */,
      26,    2,  254,    2, 0x06 /* Public */,
      28,    2,  259,    2, 0x06 /* Public */,
      31,    1,  264,    2, 0x06 /* Public */,
      33,    3,  267,    2, 0x06 /* Public */,
      37,    1,  274,    2, 0x06 /* Public */,
      39,    1,  277,    2, 0x06 /* Public */,
      41,    1,  280,    2, 0x06 /* Public */,
      42,    2,  283,    2, 0x06 /* Public */,
      43,    2,  288,    2, 0x06 /* Public */,
      46,    4,  293,    2, 0x06 /* Public */,
      48,    0,  302,    2, 0x06 /* Public */,
      49,    0,  303,    2, 0x06 /* Public */,
      50,    1,  304,    2, 0x06 /* Public */,
      51,    0,  307,    2, 0x06 /* Public */,
      52,    1,  308,    2, 0x06 /* Public */,
      54,    1,  311,    2, 0x06 /* Public */,
      56,    0,  314,    2, 0x06 /* Public */,
      57,    0,  315,    2, 0x06 /* Public */,
      58,    1,  316,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      60,    1,  319,    2, 0x0a /* Public */,
      63,    0,  322,    2, 0x0a /* Public */,
      64,    0,  323,    2, 0x0a /* Public */,
      65,    0,  324,    2, 0x0a /* Public */,
      66,    0,  325,    2, 0x0a /* Public */,
      67,    0,  326,    2, 0x08 /* Private */,
      68,    1,  327,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 11,    9,   10,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, 0x80000000 | 21,    2,
    QMetaType::Void, 0x80000000 | 23,    2,
    QMetaType::Void, 0x80000000 | 25,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   16,   27,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 29,   16,   30,
    QMetaType::Void, 0x80000000 | 32,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,   34,   35,   36,
    QMetaType::Void, 0x80000000 | 38,    2,
    QMetaType::Void, 0x80000000 | 40,    2,
    QMetaType::Void, 0x80000000 | 40,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 40,    9,    2,
    QMetaType::Void, 0x80000000 | 44, 0x80000000 | 45,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, 0x80000000 | 45,    9,   16,   47,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   36,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 53,    2,
    QMetaType::Void, 0x80000000 | 55,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   59,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 61,   62,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,

       0        // eod
};

void Parser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Parser *_t = static_cast<Parser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->streamInitialized(); break;
        case 1: _t->terminated(); break;
        case 2: _t->incomingData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 3: _t->outgoingData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->pong((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->sigEventEnterGameMode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< ClientType(*)>(_a[3]))); break;
        case 6: _t->sigEventExitGameMode(); break;
        case 7: _t->sigEventPlayerJoinedGame((*reinterpret_cast< const PublicPlayerData(*)>(_a[1]))); break;
        case 8: _t->sigEventPlayerLeavedGame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->sigEventPlayerUpdate((*reinterpret_cast< const PublicPlayerData(*)>(_a[1]))); break;
        case 10: _t->sigEventGameCanBeStarted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->sigEventGameStateChange((*reinterpret_cast< const GameState(*)>(_a[1]))); break;
        case 12: _t->sigEventGameContextChange((*reinterpret_cast< const GameContextData(*)>(_a[1]))); break;
        case 13: _t->sigEventGameSync((*reinterpret_cast< const GameSyncData(*)>(_a[1]))); break;
        case 14: _t->sigEventLifePointsChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->sigEventPlayerDied((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< PlayerRole(*)>(_a[2]))); break;
        case 16: _t->sigEventCardMovement((*reinterpret_cast< const CardMovementData(*)>(_a[1]))); break;
        case 17: _t->sigEventChatMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 18: _t->sigEventGameMessage((*reinterpret_cast< const GameMessage(*)>(_a[1]))); break;
        case 19: _t->sigQueryServerInfo((*reinterpret_cast< const QueryResult(*)>(_a[1]))); break;
        case 20: _t->sigQueryGameInfoList((*reinterpret_cast< const QueryResult(*)>(_a[1]))); break;
        case 21: _t->sigQueryGameInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QueryResult(*)>(_a[2]))); break;
        case 22: _t->sigActionCreateGame((*reinterpret_cast< const CreateGameData(*)>(_a[1])),(*reinterpret_cast< const CreatePlayerData(*)>(_a[2]))); break;
        case 23: _t->sigActionJoinGame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const CreatePlayerData(*)>(_a[4]))); break;
        case 24: _t->sigActionLeaveGame(); break;
        case 25: _t->sigActionStartGame(); break;
        case 26: _t->sigActionChatMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 27: _t->sigActionDrawCard(); break;
        case 28: _t->sigActionPlayCard((*reinterpret_cast< const ActionPlayCardData(*)>(_a[1]))); break;
        case 29: _t->sigActionUseAbility((*reinterpret_cast< const ActionUseAbilityData(*)>(_a[1]))); break;
        case 30: _t->sigActionEndTurn(); break;
        case 31: _t->sigActionPass(); break;
        case 32: _t->sigActionDiscard((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->attachSocket((*reinterpret_cast< QIODevice*(*)>(_a[1]))); break;
        case 34: _t->detachSocket(); break;
        case 35: _t->terminate(); break;
        case 36: _t->ping(); break;
        case 37: _t->sendKeepAlive(); break;
        case 38: _t->readData(); break;
        case 39: _t->writeData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 33:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QIODevice* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Parser::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::streamInitialized)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Parser::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::terminated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Parser::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::incomingData)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Parser::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::outgoingData)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Parser::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::pong)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Parser::*)(int , const QString & , ClientType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigEventEnterGameMode)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Parser::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigEventExitGameMode)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Parser::*)(const PublicPlayerData & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigEventPlayerJoinedGame)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Parser::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigEventPlayerLeavedGame)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Parser::*)(const PublicPlayerData & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigEventPlayerUpdate)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Parser::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigEventGameCanBeStarted)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Parser::*)(const GameState & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigEventGameStateChange)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Parser::*)(const GameContextData & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigEventGameContextChange)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Parser::*)(const GameSyncData & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigEventGameSync)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (Parser::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigEventLifePointsChange)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (Parser::*)(int , PlayerRole );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigEventPlayerDied)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (Parser::*)(const CardMovementData & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigEventCardMovement)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (Parser::*)(int , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigEventChatMessage)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (Parser::*)(const GameMessage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigEventGameMessage)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (Parser::*)(const QueryResult & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigQueryServerInfo)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (Parser::*)(const QueryResult & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigQueryGameInfoList)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (Parser::*)(int , const QueryResult & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigQueryGameInfo)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (Parser::*)(const CreateGameData & , const CreatePlayerData & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigActionCreateGame)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (Parser::*)(int , int , const QString & , const CreatePlayerData & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigActionJoinGame)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (Parser::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigActionLeaveGame)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (Parser::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigActionStartGame)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (Parser::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigActionChatMessage)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (Parser::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigActionDrawCard)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (Parser::*)(const ActionPlayCardData & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigActionPlayCard)) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (Parser::*)(const ActionUseAbilityData & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigActionUseAbility)) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (Parser::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigActionEndTurn)) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (Parser::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigActionPass)) {
                *result = 31;
                return;
            }
        }
        {
            using _t = void (Parser::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::sigActionDiscard)) {
                *result = 32;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Parser::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Parser.data,
      qt_meta_data_Parser,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Parser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Parser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Parser.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Parser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    }
    return _id;
}

// SIGNAL 0
void Parser::streamInitialized()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Parser::terminated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Parser::incomingData(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Parser::outgoingData(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Parser::pong(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Parser::sigEventEnterGameMode(int _t1, const QString & _t2, ClientType _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Parser::sigEventExitGameMode()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Parser::sigEventPlayerJoinedGame(const PublicPlayerData & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Parser::sigEventPlayerLeavedGame(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Parser::sigEventPlayerUpdate(const PublicPlayerData & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Parser::sigEventGameCanBeStarted(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Parser::sigEventGameStateChange(const GameState & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Parser::sigEventGameContextChange(const GameContextData & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Parser::sigEventGameSync(const GameSyncData & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Parser::sigEventLifePointsChange(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Parser::sigEventPlayerDied(int _t1, PlayerRole _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Parser::sigEventCardMovement(const CardMovementData & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void Parser::sigEventChatMessage(int _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void Parser::sigEventGameMessage(const GameMessage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void Parser::sigQueryServerInfo(const QueryResult & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void Parser::sigQueryGameInfoList(const QueryResult & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void Parser::sigQueryGameInfo(int _t1, const QueryResult & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void Parser::sigActionCreateGame(const CreateGameData & _t1, const CreatePlayerData & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void Parser::sigActionJoinGame(int _t1, int _t2, const QString & _t3, const CreatePlayerData & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void Parser::sigActionLeaveGame()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void Parser::sigActionStartGame()
{
    QMetaObject::activate(this, &staticMetaObject, 25, nullptr);
}

// SIGNAL 26
void Parser::sigActionChatMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void Parser::sigActionDrawCard()
{
    QMetaObject::activate(this, &staticMetaObject, 27, nullptr);
}

// SIGNAL 28
void Parser::sigActionPlayCard(const ActionPlayCardData & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void Parser::sigActionUseAbility(const ActionUseAbilityData & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void Parser::sigActionEndTurn()
{
    QMetaObject::activate(this, &staticMetaObject, 30, nullptr);
}

// SIGNAL 31
void Parser::sigActionPass()
{
    QMetaObject::activate(this, &staticMetaObject, 31, nullptr);
}

// SIGNAL 32
void Parser::sigActionDiscard(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
