/****************************************************************************
** Meta object code from reading C++ file 'playingfield.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TicTacToe/playingfield.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playingfield.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlayingField_t {
    QByteArrayData data[8];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayingField_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayingField_t qt_meta_stringdata_PlayingField = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PlayingField"
QT_MOC_LITERAL(1, 13, 11), // "cellPressed"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "cell"
QT_MOC_LITERAL(4, 31, 5), // "state"
QT_MOC_LITERAL(5, 37, 12), // "cellPressedV"
QT_MOC_LITERAL(6, 50, 14), // "QVector<qint8>"
QT_MOC_LITERAL(7, 65, 9) // "cellState"

    },
    "PlayingField\0cellPressed\0\0cell\0state\0"
    "cellPressedV\0QVector<qint8>\0cellState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayingField[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       1,    2,   32,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::SChar,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void PlayingField::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlayingField *_t = static_cast<PlayingField *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cellPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->cellPressed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< qint8(*)>(_a[2]))); break;
        case 2: _t->cellPressedV((*reinterpret_cast< QVector<qint8>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<qint8> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlayingField::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayingField::cellPressed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlayingField::*)(int , qint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayingField::cellPressed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PlayingField::*)(QVector<qint8> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayingField::cellPressedV)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PlayingField::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_PlayingField.data,
    qt_meta_data_PlayingField,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PlayingField::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayingField::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlayingField.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PlayingField::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void PlayingField::cellPressed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlayingField::cellPressed(int _t1, qint8 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PlayingField::cellPressedV(QVector<qint8> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
