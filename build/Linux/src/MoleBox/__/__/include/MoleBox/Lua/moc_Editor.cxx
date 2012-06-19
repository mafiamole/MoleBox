/****************************************************************************
** Meta object code from reading C++ file 'Editor.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../../include/MoleBox/Lua/Editor.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Editor.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MB__Lua__Highlighter[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_MB__Lua__Highlighter[] = {
    "MB::Lua::Highlighter\0"
};

void MB::Lua::Highlighter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MB::Lua::Highlighter::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MB::Lua::Highlighter::staticMetaObject = {
    { &QSyntaxHighlighter::staticMetaObject, qt_meta_stringdata_MB__Lua__Highlighter,
      qt_meta_data_MB__Lua__Highlighter, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MB::Lua::Highlighter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MB::Lua::Highlighter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MB::Lua::Highlighter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MB__Lua__Highlighter))
        return static_cast<void*>(const_cast< Highlighter*>(this));
    return QSyntaxHighlighter::qt_metacast(_clname);
}

int MB::Lua::Highlighter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSyntaxHighlighter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_MB__Lua__LuaEditor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      31,   20,   19,   19, 0x0a,
      53,   19,   19,   19, 0x0a,
      74,   68,   19,   19, 0x0a,
      90,   68,   19,   19, 0x0a,
     104,   19,   19,   19, 0x0a,
     128,   19,   19,   19, 0x0a,
     154,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MB__Lua__LuaEditor[] = {
    "MB::Lua::LuaEditor\0\0scriptFile\0"
    "ChangeScript(QString)\0UpdateScript()\0"
    "index\0TabChanged(int)\0CloseTab(int)\0"
    "pushButton_Save_Click()\0"
    "pushButton_SaveAs_Click()\0"
    "pushButton_New_Click()\0"
};

void MB::Lua::LuaEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LuaEditor *_t = static_cast<LuaEditor *>(_o);
        switch (_id) {
        case 0: _t->ChangeScript((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->UpdateScript(); break;
        case 2: _t->TabChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->CloseTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->pushButton_Save_Click(); break;
        case 5: _t->pushButton_SaveAs_Click(); break;
        case 6: _t->pushButton_New_Click(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MB::Lua::LuaEditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MB::Lua::LuaEditor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MB__Lua__LuaEditor,
      qt_meta_data_MB__Lua__LuaEditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MB::Lua::LuaEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MB::Lua::LuaEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MB::Lua::LuaEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MB__Lua__LuaEditor))
        return static_cast<void*>(const_cast< LuaEditor*>(this));
    return QWidget::qt_metacast(_clname);
}

int MB::Lua::LuaEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
