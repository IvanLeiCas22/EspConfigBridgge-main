/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionScanPorts;
    QAction *actionConnect_Device;
    QAction *actionDisconnect;
    QAction *actionExit;
    QWidget *centralwidget;
    QGroupBox *groupBox_5;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox;
    QGroupBox *groupBox_6;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_14;
    QLineEdit *lineEditLocalPort;
    QPushButton *pushButtonUdpOpen;
    QGroupBox *groupBox_8;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_15;
    QLineEdit *lineEditIP;
    QLabel *label_16;
    QLineEdit *lineEditPort;
    QGroupBox *groupBox_3;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButtonSend;
    QPushButton *pushButtonSend_2;
    QComboBox *comboBoxCom;
    QGroupBox *groupBox_9;
    QTextBrowser *txtBrowserCMD;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_4;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLCDNumber *NegroConfigLCD;
    QLCDNumber *BlancoConfigLCD;
    QLabel *label_6;
    QGroupBox *groupBox_7;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QLabel *label_17;
    QLabel *label_13;
    QLCDNumber *ServoMinValueLCD;
    QLCDNumber *ServoMaxValueLCD;
    QGroupBox *groupBox_10;
    QGroupBox *groupBox_11;
    QLCDNumber *ir_4;
    QLabel *irLabel_5;
    QLCDNumber *ir_3;
    QLabel *irLabel_6;
    QLabel *irLabel_7;
    QLCDNumber *ir_5;
    QLCDNumber *ir_7;
    QLabel *irLabel_8;
    QLCDNumber *ir_6;
    QLabel *irLabel_9;
    QLabel *irLabel_3;
    QLCDNumber *ir_2;
    QLCDNumber *ir_0;
    QLabel *irLabel_4;
    QLabel *irLabel_2;
    QLCDNumber *ir_1;
    QGroupBox *groupBox_12;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_6;
    QLabel *leftHSensorLabel;
    QLabel *rightHSensorLabel;
    QLCDNumber *leftPulsesLCD;
    QLCDNumber *rightPulsesLCD;
    QGroupBox *groupBox_13;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_7;
    QLabel *dLabel;
    QLabel *sLabel;
    QLCDNumber *distanceLCD;
    QLCDNumber *angleLCD;
    QLCDNumber *gyro_2;
    QLCDNumber *gyro_0;
    QLCDNumber *gyro_1;
    QLCDNumber *accel_2;
    QLCDNumber *accel_0;
    QLCDNumber *accel_1;
    QLCDNumber *vel_1;
    QLCDNumber *vel_0;
    QLCDNumber *vel_2;
    QGroupBox *groupBox_14;
    QGroupBox *groupBox_15;
    QLabel *EstadoBotonLabel;
    QGroupBox *groupBox_17;
    QLabel *AliveLabel;
    QGroupBox *groupBox_16;
    QLabel *FirmwareLabel;
    QPushButton *radarButton;
    QSlider *scaleSlider;
    QLCDNumber *rangeLCD;
    QLabel *rangeLabel;
    QWidget *widgetRadar;
    QLCDNumber *position_0;
    QLCDNumber *position_2;
    QLCDNumber *position_1;
    QLCDNumber *pitch_0;
    QLCDNumber *roll_0;
    QLCDNumber *contraAccel_y;
    QLCDNumber *contraAccel_x;
    QLCDNumber *yaw_0;
    QMenuBar *menubar;
    QMenu *menuConfiguraciones;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1296, 774);
        MainWindow->setMinimumSize(QSize(1296, 774));
        MainWindow->setMaximumSize(QSize(1296, 774));
        QFont font;
        font.setBold(false);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("car.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(1.000000000000000);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionScanPorts = new QAction(MainWindow);
        actionScanPorts->setObjectName("actionScanPorts");
        actionConnect_Device = new QAction(MainWindow);
        actionConnect_Device->setObjectName("actionConnect_Device");
        actionConnect_Device->setCheckable(false);
        actionConnect_Device->setEnabled(true);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName("actionDisconnect");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(20, 500, 411, 151));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        groupBox_5->setFont(font1);
        groupBox_5->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid gray;\n"
