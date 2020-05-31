/****************************************************************************
** Meta object code from reading C++ file 'localplayerwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../localplayerwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'localplayerwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_client__LocalPlayerWidget_t {
    QByteArrayData data[5];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_client__LocalPlayerWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_client__LocalPlayerWidget_t qt_meta_stringdata_client__LocalPlayerWidget = {
    {
QT_MOC_LITERAL(0, 0, 25), // "client::LocalPlayerWidget"
QT_MOC_LITERAL(1, 26, 16), // "onEndTurnClicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 13), // "onPassClicked"
QT_MOC_LITERAL(4, 58, 16) // "onDiscardClicked"

    },
    "client::LocalPlayerWidget\0onEndTurnClicked\0"
    "\0onPassClicked\0onDiscardClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client__LocalPlayerWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void client::LocalPlayerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LocalPlayerWidget *_t = static_cast<LocalPlayerWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onEndTurnClicked(); break;
        case 1: _t->onPassClicked(); break;
        case 2: _t->onDiscardClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject client::LocalPlayerWidget::staticMetaObject = {
    { &PlayerWidget::staticMetaObject, qt_meta_stringdata_client__LocalPlayerWidget.data,
      qt_meta_data_client__LocalPlayerWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *client::LocalPlayerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *client::LocalPlayerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_client__LocalPlayerWidget.stringdata0))
        return static_cast<void*>(const_cast< LocalPlayerWidget*>(this));
    if (!strcmp(_clname, "Ui::LocalPlayerWidget"))
        return static_cast< Ui::LocalPlayerWidget*>(const_cast< LocalPlayerWidget*>(this));
    return PlayerWidget::qt_metacast(_clname);
}

int client::LocalPlayerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PlayerWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
