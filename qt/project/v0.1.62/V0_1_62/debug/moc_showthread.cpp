/****************************************************************************
** Meta object code from reading C++ file 'showthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../showthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_showthread_t {
    QByteArrayData data[5];
    char stringdata0[34];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_showthread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_showthread_t qt_meta_stringdata_showthread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "showthread"
QT_MOC_LITERAL(1, 11, 8), // "send_img"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "send_mat"
QT_MOC_LITERAL(4, 30, 3) // "Mat"

    },
    "showthread\0send_img\0\0send_mat\0Mat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_showthread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       3,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

       0        // eod
};

void showthread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        showthread *_t = static_cast<showthread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_img((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 1: _t->send_mat((*reinterpret_cast< const Mat(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (showthread::*_t)(const QImage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&showthread::send_img)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (showthread::*_t)(const Mat & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&showthread::send_mat)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject showthread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_showthread.data,
      qt_meta_data_showthread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *showthread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *showthread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_showthread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int showthread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void showthread::send_img(const QImage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void showthread::send_mat(const Mat & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