"    border-color: black;\n"
"    border-radius: 2px;\n"
"}"));
        groupBox_5->setCheckable(false);
        textBrowser = new QTextBrowser(groupBox_5);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(10, 30, 391, 111));
        textBrowser->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 10, 411, 331));
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid gray;\n"
"    border-color: black;\n"
"    border-radius: 2px;\n"
"}"));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        groupBox_6 = new QGroupBox(groupBox);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(10, 30, 391, 61));
        groupBox_6->setFont(font1);
        horizontalLayoutWidget = new QWidget(groupBox_6);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 371, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(horizontalLayoutWidget);
        label_14->setObjectName("label_14");
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        label_14->setFont(font2);

        horizontalLayout->addWidget(label_14);

        lineEditLocalPort = new QLineEdit(horizontalLayoutWidget);
        lineEditLocalPort->setObjectName("lineEditLocalPort");
        lineEditLocalPort->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        lineEditLocalPort->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEditLocalPort);

        pushButtonUdpOpen = new QPushButton(horizontalLayoutWidget);
        pushButtonUdpOpen->setObjectName("pushButtonUdpOpen");
        pushButtonUdpOpen->setFont(font2);

        horizontalLayout->addWidget(pushButtonUdpOpen);

        groupBox_8 = new QGroupBox(groupBox);
        groupBox_8->setObjectName("groupBox_8");
        groupBox_8->setGeometry(QRect(10, 100, 391, 101));
        groupBox_8->setFont(font1);
        gridLayoutWidget = new QWidget(groupBox_8);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 20, 371, 81));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName("label_15");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        font3.setPointSize(10);
        font3.setBold(false);
        label_15->setFont(font3);

        gridLayout->addWidget(label_15, 0, 0, 1, 1);

        lineEditIP = new QLineEdit(gridLayoutWidget);
        lineEditIP->setObjectName("lineEditIP");
        lineEditIP->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));

        gridLayout->addWidget(lineEditIP, 0, 1, 1, 1);

        label_16 = new QLabel(gridLayoutWidget);
        label_16->setObjectName("label_16");
        label_16->setFont(font2);

        gridLayout->addWidget(label_16, 1, 0, 1, 1);

        lineEditPort = new QLineEdit(gridLayoutWidget);
        lineEditPort->setObjectName("lineEditPort");
        lineEditPort->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));

        gridLayout->addWidget(lineEditPort, 1, 1, 1, 1);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 210, 391, 111));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe UI")});
        font4.setPointSize(10);
        font4.setBold(true);
        groupBox_3->setFont(font4);
        groupBox_3->setStyleSheet(QString::fromUtf8(""));
        gridLayoutWidget_2 = new QWidget(groupBox_3);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(10, 20, 371, 91));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonSend = new QPushButton(gridLayoutWidget_2);
        pushButtonSend->setObjectName("pushButtonSend");
        pushButtonSend->setFont(font4);
        pushButtonSend->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));

        gridLayout_2->addWidget(pushButtonSend, 1, 0, 1, 1);

        pushButtonSend_2 = new QPushButton(gridLayoutWidget_2);
        pushButtonSend_2->setObjectName("pushButtonSend_2");
        pushButtonSend_2->setFont(font4);
        pushButtonSend_2->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));

        gridLayout_2->addWidget(pushButtonSend_2, 1, 1, 1, 1);

        comboBoxCom = new QComboBox(gridLayoutWidget_2);
        comboBoxCom->setObjectName("comboBoxCom");
        comboBoxCom->setFont(font3);
        comboBoxCom->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));

        gridLayout_2->addWidget(comboBoxCom, 0, 0, 1, 2);

        groupBox_9 = new QGroupBox(centralwidget);
        groupBox_9->setObjectName("groupBox_9");
        groupBox_9->setGeometry(QRect(20, 350, 411, 141));
        groupBox_9->setFont(font1);
        groupBox_9->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid gray;\n"
