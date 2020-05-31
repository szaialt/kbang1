/****************************************************************************
** Meta object code from reading C++ file 'cardbeer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../cardbeer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cardbeer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CardBeer_t {
    QByteArrayData data[1];
    char stringdata0[9];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CardBeer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CardBeer_t qt_meta_stringdata_CardBeer = {
    {
QT_MOC_LITERAL(0, 0, 8) // "CardBeer"

    },
    "CardBeer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CardBeer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void CardBeer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject CardBeer::staticMetaObject = {
    { &PlayingCard::staticMetaObject, qt_meta_stringdata_CardBeer.data,
      qt_meta_data_CardBeer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CardBeer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CardBeer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CardBeer.stringdata0))
        return static_cast<void*>(const_cast< CardBeer*>(this));
    return PlayingCard::qt_metacast(_clname);
}

int CardBeer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PlayingCard::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_BeerRescue_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BeerRescue_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BeerRescue_t qt_meta_stringdata_BeerRescue = {
    {
QT_MOC_LITERAL(0, 0, 10) // "BeerRescue"

    },
    "BeerRescue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BeerRescue[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void BeerRescue::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject BeerRescue::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BeerRescue.data,
      qt_meta_data_BeerRescue,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BeerRescue::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BeerRescue::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BeerRescue.stringdata0))
        return static_cast<void*>(const_cast< BeerRescue*>(this));
    if (!strcmp(_clname, "ReactionHandler"))
        return static_cast< ReactionHandler*>(const_cast< BeerRescue*>(this));
    return QObject::qt_metacast(_clname);
}

int BeerRescue::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
