#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <stdio.h>
#include <QDateTime>
#include <QtGlobal>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setupPlot();

    connect(ui->actionExit,&QAction::triggered,this,&MainWindow::close);

    serial = new QSerialPort(this);
    settingPorts = new SettingsDialog(this);
    connect(ui->pushButtonSend,&QPushButton::clicked,this,&MainWindow::sendDataSerial);
    connect(serial,&QSerialPort::readyRead,this,&MainWindow::dataRecived);
    connect(ui->actionScanPorts,&QAction::triggered,settingPorts,&SettingsDialog::show);
    connect(ui->actionConnect_Device, &QAction::triggered,this,&MainWindow::openSerialPorts);
    connect(ui->actionDisconnect,&QAction::triggered,this,&MainWindow::closeSerialPorts);
    estadoProtocolo = START;

    UdpSocket1 = new QUdpSocket(this);
    ui->pushButtonSend_2->setEnabled(false);
    connect(ui->pushButtonSend_2,&QPushButton::clicked,this,&MainWindow::sendDataUDP);
    connect(UdpSocket1,&QUdpSocket::readyRead,this,&MainWindow::OnUdpRxData);
    estadoProtocoloUdp = START;

    estadoSerial = new QLabel(this);
    estadoSerial->setText("Desconectado ......");
    ui->statusbar->addWidget(estadoSerial);
    ui->actionDisconnect->setEnabled(false);

    QTimer1 = new QTimer(this);
    connect(QTimer1, &QTimer::timeout, this, &MainWindow::OnQTimer1);

    QPaintBox1 = new QPaintBox(0, 0, ui->widgetRadar);

    ui->comboBoxCom->addItem("ALIVE", 0xF0);
    ui->comboBoxCom->addItem("FIRMWARE", 0xF1);
    //ui->comboBoxCom->addItem("LEDS STATE", 0x10);
    ui->comboBoxCom->addItem("SWITCHS STATE", 0x12);
    ui->comboBoxCom->addItem("DISTANCE", 0xA3);
    ui->comboBoxCom->addItem("IRs STATE", 0xA0);
    ui->comboBoxCom->addItem("IRs BLACK CONFIG", 0xA6);
    ui->comboBoxCom->addItem("IRs WHITE CONFIG", 0xA7);
    ui->comboBoxCom->addItem("SERVO ANGLE", 0xA2);
    ui->comboBoxCom->addItem("SERVO CONFIG", 0xA5);
    ui->comboBoxCom->addItem("MOTOR POWER", 0xA1);
    ui->comboBoxCom->addItem("SPEED", 0xA4);

    //C:/Users/ivanl/OneDrive/Documentos/Microcontroladores/DESKTOP_COMPUTER/EspConfigBridgge/EspConfigBridgge/background3.jpg
    //C:/Users/GAMING/Documents/Microcontroladores/Qt_nuevo/EspConfigBridgge/EspConfigBridgge/background3.jpg

    QPixmap bkgnd("C:/Users/ivanl/OneDrive/Documentos/Microcontroladores/DESKTOP_COMPUTER/EspConfigBridgge/EspConfigBridgge/background3.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete QPaintBox1;
}

void MainWindow::MahonyAHRSupdateIMU(float gx, float gy, float gz, float ax, float ay, float az)
{
    float recipNorm;
    float halfvx, halfvy, halfvz;
    float halfex, halfey, halfez;
    float qa, qb, qc;

    // Convert gyroscope degrees/sec to radians/sec
    gx *= 0.0174533f;
    gy *= 0.0174533f;
    gz *= 0.0174533f;

    // Compute feedback only if accelerometer measurement valid (avoids NaN in accelerometer normalisation)
    if(!((ax == 0.0f) && (ay == 0.0f) && (az == 0.0f))) {

        // Normalise accelerometer measurement
        recipNorm = 1.0f / sqrtf(ax * ax + ay * ay + az * az);
        ax *= recipNorm;
        ay *= recipNorm;
        az *= recipNorm;

        // Estimated direction of gravity and vector perpendicular to magnetic flux
        halfvx = q.q1 * q.q3 - q.q0 * q.q2;
        halfvy = q.q0 * q.q1 + q.q2 * q.q3;
        halfvz = q.q0 * q.q0 - 0.5f + q.q3 * q.q3;

        // Error is sum of cross product between estimated and measured direction of gravity
        halfex = (ay * halfvz - az * halfvy);
        halfey = (az * halfvx - ax * halfvz);
        halfez = (ax * halfvy - ay * halfvx);

        // Compute and apply integral feedback if enabled
        if(twoKi > 0.0f) {
            integralFBx += twoKi * halfex * (1.0f / SAMPLE_FREQ);  // integral error scaled by Ki
            integralFBy += twoKi * halfey * (1.0f / SAMPLE_FREQ);
            integralFBz += twoKi * halfez * (1.0f / SAMPLE_FREQ);
            gx += integralFBx;      // apply integral feedback
            gy += integralFBy;
            gz += integralFBz;
        }
        else {
            integralFBx = 0.0f;     // prevent integral windup
            integralFBy = 0.0f;
            integralFBz = 0.0f;
        }

        // Apply proportional feedback
        gx += twoKp * halfex;
        gy += twoKp * halfey;
        gz += twoKp * halfez;
    }

    // Integrate rate of change of quaternion
    gx *= (0.5f * (1.0f / SAMPLE_FREQ));     // pre-multiply common factors
    gy *= (0.5f * (1.0f / SAMPLE_FREQ));
    gz *= (0.5f * (1.0f / SAMPLE_FREQ));
    qa = q.q0;
    qb = q.q1;
    qc = q.q2;
    q.q0 += (-qb * gx - qc * gy - q.q3 * gz);
    q.q1 += (qa * gx + qc * gz - q.q3 * gy);
    q.q2 += (qa * gy - qb * gz + q.q3 * gx);
    q.q3 += (qa * gz + qb * gy - qc * gx);

    // Normalise quaternion
    recipNorm = 1.0f / sqrtf(q.q0 * q.q0 + q.q1 * q.q1 + q.q2 * q.q2 + q.q3 * q.q3);
    q.q0 *= recipNorm;
    q.q1 *= recipNorm;
    q.q2 *= recipNorm;
    q.q3 *= recipNorm;
}


void MainWindow::openSerialPorts()
{
    if(UdpSocket1->isOpen()){
        UdpSocket1->close();
        ui->pushButtonUdpOpen->setText("OPEN");
        QTimer1->stop();
        alive = false;
        reiniciarUI();
        return;
    }

    const SettingsDialog::Settings p = settingPorts->settings();
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    serial->open(QSerialPort::ReadWrite);
    if (serial->isOpen()){
        ui->actionDisconnect->setEnabled(true);
        estadoSerial->setText(tr("Connected to %1 : %2, %3, %4, %5, %6, %7")
                                .arg(p.name)
                                .arg(p.stringBaudRate)
                                .arg(p.stringDataBits)
                                .arg(p.stringParity)
                                .arg(p.stringStopBits)
                                .arg(p.stringFlowControl)
                                .arg(p.fabricante)
                               );
        QTimer1->start(10);
        inicializaciones();
        connectionType = SERIALCONNECTION;
    } else {
       QMessageBox::critical(this, tr("Error"), serial->errorString());
    }
}

void MainWindow::closeSerialPorts()
{
    ui->actionDisconnect->setEnabled(false);
    estadoSerial->setText("Desconectado ......");
    if (serial->isOpen()) {
        serial->close();
        QTimer1->stop();
        alive = false;
        reiniciarUI();
    }
}

