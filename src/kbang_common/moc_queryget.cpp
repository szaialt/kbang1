/****************************************************************************
** Meta object code from reading C++ file 'queryget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "parser/queryget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'queryget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QueryGet_t {
    QByteArrayData data[8];
    char stringdata[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QueryGet_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QueryGet_t qt_meta_stringdata_QueryGet = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 6),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 14),
QT_MOC_LITERAL(4, 32, 12),
QT_MOC_LITERAL(5, 45, 16),
QT_MOC_LITERAL(6, 62, 4),
QT_MOC_LITERAL(7, 67, 7)
    },
    "QueryGet\0result\0\0ServerInfoData\0"
    "GameInfoData\0GameInfoListData\0pong\0"
    "latency"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QueryGet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       1,    1,   37,    2, 0x06 /* Public */,
       1,    1,   40,    2, 0x06 /* Public */,
       6,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void QueryGet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QueryGet *_t = static_cast<QueryGet *>(_o);
        switch (_id) {
        case 0: _t->result((*reinterpret_cast< const ServerInfoData(*)>(_a[1]))); break;
        case 1: _t->result((*reinterpret_cast< const GameInfoData(*)>(_a[1]))); break;
        case 2: _t->result((*reinterpret_cast< const GameInfoListData(*)>(_a[1]))); break;
        case 3: _t->pong((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QueryGet::*_t)(const ServerInfoData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QueryGet::result)) {
                *result = 0;
            }
        }
        {
            typedef void (QueryGet::*_t)(const GameInfoData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QueryGet::result)) {
                *result = 1;
            }
        }
        {
            typedef void (QueryGet::*_t)(const GameInfoListData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QueryGet::result)) {
                *result = 2;
            }
        }
        {
            typedef void (QueryGet::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QueryGet::pong)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject QueryGet::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QueryGet.data,
      qt_meta_data_QueryGet,  qt_static_metacall, 0, 0}
};


const QMetaObject *QueryGet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QueryGet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QueryGet.stringdata))
        return static_cast<void*>(const_cast< QueryGet*>(this));
    return QObject::qt_metacast(_clname);
}

int QueryGet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void QueryGet::result(const ServerInfoData & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QueryGet::result(const GameInfoData & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QueryGet::result(const GameInfoListData & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QueryGet::pong(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
