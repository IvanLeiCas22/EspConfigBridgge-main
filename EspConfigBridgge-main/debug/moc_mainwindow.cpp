/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "openSerialPorts",
    "",
    "closeSerialPorts",
    "dataRecived",
    "decodeData",
    "uint8_t*",
    "datosRx",
    "uint8_t",
    "source",
    "sendDataSerial",
    "sendDataUDP",
    "on_pushButtonUdpOpen_clicked",
    "OnUdpRxData",
    "OnQTimer1",
    "inicializaciones",
    "lecturaSensores",
    "reiniciarUI",
    "on_radarButton_clicked",
    "DibujarFondoRadar",
    "RadarRun",
    "DibujarDeteccion",
    "MahonyAHRSupdateIMU",
    "gx",
    "gy",
    "gz",
    "ax",
    "ay",
    "az"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[58];
    char stringdata0[11];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[12];
    char stringdata5[11];
    char stringdata6[9];
    char stringdata7[8];
    char stringdata8[8];
    char stringdata9[7];
    char stringdata10[15];
    char stringdata11[12];
    char stringdata12[29];
    char stringdata13[12];
    char stringdata14[10];
    char stringdata15[17];
    char stringdata16[16];
    char stringdata17[12];
    char stringdata18[23];
    char stringdata19[18];
    char stringdata20[9];
    char stringdata21[17];
    char stringdata22[20];
    char stringdata23[3];
    char stringdata24[3];
    char stringdata25[3];
    char stringdata26[3];
    char stringdata27[3];
    char stringdata28[3];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 15),  // "openSerialPorts"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 16),  // "closeSerialPorts"
        QT_MOC_LITERAL(45, 11),  // "dataRecived"
        QT_MOC_LITERAL(57, 10),  // "decodeData"
        QT_MOC_LITERAL(68, 8),  // "uint8_t*"
        QT_MOC_LITERAL(77, 7),  // "datosRx"
        QT_MOC_LITERAL(85, 7),  // "uint8_t"
        QT_MOC_LITERAL(93, 6),  // "source"
        QT_MOC_LITERAL(100, 14),  // "sendDataSerial"
        QT_MOC_LITERAL(115, 11),  // "sendDataUDP"
        QT_MOC_LITERAL(127, 28),  // "on_pushButtonUdpOpen_clicked"
        QT_MOC_LITERAL(156, 11),  // "OnUdpRxData"
        QT_MOC_LITERAL(168, 9),  // "OnQTimer1"
        QT_MOC_LITERAL(178, 16),  // "inicializaciones"
        QT_MOC_LITERAL(195, 15),  // "lecturaSensores"
        QT_MOC_LITERAL(211, 11),  // "reiniciarUI"
        QT_MOC_LITERAL(223, 22),  // "on_radarButton_clicked"
        QT_MOC_LITERAL(246, 17),  // "DibujarFondoRadar"
        QT_MOC_LITERAL(264, 8),  // "RadarRun"
        QT_MOC_LITERAL(273, 16),  // "DibujarDeteccion"
        QT_MOC_LITERAL(290, 19),  // "MahonyAHRSupdateIMU"
        QT_MOC_LITERAL(310, 2),  // "gx"
        QT_MOC_LITERAL(313, 2),  // "gy"
        QT_MOC_LITERAL(316, 2),  // "gz"
        QT_MOC_LITERAL(319, 2),  // "ax"
        QT_MOC_LITERAL(322, 2),  // "ay"
        QT_MOC_LITERAL(325, 2)   // "az"
    },
    "MainWindow",
    "openSerialPorts",
    "",
    "closeSerialPorts",
    "dataRecived",
    "decodeData",
    "uint8_t*",
    "datosRx",
    "uint8_t",
    "source",
    "sendDataSerial",
    "sendDataUDP",
    "on_pushButtonUdpOpen_clicked",
    "OnUdpRxData",
    "OnQTimer1",
    "inicializaciones",
    "lecturaSensores",
    "reiniciarUI",
    "on_radarButton_clicked",
    "DibujarFondoRadar",
    "RadarRun",
    "DibujarDeteccion",
    "MahonyAHRSupdateIMU",
    "gx",
    "gy",
    "gz",
    "ax",
    "ay",
    "az"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  116,    2, 0x08,    1 /* Private */,
       3,    0,  117,    2, 0x08,    2 /* Private */,
       4,    0,  118,    2, 0x08,    3 /* Private */,
       5,    2,  119,    2, 0x08,    4 /* Private */,
      10,    0,  124,    2, 0x08,    7 /* Private */,
      11,    0,  125,    2, 0x08,    8 /* Private */,
      12,    0,  126,    2, 0x08,    9 /* Private */,
      13,    0,  127,    2, 0x08,   10 /* Private */,
      14,    0,  128,    2, 0x08,   11 /* Private */,
      15,    0,  129,    2, 0x08,   12 /* Private */,
      16,    0,  130,    2, 0x08,   13 /* Private */,
      17,    0,  131,    2, 0x08,   14 /* Private */,
      18,    0,  132,    2, 0x08,   15 /* Private */,
      19,    0,  133,    2, 0x08,   16 /* Private */,
      20,    0,  134,    2, 0x08,   17 /* Private */,
      21,    0,  135,    2, 0x08,   18 /* Private */,
      22,    6,  136,    2, 0x08,   19 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,   23,   24,   25,   26,   27,   28,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'openSerialPorts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'closeSerialPorts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dataRecived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'decodeData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t *, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>,
        // method 'sendDataSerial'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendDataUDP'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonUdpOpen_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnUdpRxData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnQTimer1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'inicializaciones'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'lecturaSensores'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'reiniciarUI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_radarButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DibujarFondoRadar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RadarRun'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DibujarDeteccion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'MahonyAHRSupdateIMU'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->openSerialPorts(); break;
        case 1: _t->closeSerialPorts(); break;
        case 2: _t->dataRecived(); break;
        case 3: _t->decodeData((*reinterpret_cast< std::add_pointer_t<uint8_t*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[2]))); break;
        case 4: _t->sendDataSerial(); break;
        case 5: _t->sendDataUDP(); break;
        case 6: _t->on_pushButtonUdpOpen_clicked(); break;
        case 7: _t->OnUdpRxData(); break;
        case 8: _t->OnQTimer1(); break;
        case 9: _t->inicializaciones(); break;
        case 10: _t->lecturaSensores(); break;
        case 11: _t->reiniciarUI(); break;
        case 12: _t->on_radarButton_clicked(); break;
        case 13: _t->DibujarFondoRadar(); break;
        case 14: _t->RadarRun(); break;
        case 15: _t->DibujarDeteccion(); break;
        case 16: _t->MahonyAHRSupdateIMU((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[6]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