void MainWindow::on_pushButtonUdpOpen_clicked()
{
    int Port;
    bool ok;

    ui->actionDisconnect->setEnabled(false);
    estadoSerial->setText("Desconectado ......");
    if (serial->isOpen()) {
        serial->close();
        QTimer1->stop();
        alive = false;
        reiniciarUI();
        return;
    }

    if(UdpSocket1->isOpen()){
        UdpSocket1->close();
        ui->pushButtonUdpOpen->setText("OPEN");
        QTimer1->stop();
        alive = false;
        reiniciarUI();
        return;
    }

    Port = ui->lineEditLocalPort->text().toInt(&ok,10);
    if(!ok || Port<=0 || Port>65535){
        QMessageBox::information(this, tr("SERVER PORT"),tr("ERRRO. Number PORT."));
        return;
    }

    try{
        UdpSocket1->abort();
        UdpSocket1->bind(Port);
        UdpSocket1->open(QUdpSocket::ReadWrite);
    }catch(...){
        QMessageBox::information(this, tr("SERVER PORT"),tr("Can't OPEN Port."));
        return;
    }
    ui->pushButtonUdpOpen->setText("CLOSE");
    ui->pushButtonSend_2->setEnabled(true);
    ui->pushButtonSend->setEnabled(false);
    if (UdpSocket1->isOpen()){
        if(clientAddress.isNull())
            clientAddress.setAddress(ui->lineEditIP->text());
        if(puertoremoto==0)
            puertoremoto=ui->lineEditPort->text().toInt();
        UdpSocket1->writeDatagram("r", 1, clientAddress, puertoremoto);
        QTimer1->start(10);
        inicializaciones();
        connectionType = UDPCONNECTION;
    }
}

void MainWindow::dataRecived() //!< RECIBIR DATOS POR SERIAL
{
    unsigned char *incomingBuffer;
    int count;

    count = serial->bytesAvailable();
    if(count<=0)
        return;
    incomingBuffer = new unsigned char[count];
    serial->read((char *)incomingBuffer,count);
    QString str="";
    for(int i=0; i<=count; i++){
        if(isalnum(incomingBuffer[i]))
            str = str + QString("%1").arg((char)incomingBuffer[i]);
        else
            str = str +"{" + QString("%1").arg(incomingBuffer[i],2,16,QChar('0')) + "}";
    }
    ui->textBrowser->append("MBED-->SERIAL-->PC (" + str + ")");

    for(int i=0;i<count; i++){
        switch (estadoProtocolo) {
            case START:
                if (incomingBuffer[i]=='U'){
                    estadoProtocolo=HEADER_1;
                    rxData.cheksum=0;
                }
                break;
            case HEADER_1:
                if (incomingBuffer[i]=='N')
                   estadoProtocolo=HEADER_2;
                else{
                    i--;
                    estadoProtocolo=START;
                }
                break;
            case HEADER_2:
                if (incomingBuffer[i]=='E')
                    estadoProtocolo=HEADER_3;
                else{
                    i--;
                   estadoProtocolo=START;
                }
                break;
            case HEADER_3:
                if (incomingBuffer[i]=='R')
                    estadoProtocolo=NBYTES;
                else{
                    i--;
                   estadoProtocolo=START;
                }
                break;
            case NBYTES:
                rxData.nBytes=incomingBuffer[i];
                estadoProtocolo=TOKEN;
                break;
            case TOKEN:
                if (incomingBuffer[i]==':'){
                    estadoProtocolo=PAYLOAD;
                    rxData.cheksum='U'^'N'^'E'^'R'^ rxData.nBytes^':';
                    rxData.payLoad[0]=rxData.nBytes;
                    rxData.index=1;
                }
                else{
                    i--;
                    estadoProtocolo=START;
                }
                break;
            case PAYLOAD:
                if (rxData.nBytes>1){
                    rxData.payLoad[rxData.index++]=incomingBuffer[i];
                    rxData.cheksum^=incomingBuffer[i];
                }
                rxData.nBytes--;
                if(rxData.nBytes==0){
                    estadoProtocolo=START;
                    if(rxData.cheksum==incomingBuffer[i]){
                        decodeData(&rxData.payLoad[0],SERIE);
                    }
                }
                break;
            default:
                estadoProtocolo=START;
                break;
        }
    }
    delete [] incomingBuffer;

}

void MainWindow::OnUdpRxData(){ //!< RECIBIR DATOS POR UDP
    qint64          count=0;
    unsigned char   *incomingBuffer;

    while(UdpSocket1->hasPendingDatagrams()){
        count = UdpSocket1->pendingDatagramSize();
        incomingBuffer = new unsigned char[count];
        UdpSocket1->readDatagram( reinterpret_cast<char *>(incomingBuffer), count, &RemoteAddress, &RemotePort);
    }

    QString str="";
    for(int i=0; i<=count; i++){
        if(isalnum(incomingBuffer[i]))
            str = str + QString("%1").arg(char(incomingBuffer[i]));
        else
            str = str +"{" + QString("%1").arg(incomingBuffer[i],2,16,QChar('0')) + "}";
    }
    ui->textBrowser->append("MBED-->UDP-->PC (" + str + ")");
    QString adress=RemoteAddress.toString();
    ui->textBrowser->append(" adr " + adress);
    ui->lineEditIP->setText(RemoteAddress.toString().right((RemoteAddress.toString().length())-7));
    ui->lineEditPort->setText(QString().number(RemotePort,10));

    for(int i=0;i<count; i++){
        switch (estadoProtocoloUdp) {
            case START:
                if (incomingBuffer[i]=='U'){
                    estadoProtocoloUdp=HEADER_1;
                    rxDataUdp.cheksum=0;
                }
                break;
            case HEADER_1:
                if (incomingBuffer[i]=='N')
                   estadoProtocoloUdp=HEADER_2;
                else{
                    i--;
                    estadoProtocoloUdp=START;
                }
                break;
            case HEADER_2:
                if (incomingBuffer[i]=='E')
                    estadoProtocoloUdp=HEADER_3;
                else{
                    i--;
                   estadoProtocoloUdp=START;
                }
                break;
            case HEADER_3:
                if (incomingBuffer[i]=='R')
                    estadoProtocoloUdp=NBYTES;
                else{
                    i--;
                   estadoProtocoloUdp=START;
                }
                break;
            case NBYTES:
                rxDataUdp.nBytes=incomingBuffer[i];
                estadoProtocoloUdp=TOKEN;
                break;
            case TOKEN:
                if (incomingBuffer[i]==':'){
                   estadoProtocoloUdp=PAYLOAD;
                   rxDataUdp.cheksum='U'^'N'^'E'^'R'^ rxDataUdp.nBytes^':';
                   rxDataUdp.payLoad[0]=rxDataUdp.nBytes;
                   rxDataUdp.index=1;
                }
                else{
                    i--;
                    estadoProtocoloUdp=START;
                }
                break;
            case PAYLOAD:
                if (rxDataUdp.nBytes>1){
                    rxDataUdp.payLoad[rxDataUdp.index++]=incomingBuffer[i];
                    rxDataUdp.cheksum^=incomingBuffer[i];
                }
                rxDataUdp.nBytes--;
                if(rxDataUdp.nBytes==0){
                    estadoProtocoloUdp=START;
                    if(rxDataUdp.cheksum==incomingBuffer[i]){
                        decodeData(&rxDataUdp.payLoad[0],UDP);
                    }else{
                        ui->textBrowser->append(" CHK DISTINTO!!!!! ");
                    }
                }
                break;
            default:
                estadoProtocoloUdp=START;
                break;
        }
    }
}

