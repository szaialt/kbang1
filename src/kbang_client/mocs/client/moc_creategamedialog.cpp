/****************************************************************************
** Meta object code from reading C++ file 'creategamedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../creategamedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'creategamedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_client__CreateGameDialog_t {
    QByteArrayData data[8];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_client__CreateGameDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_client__CreateGameDialog_t qt_meta_stringdata_client__CreateGameDialog = {
    {
QT_MOC_LITERAL(0, 0, 24), // "client::CreateGameDialog"
QT_MOC_LITERAL(1, 25, 10), // "createGame"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 14), // "CreateGameData"
QT_MOC_LITERAL(4, 52, 16), // "CreatePlayerData"
QT_MOC_LITERAL(5, 69, 19), // "playerCountsChanged"
QT_MOC_LITERAL(6, 89, 13), // "validateInput"
QT_MOC_LITERAL(7, 103, 27) // "on_pushButtonCreate_clicked"

    },
    "client::CreateGameDialog\0createGame\0"
    "\0CreateGameData\0CreatePlayerData\0"
    "playerCountsChanged\0validateInput\0"
    "on_pushButtonCreate_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client__CreateGameDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   39,    2, 0x08 /* Private */,
       6,    0,   40,    2, 0x08 /* Private */,
       7,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void client::CreateGameDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateGameDialog *_t = static_cast<CreateGameDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createGame((*reinterpret_cast< const CreateGameData(*)>(_a[1])),(*reinterpret_cast< const CreatePlayerData(*)>(_a[2]))); break;
        case 1: _t->playerCountsChanged(); break;
        case 2: _t->validateInput(); break;
        case 3: _t->on_pushButtonCreate_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CreateGameDialog::*)(const CreateGameData & , const CreatePlayerData & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CreateGameDialog::createGame)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject client::CreateGameDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_client__CreateGameDialog.data,
      qt_meta_data_client__CreateGameDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *client::CreateGameDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *client::CreateGameDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_client__CreateGameDialog.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::CreateGameDialog"))
        return static_cast< Ui::CreateGameDialog*>(this);
    return QDialog::qt_metacast(_clname);
}

int client::CreateGameDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void client::CreateGameDialog::createGame(const CreateGameData & _t1, const CreatePlayerData & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
