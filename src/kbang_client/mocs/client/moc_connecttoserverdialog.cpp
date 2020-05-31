/****************************************************************************
** Meta object code from reading C++ file 'connecttoserverdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../connecttoserverdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connecttoserverdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_client__ConnectToServerDialog_t {
    QByteArrayData data[12];
    char stringdata0[277];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_client__ConnectToServerDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_client__ConnectToServerDialog_t qt_meta_stringdata_client__ConnectToServerDialog = {
    {
QT_MOC_LITERAL(0, 0, 29), // "client::ConnectToServerDialog"
QT_MOC_LITERAL(1, 30, 15), // "connectToServer"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 10), // "serverHost"
QT_MOC_LITERAL(4, 58, 10), // "serverPort"
QT_MOC_LITERAL(5, 69, 32), // "on_serverList_currentItemChanged"
QT_MOC_LITERAL(6, 102, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(7, 119, 31), // "on_serverList_itemDoubleClicked"
QT_MOC_LITERAL(8, 151, 30), // "on_pushButtonAddServer_clicked"
QT_MOC_LITERAL(9, 182, 31), // "on_pushButtonEditServer_clicked"
QT_MOC_LITERAL(10, 214, 33), // "on_pushButtonDeleteServer_cli..."
QT_MOC_LITERAL(11, 248, 28) // "on_pushButtonConnect_clicked"

    },
    "client::ConnectToServerDialog\0"
    "connectToServer\0\0serverHost\0serverPort\0"
    "on_serverList_currentItemChanged\0"
    "QTreeWidgetItem*\0on_serverList_itemDoubleClicked\0"
    "on_pushButtonAddServer_clicked\0"
    "on_pushButtonEditServer_clicked\0"
    "on_pushButtonDeleteServer_clicked\0"
    "on_pushButtonConnect_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client__ConnectToServerDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   54,    2, 0x08 /* Private */,
       7,    2,   59,    2, 0x08 /* Private */,
       8,    0,   64,    2, 0x08 /* Private */,
       9,    0,   65,    2, 0x08 /* Private */,
      10,    0,   66,    2, 0x08 /* Private */,
      11,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    2,    2,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void client::ConnectToServerDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConnectToServerDialog *_t = static_cast<ConnectToServerDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectToServer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_serverList_currentItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        case 2: _t->on_serverList_itemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_pushButtonAddServer_clicked(); break;
        case 4: _t->on_pushButtonEditServer_clicked(); break;
        case 5: _t->on_pushButtonDeleteServer_clicked(); break;
        case 6: _t->on_pushButtonConnect_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ConnectToServerDialog::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConnectToServerDialog::connectToServer)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject client::ConnectToServerDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_client__ConnectToServerDialog.data,
      qt_meta_data_client__ConnectToServerDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *client::ConnectToServerDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *client::ConnectToServerDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_client__ConnectToServerDialog.stringdata0))
        return static_cast<void*>(const_cast< ConnectToServerDialog*>(this));
    if (!strcmp(_clname, "Ui::ConnectToServerDialog"))
        return static_cast< Ui::ConnectToServerDialog*>(const_cast< ConnectToServerDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int client::ConnectToServerDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void client::ConnectToServerDialog::connectToServer(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
