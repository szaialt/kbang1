/****************************************************************************
** Meta object code from reading C++ file 'charactercassidygringo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../charactercassidygringo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'charactercassidygringo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CharacterCassidyGringo_t {
    QByteArrayData data[6];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CharacterCassidyGringo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CharacterCassidyGringo_t qt_meta_stringdata_CharacterCassidyGringo = {
    {
QT_MOC_LITERAL(0, 0, 22), // "CharacterCassidyGringo"
QT_MOC_LITERAL(1, 23, 5), // "onHit"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 10), // "lifePoints"
QT_MOC_LITERAL(4, 41, 7), // "Player*"
QT_MOC_LITERAL(5, 49, 8) // "causedBy"

    },
    "CharacterCassidyGringo\0onHit\0\0lifePoints\0"
    "Player*\0causedBy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CharacterCassidyGringo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x0a /* Public */,
       1,    1,   29,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void CharacterCassidyGringo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CharacterCassidyGringo *_t = static_cast<CharacterCassidyGringo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onHit((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Player*(*)>(_a[2]))); break;
        case 1: _t->onHit((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CharacterCassidyGringo::staticMetaObject = {
    { &CharacterBase::staticMetaObject, qt_meta_stringdata_CharacterCassidyGringo.data,
      qt_meta_data_CharacterCassidyGringo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CharacterCassidyGringo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CharacterCassidyGringo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CharacterCassidyGringo.stringdata0))
        return static_cast<void*>(const_cast< CharacterCassidyGringo*>(this));
    return CharacterBase::qt_metacast(_clname);
}

int CharacterCassidyGringo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CharacterBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
