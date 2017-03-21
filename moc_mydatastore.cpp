/****************************************************************************
** Meta object code from reading C++ file 'mydatastore.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mydatastore.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mydatastore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyDataStore[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   13,   12,   12, 0x0a,
      34,   12,   12,   12, 0x0a,
      47,   41,   12,   12, 0x0a,
      78,   67,   12,   12, 0x0a,
     113,  111,   99,   12, 0x0a,
     129,  111,   12,   12, 0x0a,
     149,  144,   12,   12, 0x0a,
     168,  144,   12,   12, 0x0a,
     185,   12,   12,   12, 0x0a,
     194,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyDataStore[] = {
    "MyDataStore\0\0r\0addReview(Review*)\0"
    "sort()\0ofile\0dump(std::ostream&)\0"
    "u,hitindex\0addtoCart(User*,int)\0"
    "std::string\0u\0viewCart(User*)\0"
    "buyCart(User*)\0type\0setsearchType(int)\0"
    "setsortType(int)\0search()\0"
    "updatesearch(QString)\0"
};

void MyDataStore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyDataStore *_t = static_cast<MyDataStore *>(_o);
        switch (_id) {
        case 0: _t->addReview((*reinterpret_cast< Review*(*)>(_a[1]))); break;
        case 1: _t->sort(); break;
        case 2: _t->dump((*reinterpret_cast< std::ostream(*)>(_a[1]))); break;
        case 3: _t->addtoCart((*reinterpret_cast< User*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: { std::string _r = _t->viewCart((*reinterpret_cast< User*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = _r; }  break;
        case 5: _t->buyCart((*reinterpret_cast< User*(*)>(_a[1]))); break;
        case 6: _t->setsearchType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setsortType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->search(); break;
        case 9: _t->updatesearch((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyDataStore::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyDataStore::staticMetaObject = {
    { &DataStore::staticMetaObject, qt_meta_stringdata_MyDataStore,
      qt_meta_data_MyDataStore, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyDataStore::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyDataStore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyDataStore::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyDataStore))
        return static_cast<void*>(const_cast< MyDataStore*>(this));
    return DataStore::qt_metacast(_clname);
}

int MyDataStore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataStore::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
