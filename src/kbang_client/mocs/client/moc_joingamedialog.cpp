/****************************************************************************
** Meta object code from reading C++ file 'joingamedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../joingamedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'joingamedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_client__JoinGameDialog_t {
    QByteArrayData data[20];
    char stringdata0[306];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_client__JoinGameDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_client__JoinGameDialog_t qt_meta_stringdata_client__JoinGameDialog = {
    {
QT_MOC_LITERAL(0, 0, 22), // "client::JoinGameDialog"
QT_MOC_LITERAL(1, 23, 8), // "joinGame"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 6), // "gameId"
QT_MOC_LITERAL(4, 40, 8), // "playerId"
QT_MOC_LITERAL(5, 49, 8), // "password"
QT_MOC_LITERAL(6, 58, 16), // "CreatePlayerData"
QT_MOC_LITERAL(7, 75, 15), // "refreshGameList"
QT_MOC_LITERAL(8, 91, 14), // "updateGameList"
QT_MOC_LITERAL(9, 106, 16), // "GameInfoListData"
QT_MOC_LITERAL(10, 123, 10), // "updateGame"
QT_MOC_LITERAL(11, 134, 12), // "GameInfoData"
QT_MOC_LITERAL(12, 147, 27), // "on_gameListView_itemClicked"
QT_MOC_LITERAL(13, 175, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(14, 192, 4), // "item"
QT_MOC_LITERAL(15, 197, 6), // "column"
QT_MOC_LITERAL(16, 204, 29), // "on_playerListView_itemClicked"
QT_MOC_LITERAL(17, 234, 25), // "on_pushButtonPlay_clicked"
QT_MOC_LITERAL(18, 260, 29), // "on_pushButtonSpectate_clicked"
QT_MOC_LITERAL(19, 290, 15) // "setButtonsState"

    },
    "client::JoinGameDialog\0joinGame\0\0"
    "gameId\0playerId\0password\0CreatePlayerData\0"
    "refreshGameList\0updateGameList\0"
    "GameInfoListData\0updateGame\0GameInfoData\0"
    "on_gameListView_itemClicked\0"
    "QTreeWidgetItem*\0item\0column\0"
    "on_playerListView_itemClicked\0"
    "on_pushButtonPlay_clicked\0"
    "on_pushButtonSpectate_clicked\0"
    "setButtonsState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client__JoinGameDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   68,    2, 0x0a /* Public */,
       8,    1,   69,    2, 0x0a /* Public */,
      10,    1,   72,    2, 0x0a /* Public */,
      12,    2,   75,    2, 0x0a /* Public */,
      16,    2,   80,    2, 0x0a /* Public */,
      17,    0,   85,    2, 0x0a /* Public */,
      18,    0,   86,    2, 0x0a /* Public */,
      19,    0,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, 0x80000000 | 6,    3,    4,    5,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int,   14,   15,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void client::JoinGameDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        JoinGameDialog *_t = static_cast<JoinGameDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->joinGame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const CreatePlayerData(*)>(_a[4]))); break;
        case 1: _t->refreshGameList(); break;
        case 2: _t->updateGameList((*reinterpret_cast< const GameInfoListData(*)>(_a[1]))); break;
        case 3: _t->updateGame((*reinterpret_cast< const GameInfoData(*)>(_a[1]))); break;
        case 4: _t->on_gameListView_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->on_playerListView_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->on_pushButtonPlay_clicked(); break;
        case 7: _t->on_pushButtonSpectate_clicked(); break;
        case 8: _t->setButtonsState(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (JoinGameDialog::*)(int , int , const QString & , const CreatePlayerData & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JoinGameDialog::joinGame)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject client::JoinGameDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_client__JoinGameDialog.data,
      qt_meta_data_client__JoinGameDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *client::JoinGameDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *client::JoinGameDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_client__JoinGameDialog.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::JoinGameDialog"))
        return static_cast< Ui::JoinGameDialog*>(this);
    return QDialog::qt_metacast(_clname);
}

int client::JoinGameDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void client::JoinGameDialog::joinGame(int _t1, int _t2, const QString & _t3, const CreatePlayerData & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