"    border-color: black;\n"
"    border-radius: 2px;\n"
"}"));
        groupBox_9->setCheckable(false);
        txtBrowserCMD = new QTextBrowser(groupBox_9);
        txtBrowserCMD->setObjectName("txtBrowserCMD");
        txtBrowserCMD->setGeometry(QRect(10, 30, 391, 101));
        txtBrowserCMD->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(440, 10, 431, 151));
        groupBox_2->setFont(font1);
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid gray;\n"
"    border-color: black;\n"
"    border-radius: 2px;\n"
"}"));
        groupBox_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(10, 30, 221, 111));
        groupBox_4->setFont(font1);
        groupBox_4->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_3 = new QWidget(groupBox_4);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(10, 30, 201, 61));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(gridLayoutWidget_3);
        label_5->setObjectName("label_5");
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial Narrow")});
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setUnderline(false);
        font5.setStrikeOut(false);
        label_5->setFont(font5);
        label_5->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        label_5->setFrameShape(QFrame::Box);
        label_5->setFrameShadow(QFrame::Plain);
        label_5->setLineWidth(1);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_5, 0, 1, 1, 1);

        NegroConfigLCD = new QLCDNumber(gridLayoutWidget_3);
        NegroConfigLCD->setObjectName("NegroConfigLCD");
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Arial")});
        font6.setPointSize(9);
        font6.setBold(false);
        font6.setItalic(false);
        font6.setUnderline(false);
        font6.setStrikeOut(false);
        font6.setKerning(true);
        NegroConfigLCD->setFont(font6);
        NegroConfigLCD->setLayoutDirection(Qt::LeftToRight);
        NegroConfigLCD->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        NegroConfigLCD->setFrameShape(QFrame::Box);
        NegroConfigLCD->setFrameShadow(QFrame::Plain);
        NegroConfigLCD->setLineWidth(1);
        NegroConfigLCD->setDigitCount(5);
        NegroConfigLCD->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_3->addWidget(NegroConfigLCD, 1, 0, 1, 1);

        BlancoConfigLCD = new QLCDNumber(gridLayoutWidget_3);
        BlancoConfigLCD->setObjectName("BlancoConfigLCD");
        BlancoConfigLCD->setFont(font6);
        BlancoConfigLCD->setLayoutDirection(Qt::LeftToRight);
        BlancoConfigLCD->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        BlancoConfigLCD->setFrameShape(QFrame::Box);
        BlancoConfigLCD->setFrameShadow(QFrame::Plain);
        BlancoConfigLCD->setLineWidth(1);
        BlancoConfigLCD->setDigitCount(5);
        BlancoConfigLCD->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_3->addWidget(BlancoConfigLCD, 1, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_3);
        label_6->setObjectName("label_6");
        label_6->setFont(font5);
        label_6->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        label_6->setFrameShape(QFrame::Box);
        label_6->setFrameShadow(QFrame::Plain);
        label_6->setLineWidth(1);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        gridLayout_3->setRowStretch(1, 1);
        groupBox_7 = new QGroupBox(groupBox_2);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setGeometry(QRect(240, 30, 181, 111));
        groupBox_7->setFont(font1);
        groupBox_7->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_5 = new QWidget(groupBox_7);
        gridLayoutWidget_5->setObjectName("gridLayoutWidget_5");
        gridLayoutWidget_5->setGeometry(QRect(10, 30, 161, 61));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(gridLayoutWidget_5);
        label_17->setObjectName("label_17");
        label_17->setFont(font5);
        label_17->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        label_17->setFrameShape(QFrame::Box);
        label_17->setFrameShadow(QFrame::Plain);
        label_17->setLineWidth(1);
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_17, 0, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget_5);
        label_13->setObjectName("label_13");
        label_13->setFont(font5);
        label_13->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        label_13->setFrameShape(QFrame::Box);
        label_13->setFrameShadow(QFrame::Plain);
        label_13->setLineWidth(1);
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_13, 0, 0, 1, 1);

        ServoMinValueLCD = new QLCDNumber(gridLayoutWidget_5);
        ServoMinValueLCD->setObjectName("ServoMinValueLCD");
        ServoMinValueLCD->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        ServoMinValueLCD->setFrameShadow(QFrame::Plain);
        ServoMinValueLCD->setDigitCount(4);
        ServoMinValueLCD->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_5->addWidget(ServoMinValueLCD, 1, 1, 1, 1);

        ServoMaxValueLCD = new QLCDNumber(gridLayoutWidget_5);
        ServoMaxValueLCD->setObjectName("ServoMaxValueLCD");
        ServoMaxValueLCD->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        ServoMaxValueLCD->setFrameShadow(QFrame::Plain);
        ServoMaxValueLCD->setDigitCount(4);
        ServoMaxValueLCD->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_5->addWidget(ServoMaxValueLCD, 1, 0, 1, 1);

        gridLayout_5->setRowStretch(1, 1);
        groupBox_10 = new QGroupBox(centralwidget);
        groupBox_10->setObjectName("groupBox_10");
        groupBox_10->setGeometry(QRect(440, 190, 841, 331));
        groupBox_10->setFont(font1);
        groupBox_10->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid gray;\n"
