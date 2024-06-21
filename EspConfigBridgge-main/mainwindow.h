#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "qlcdnumber.h"
#define NUMSWITCHES                 1
#define SERIALCONNECTION            1
#define UDPCONNECTION               2
#define MINRANGOSLIDER              100
#define SAMPLE_FREQ   100.0f      // sample frequency in Hz
#define TWO_KP_DEF    (2.0f * 0.5f)   // 2 * proportional gain
#define TWO_KI_DEF    (2.0f * 0.0f)   // 2 * integral gain
#define DEG_TO_RAD    0.017453292f

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtNetwork/QUdpSocket>
#include <QLabel>
#include <QDebug>
#include <QInputDialog>
#include "settingsdialog.h"
#include <QTimer>
#include <qpaintbox.h>
#include <QPainter>
#include <QStyle>
#include <qlcdnumber.h>
#include <QElapsedTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openSerialPorts();

    void closeSerialPorts();

    void dataRecived();

    void decodeData(uint8_t *datosRx, uint8_t source);

    void sendDataSerial();

    void sendDataUDP();

    void on_pushButtonUdpOpen_clicked();

    void OnUdpRxData();

    void OnQTimer1(); // Se implementa con Alt + enter

    void inicializaciones();

    void lecturaSensores();

    void reiniciarUI();

    void on_radarButton_clicked();

    void DibujarFondoRadar();

    void RadarRun();

    void DibujarDeteccion();

    // void setupPlot();

    //void updatePlot(float ax, float ay, float deltaTime);

    //double integrate(float previousValue, float newValue, float deltaTime);

    void MahonyAHRSupdateIMU(float gx, float gy, float gz, float ax, float ay, float az);

private:

    Ui::MainWindow *ui;
    QSerialPort *serial;
    SettingsDialog *settingPorts;
    QLabel *estadoSerial;
    QUdpSocket *UdpSocket1;
    QHostAddress RemoteAddress;
    quint16 RemotePort;
    QHostAddress clientAddress;
    int puertoremoto;

    typedef enum{
        START,
        HEADER_1,
        HEADER_2,
        HEADER_3,
        NBYTES,
        TOKEN,
        PAYLOAD
    }_eProtocolo;

    _eProtocolo estadoProtocolo, estadoProtocoloUdp;

    typedef enum{
       UDP=0,
       SERIE=1,
       STARTCONFIG=0xEE,
       ACK=0x0D,
       GETALIVE=0xF0,
       GETFIRMWARE=0xF1,
       UNKNOWCMD=0xFF,
       SETLEDS=0x10,
       GETSWITCHES=0x12,
       LAST_ADC=0xA0,
       SETMOTORTEST=0xA1,
       MPU=0xA2,
       //SERVOMOVESTOP=0x0A,
       //GETDISTANCE=0xA3,
       GETSPEED=0xA4,
       //SETSERVOLIMITS=0xA5,
       //SETBLACKCOLORDETECTED=0xA6,
       //SETWHITECOLORDETECTED=0xA7,
       //GETSERVOANGLE=0xA8,
       OTHERS
    }_eCmd;

    typedef enum {
        MOVIENDO_SERVO = 1,
        MIDIENDO = 2,
        DIBUJANDO = 3,
        FINALIZANDO = 4
    }_eEstadosRadar;

    typedef struct{
        uint8_t timeOut;
        uint8_t cheksum;
        uint8_t payLoad[256];
        uint8_t nBytes;
        uint8_t index;
    }_sDatos ;

    _sDatos rxData, rxDataUdp;

    typedef union{
        uint8_t     u8[4];
        int8_t      i8[4];
        uint16_t    u16[2];
        int16_t     i16[2];
        uint32_t    u32;
        int32_t     i32;
        float       f;
    }_work;

    typedef union {
        double  d32;
        float f32;
        int i32;
        unsigned int ui32;
        unsigned short ui16[2];
        short i16[2];
        uint8_t ui8[4];
        char chr[4];
        unsigned char uchr[4];
        int8_t  i8[4];
    }_udat;

