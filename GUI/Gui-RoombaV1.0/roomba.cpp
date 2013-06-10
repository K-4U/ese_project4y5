#include "roomba.h"
#include "ui_roomba.h"
#include "displaylogs.h"
#include "mytimer.h"
#include <QtGui>

Roomba::Roomba(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Roomba),
    server(),
    controlling_roomba(new Controllingroomba(this))
{
    ui->setupUi(this);
}

Roomba::~Roomba()
{
    delete ui;
}

void Roomba::RoombaModeChanged(Modes newMode)
{
    jsonCommand toSend(JSONCOMMAND_NEWMODE);
    toSend.addToData("newmode", newMode);
    this->server->sendCommand(toSend);
}

void Roomba::MotorBrushVacuumChanged(bool MainBrush, bool SideBrush, bool Vacuum)
{
    jsonCommand toSend(JSONCOMMAND_SETMOTORBRUSHVACUUM);
    toSend.addToData("MainBrush", MainBrush);
    toSend.addToData("SideBrush", SideBrush);
    toSend.addToData("Vacuum", Vacuum);
    this->server->sendCommand(toSend);
}

void Roomba::MotorSpeedChanged(int setLeftMotorSpeed, int setRightMotorSpeed)
{
    jsonCommand toSend(JSONCOMMAND_SETMOTOR);
    toSend.addToData("LeftMotorSpeed", setLeftMotorSpeed);
    toSend.addToData("RightMotorSpeed", setRightMotorSpeed);
    this->server->sendCommand(toSend);
}

void Roomba::sendSensorDataRequest()
{
    QList<QVariant> sensors;
    QVariant sendData;
    sensors.append(QVariant(7));  //Bump and Wheel drops 1
    sensors.append(QVariant(9));  //Cliff Left 1
    sensors.append(QVariant(10)); //Cliff FrontLeft 1
    sensors.append(QVariant(11)); //Cliff FrontRight 1
    sensors.append(QVariant(12)); //Cliff Right 1
    sensors.append(QVariant(19)); //Distance 2
    sensors.append(QVariant(20)); //Angle 2
    sensors.append(QVariant(21)); //Charging State 1
    sensors.append(QVariant(24)); //Temperature 1
    sensors.append(QVariant(25)); //Battery Charge 2
    sensors.append(QVariant(26)); //Battery Capacity 2
    sensors.append(QVariant(35)); //OI Mode 1

    readDataTimer->start(1000);
    sendData = QVariant::fromValue(sensors);

    jsonCommand toSend(JSONCOMMAND_SENDSENSORDATAREQUEST);
    toSend.addToData("Sensors", sendData);
    this->server->sendCommand(toSend);
}

void Roomba::readSensorData(eventSensor *theMessage)
{
    foreach(QVariant sensor, theMessage->getData("Sensors").toList())
    {
        QVariantMap sensorMap = sensor.toMap();
        this->controlling_roomba->allSensorData(sensorMap["id"].toInt(), sensorMap["value"].toInt());
    }
}

void Roomba::disconnectDoIt(bool disconnectDo)
{
    if(disconnectDo == true)
    {
        this->server->doDisconnect();
    }
    readDataTimer->stop();
}

void Roomba::roombaConnected()
{
    //Controllingroomba *controlling_roomba = new Controllingroomba(this);
    this->hide();
    controlling_roomba->show();

    readDataTimer = new QTimer(this);
    connect(readDataTimer, SIGNAL(timeout()),
            this, SLOT(sendSensorDataRequest()));
    readDataTimer->start(1000);

    connect(controlling_roomba, SIGNAL(disconnectDo(bool)),
            this, SLOT(disconnectDoIt(bool)));

    connect(controlling_roomba, SIGNAL(ModeChanged(Modes)),
            this, SLOT(RoombaModeChanged(Modes)));

    connect(controlling_roomba, SIGNAL(setMotorBrushVacuum(bool, bool, bool)),
            this, SLOT(MotorBrushVacuumChanged(bool, bool, bool)));

    connect(controlling_roomba, SIGNAL(setMotorSpeed(int, int)),
            this, SLOT(MotorSpeedChanged(int, int)));

    connect(this->server, SIGNAL (sensorDataReceived(eventSensor*)),
            this, SLOT(readSensorData(eventSensor*)));
}

void Roomba::on_pbConnect_clicked()
{
    QString IP;
    IP.append(ui->leIP->text());
    this->server = new clsServerConn(IP, 1337);

    connect(this->server, SIGNAL (connected()),
            this, SLOT(roombaConnected()));

    this->server->doConnect();
}