void MainWindow::decodeData(uint8_t *datosRx, uint8_t source)
{
    int32_t length = sizeof(*datosRx)/sizeof(datosRx[0]);
    uint8_t i=0;
    QString str, str2;
    _work myWorker;
    myWorker.u32 = 0;
    // int32_t accelPromedio = 0;
    // int32_t velPromedio = 0;
    float accelPromedio = 0;
    float velPromedio = 0;
    static uint8_t timeoutSpeed[3] = {0, 0, 0};

    for(int i = 1; i<length; i++){
        if(isalnum(datosRx[i]))
            str = str + QString("%1").arg(char(datosRx[i]));
        else
            str = str +QString("%1").arg(datosRx[i],2,16,QChar('0'));
    }
    ui->textBrowser->append("*(MBED-S->PC)->decodeData (" + str + ")");

    switch (datosRx[1]) {
        case LAST_ADC://     ANALOGSENSORS=0xA0,
            for (uint8_t i=0; i<16; i+=2) {
                myWorker.u8[0] = datosRx[i+2];
                myWorker.u8[1] = datosRx[i+3];
                irSensorsMeasure[i/2] = myWorker.u16[0];
            }

            for (uint8_t i=0; i<8; i++) {
                ui->txtBrowserCMD->append(QString("--> IR Nº%1 = %2").arg(i).arg(irSensorsMeasure[i]));
            }

            ui->ir_0->display(QString("%1").arg(irSensorsMeasure[0], 2, 10, QChar('0')));
            ui->ir_1->display(QString("%1").arg(irSensorsMeasure[1], 2, 10, QChar('0')));
            ui->ir_2->display(QString("%1").arg(irSensorsMeasure[2], 2, 10, QChar('0')));
            ui->ir_3->display(QString("%1").arg(irSensorsMeasure[3], 2, 10, QChar('0')));
            ui->ir_4->display(QString("%1").arg(irSensorsMeasure[4], 2, 10, QChar('0')));
            ui->ir_5->display(QString("%1").arg(irSensorsMeasure[5], 2, 10, QChar('0')));
            ui->ir_6->display(QString("%1").arg(irSensorsMeasure[6], 2, 10, QChar('0')));
            ui->ir_7->display(QString("%1").arg(irSensorsMeasure[7], 2, 10, QChar('0')));
            break;
        case SETMOTORTEST://     MOTORTEST=0xA1,
//            if (datosRx[4] == ACK)
//                ui->txtBrowserCMD->append("POWER HAS BEEN SET");
            break;
        case MPU://     SERVOANGLE=0xA2,
            for (uint8_t i=0; i<6; i+=2) {
                myWorker.u8[0] = datosRx[i+2];
                myWorker.u8[1] = datosRx[i+3];
                Accel[i/2] = myWorker.i16[0];
                if (i/2 == 2) {
                    Accel[i/2] = Accel[i/2] /15716; // revisar esto, el resultado tiene que ser cercano a 1
                } else {
                    Accel[i/2] = Accel[i/2] /16384;
                }
            }
            for (uint8_t i=8; i<14; i+=2) {
                myWorker.u8[0] = datosRx[i+2];
                myWorker.u8[1] = datosRx[i+3];
                Gyro[(i-8)/2] = myWorker.i16[0];
                Gyro[(i-8)/2] /= 131;
            }

            MahonyAHRSupdateIMU(Gyro[0], Gyro[1], Gyro[2], Accel[0], Accel[1], Accel[2]);

            roll = atan2f(2.0f * (q.q0 * q.q1 + q.q2 * q.q3), 1.0f - 2.0f * (q.q1 * q.q1 + q.q2 * q.q2));
            pitch = asinf(2.0f * (q.q0 * q.q2 - q.q3 * q.q1));
            yaw = atan2f(2.0f * (q.q0 * q.q3 + q.q1 * q.q2), 1.0f - 2.0f * (q.q2 * q.q2 + q.q3 * q.q3));

            // Convert to degrees
            roll *= 57.29578f;
            pitch *= 57.29578f;
            yaw *= 57.29578f;

            gravity.x = (1 - 2*q.q2*q.q2 - 2*q.q3*q.q3) * gravity_earth.x + (2*q.q1*q.q2 - 2*q.q3*q.q0) * gravity_earth.y + (2*q.q1*q.q3 + 2*q.q2*q.q0) * gravity_earth.z;
            gravity.y = (2*q.q1*q.q2 + 2*q.q3*q.q0) * gravity_earth.x + (1 - 2*q.q1*q.q1 - 2*q.q3*q.q3) * gravity_earth.y + (2*q.q2*q.q3 - 2*q.q1*q.q0) * gravity_earth.z;
            gravity.z = (2*q.q1*q.q3 - 2*q.q2*q.q0) * gravity_earth.x + (2*q.q2*q.q3 + 2*q.q1*q.q0) * gravity_earth.y + (1 - 2*q.q1*q.q1 - 2*q.q2*q.q2) * gravity_earth.z;

            lineal_accel.x = Accel[0] + gravity.x;
            lineal_accel.y = Accel[1] + gravity.y;
            lineal_accel.z = Accel[2] - gravity.z;

            // lineal_accel.x = Accel[0];
            // lineal_accel.y = Accel[1];
            // lineal_accel.z = Accel[2];

            // if (!firstTime) {
            //     firstTime = 1;
            //     roll = atan2(Accel[1], Accel[2]);
            //     pitch = atan2(-Accel[0], sqrt(Accel[1] * Accel[1] + Accel[2] * Accel[2]));
            // }

            // Integrar giroscopio para calcular roll y pitch
            // roll_g = roll + Gyro[0] * 10 / 1000;
            // pitch_g = pitch + Gyro[1] * 10 / 1000;

            // roll_a = atan2(Accel[1], Accel[2]) * 1000;
            // pitch_a = atan2(-Accel[0], sqrt(Accel[1] * Accel[1] + Accel[2] * Accel[2])) * 1000;

            // roll = (990 * roll_g + (1000 - 990) * roll_a) / 1000;
            // pitch = (990 * pitch_g + (1000 - 990) * pitch_a) / 1000;

            // ui->txtBrowserCMD->append(QString("--> Roll = %1").arg(roll));
            // ui->txtBrowserCMD->append(QString("--> Pitch = %1").arg(pitch));

            // gravedad_x = -sin(pitch / (double)1000) * 1000;
            // gravedad_y = sin(roll / (double)1000) * cos(pitch / (double)1000) * 1000;

            // Accel[0] = Accel[0] - gravedad_x;
            // Accel[1] = Accel[1] - gravedad_y;

            //Integrar giroscopio para calcular roll y pitch
            // roll_g = roll + ((Gyro[0] * 3.1416) / 180) * 0.01;
            // pitch_g = pitch + ((Gyro[1] * 3.1416) / 180) * 0.01;

            // roll_g = roll + (Gyro[0] * 0.01);
            // pitch_g = pitch + (Gyro[1] * 0.01);

            // // Calcular ángulos del acelerómetro
            // roll_a = (atan2(Accel[1], Accel[2]) * 180) /M_PI;
            // pitch_a = (atan2(-Accel[0], sqrt(Accel[1] * Accel[1] + Accel[2] * Accel[2])) * 180) /M_PI;

            // Gyro[0] *= 131;
            // Gyro[1] *= 131;
            // Gyro[2] *= 131;

            // // //Aplicar filtro complementario
            // if (qAbs(Gyro[0]) < 10 && qAbs(Gyro[1]) < 10 && qAbs(Gyro[2]) < 10) {
            //     roll = 0;
            //     pitch = 0;
            // } else {
            //     roll = 0.98 * roll_g + (1 - 0.98) * roll_a;
            //     pitch = 0.98* pitch_g + (1 - 0.98) * pitch_a;
            // }

            // roll = (roll * M_PI) / 180;
            // pitch = (pitch * M_PI) / 180;

            // // Calcular la componente de la gravedad
            // gravedad_x = -sin(pitch) * 15700;
            // gravedad_y = sin(roll) * cos(pitch) * 15700;

            // roll = (roll * 180) / M_PI;
            // pitch = (pitch * 180) / M_PI;

            // // Restar la componente de la gravedad de las lecturas del acelerómetro
            // Accel[0] = (Accel[0] - gravedad_x); //- gravedad_x
            // Accel[1] = (Accel[1] - gravedad_y); //- gravedad_y
            // Accel[2] = Accel[2];

            // Actualizar velocidad y posicion
            accelPromedio = (lineal_accel.x + prevAccel[0])/2;
            if (qAbs(accelPromedio) > 0.007) {
                timeoutSpeed[0] = 0;
                velocity.x += accelPromedio * 0.01f;
                velPromedio = (velocity.x + prevVel[0])/2;
                position.x += velPromedio * 0.01f;
            } else {
                timeoutSpeed[0]++;
                if (timeoutSpeed[0] == 5) {
                    velocity.x = 0;
                }
            }
            accelPromedio = 0;

            accelPromedio = (lineal_accel.y + prevAccel[1])/2;
            if (qAbs(accelPromedio) > 0.007) {
                timeoutSpeed[1] = 0;
                velocity.y += accelPromedio * 0.01f;
                velPromedio = (velocity.y + prevVel[1])/2;
                position.y += velPromedio * 0.01f;
            } else {
                timeoutSpeed[1]++;
                if (timeoutSpeed[1] == 5) {
                    velocity.y = 0;
                }
            }
            accelPromedio = 0;

            accelPromedio = (lineal_accel.z + prevAccel[2])/2;
            if (qAbs(accelPromedio) > 0.007) {
                timeoutSpeed[2] = 0;
                velocity.z += accelPromedio * 0.01f;
                velPromedio = velocity.z + prevVel[2];
                position.z += velPromedio * 0.01f;
            } else {
                timeoutSpeed[2]++;
                if (timeoutSpeed[2] == 5) {
                    velocity.z = 0;
                }
            }
            accelPromedio = 0;

            // if (qAbs(lineal_accel.y) > 0.007) {
            //     velocity.y += lineal_accel.y * 0.01f;
            //     position.y += velocity.y * 0.01f;
            // }

            // if (qAbs(lineal_accel.z) > 0.007) {
            //     velocity.z += lineal_accel.z * 0.01f;
            //     position.z += velocity.z * 0.01f;
            // }

            prevVel[0] = velocity.x;
            prevVel[1] = velocity.y;
            prevVel[2] = velocity.z;

            // for (uint8_t i=0; i<3; i++){
            //     prevVel[i] = Vel[i];
            //     accelPromedio = (Accel[i]+prevAccel[i])/2;
            //     Vel[i] += (accelPromedio * 10) / 1000; // accel * 0.01 seg
            //     if (qAbs(Gyro[0]) < 10 && qAbs(Gyro[1]) < 10 && qAbs(Gyro[2]) < 10)
            //         Vel[i] = 0;
            //     //Vel[i] += (Accel[i] * 10) / 1000;
            //     accelPromedio = 0;

            //     //velPromedio = (Vel[i]+prevVel[i])/2;
            //     accelPromedio = (Accel[i]+prevAccel[i])/2;
            //     position[i] += ((prevVel[i] * 10) / 1000) + (accelPromedio * (10/1000) * (10/1000)) / 2; // accel * 0.01 seg
            //     //Vel[i] += (Accel[i] * 10) / 1000;
            //     velPromedio = 0;
            //     accelPromedio = 0;
            // }

            prevAccel[0] = lineal_accel.x;
            prevAccel[1] = lineal_accel.y;
            prevAccel[2] = lineal_accel.z;

            // ui->txtBrowserCMD->append(QString("--> Gyro X= %1").arg(Gyro[0]));
            // ui->txtBrowserCMD->append(QString("--> Gyro Y= %1").arg(Gyro[1]));
            // ui->txtBrowserCMD->append(QString("--> Gyro Z= %1").arg(Gyro[2]));

            ui->gyro_0->display(QString("%1").arg((int32_t)(Gyro[0]*100)));
            ui->gyro_1->display(QString("%1").arg((int32_t)(Gyro[1]*100)));
            ui->gyro_2->display(QString("%1").arg((int32_t)(Gyro[2]*100)));

            // ui->txtBrowserCMD->append(QString("--> Accel X= %1").arg(Accel[0]));
            // ui->txtBrowserCMD->append(QString("--> Accel Y= %1").arg(Accel[1]));
            // ui->txtBrowserCMD->append(QString("--> Accel Z= %1").arg(Accel[2]));

            ui->accel_0->display(QString("%1").arg((int32_t)(lineal_accel.x * 1000)));
            ui->accel_1->display(QString("%1").arg((int32_t)(lineal_accel.y * 1000)));
            ui->accel_2->display(QString("%1").arg((int32_t)(lineal_accel.z * 1000)));

            ui->vel_0->display(QString("%1").arg((int32_t)(velocity.x * 1000)));
            ui->vel_1->display(QString("%1").arg((int32_t)(velocity.y * 1000)));
            ui->vel_2->display(QString("%1").arg((int32_t)(velocity.z * 1000)));

            ui->position_0->display(QString("%1").arg((int32_t)(position.x * 1000)));
            ui->position_1->display(QString("%1").arg((int32_t)(position.y * 1000)));
            ui->position_2->display(QString("%1").arg((int32_t)(position.z * 1000)));

            ui->pitch_0->display(QString("%1").arg((int32_t)pitch));
            ui->roll_0->display(QString("%1").arg((int32_t)roll));
            ui->yaw_0->display(QString("%1").arg((int32_t)yaw));
            ui->contraAccel_x->display(QString("%1").arg((int32_t)(Accel[0] * 1000)));
            ui->contraAccel_y->display(QString("%1").arg((int32_t)(Accel[1] * 1000)));

            break;
//        case GETSERVOANGLE://    GETSERVOANGLE=0xA8,
//            servoAngleToShow = datosRx[4];
//            ui->angleLCD->display(QString("%1").arg(servoAngleToShow, 2, 10, QChar('0')));
//            break;
//        case GETDISTANCE://     GETDISTANCE=0xA3,
//            for (uint8_t apendice = 0; apendice < 4; apendice++) {
//                myWorker.u8[apendice] = datosRx[apendice+4];
//            }
//            distancia = floor((myWorker.u32/58)+0.5);

//            ui->txtBrowserCMD->append(QString("--> Distancia = %1").arg(distancia, 0, 10, QChar('0')).toUpper());

//            ui->distanceLCD->display(QString("%1").arg(distancia, 2, 10, QChar('0')));
//            break;
        case GETSPEED://     GETSPEED=0xA4,
            for (uint8_t i=0; i<4; i++) {
                myWorker.u8[i] = datosRx[i+4];
            }
            hSensors.rightSensorPulses = myWorker.u32;
            for (uint8_t i=0; i<4; i++) {
                myWorker.u8[i] = datosRx[i+8];
            }
            hSensors.leftSensorPulses = myWorker.u32;

            ui->txtBrowserCMD->append(QString("--> PulsosDerecha = %1").arg(hSensors.rightSensorPulses, 0, 10, QChar('0')).toUpper());
            ui->txtBrowserCMD->append(QString("--> PulsosIzquierda = %1").arg(hSensors.leftSensorPulses, 0, 10, QChar('0')).toUpper());

            ui->leftPulsesLCD->display(QString("%1").arg((hSensors.leftSensorPulses*3), 2, 10, QChar('0')));
            ui->rightPulsesLCD->display(QString("%1").arg((hSensors.rightSensorPulses*3), 2, 10, QChar('0')));
            break;
        case GETSWITCHES: //GETSWITCHES=0xA5
            switches[0].status = datosRx[4];
            str2 = "SW0: ";
            if(switches[0].status) {
                str2 = str2 + "UP";
                ui->EstadoBotonLabel->setText("UP");
            } else {
                str2 = str2 + "DOWN";
                ui->EstadoBotonLabel->setText("DOWN");
            }

            ui->txtBrowserCMD->append(str2);
            break;
        case GETALIVE://     GETALIVE=0xF0,
            if(datosRx[2]==ACK){
                if(source)
                    str="ALIVE BLUEPILL VIA *SERIE* RECIBIDO!!!";
                else{
                    contadorAlive++;
                     str="ALIVE BLUEPILL VIA *UDP* RECIBIDO N°: " + QString().number(contadorAlive,10);
                }
            }else{
                str= "ALIVE BLUEPILL VIA *SERIE*  NO ACK!!!";
            }
            ui->AliveLabel->setStyleSheet("border: 1px solid gray;border-color: black;border-radius: 2px;background-color: green;color: white;");
            ui->AliveLabel->setText("YES");
            alive = true;
            aliveTimeOut = 0;
            ui->textBrowser->append(str);
            ui->txtBrowserCMD->append(str);
            break;
        case GETFIRMWARE://     GETFIRMWARE=0xF1
            while (datosRx[i+4]) {
                firmwareCadena[i] = datosRx[i+4];
                i++;
            }
            ui->FirmwareLabel->setText(firmwareCadena);
            break;
//        case SETLEDS:

//            break;
        case STARTCONFIG:
            if(datosRx[4]==ACK){
                if(source)
                    str="DATOS CONFIG WIFI ACK VIA *SERIE* RECIBIDO!!!!";
                else
                    str="DATOS CONFIG WIFI ACK VIA *UDP* RECIBIDO!!!";
            }else{
                str="DATOS CONFIG WIFI NO ACK!!!";
            }
            ui->txtBrowserCMD->append(str);
            break;
//        case SETSERVOLIMITS:
//            myWorker.u8[0] = datosRx[4];
//            myWorker.u8[1] = datosRx[5];
//            servoConfig.maxMsServo = myWorker.u16[0];
//            myWorker.u8[0] = datosRx[6];
//            myWorker.u8[1] = datosRx[7];
//            servoConfig.minMsServo = myWorker.u16[0];

//            ui->txtBrowserCMD->append(QString("max: %1").arg(servoConfig.maxMsServo, 0, 10, QChar('0')));
//            ui->txtBrowserCMD->append(QString("min: %1").arg(servoConfig.minMsServo, 0, 10, QChar('0')));

//            ui->ServoMaxValueLCD->display(QString("%1").arg(servoConfig.maxMsServo, 0, 10, QChar('0')));
//            ui->ServoMinValueLCD->display(QString("%1").arg(servoConfig.minMsServo, 0, 10, QChar('0')));
//            break;
//        case SETBLACKCOLORDETECTED:
//            myWorker.u8[0] = datosRx[4];
//            myWorker.u8[1] = datosRx[5];
//            irConfig.blackLeft = myWorker.u16[0];
//            myWorker.u8[0] = datosRx[6];
//            myWorker.u8[1] = datosRx[7];
//            irConfig.blackCenter = myWorker.u16[0];
//            myWorker.u8[0] = datosRx[8];
//            myWorker.u8[1] = datosRx[9];
//            irConfig.blackRight = myWorker.u16[0];

//            ui->txtBrowserCMD->append(QString("leftBlack: %1").arg(irConfig.blackLeft, 0, 10, QChar('0')));
//            ui->txtBrowserCMD->append(QString("centerBlack: %1").arg(irConfig.blackCenter, 0, 10, QChar('0')));
//            ui->txtBrowserCMD->append(QString("rightBlack: %1").arg(irConfig.blackRight, 0, 10, QChar('0')));

//            ui->NegroConfigLCD->display(QString("%1").arg(irConfig.blackLeft, 0, 10, QChar('0')));
//            break;
//        case SETWHITECOLORDETECTED:
//            myWorker.u8[0] = datosRx[4];
//            myWorker.u8[1] = datosRx[5];
//            irConfig.whiteLeft = myWorker.u16[0];
//            myWorker.u8[0] = datosRx[6];
//            myWorker.u8[1] = datosRx[7];
//            irConfig.whiteCenter = myWorker.u16[0];
//            myWorker.u8[0] = datosRx[8];
//            myWorker.u8[1] = datosRx[9];
//            irConfig.whiteRight = myWorker.u16[0];

//            ui->txtBrowserCMD->append(QString("leftWhite: %1").arg(irConfig.whiteLeft, 0, 10, QChar('0')));
//            ui->txtBrowserCMD->append(QString("centerWhite: %1").arg(irConfig.whiteCenter, 0, 10, QChar('0')));
//            ui->txtBrowserCMD->append(QString("rightWhite: %1").arg(irConfig.whiteRight, 0, 10, QChar('0')));

//            ui->BlancoConfigLCD->display(QString("%1").arg(irConfig.whiteLeft, 0, 10, QChar('0')));
//            break;
        default:
            str = str + "Comando DESCONOCIDO!!!!";
            ui->txtBrowserCMD->append(str);
    }
}