"    border-color: black;\n"
"    border-radius: 2px;\n"
"}"));
        groupBox_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox_10->setFlat(false);
        groupBox_11 = new QGroupBox(groupBox_10);
        groupBox_11->setObjectName("groupBox_11");
        groupBox_11->setGeometry(QRect(10, 30, 321, 281));
        groupBox_11->setFont(font1);
        groupBox_11->setAlignment(Qt::AlignCenter);
        ir_4 = new QLCDNumber(groupBox_11);
        ir_4->setObjectName("ir_4");
        ir_4->setGeometry(QRect(109, 130, 95, 36));
        ir_4->setFont(font6);
        ir_4->setLayoutDirection(Qt::LeftToRight);
        ir_4->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        ir_4->setFrameShape(QFrame::Box);
        ir_4->setFrameShadow(QFrame::Plain);
        ir_4->setLineWidth(1);
        ir_4->setDigitCount(5);
        ir_4->setSegmentStyle(QLCDNumber::Flat);
        irLabel_5 = new QLabel(groupBox_11);
        irLabel_5->setObjectName("irLabel_5");
        irLabel_5->setGeometry(QRect(109, 107, 95, 17));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Arial Narrow")});
        font7.setPointSize(10);
        font7.setBold(true);
        font7.setItalic(false);
        irLabel_5->setFont(font7);
        irLabel_5->setLayoutDirection(Qt::LeftToRight);
        irLabel_5->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        irLabel_5->setFrameShape(QFrame::Box);
        irLabel_5->setLineWidth(1);
        irLabel_5->setTextFormat(Qt::AutoText);
        irLabel_5->setAlignment(Qt::AlignCenter);
        ir_3 = new QLCDNumber(groupBox_11);
        ir_3->setObjectName("ir_3");
        ir_3->setGeometry(QRect(12, 130, 91, 36));
        ir_3->setFont(font6);
        ir_3->setLayoutDirection(Qt::LeftToRight);
        ir_3->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        ir_3->setFrameShape(QFrame::Box);
        ir_3->setFrameShadow(QFrame::Plain);
        ir_3->setLineWidth(1);
        ir_3->setDigitCount(5);
        ir_3->setSegmentStyle(QLCDNumber::Flat);
        irLabel_6 = new QLabel(groupBox_11);
        irLabel_6->setObjectName("irLabel_6");
        irLabel_6->setGeometry(QRect(12, 107, 91, 16));
        irLabel_6->setFont(font7);
        irLabel_6->setLayoutDirection(Qt::LeftToRight);
        irLabel_6->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        irLabel_6->setFrameShape(QFrame::Box);
        irLabel_6->setFrameShadow(QFrame::Plain);
        irLabel_6->setLineWidth(1);
        irLabel_6->setTextFormat(Qt::AutoText);
        irLabel_6->setAlignment(Qt::AlignCenter);
        irLabel_6->setWordWrap(false);
        irLabel_7 = new QLabel(groupBox_11);
        irLabel_7->setObjectName("irLabel_7");
        irLabel_7->setGeometry(QRect(210, 107, 96, 17));
        irLabel_7->setFont(font7);
        irLabel_7->setLayoutDirection(Qt::LeftToRight);
        irLabel_7->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        irLabel_7->setFrameShape(QFrame::Box);
        irLabel_7->setLineWidth(1);
        irLabel_7->setTextFormat(Qt::AutoText);
        irLabel_7->setAlignment(Qt::AlignCenter);
        ir_5 = new QLCDNumber(groupBox_11);
        ir_5->setObjectName("ir_5");
        ir_5->setGeometry(QRect(210, 130, 96, 36));
        ir_5->setFont(font6);
        ir_5->setLayoutDirection(Qt::LeftToRight);
        ir_5->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        ir_5->setFrameShape(QFrame::Box);
        ir_5->setFrameShadow(QFrame::Plain);
        ir_5->setLineWidth(1);
        ir_5->setDigitCount(5);
        ir_5->setSegmentStyle(QLCDNumber::Flat);
        ir_7 = new QLCDNumber(groupBox_11);
        ir_7->setObjectName("ir_7");
        ir_7->setGeometry(QRect(109, 200, 95, 36));
        ir_7->setFont(font6);
        ir_7->setLayoutDirection(Qt::LeftToRight);
        ir_7->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        ir_7->setFrameShape(QFrame::Box);
        ir_7->setFrameShadow(QFrame::Plain);
        ir_7->setLineWidth(1);
        ir_7->setDigitCount(5);
        ir_7->setSegmentStyle(QLCDNumber::Flat);
        irLabel_8 = new QLabel(groupBox_11);
        irLabel_8->setObjectName("irLabel_8");
        irLabel_8->setGeometry(QRect(109, 177, 95, 17));
        irLabel_8->setFont(font7);
        irLabel_8->setLayoutDirection(Qt::LeftToRight);
        irLabel_8->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        irLabel_8->setFrameShape(QFrame::Box);
        irLabel_8->setLineWidth(1);
        irLabel_8->setTextFormat(Qt::AutoText);
        irLabel_8->setAlignment(Qt::AlignCenter);
        ir_6 = new QLCDNumber(groupBox_11);
        ir_6->setObjectName("ir_6");
        ir_6->setGeometry(QRect(12, 200, 91, 36));
        ir_6->setFont(font6);
        ir_6->setLayoutDirection(Qt::LeftToRight);
        ir_6->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        ir_6->setFrameShape(QFrame::Box);
        ir_6->setFrameShadow(QFrame::Plain);
        ir_6->setLineWidth(1);
        ir_6->setDigitCount(5);
        ir_6->setSegmentStyle(QLCDNumber::Flat);
        irLabel_9 = new QLabel(groupBox_11);
        irLabel_9->setObjectName("irLabel_9");
        irLabel_9->setGeometry(QRect(12, 177, 91, 16));
        irLabel_9->setFont(font7);
        irLabel_9->setLayoutDirection(Qt::LeftToRight);
        irLabel_9->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        irLabel_9->setFrameShape(QFrame::Box);
        irLabel_9->setFrameShadow(QFrame::Plain);
        irLabel_9->setLineWidth(1);
        irLabel_9->setTextFormat(Qt::AutoText);
        irLabel_9->setAlignment(Qt::AlignCenter);
        irLabel_9->setWordWrap(false);
        irLabel_3 = new QLabel(groupBox_11);
        irLabel_3->setObjectName("irLabel_3");
        irLabel_3->setGeometry(QRect(113, 31, 91, 16));
        irLabel_3->setFont(font7);
        irLabel_3->setLayoutDirection(Qt::LeftToRight);
        irLabel_3->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        irLabel_3->setFrameShape(QFrame::Box);
        irLabel_3->setLineWidth(1);
        irLabel_3->setTextFormat(Qt::AutoText);
        irLabel_3->setAlignment(Qt::AlignCenter);
        ir_2 = new QLCDNumber(groupBox_11);
        ir_2->setObjectName("ir_2");
        ir_2->setGeometry(QRect(214, 54, 91, 41));
        ir_2->setFont(font6);
        ir_2->setLayoutDirection(Qt::LeftToRight);
        ir_2->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        ir_2->setFrameShape(QFrame::Box);
        ir_2->setFrameShadow(QFrame::Plain);
        ir_2->setLineWidth(1);
        ir_2->setDigitCount(5);
        ir_2->setSegmentStyle(QLCDNumber::Flat);
        ir_0 = new QLCDNumber(groupBox_11);
        ir_0->setObjectName("ir_0");
        ir_0->setGeometry(QRect(11, 54, 91, 41));
        ir_0->setFont(font6);
        ir_0->setLayoutDirection(Qt::LeftToRight);
        ir_0->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        ir_0->setFrameShape(QFrame::Box);
        ir_0->setFrameShadow(QFrame::Plain);
        ir_0->setLineWidth(1);
        ir_0->setDigitCount(5);
        ir_0->setSegmentStyle(QLCDNumber::Flat);
        irLabel_4 = new QLabel(groupBox_11);
        irLabel_4->setObjectName("irLabel_4");
        irLabel_4->setGeometry(QRect(11, 31, 91, 17));
        irLabel_4->setFont(font7);
        irLabel_4->setLayoutDirection(Qt::LeftToRight);
        irLabel_4->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        irLabel_4->setFrameShape(QFrame::Box);
        irLabel_4->setFrameShadow(QFrame::Plain);
        irLabel_4->setLineWidth(1);
        irLabel_4->setTextFormat(Qt::AutoText);
        irLabel_4->setAlignment(Qt::AlignCenter);
        irLabel_4->setWordWrap(false);
        irLabel_2 = new QLabel(groupBox_11);
        irLabel_2->setObjectName("irLabel_2");
        irLabel_2->setGeometry(QRect(214, 31, 91, 16));
        irLabel_2->setFont(font7);
        irLabel_2->setLayoutDirection(Qt::LeftToRight);
        irLabel_2->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        irLabel_2->setFrameShape(QFrame::Box);
        irLabel_2->setLineWidth(1);
        irLabel_2->setTextFormat(Qt::AutoText);
        irLabel_2->setAlignment(Qt::AlignCenter);
        ir_1 = new QLCDNumber(groupBox_11);
        ir_1->setObjectName("ir_1");
        ir_1->setGeometry(QRect(113, 54, 91, 41));
        ir_1->setFont(font6);
        ir_1->setLayoutDirection(Qt::LeftToRight);
        ir_1->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        ir_1->setFrameShape(QFrame::Box);
        ir_1->setFrameShadow(QFrame::Plain);
        ir_1->setLineWidth(1);
        ir_1->setDigitCount(5);
        ir_1->setSegmentStyle(QLCDNumber::Flat);
        groupBox_12 = new QGroupBox(groupBox_10);
        groupBox_12->setObjectName("groupBox_12");
        groupBox_12->setGeometry(QRect(340, 30, 221, 111));
        groupBox_12->setFont(font1);
        groupBox_12->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(groupBox_12);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 30, 201, 61));
        gridLayout_6 = new QGridLayout(layoutWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        leftHSensorLabel = new QLabel(layoutWidget);
        leftHSensorLabel->setObjectName("leftHSensorLabel");
        leftHSensorLabel->setFont(font7);
        leftHSensorLabel->setLayoutDirection(Qt::LeftToRight);
        leftHSensorLabel->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        leftHSensorLabel->setFrameShape(QFrame::Box);
        leftHSensorLabel->setLineWidth(1);
        leftHSensorLabel->setTextFormat(Qt::AutoText);
        leftHSensorLabel->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(leftHSensorLabel, 0, 0, 1, 1);

        rightHSensorLabel = new QLabel(layoutWidget);
        rightHSensorLabel->setObjectName("rightHSensorLabel");
        rightHSensorLabel->setFont(font7);
        rightHSensorLabel->setLayoutDirection(Qt::LeftToRight);
        rightHSensorLabel->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        rightHSensorLabel->setFrameShape(QFrame::Box);
        rightHSensorLabel->setLineWidth(1);
        rightHSensorLabel->setTextFormat(Qt::AutoText);
        rightHSensorLabel->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(rightHSensorLabel, 0, 1, 1, 1);

        leftPulsesLCD = new QLCDNumber(layoutWidget);
        leftPulsesLCD->setObjectName("leftPulsesLCD");
        leftPulsesLCD->setFont(font6);
        leftPulsesLCD->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        leftPulsesLCD->setFrameShape(QFrame::Box);
        leftPulsesLCD->setFrameShadow(QFrame::Plain);
        leftPulsesLCD->setLineWidth(1);
        leftPulsesLCD->setDigitCount(5);
        leftPulsesLCD->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_6->addWidget(leftPulsesLCD, 1, 0, 1, 1);

        rightPulsesLCD = new QLCDNumber(layoutWidget);
        rightPulsesLCD->setObjectName("rightPulsesLCD");
        rightPulsesLCD->setFont(font6);
        rightPulsesLCD->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        rightPulsesLCD->setFrameShape(QFrame::Box);
        rightPulsesLCD->setFrameShadow(QFrame::Plain);
        rightPulsesLCD->setLineWidth(1);
        rightPulsesLCD->setDigitCount(5);
        rightPulsesLCD->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_6->addWidget(rightPulsesLCD, 1, 1, 1, 1);

        gridLayout_6->setRowStretch(1, 1);
        groupBox_13 = new QGroupBox(groupBox_10);
        groupBox_13->setObjectName("groupBox_13");
        groupBox_13->setGeometry(QRect(580, 30, 251, 111));
        groupBox_13->setFont(font1);
        groupBox_13->setAlignment(Qt::AlignCenter);
        layoutWidget1 = new QWidget(groupBox_13);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 30, 231, 61));
        gridLayout_7 = new QGridLayout(layoutWidget1);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        dLabel = new QLabel(layoutWidget1);
        dLabel->setObjectName("dLabel");
        dLabel->setFont(font7);
        dLabel->setLayoutDirection(Qt::LeftToRight);
        dLabel->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        dLabel->setFrameShape(QFrame::Box);
        dLabel->setLineWidth(1);
        dLabel->setTextFormat(Qt::AutoText);
        dLabel->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(dLabel, 0, 0, 1, 1);

        sLabel = new QLabel(layoutWidget1);
        sLabel->setObjectName("sLabel");
        sLabel->setFont(font7);
        sLabel->setLayoutDirection(Qt::LeftToRight);
        sLabel->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        sLabel->setFrameShape(QFrame::Box);
        sLabel->setLineWidth(1);
        sLabel->setTextFormat(Qt::AutoText);
        sLabel->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(sLabel, 0, 1, 1, 1);

        distanceLCD = new QLCDNumber(layoutWidget1);
        distanceLCD->setObjectName("distanceLCD");
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Arial")});
        font8.setPointSize(10);
        font8.setBold(false);
        font8.setItalic(false);
        font8.setUnderline(false);
        font8.setStrikeOut(false);
        font8.setKerning(true);
        distanceLCD->setFont(font8);
        distanceLCD->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        distanceLCD->setFrameShape(QFrame::Box);
        distanceLCD->setFrameShadow(QFrame::Plain);
        distanceLCD->setLineWidth(1);
        distanceLCD->setDigitCount(6);
        distanceLCD->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_7->addWidget(distanceLCD, 1, 0, 1, 1);

        angleLCD = new QLCDNumber(layoutWidget1);
        angleLCD->setObjectName("angleLCD");
        angleLCD->setFont(font8);
        angleLCD->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        angleLCD->setFrameShape(QFrame::Box);
        angleLCD->setFrameShadow(QFrame::Plain);
        angleLCD->setLineWidth(1);
        angleLCD->setDigitCount(6);
        angleLCD->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_7->addWidget(angleLCD, 1, 1, 1, 1);

        gridLayout_7->setRowStretch(1, 1);
        gyro_2 = new QLCDNumber(groupBox_10);
        gyro_2->setObjectName("gyro_2");
        gyro_2->setGeometry(QRect(540, 170, 81, 41));
        gyro_2->setDigitCount(6);
        gyro_0 = new QLCDNumber(groupBox_10);
        gyro_0->setObjectName("gyro_0");
        gyro_0->setGeometry(QRect(340, 170, 81, 41));
        gyro_0->setDigitCount(6);
        gyro_1 = new QLCDNumber(groupBox_10);
        gyro_1->setObjectName("gyro_1");
        gyro_1->setGeometry(QRect(440, 170, 81, 41));
        gyro_1->setDigitCount(6);
        accel_2 = new QLCDNumber(groupBox_10);
        accel_2->setObjectName("accel_2");
        accel_2->setGeometry(QRect(540, 220, 81, 41));
        accel_2->setDigitCount(6);
        accel_0 = new QLCDNumber(groupBox_10);
        accel_0->setObjectName("accel_0");
        accel_0->setGeometry(QRect(340, 220, 81, 41));
        accel_0->setDigitCount(6);
        accel_1 = new QLCDNumber(groupBox_10);
        accel_1->setObjectName("accel_1");
        accel_1->setGeometry(QRect(440, 220, 81, 41));
        accel_1->setDigitCount(6);
        vel_1 = new QLCDNumber(groupBox_10);
        vel_1->setObjectName("vel_1");
        vel_1->setGeometry(QRect(440, 270, 81, 41));
        vel_1->setDigitCount(6);
        vel_0 = new QLCDNumber(groupBox_10);
        vel_0->setObjectName("vel_0");
        vel_0->setGeometry(QRect(340, 270, 81, 41));
        vel_0->setDigitCount(6);
        vel_2 = new QLCDNumber(groupBox_10);
        vel_2->setObjectName("vel_2");
        vel_2->setGeometry(QRect(540, 270, 81, 41));
        vel_2->setDigitCount(6);
        groupBox_14 = new QGroupBox(centralwidget);
        groupBox_14->setObjectName("groupBox_14");
        groupBox_14->setGeometry(QRect(880, 10, 401, 151));
        groupBox_14->setFont(font1);
        groupBox_14->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid gray;\n"
