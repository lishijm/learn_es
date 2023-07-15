/****************************************************************************
** Meta object code from reading C++ file 'nmusersel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../nmusersel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nmusersel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_nmusersel_t {
    QByteArrayData data[10];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_nmusersel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_nmusersel_t qt_meta_stringdata_nmusersel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "nmusersel"
QT_MOC_LITERAL(1, 10, 6), // "to_sin"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 6), // "to_sup"
QT_MOC_LITERAL(4, 25, 7), // "sgsksin"
QT_MOC_LITERAL(5, 33, 11), // "QTcpSocket*"
QT_MOC_LITERAL(6, 45, 7), // "sgsksup"
QT_MOC_LITERAL(7, 53, 4), // "resg"
QT_MOC_LITERAL(8, 58, 21), // "on_nmselinbtn_clicked"
QT_MOC_LITERAL(9, 80, 21) // "on_nmselupbtn_clicked"

    },
    "nmusersel\0to_sin\0\0to_sup\0sgsksin\0"
    "QTcpSocket*\0sgsksup\0resg\0on_nmselinbtn_clicked\0"
    "on_nmselupbtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nmusersel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    1,   51,    2, 0x06 /* Public */,
       6,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   57,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void nmusersel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        nmusersel *_t = static_cast<nmusersel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->to_sin(); break;
        case 1: _t->to_sup(); break;
        case 2: _t->sgsksin((*reinterpret_cast< QTcpSocket*(*)>(_a[1]))); break;
        case 3: _t->sgsksup((*reinterpret_cast< QTcpSocket*(*)>(_a[1]))); break;
        case 4: _t->resg((*reinterpret_cast< QTcpSocket*(*)>(_a[1]))); break;
        case 5: _t->on_nmselinbtn_clicked(); break;
        case 6: _t->on_nmselupbtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (nmusersel::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmusersel::to_sin)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (nmusersel::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmusersel::to_sup)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (nmusersel::*_t)(QTcpSocket * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmusersel::sgsksin)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (nmusersel::*_t)(QTcpSocket * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmusersel::sgsksup)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject nmusersel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_nmusersel.data,
      qt_meta_data_nmusersel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *nmusersel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nmusersel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_nmusersel.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int nmusersel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void nmusersel::to_sin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void nmusersel::to_sup()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void nmusersel::sgsksin(QTcpSocket * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void nmusersel::sgsksup(QTcpSocket * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