void MainWindow::sendDataSerial()
{
    uint8_t cmdId;
    _work w;
    bool ok;
    unsigned char dato[256];
    unsigned char indice=0, chk=0;
    QString str="";

    dato[indice++]='U';
    dato[indice++]='N';
    dato[indice++]='E';
    dato[indice++]='R';
    dato[indice++]=0x00;
    dato[indice++]=':';
    //dato[indice++]=0x0C;
    //dato[indice++]=0x00;

    if (isASelectedCmd) {
        cmdId = auxComand;
    } else
        cmdId = ui->comboBoxCom->currentData().toInt();

    switch (cmdId) {
        case SETMOTORTEST://MOTORTEST=0xA1,
            dato[indice++] = SETMOTORTEST;
            w.i32 = QInputDialog::getInt(this, "Velocidad", "Motor1:", 0, -100, 100, 1, &ok);
            if(!ok)
                break;
            dato[indice++] = w.u8[0];
            dato[indice++] = w.u8[1];
            dato[indice++] = w.u8[2];
            dato[indice++] = w.u8[3];
            w.i32 = QInputDialog::getInt(this, "Velocidad", "Motor2:", 0, -100, 100, 1, &ok);
            if(!ok)
                break;
            dato[indice++] = w.u8[0];
            dato[indice++] = w.u8[1];
            dato[indice++] = w.u8[2];
            dato[indice++] = w.u8[3];
            dato[NBYTES]= 0x0C;
            break;
        case MPU://SERVOANGLE=0xA2,
//            dato[indice++] = MPU;
//            if (isASelectedCmd) {
//                w.i32 = servoAngle;
//            } else {
//                w.i32 = QInputDialog::getInt(this, "SERVO", "Angulo:", 0, 0, 180, 1, &ok);
//                if(!ok)
//                    break;
//            }
//            dato[indice++] = w.i8[0];
//            dato[NBYTES]= 0x05;
            break;
        case GETALIVE:
        //case GETDISTANCE://GETDISTANCE=0xA3
        case GETSPEED://GETSPEED=0xA4
        case GETSWITCHES://GETSWITCHES=0xA5
        case GETFIRMWARE:// GETFIRMWARE=0xF1
        case LAST_ADC://ANALOGSENSORS=0xA0
        //case GETSERVOANGLE://GETSERVOANGLE=0xA8
        case SETLEDS:
            dato[indice++] = cmdId;
            dato[NBYTES] = 0x02;
            break;
//        case SETSERVOLIMITS:
//            dato[indice++] = cmdId;
//            if (!isASelectedCmd) {
//                servoConfig.modo = QInputDialog::getInt(this, "ELEGIR MODO", " 0->LEER   1->CONFIGURAR ", 0, 0, 1, 1, &ok);
//                if (!ok)
//                    break;
//            }
//            dato[indice++] = servoConfig.modo;
//            if (servoConfig.modo) {
//                servoConfig.maxMsServo = QInputDialog::getInt(this, "MAX MS", "Elegir ms maximos del servo", 2000, 2000, 2450, 1, &ok);
//                if (ok) {
//                    w.u16[0] = servoConfig.maxMsServo;
//                    dato[indice++] = w.u8[0];
//                    dato[indice++] = w.u8[1];
//                } else
//                    return;
//                servoConfig.minMsServo = QInputDialog::getInt(this, "MIN MS", "Elegir ms minimos del servo", 1000, 480, 1000, 1, &ok);
//                if (ok) {
//                    w.u16[0] = servoConfig.minMsServo;
//                    dato[indice++] = w.u8[0];
//                    dato[indice++] = w.u8[1];
//                } else
//                    return;
//                dato[NBYTES] = 0x09;
//            }
//            else
//                dato[NBYTES] = 0x05;
//            break;
//        case SETBLACKCOLORDETECTED:
//            dato[indice++] = cmdId;
//            if (!isASelectedCmd) {
//                irConfig.modo = QInputDialog::getInt(this, "ELEGIR MODO", " 0->LEER   1->CONFIGURAR ", 0, 0, 1, 1, &ok);
//                if (!ok)
//                    break;
//            }
//            dato[indice++] = irConfig.modo;
//            if (irConfig.modo) {
//                irConfig.blackLeft = QInputDialog::getInt(this, "BLACK COLOR", "Deteccion negro izquierdo:", 6000, 2000, 60000, 1, &ok);
//                if (ok) {
//                    w.u16[0] = irConfig.blackLeft;
//                    dato[indice++] = w.u8[0];
//                    dato[indice++] = w.u8[1];
//                } else
//                    return;
//                irConfig.blackCenter = QInputDialog::getInt(this, "BLACK COLOR", "Deteccion negro centro:", 6000, 2000, 60000, 1, &ok);
//                if (ok) {
//                    w.u16[0] = irConfig.blackCenter;
//                    dato[indice++] = w.u8[0];
//                    dato[indice++] = w.u8[1];
//                } else
//                    return;
//                irConfig.blackRight = QInputDialog::getInt(this, "BLACK COLOR", "Deteccion negro derecho:", 6000, 2000, 60000, 1, &ok);
//                if (ok) {
//                    w.u16[0] = irConfig.blackRight;
//                    dato[indice++] = w.u8[0];
//                    dato[indice++] = w.u8[1];
//                } else
//                    return;
//                dato[NBYTES] = 0x0B;
//            } else
//                dato[NBYTES] = 0x05;
//            break;
//        case SETWHITECOLORDETECTED:
//            dato[indice++] = cmdId;
//            if (!isASelectedCmd) {
//                irConfig.modo = QInputDialog::getInt(this, "ELEGIR MODO", " 0->LEER   1->CONFIGURAR ", 0, 0, 1, 1, &ok);
//                if (!ok)
//                    break;
//            }
//            dato[indice++] = irConfig.modo;
//            if (irConfig.modo) {
//                irConfig.whiteLeft = QInputDialog::getInt(this, "WHITE COLOR", "Deteccion blanco izquierdo:", 3500, 1000, 20000, 1, &ok);
//                if (ok) {
//                    w.u16[0] = irConfig.whiteLeft;
//                    dato[indice++] = w.u8[0];
//                    dato[indice++] = w.u8[1];
//                } else
//                    return;
//                irConfig.whiteCenter = QInputDialog::getInt(this, "WHITE COLOR", "Deteccion blanco centro:", 3500, 1000, 20000, 1, &ok);
//                if (ok) {
//                    w.u16[0] = irConfig.whiteCenter;
//                    dato[indice++] = w.u8[0];
//                    dato[indice++] = w.u8[1];
//                } else
//                    return;
//                irConfig.whiteRight = QInputDialog::getInt(this, "WHITE COLOR", "Deteccion blanco derecho:", 3500, 1000, 20000, 1, &ok);
//                if (ok) {
//                    w.u16[0] = irConfig.whiteRight;
//                    dato[indice++] = w.u8[0];
//                    dato[indice++] = w.u8[1];
//                } else
//                    return;
//                dato[NBYTES] = 0x0B;
//            } else
//                dato[NBYTES] = 0x05;
//            break;
        default:
            return;
    }

    isASelectedCmd = false;

    for(int a=0 ;a<indice;a++)
        chk^=dato[a];
    dato[indice]=chk;

    if(serial->isWritable()){
        serial->write(reinterpret_cast<char *>(dato),dato[NBYTES]+PAYLOAD);
    }

    for(int i=0; i<=indice; i++){
        if(isalnum(dato[i]))
            str = str + QString("%1").arg(char(dato[i]));
        else
            str = str +"{" + QString("%1").arg(dato[i],2,16,QChar('0')) + "}";
    }

    uint16_t valor=dato[NBYTES]+PAYLOAD;
    ui->textBrowser->append("INDICE ** " +QString().number(indice,10) + " **" );
    ui->textBrowser->append("NUMERO DE DATOS ** " +QString().number(valor,10) + " **" );
    ui->textBrowser->append("CHECKSUM ** " +QString().number(chk,16) + " **" );
    ui->textBrowser->append("PC--SERIAL-->MBED ( " + str + " )");

}