"    border-color: black;\n"
"    border-radius: 2px;\n"
"}"));
        groupBox_15 = new QGroupBox(groupBox_14);
        groupBox_15->setObjectName("groupBox_15");
        groupBox_15->setGeometry(QRect(10, 30, 101, 111));
        groupBox_15->setFont(font1);
        groupBox_15->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid gray;\n"
"    border-color: black;\n"
"    border-radius: 2px;\n"
"}"));
        groupBox_15->setAlignment(Qt::AlignCenter);
        EstadoBotonLabel = new QLabel(groupBox_15);
        EstadoBotonLabel->setObjectName("EstadoBotonLabel");
        EstadoBotonLabel->setGeometry(QRect(10, 30, 81, 61));
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Arial")});
        font9.setPointSize(10);
        font9.setBold(true);
        font9.setItalic(false);
        EstadoBotonLabel->setFont(font9);
        EstadoBotonLabel->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        EstadoBotonLabel->setFrameShape(QFrame::Box);
        EstadoBotonLabel->setFrameShadow(QFrame::Plain);
        EstadoBotonLabel->setLineWidth(1);
        EstadoBotonLabel->setAlignment(Qt::AlignCenter);
        groupBox_17 = new QGroupBox(groupBox_14);
        groupBox_17->setObjectName("groupBox_17");
        groupBox_17->setGeometry(QRect(120, 30, 131, 111));
        groupBox_17->setFont(font1);
        groupBox_17->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid gray;\n"
