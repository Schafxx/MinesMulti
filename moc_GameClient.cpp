/****************************************************************************
** Meta object code from reading C++ file 'GameClient.h'
**
** Created: Wed Mar 14 00:17:56 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GameClient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameClient[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GameClient[] = {
    "GameClient\0\0D\0rec(QByteArray)\0read()\0"
};

const QMetaObject GameClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameClient,
      qt_meta_data_GameClient, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameClient))
        return static_cast<void*>(const_cast< GameClient*>(this));
    return QObject::qt_metacast(_clname);
}

int GameClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: rec((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: read(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GameClient::rec(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