void MainWindow::sendDataUDP()
{
    uint8_t cmdId;
    _work w;
    unsigned char dato[256];
    unsigned char indice=0, chk=0;
    QString str;
    int puerto=0;
    bool ok;

    dato[indice++]='U';
    dato[indice++]='N';
    dato[indice++]='E';
    dato[indice++]='R';
    dato[indice++]=0x00;
    dato[indice++]=':';
    //dato[indice++]=0x0C;
   // dato[indice++]=0x00;

    if (isASelectedCmd) {
        cmdId = auxComand;
    } else
        cmdId = ui->comboBoxCom->currentData().toInt();

    switch (cmdId) {
        case SETMOTORTEST://MOTORTEST=0xA1,
            dato[indice++] = SETMOTORTEST;
            w.i32 = QInputDialog::getInt(this, "Velocidad", "Motor1:", 0, -100, 100, 1, &ok);
            if(!ok)
                break;
            dato[indice++] = w.u8[0];
            dato[indice++] = w.u8[1];
            dato[indice++] = w.u8[2];
            dato[indice++] = w.u8[3];
            w.i32 = QInputDialog::getInt(this, "Velocidad", "Motor2:", 0, -100, 100, 1, &ok);
            if(!ok)
                break;
            dato[indice++] = w.u8[0];
            dato[indice++] = w.u8[1];
            dato[indice++] = w.u8[2];
            dato[indice++] = w.u8[3];
            dato[NBYTES]= 0x0C;
            break;
        case MPU://SERVOANGLE=0xA2,
            dato[indice++] = MPU;
            if (isASelectedCmd) {
                w.i32 = servoAngle;
            } else {
                w.i32 = QInputDialog::getInt(this, "SERVO", "Angulo:", 0, 0, 180, 1, &ok);
                if(!ok)
                    break;
            }
            dato[indice++] = w.i8[0];
            dato[NBYTES]= 0x05;
            break;
        case GETALIVE:
        //case GETDISTANCE://GETDISTANCE=0xA3,
        case GETSPEED://GETSPEED=0xA4,
        case GETSWITCHES://GETSWITCHES=0xA5
        case GETFIRMWARE:// GETFIRMWARE=0xF1
        case LAST_ADC://ANALOGSENSORS=0xA0,
        //case GETSERVOANGLE://GETSERVOANGLE=0xA8
        case SETLEDS:
            dato[indice++] = cmdId;
            dato[NBYTES] = 0x02;
            break;
//        case SETSERVOLIMITS:
//            dato[indice++] = cmdId;
//            if (!isASelectedCmd) {
//                servoConfig.modo = QInputDialog::getInt(this, "ELEGIR MODO", " 0->LEER   1->CONFIGURAR ", 0, 0, 1, 1, &ok);
//                if (!ok)
//                    break;
//            }
//            dato[indice++] = servoConfig.modo;
//            if (servoConfig.modo) {
//                servoConfig.maxMsServo = QInputDialog::getInt(this, "MAX MS", "Elegir ms maximos del servo", 2000, 2000, 2450, 1, &ok);
//                if (ok) {
//                    w.u16[0] = servoConfig.maxMsServo;
//                    dato[indice++] = w.u8[0];
//                    dato[indice++] = w.u8[1];
//                } else
//                    return;
//                servoConfig.minMsServo = QInputDialog::getInt(this, "MIN MS", "Elegir ms minimos del servo", 1000, 480, 1000, 1, &ok);
//                if (ok) {
//                    w.u16[0] = servoConfig.minMsServo;
//                    dato[indice++] = w.u8[0];
//                    dato[indice++] = w.u8[1];
//                } else
//                    return;
//                dato[NBYTES] = 0x09;
//            }
//            else
//                dato[NBYTES] = 0x05;
//            break;
//        case SETBLACKCOLORDETECTED:
//            dato[indice++] = cmdId;
//            if (!isASelectedCmd) {
//                irConfig.modo = QInputDialog::getInt(this, "ELEGIR MODO", " 0->LEER   1->CONFIGURAR ", 0, 0, 1, 1, &ok);
//                if (!ok)
//                    break;
//            }
//            dato[indice++] = irConfig.modo;
//            if (irConfig.modo) {
//                irConfig.blackLeft = QInputDialog::getInt(this, "BLACK COLOR", "Deteccion negro izquierdo:", 6000, 2000, 60000, 1, &ok);
//                if (ok) {
//                    w.u16[0] = irConfig.blackLeft;
//                    dato[indice++] = w.u8[0];
//                    dato[indice++] = w.u8[1];
//                } else
//                    return;
//                irConfig.blackCenter = QInputDialog::getInt(this, "BLACK COLOR", "Deteccion negro centro:", 6000, 2000, 60000, 1, &ok);
//                if (ok) {
//                    w.u16[0] = irConfig.blackCenter;
//                    dato[indice++] = w.u8[0];
//                    dato[indice++] = w.u8[1];
//                } else
//                    return;
//                irConfig.blackRight = QInputDialog::getInt(this, "BLACK COLOR", "Deteccion negro derecho:", 6000, 2000, 60000, 1, &ok);
//                if (ok) {
//                    w.u16[0] = irConfig.blackRight;
//                    dato[indice++] = w.u8[0];
//                    dato[indice++] = w.u8[1];
//                } else
//                    return;
//                dato[NBYTES] = 0x0B;
//            } else
//                dato[NBYTES] = 0x05;
//            break;
//        case SETWHITECOLORDETECTED:
//            dato[indice++] = cmdId;
//            if (!isASelectedCmd) {
//                irConfig.modo = QInputDialog::getInt(this, "ELEGIR MODO", " 0->LEER   1->CONFIGURAR ", 0, 0, 1, 1, &ok);
//                if (!ok)
//                    break;
//            }
//            dato[indice++] = irConfig.modo;
//            if (irConfig.modo) {
//                irConfig.whiteLeft = QInputDialog::getInt(this, "WHITE COLOR", "Deteccion blanco izquierdo:", 3500, 1000, 20000, 1, &ok);
//                if (ok) {
//                    w.u16[0] = irConfig.whiteLeft;
//                    dato[indice++] = w.u8[0];
//                    dato[indice++] = w.u8[1];
//                } else
//                    return;
//                irConfig.whiteCenter = QInputDialog::getInt(this, "WHITE COLOR", "Deteccion blanco centro:", 3500, 1000, 20000, 1, &ok);
//                if (ok) {
//                    w.u16[0] = irConfig.whiteCenter;
//                    dato[indice++] = w.u8[0];
//                    dato[indice++] = w.u8[1];
//                } else
//                    return;
//                irConfig.whiteRight = QInputDialog::getInt(this, "WHITE COLOR", "Deteccion blanco derecho:", 3500, 1000, 20000, 1, &ok);
//                if (ok) {
//                    w.u16[0] = irConfig.whiteRight;
//                    dato[indice++] = w.u8[0];
//                    dato[indice++] = w.u8[1];
//                } else
//                    return;
//                dato[NBYTES] = 0x0B;
//            } else
//                dato[NBYTES] = 0x05;
//            break;
        default:
            return;
    }

    isASelectedCmd = false;

    puerto=ui->lineEditPort->text().toInt();
    puertoremoto=puerto;
    for(int a=0 ;a<indice;a++)
        chk^=dato[a];
    dato[indice]=chk;
    if(clientAddress.isNull())
        clientAddress.setAddress(ui->lineEditIP->text());
    if(puertoremoto==0)
        puertoremoto=puerto;
    if(UdpSocket1->isOpen()){
        UdpSocket1->writeDatagram(reinterpret_cast<const char *>(dato), (dato[4]+7), clientAddress, puertoremoto);
    }
    for(int i=0; i<=indice; i++){
        if(isalnum(dato[i]))
            str = str + QString("%1").arg(char(dato[i]));
        else
            str = str +"{" + QString("%1").arg(dato[i],2,16,QChar('0')) + "}";
    }
    str=str + clientAddress.toString() + "  " +  QString().number(puertoremoto,10);
    ui->textBrowser->append("PC--UDP-->MBED ( " + str + " )");
}

