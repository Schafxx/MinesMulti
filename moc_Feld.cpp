/****************************************************************************
** Meta object code from reading C++ file 'Feld.h'
**
** Created: Sun Mar 11 21:00:48 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Feld.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Feld.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Feld[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,
      27,   18,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,    5,    5,    5, 0x0a,
      60,    5,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Feld[] = {
    "Feld\0\0Explosion()\0Anzahl,p\0"
    "notExplosion(int,QPoint)\0klick()\0"
    "deaktivieren()\0"
};

const QMetaObject Feld::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_Feld,
      qt_meta_data_Feld, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Feld::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Feld::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Feld::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Feld))
        return static_cast<void*>(const_cast< Feld*>(this));
    return QPushButton::qt_metacast(_clname);
}

int Feld::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Explosion(); break;
        case 1: notExplosion((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 2: klick(); break;
        case 3: deaktivieren(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Feld::Explosion()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Feld::notExplosion(int _t1, QPoint _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
