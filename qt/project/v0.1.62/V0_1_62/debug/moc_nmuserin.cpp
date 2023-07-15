/****************************************************************************
** Meta object code from reading C++ file 'nmuserin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../nmuserin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nmuserin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_nmuserin_t {
    QByteArrayData data[9];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_nmuserin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_nmuserin_t qt_meta_stringdata_nmuserin = {
    {
QT_MOC_LITERAL(0, 0, 8), // "nmuserin"
QT_MOC_LITERAL(1, 9, 7), // "to_home"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 4), // "resg"
QT_MOC_LITERAL(4, 23, 11), // "QTcpSocket*"
QT_MOC_LITERAL(5, 35, 8), // "recv_img"
QT_MOC_LITERAL(6, 44, 6), // "soktre"
QT_MOC_LITERAL(7, 51, 18), // "on_nminbtn_clicked"
QT_MOC_LITERAL(8, 70, 20) // "on_nminclbtn_clicked"

    },
    "nmuserin\0to_home\0\0resg\0QTcpSocket*\0"
    "recv_img\0soktre\0on_nminbtn_clicked\0"
    "on_nminclbtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nmuserin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   45,    2, 0x0a /* Public */,
       5,    1,   48,    2, 0x0a /* Public */,
       6,    0,   51,    2, 0x0a /* Public */,
       7,    0,   52,    2, 0x08 /* Private */,
       8,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void nmuserin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        nmuserin *_t = static_cast<nmuserin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->to_home(); break;
        case 1: _t->resg((*reinterpret_cast< QTcpSocket*(*)>(_a[1]))); break;
        case 2: _t->recv_img((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 3: _t->soktre(); break;
        case 4: _t->on_nminbtn_clicked(); break;
        case 5: _t->on_nminclbtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
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
            typedef void (nmuserin::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nmuserin::to_home)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject nmuserin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_nmuserin.data,
      qt_meta_data_nmuserin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *nmuserin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nmuserin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_nmuserin.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int nmuserin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void nmuserin::to_home()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
