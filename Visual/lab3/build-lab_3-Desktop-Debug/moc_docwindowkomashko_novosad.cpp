/****************************************************************************
** Meta object code from reading C++ file 'docwindowkomashko_novosad.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../lab_3/docwindowkomashko_novosad.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'docwindowkomashko_novosad.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DocWindowKomashko_Novosad_t {
    QByteArrayData data[7];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DocWindowKomashko_Novosad_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DocWindowKomashko_Novosad_t qt_meta_stringdata_DocWindowKomashko_Novosad = {
    {
QT_MOC_LITERAL(0, 0, 25), // "DocWindowKomashko_Novosad"
QT_MOC_LITERAL(1, 26, 17), // "changeWindowTitle"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 8), // "slotLoad"
QT_MOC_LITERAL(4, 54, 8), // "slotSave"
QT_MOC_LITERAL(5, 63, 10), // "slotSaveAs"
QT_MOC_LITERAL(6, 74, 15) // "slotChangeColor"

    },
    "DocWindowKomashko_Novosad\0changeWindowTitle\0"
    "\0slotLoad\0slotSave\0slotSaveAs\0"
    "slotChangeColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DocWindowKomashko_Novosad[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   42,    2, 0x0a /* Public */,
       4,    0,   43,    2, 0x0a /* Public */,
       5,    0,   44,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DocWindowKomashko_Novosad::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DocWindowKomashko_Novosad *_t = static_cast<DocWindowKomashko_Novosad *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeWindowTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->slotLoad(); break;
        case 2: _t->slotSave(); break;
        case 3: _t->slotSaveAs(); break;
        case 4: _t->slotChangeColor(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DocWindowKomashko_Novosad::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocWindowKomashko_Novosad::changeWindowTitle)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DocWindowKomashko_Novosad::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_DocWindowKomashko_Novosad.data,
      qt_meta_data_DocWindowKomashko_Novosad,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DocWindowKomashko_Novosad::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DocWindowKomashko_Novosad::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DocWindowKomashko_Novosad.stringdata0))
        return static_cast<void*>(this);
    return QTextEdit::qt_metacast(_clname);
}

int DocWindowKomashko_Novosad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DocWindowKomashko_Novosad::changeWindowTitle(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