"    border-color: black;\n"
"    border-radius: 2px;\n"
"}"));
        groupBox_17->setAlignment(Qt::AlignCenter);
        AliveLabel = new QLabel(groupBox_17);
        AliveLabel->setObjectName("AliveLabel");
        AliveLabel->setGeometry(QRect(10, 30, 111, 61));
        AliveLabel->setFont(font9);
        AliveLabel->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;\n"
"background-color: red;\n"
"color: white;"));
        AliveLabel->setFrameShape(QFrame::Box);
        AliveLabel->setFrameShadow(QFrame::Plain);
        AliveLabel->setLineWidth(1);
        AliveLabel->setAlignment(Qt::AlignCenter);
        groupBox_16 = new QGroupBox(groupBox_14);
        groupBox_16->setObjectName("groupBox_16");
        groupBox_16->setGeometry(QRect(260, 30, 131, 111));
        groupBox_16->setFont(font1);
        groupBox_16->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid gray;\n"
"    border-color: black;\n"
"    border-radius: 2px;\n"
"}"));
        groupBox_16->setAlignment(Qt::AlignCenter);
        FirmwareLabel = new QLabel(groupBox_16);
        FirmwareLabel->setObjectName("FirmwareLabel");
        FirmwareLabel->setGeometry(QRect(10, 30, 111, 61));
        FirmwareLabel->setFont(font9);
        FirmwareLabel->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        FirmwareLabel->setFrameShape(QFrame::Box);
        FirmwareLabel->setFrameShadow(QFrame::Plain);
        FirmwareLabel->setLineWidth(1);
        FirmwareLabel->setAlignment(Qt::AlignCenter);
        radarButton = new QPushButton(centralwidget);
        radarButton->setObjectName("radarButton");
        radarButton->setGeometry(QRect(140, 663, 141, 61));
        radarButton->setFont(font2);
        scaleSlider = new QSlider(centralwidget);
        scaleSlider->setObjectName("scaleSlider");
        scaleSlider->setGeometry(QRect(1240, 360, 20, 361));
        scaleSlider->setMinimum(100);
        scaleSlider->setMaximum(400);
        scaleSlider->setSingleStep(1);
        scaleSlider->setPageStep(10);
        scaleSlider->setValue(100);
        scaleSlider->setSliderPosition(100);
        scaleSlider->setOrientation(Qt::Vertical);
        scaleSlider->setTickPosition(QSlider::NoTicks);
        rangeLCD = new QLCDNumber(centralwidget);
        rangeLCD->setObjectName("rangeLCD");
        rangeLCD->setGeometry(QRect(290, 680, 141, 41));
        rangeLCD->setFont(font6);
        rangeLCD->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        rangeLCD->setFrameShape(QFrame::Box);
        rangeLCD->setFrameShadow(QFrame::Plain);
        rangeLCD->setLineWidth(1);
        rangeLCD->setDigitCount(7);
        rangeLCD->setSegmentStyle(QLCDNumber::Flat);
        rangeLabel = new QLabel(centralwidget);
        rangeLabel->setObjectName("rangeLabel");
        rangeLabel->setGeometry(QRect(290, 660, 141, 21));
        QFont font10;
        font10.setBold(true);
        font10.setItalic(false);
        rangeLabel->setFont(font10);
        rangeLabel->setLayoutDirection(Qt::LeftToRight);
        rangeLabel->setStyleSheet(QString::fromUtf8("border: 1px solid gray;\n"
"border-color: black;\n"
"border-radius: 2px;"));
        rangeLabel->setFrameShape(QFrame::Box);
        rangeLabel->setLineWidth(1);
        rangeLabel->setTextFormat(Qt::AutoText);
        rangeLabel->setAlignment(Qt::AlignCenter);
        widgetRadar = new QWidget(centralwidget);
        widgetRadar->setObjectName("widgetRadar");
        widgetRadar->setGeometry(QRect(440, 520, 128, 64));
        position_0 = new QLCDNumber(centralwidget);
        position_0->setObjectName("position_0");
        position_0->setGeometry(QRect(780, 530, 81, 41));
        position_0->setDigitCount(6);
        position_2 = new QLCDNumber(centralwidget);
        position_2->setObjectName("position_2");
        position_2->setGeometry(QRect(980, 530, 81, 41));
        position_2->setDigitCount(6);
        position_1 = new QLCDNumber(centralwidget);
        position_1->setObjectName("position_1");
        position_1->setGeometry(QRect(880, 530, 81, 41));
        position_1->setDigitCount(6);
        pitch_0 = new QLCDNumber(centralwidget);
        pitch_0->setObjectName("pitch_0");
        pitch_0->setGeometry(QRect(580, 580, 161, 41));
        pitch_0->setDigitCount(8);
        roll_0 = new QLCDNumber(centralwidget);
        roll_0->setObjectName("roll_0");
        roll_0->setGeometry(QRect(780, 580, 181, 41));
        roll_0->setSmallDecimalPoint(false);
        roll_0->setDigitCount(8);
        contraAccel_y = new QLCDNumber(centralwidget);
        contraAccel_y->setObjectName("contraAccel_y");
        contraAccel_y->setGeometry(QRect(980, 630, 181, 41));
        contraAccel_y->setSmallDecimalPoint(false);
        contraAccel_y->setDigitCount(8);
        contraAccel_x = new QLCDNumber(centralwidget);
        contraAccel_x->setObjectName("contraAccel_x");
        contraAccel_x->setGeometry(QRect(780, 630, 161, 41));
        contraAccel_x->setDigitCount(8);
        yaw_0 = new QLCDNumber(centralwidget);
        yaw_0->setObjectName("yaw_0");
        yaw_0->setGeometry(QRect(980, 580, 181, 41));
        yaw_0->setSmallDecimalPoint(false);
        yaw_0->setDigitCount(8);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 1296, 25));
        menuConfiguraciones = new QMenu(menubar);
        menuConfiguraciones->setObjectName("menuConfiguraciones");
        menuConfiguraciones->setEnabled(true);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuConfiguraciones->menuAction());
        menuConfiguraciones->addAction(actionScanPorts);
        menuConfiguraciones->addAction(actionConnect_Device);
        menuConfiguraciones->addAction(actionDisconnect);
        menuConfiguraciones->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Car Management", nullptr));
        actionScanPorts->setText(QCoreApplication::translate("MainWindow", "ScanPorts", nullptr));
        actionConnect_Device->setText(QCoreApplication::translate("MainWindow", "Connect_Device", nullptr));
        actionDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "DATA FLOW", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "COMUNICATIONS SETTINGS", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "UDP SERVER", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Local Port:", nullptr));
        pushButtonUdpOpen->setText(QCoreApplication::translate("MainWindow", "OPEN", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "UDP CLIENT", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "IP Adress:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Remote Port:", nullptr));