void MainWindow::OnQTimer1()
{
    // if (timeLecturaSensoresTask10ms >= 50) {
    //     lecturaSensores();
    //     timeLecturaSensoresTask10ms = 0;
    // } else
    //     timeLecturaSensoresTask10ms++;

    if (timeClearLog10ms >= 1000) {
        ui->txtBrowserCMD->clear();
        ui->textBrowser->clear();
        timeClearLog10ms = 0;
    } else
        timeClearLog10ms++;

    // if (aliveTimeOut >= 1000) {
    //     if (connectionType == 1) {
    //         closeSerialPorts();
    //     } else {
    //         if (connectionType == 2) {
    //             on_pushButtonUdpOpen_clicked();
    //         }
    //     }
    //     alive = false;
    //     aliveTimeOut = 0;
    // } else
    //     aliveTimeOut++;

//    if (radarDrawing)
//            RadarRun();
}

void MainWindow::inicializaciones()
{
    distancia = 0;
    servoAngleToShow = 90;
    //irSensors.RightSensor = 0;
    //irSensors.CenterSensor = 0;
    //irSensors.LeftSensor = 0;
    hSensors.leftSensorPulses = 0;
    hSensors.rightSensorPulses = 0;
    switches[0].status = true;
    aliveTimeOut = 0;
    recibirConfig = true;
    DibujarFondoRadar();
    for (uint8_t i=0; i<3; i++){
        Accel[i] = 0;
        Vel[i] = 0;
        prevAccel[i] = 0;
        //position[i] = 0;
        prevVel[i] = 0;
    }
    lineal_accel.x = 0;
    lineal_accel.y = 0;
    lineal_accel.z = 0;
    velocity.x = 0;
    velocity.y = 0;
    velocity.z = 0;
    position.x = 0;
    position.y = 0;
    position.z = 0;
    roll = 0;
    pitch = 0;
    yaw = 0;
    roll_g = 0;
    pitch_g = 0;
    roll_a = 0;
    pitch_a = 0;
}

