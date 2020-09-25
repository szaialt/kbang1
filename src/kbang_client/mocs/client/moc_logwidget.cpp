/****************************************************************************
** Meta object code from reading C++ file 'logwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../logwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_client__LogWidget_t {
    QByteArrayData data[7];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_client__LogWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_client__LogWidget_t qt_meta_stringdata_client__LogWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "client::LogWidget"
QT_MOC_LITERAL(1, 18, 16), // "appendLogMessage"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 7), // "message"
QT_MOC_LITERAL(4, 44, 18), // "appendIncomingData"
QT_MOC_LITERAL(5, 63, 4), // "data"
QT_MOC_LITERAL(6, 68, 18) // "appendOutgoingData"

    },
    "client::LogWidget\0appendLogMessage\0\0"
    "message\0appendIncomingData\0data\0"
    "appendOutgoingData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client__LogWidget[] = {

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
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       6,    1,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void, QMetaType::QByteArray,    5,

       0        // eod
};

void client::LogWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LogWidget *_t = static_cast<LogWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->appendLogMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->appendIncomingData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 2: _t->appendOutgoingData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject client::LogWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_client__LogWidget.data,
      qt_meta_data_client__LogWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *client::LogWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *client::LogWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_client__LogWidget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::LogWidget"))
        return static_cast< Ui::LogWidget*>(this);
    return QWidget::qt_metacast(_clname);
}

int client::LogWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
