/****************************************************************************
** Meta object code from reading C++ file 'MinesMulti.h'
**
** Created: Wed Mar 14 00:17:58 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MinesMulti.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MinesMulti.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MinesMulti[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      21,   11,   11,   11, 0x08,
      30,   11,   11,   11, 0x08,
      39,   11,   11,   11, 0x08,
      54,   11,   11,   11, 0x08,
      68,   66,   11,   11, 0x08,
      85,   11,   11,   11, 0x08,
      99,   97,   11,   11, 0x08,
     123,   11,   11,   11, 0x08,
     130,   11,   11,   11, 0x08,
     136,   11,   11,   11, 0x08,
     148,  144,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MinesMulti[] = {
    "MinesMulti\0\0Server()\0Client()\0Senden()\0"
    "FeldSichtbar()\0Verbinden()\0D\0"
    "read(QByteArray)\0MineLegen()\0m\0"
    "Minerhalten(QByteArray)\0LOSE()\0WIN()\0"
    "crypt()\0c,p\0finden(int,QPoint)\0"
};

const QMetaObject MinesMulti::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MinesMulti,
      qt_meta_data_MinesMulti, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MinesMulti::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MinesMulti::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MinesMulti::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MinesMulti))
        return static_cast<void*>(const_cast< MinesMulti*>(this));
    if (!strcmp(_clname, "Ui::MainWindow"))
        return static_cast< Ui::MainWindow*>(const_cast< MinesMulti*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MinesMulti::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Server(); break;
        case 1: Client(); break;
        case 2: Senden(); break;
        case 3: FeldSichtbar(); break;
        case 4: Verbinden(); break;
        case 5: read((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: MineLegen(); break;
        case 7: Minerhalten((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: LOSE(); break;
        case 9: WIN(); break;
        case 10: crypt(); break;
        case 11: finden((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
