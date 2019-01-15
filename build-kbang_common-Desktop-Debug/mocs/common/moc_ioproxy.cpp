/****************************************************************************
** Meta object code from reading C++ file 'ioproxy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/common/parser/ioproxy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ioproxy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IOProxy_t {
    QByteArrayData data[4];
    char stringdata[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IOProxy_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IOProxy_t qt_meta_stringdata_IOProxy = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 10),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 4)
    },
    "IOProxy\0networkOut\0\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IOProxy[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

       0        // eod
};

void IOProxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IOProxy *_t = static_cast<IOProxy *>(_o);
        switch (_id) {
        case 0: _t->networkOut((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IOProxy::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IOProxy::networkOut)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject IOProxy::staticMetaObject = {
    { &QIODevice::staticMetaObject, qt_meta_stringdata_IOProxy.data,
      qt_meta_data_IOProxy,  qt_static_metacall, 0, 0}
};


const QMetaObject *IOProxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IOProxy::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IOProxy.stringdata))
        return static_cast<void*>(const_cast< IOProxy*>(this));
    return QIODevice::qt_metacast(_clname);
}

int IOProxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QIODevice::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void IOProxy::networkOut(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
