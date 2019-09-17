/****************************************************************************
** Meta object code from reading C++ file 'sdiprogramkomasko_novosad.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../lab_3/sdiprogramkomasko_novosad.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sdiprogramkomasko_novosad.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SDIProgramKomasko_Novosad_t {
    QByteArrayData data[5];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SDIProgramKomasko_Novosad_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SDIProgramKomasko_Novosad_t qt_meta_stringdata_SDIProgramKomasko_Novosad = {
    {
QT_MOC_LITERAL(0, 0, 25), // "SDIProgramKomasko_Novosad"
QT_MOC_LITERAL(1, 26, 9), // "slotAbout"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 21), // "slotChangeWindowTitle"
QT_MOC_LITERAL(4, 59, 3) // "str"

    },
    "SDIProgramKomasko_Novosad\0slotAbout\0"
    "\0slotChangeWindowTitle\0str"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SDIProgramKomasko_Novosad[] = {

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
       1,    0,   24,    2, 0x0a /* Public */,
       3,    1,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void SDIProgramKomasko_Novosad::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SDIProgramKomasko_Novosad *_t = static_cast<SDIProgramKomasko_Novosad *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotAbout(); break;
        case 1: _t->slotChangeWindowTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SDIProgramKomasko_Novosad::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SDIProgramKomasko_Novosad.data,
      qt_meta_data_SDIProgramKomasko_Novosad,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SDIProgramKomasko_Novosad::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SDIProgramKomasko_Novosad::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SDIProgramKomasko_Novosad.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SDIProgramKomasko_Novosad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
