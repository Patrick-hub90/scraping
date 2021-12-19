/****************************************************************************
** Meta object code from reading C++ file 'search.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../scrapping/search.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'search.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Search_t {
    const uint offsetsAndSize[24];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Search_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Search_t qt_meta_stringdata_Search = {
    {
QT_MOC_LITERAL(0, 6), // "Search"
QT_MOC_LITERAL(7, 4), // "clik"
QT_MOC_LITERAL(12, 0), // ""
QT_MOC_LITERAL(13, 4), // "klic"
QT_MOC_LITERAL(18, 9), // "m_revenir"
QT_MOC_LITERAL(28, 7), // "Affiche"
QT_MOC_LITERAL(36, 6), // "chaine"
QT_MOC_LITERAL(43, 7), // "display"
QT_MOC_LITERAL(51, 3), // "pix"
QT_MOC_LITERAL(55, 6), // "Erreur"
QT_MOC_LITERAL(62, 5), // "error"
QT_MOC_LITERAL(68, 5) // "clike"

    },
    "Search\0clik\0\0klic\0m_revenir\0Affiche\0"
    "chaine\0display\0pix\0Erreur\0error\0clike"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Search[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,
       3,    1,   57,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   60,    2, 0x0a,    4 /* Public */,
       5,    1,   61,    2, 0x0a,    5 /* Public */,
       7,    1,   64,    2, 0x0a,    7 /* Public */,
       9,    1,   67,    2, 0x0a,    9 /* Public */,
      11,    1,   70,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QPixmap,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QPixmap,    8,

       0        // eod
};

void Search::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Search *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clik(); break;
        case 1: _t->klic((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 2: _t->m_revenir(); break;
        case 3: _t->Affiche((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->display((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 5: _t->Erreur((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->clike((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Search::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Search::clik)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Search::*)(QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Search::klic)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Search::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Search.offsetsAndSize,
    qt_meta_data_Search,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Search_t
, QtPrivate::TypeAndForceComplete<Search, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPixmap, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPixmap, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPixmap, std::false_type>


>,
    nullptr
} };


const QMetaObject *Search::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Search::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Search.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Search::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Search::clik()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Search::klic(QPixmap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
