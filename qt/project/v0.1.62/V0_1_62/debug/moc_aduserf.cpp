/****************************************************************************
** Meta object code from reading C++ file 'aduserf.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../aduserf.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aduserf.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_aduserf_t {
    QByteArrayData data[12];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_aduserf_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_aduserf_t qt_meta_stringdata_aduserf = {
    {
QT_MOC_LITERAL(0, 0, 7), // "aduserf"
QT_MOC_LITERAL(1, 8, 7), // "to_look"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 9), // "to_search"
QT_MOC_LITERAL(4, 27, 7), // "to_home"
QT_MOC_LITERAL(5, 35, 7), // "sgskalk"
QT_MOC_LITERAL(6, 43, 11), // "QTcpSocket*"
QT_MOC_LITERAL(7, 55, 7), // "sgskasc"
QT_MOC_LITERAL(8, 63, 4), // "resg"
QT_MOC_LITERAL(9, 68, 18), // "on_adflbtn_clicked"
QT_MOC_LITERAL(10, 87, 17), // "on_adsbtn_clicked"
QT_MOC_LITERAL(11, 105, 20) // "on_adexitbtn_clicked"

    },
    "aduserf\0to_look\0\0to_search\0to_home\0"
    "sgskalk\0QTcpSocket*\0sgskasc\0resg\0"
    "on_adflbtn_clicked\0on_adsbtn_clicked\0"
    "on_adexitbtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_aduserf[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,
       7,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   68,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void aduserf::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        aduserf *_t = static_cast<aduserf *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->to_look(); break;
        case 1: _t->to_search(); break;
        case 2: _t->to_home(); break;
        case 3: _t->sgskalk((*reinterpret_cast< QTcpSocket*(*)>(_a[1]))); break;
        case 4: _t->sgskasc((*reinterpret_cast< QTcpSocket*(*)>(_a[1]))); break;
        case 5: _t->resg((*reinterpret_cast< QTcpSocket*(*)>(_a[1]))); break;
        case 6: _t->on_adflbtn_clicked(); break;
        case 7: _t->on_adsbtn_clicked(); break;
        case 8: _t->on_adexitbtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
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
        case 5:
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
            typedef void (aduserf::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&aduserf::to_look)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (aduserf::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&aduserf::to_search)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (aduserf::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&aduserf::to_home)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (aduserf::*_t)(QTcpSocket * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&aduserf::sgskalk)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (aduserf::*_t)(QTcpSocket * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&aduserf::sgskasc)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject aduserf::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_aduserf.data,
      qt_meta_data_aduserf,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *aduserf::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *aduserf::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_aduserf.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int aduserf::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void aduserf::to_look()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void aduserf::to_search()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void aduserf::to_home()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void aduserf::sgskalk(QTcpSocket * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void aduserf::sgskasc(QTcpSocket * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
