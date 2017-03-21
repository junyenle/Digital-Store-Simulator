/****************************************************************************
** Meta object code from reading C++ file 'datastore.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "datastore.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datastore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DataStore[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      26,   20,   10,   10, 0x0a,
      48,   46,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DataStore[] = {
    "DataStore\0\0search()\0ofile\0dump(std::ostream&)\0"
    "r\0addReview(Review*)\0"
};

void DataStore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DataStore *_t = static_cast<DataStore *>(_o);
        switch (_id) {
        case 0: _t->search(); break;
        case 1: _t->dump((*reinterpret_cast< std::ostream(*)>(_a[1]))); break;
        case 2: _t->addReview((*reinterpret_cast< Review*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DataStore::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DataStore::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DataStore,
      qt_meta_data_DataStore, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DataStore::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DataStore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DataStore::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DataStore))
        return static_cast<void*>(const_cast< DataStore*>(this));
    return QWidget::qt_metacast(_clname);
}

int DataStore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
