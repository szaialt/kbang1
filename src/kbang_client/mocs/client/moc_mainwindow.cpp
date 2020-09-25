/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_client__MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[260];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_client__MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_client__MainWindow_t qt_meta_stringdata_client__MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 18), // "client::MainWindow"
QT_MOC_LITERAL(1, 19, 25), // "showConnectToServerDialog"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 20), // "disconnectFromServer"
QT_MOC_LITERAL(4, 67, 20), // "showCreateGameDialog"
QT_MOC_LITERAL(5, 88, 10), // "createGame"
QT_MOC_LITERAL(6, 99, 14), // "CreateGameData"
QT_MOC_LITERAL(7, 114, 16), // "CreatePlayerData"
QT_MOC_LITERAL(8, 131, 18), // "showJoinGameDialog"
QT_MOC_LITERAL(9, 150, 9), // "leaveGame"
QT_MOC_LITERAL(10, 160, 15), // "showAboutDialog"
QT_MOC_LITERAL(11, 176, 13), // "enterGameMode"
QT_MOC_LITERAL(12, 190, 6), // "gameId"
QT_MOC_LITERAL(13, 197, 8), // "gameName"
QT_MOC_LITERAL(14, 206, 10), // "ClientType"
QT_MOC_LITERAL(15, 217, 12), // "exitGameMode"
QT_MOC_LITERAL(16, 230, 29) // "serverConnectionStatusChanged"

    },
    "client::MainWindow\0showConnectToServerDialog\0"
    "\0disconnectFromServer\0showCreateGameDialog\0"
    "createGame\0CreateGameData\0CreatePlayerData\0"
    "showJoinGameDialog\0leaveGame\0"
    "showAboutDialog\0enterGameMode\0gameId\0"
    "gameName\0ClientType\0exitGameMode\0"
    "serverConnectionStatusChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client__MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    2,   67,    2, 0x0a /* Public */,
       8,    0,   72,    2, 0x0a /* Public */,
       9,    0,   73,    2, 0x0a /* Public */,
      10,    0,   74,    2, 0x0a /* Public */,
      11,    3,   75,    2, 0x0a /* Public */,
      15,    0,   82,    2, 0x0a /* Public */,
      16,    0,   83,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 7,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 14,   12,   13,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void client::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showConnectToServerDialog(); break;
        case 1: _t->disconnectFromServer(); break;
        case 2: _t->showCreateGameDialog(); break;
        case 3: _t->createGame((*reinterpret_cast< CreateGameData(*)>(_a[1])),(*reinterpret_cast< CreatePlayerData(*)>(_a[2]))); break;
        case 4: _t->showJoinGameDialog(); break;
        case 5: _t->leaveGame(); break;
        case 6: _t->showAboutDialog(); break;
        case 7: _t->enterGameMode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< ClientType(*)>(_a[3]))); break;
        case 8: _t->exitGameMode(); break;
        case 9: _t->serverConnectionStatusChanged(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject client::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_client__MainWindow.data,
      qt_meta_data_client__MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *client::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *client::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_client__MainWindow.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::MainWindow"))
        return static_cast< Ui::MainWindow*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int client::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