void MainWindow::lecturaSensores()
{
//    auxComand = GETDISTANCE;
//    isASelectedCmd = true;
//    sendDataSerial();
//    isASelectedCmd = true;
//    sendDataUDP();

//    auxComand = GETSERVOANGLE;
//    isASelectedCmd = true;
//    sendDataSerial();
//    isASelectedCmd = true;
//    sendDataUDP();

    auxComand = LAST_ADC;
    isASelectedCmd = true;
    sendDataSerial();
    isASelectedCmd = true;
    sendDataUDP();

    auxComand = GETSPEED;
    isASelectedCmd = true;
    sendDataSerial();
    isASelectedCmd = true;
    sendDataUDP();

    auxComand = GETSWITCHES;
    isASelectedCmd = true;
    sendDataSerial();
    isASelectedCmd = true;
    sendDataUDP();

    if (alive && recibirConfig) {
        recibirConfig = false;

//        auxComand = GETFIRMWARE;
//        isASelectedCmd = true;
//        sendDataUDP();
//        isASelectedCmd = true;
//        sendDataSerial();

        ui->FirmwareLabel->setText("20221211-v1.0");

//        auxComand = SETSERVOLIMITS;
//        servoConfig.modo = 0;
//        isASelectedCmd = true;
//        sendDataUDP();
//        isASelectedCmd = true;
//        sendDataSerial();

//        auxComand = SETBLACKCOLORDETECTED;
//        irConfig.modo = 0;
//        isASelectedCmd = true;
//        sendDataSerial();
//        isASelectedCmd = true;
//        sendDataUDP();

//        auxComand = SETWHITECOLORDETECTED;
//        irConfig.modo = 0;
//        isASelectedCmd = true;
//        sendDataSerial();
//        isASelectedCmd = true;
//        sendDataUDP();
    }

    if (connectionType == 1) {
        auxComand = GETALIVE;
        isASelectedCmd = true;
        sendDataSerial();
    }

    ui->rangeLCD->display(QString("%1").arg((100*MINRANGOSLIDER)/ui->scaleSlider->value(), 2, 10, QChar('0')));
}