//    typedef struct{
//        uint16_t    ir_ONE;
//        uint16_t    ir_TWO;
//        uint16_t    ir_THREE;
//        uint16_t    ir_FOUR;
//        uint16_t    ir_FIVE;
//        uint16_t    ir_SIX;
//        uint16_t    ir_SEVEN;
//        uint16_t    ir_EIGHT;
//    }_irStruct;
//    _irStruct irSensors;

    typedef struct{
        uint32_t rightSensorPulses;
        uint32_t leftSensorPulses;
    }_sHorquillaSensors;
    _sHorquillaSensors hSensors;

    typedef struct{
        uint8_t modo;
        uint16_t maxMsServo;
        uint16_t minMsServo;
    }_sServoConfig;
    _sServoConfig servoConfig;

    typedef struct{
        uint8_t     modo;
        uint16_t    blackLeft;
        uint16_t    blackCenter;
        uint16_t    blackRight;
        uint16_t    whiteLeft;
        uint16_t    whiteCenter;
        uint16_t    whiteRight;
    }_sIrConfig;
    _sIrConfig irConfig;

    typedef struct{
        bool status;
    }_sSwitches;
    _sSwitches switches[NUMSWITCHES];

    int contadorAlive=0;

    /******TCRT5000******/
    uint16_t irSensorsMeasure[8];

    /******MPU******/
    // int32_t Gyro[3];
    // int32_t Accel[3];
    // int32_t prevAccel[3];
    // int32_t prevVel[3];
    // int32_t position[3];
    // int32_t Vel[3];
    float twoKp = TWO_KP_DEF;    // 2 * proportional gain (Kp)
    float twoKi = TWO_KI_DEF;    // 2 * integral gain (Ki)
    float integralFBx = 0.0f;
    float integralFBy = 0.0f;
    float integralFBz = 0.0f;    // integral error terms scaled by Ki
    typedef struct {
        float q0, q1, q2, q3;  // Quaternion
    } Quaternion;
    Quaternion q = {1.0f, 0.0f, 0.0f, 0.0f};  // Quaternion of sensor frame relative to au
    typedef struct {
        float x, y, z;
    } Vector3f;
    Vector3f gravity_earth = {0, 0, 0.981}; // Assuming 1g in the z direction
    Vector3f gravity;
    Vector3f lineal_accel;
    Vector3f velocity;
    Vector3f position;
    float Gyro[3];
    float Accel[3];
    float prevAccel[3];
    float prevVel[3];
    //float position[3];
    float Vel[3];
    // int32_t roll, pitch;
    // int32_t roll_g, pitch_g;
    // int32_t roll_a, pitch_a;
    // int32_t gravedad_x;
    // int32_t gravedad_y;
    float roll, pitch, yaw;
    float roll_g, pitch_g;
    float roll_a, pitch_a;
    float gravedad_x;
    float gravedad_y;
    float px, py;
    float vx, vy;
    float previousTime;
    float aux = 0;

    /*TIMER*/
    QTimer *QTimer1;
    uint8_t timeLecturaSensoresTask10ms = 0;
    uint16_t timeClearLog10ms = 0;
    QElapsedTimer PreciseTimer;

    /*SERVO*/
    bool servoIsMoving = false;
    uint8_t servoAngle;
    uint8_t servoAngleToShow = 90;

    /*ULTRASONIDO*/
    uint32_t distancia;

    /*RADAR*/
    bool radarDrawing = false;
    uint8_t radarStatus;
    QPaintBox *QPaintBox1;

    /*AUXILIARES PARA ENVIAR PETICIONES*/
    bool isASelectedCmd = false;
    uint8_t auxComand;
    bool recibirConfig = true;

    /*METODO DE CONEXION Y ALIVE*/
    uint8_t connectionType = 0;
    uint16_t aliveTimeOut = 0;
    bool alive = false;
    char firmwareCadena[30];

};
#endif // MAINWINDOW_H