#if QT_CONFIG(accessibility)
        groupBox_3->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "COMMAND WINDOW", nullptr));
        pushButtonSend->setText(QCoreApplication::translate("MainWindow", "SEND UART", nullptr));
        pushButtonSend_2->setText(QCoreApplication::translate("MainWindow", "SEND UDP", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "DATA COMMANDS", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "CAR GADGETS SETTINGS", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "IR SENSORS SETTING", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "WHITE", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "BLACK", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "SERVO SETTING", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "MIN", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "MAX", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("MainWindow", "CAR SENSORS INFO", nullptr));
        groupBox_11->setTitle(QCoreApplication::translate("MainWindow", "IR SENSORS", nullptr));
        irLabel_5->setText(QCoreApplication::translate("MainWindow", "FOUR", nullptr));
        irLabel_6->setText(QCoreApplication::translate("MainWindow", "THREE", nullptr));
        irLabel_7->setText(QCoreApplication::translate("MainWindow", "FIVE", nullptr));
        irLabel_8->setText(QCoreApplication::translate("MainWindow", "SEVEN", nullptr));
        irLabel_9->setText(QCoreApplication::translate("MainWindow", "SIX", nullptr));
        irLabel_3->setText(QCoreApplication::translate("MainWindow", "ONE", nullptr));
        irLabel_4->setText(QCoreApplication::translate("MainWindow", "CERO", nullptr));
        irLabel_2->setText(QCoreApplication::translate("MainWindow", "TWO", nullptr));
        groupBox_12->setTitle(QCoreApplication::translate("MainWindow", "SPEED (RPM)", nullptr));
        leftHSensorLabel->setText(QCoreApplication::translate("MainWindow", "LEFT", nullptr));
        rightHSensorLabel->setText(QCoreApplication::translate("MainWindow", "RIGHT", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("MainWindow", "DISTANCE AND SERVO", nullptr));
        dLabel->setText(QCoreApplication::translate("MainWindow", "DISTANCE (CM)", nullptr));
        sLabel->setText(QCoreApplication::translate("MainWindow", "SERVO ANGLE", nullptr));
        groupBox_14->setTitle(QCoreApplication::translate("MainWindow", "STATE INFO", nullptr));
        groupBox_15->setTitle(QCoreApplication::translate("MainWindow", "BUTTON", nullptr));
        EstadoBotonLabel->setText(QCoreApplication::translate("MainWindow", "UP", nullptr));
        groupBox_17->setTitle(QCoreApplication::translate("MainWindow", "ALIVE", nullptr));
        AliveLabel->setText(QCoreApplication::translate("MainWindow", "NO", nullptr));
        groupBox_16->setTitle(QCoreApplication::translate("MainWindow", "FIRMWARE", nullptr));
        FirmwareLabel->setText(QCoreApplication::translate("MainWindow", "UNKNOW", nullptr));
        radarButton->setText(QCoreApplication::translate("MainWindow", "RUN RADAR", nullptr));
        rangeLabel->setText(QCoreApplication::translate("MainWindow", "MAX RANGE (CM)", nullptr));
        menuConfiguraciones->setTitle(QCoreApplication::translate("MainWindow", "UART", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