void MainWindow::reiniciarUI()
{
    ui->distanceLCD->display(0);
    ui->angleLCD->display(0);
    //ui->ir_THREE->display(0);
    //ui->ir_TWO->display(0);
    //ui->ir_ONE->display(0);
    ui->leftPulsesLCD->display(0);
    ui->rightPulsesLCD->display(0);
    ui->BlancoConfigLCD->display(0);
    ui->NegroConfigLCD->display(0);
    ui->ServoMaxValueLCD->display(0);
    ui->ServoMinValueLCD->display(0);
    ui->EstadoBotonLabel->setText("UP");
    ui->txtBrowserCMD->clear();
    ui->textBrowser->clear();
    ui->AliveLabel->setStyleSheet("border: 1px solid gray;border-color: black;border-radius: 2px;background-color: red;color: white;");
    ui->AliveLabel->setText("NO");
//    ui->lineEditIP->clear();
//    ui->lineEditPort->clear();
    ui->FirmwareLabel->clear();
}

void MainWindow::on_radarButton_clicked()
{
    if (radarDrawing) {
        auxComand = MPU;
        servoAngle = 90;
        isASelectedCmd = true;
        sendDataSerial();
        isASelectedCmd = true;
        sendDataUDP();
        radarDrawing = false;
        ui->radarButton->setText("RUN RADAR");
        ui->scaleSlider->setEnabled(true);
    } else {
        radarDrawing = true;
        ui->radarButton->setText("STOP RADAR");
        DibujarFondoRadar();
        servoAngle = 0;
        radarStatus = MOVIENDO_SERVO;
        ui->scaleSlider->setEnabled(false);
    }
}

void MainWindow::DibujarFondoRadar() {
    QPen pen;
    QRadialGradient gradient(0, 0, 300);
    gradient.setColorAt(0, QColor(0, 20, 0, 255));
    gradient.setColorAt(1, QColor(0, 50, 0, 255));
    QBrush brush(gradient);
    QPainter painter(QPaintBox1->getCanvas());
    uint8_t painterAngle = 10;

    QPaintBox1->getCanvas()->fill(QColor(238,215,243,255));

    pen.setWidth(1);
    pen.setColor(QColorConstants::Svg::darkgreen);
    brush.setStyle(Qt::BrushStyle::RadialGradientPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.translate(ui->widgetRadar->width()/2, ui->widgetRadar->height());
    painter.drawEllipse(QPointF(0,0), ui->widgetRadar->width()/2, ui->widgetRadar->height());
    painter.setBrush(Qt::NoBrush);
    for (uint8_t i=0; i<10; i++) {
        painter.drawEllipse(QPointF(0,0), (ui->widgetRadar->width()/2) - (i*30+30), (ui->widgetRadar->height()) - (i*30+30));
    }
    for (uint8_t i=0; i<18; i++) {
        painter.drawLine(0, 0, cos(painterAngle*M_PI/180)*ui->widgetRadar->width()/2, sin(painterAngle*M_PI/180)*(-(ui->widgetRadar->height())));
        painterAngle += 10;
       painter.drawLine(0, 0, (ui->widgetRadar->width()/2), 0);
       painter.rotate(-10);
    }
    QPaintBox1->update();
}

void MainWindow::RadarRun()
{
    switch (radarStatus)
    {
        case MOVIENDO_SERVO:
            auxComand = MPU;
            isASelectedCmd = true;
            sendDataSerial();
            isASelectedCmd = true;
            sendDataUDP();
            radarStatus = MIDIENDO;
        break;
        case MIDIENDO:
            if (!servoIsMoving) {
                //auxComand = GETDISTANCE;
                isASelectedCmd = true;
                sendDataSerial();
                isASelectedCmd = true;
                sendDataUDP();
                radarStatus = DIBUJANDO;
            }
        break;
        case DIBUJANDO:
            if (distancia <= 100) {
                DibujarDeteccion();
                servoAngle += 1;
                radarStatus = MOVIENDO_SERVO;
            } else {
                servoAngle += 1;
                radarStatus = MOVIENDO_SERVO;
            }
            if (servoAngle > 180) {
                radarStatus = FINALIZANDO;
            }
        break;
        case FINALIZANDO:
            auxComand = MPU;
            servoAngle = 90;
            isASelectedCmd = true;
            sendDataSerial();
            isASelectedCmd = true;
            sendDataUDP();
            radarDrawing = false;
            ui->radarButton->setText("RUN RADAR");
            ui->scaleSlider->setEnabled(true);
        break;
    }
}

void MainWindow::DibujarDeteccion() {
    QPen pen;
    QBrush brush;
    QPainter painter(QPaintBox1->getCanvas());
    QColor colorVerde(0, 255, 0, 80);
    QColor colorRojo(255, 0, 0, 80);
    int16_t X;
    int16_t Y;

    painter.setRenderHint(QPainter::Antialiasing);

    if (distancia*(ui->scaleSlider->value())/MINRANGOSLIDER <= 100) {
        X = (floor(cos(servoAngle*M_PI/180)*(distancia)*(ui->scaleSlider->value())/MINRANGOSLIDER + 0.5))*3.6;
        Y = (floor(sin(servoAngle*M_PI/180)*(distancia)*(ui->scaleSlider->value())/MINRANGOSLIDER + 0.5))*(-3.6);
        painter.translate(ui->widgetRadar->width()/2, ui->widgetRadar->height());
        pen.setWidth(1);
        pen.setColor(colorVerde);
        painter.setPen(pen);
        painter.drawLine(0, 0, X, Y);
        pen.setColor(colorRojo);
        painter.setPen(pen);
        painter.drawLine(X, Y, cos(servoAngle*M_PI/180)*ui->widgetRadar->width()/2, sin(servoAngle*M_PI/180)*(-(ui->widgetRadar->height())));

        pen.setColor(QColorConstants::Svg::black);
        painter.setPen(pen);
        brush.setColor(QColorConstants::Svg::darkgreen);
        brush.setStyle(Qt::SolidPattern);
        painter.setBrush(brush);
        painter.drawEllipse(QPoint(X, Y), 4, 4);
    }
    QPaintBox1->update();
}
