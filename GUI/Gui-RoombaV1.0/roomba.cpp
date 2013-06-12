#include "roomba.h"
#include "ui_roomba.h"
#include "mytimer.h"
#include <QtGui>

Roomba::Roomba(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Roomba),
    server(),
    controlling_roomba(new Controllingroomba(this)),
    log(LOGTAGS_ROOMBA)
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
    jsonCommand toSend(JSONCOMMAND_SETMOTORSPEED);
    toSend.addToData("Left", setLeftMotorSpeed);
    toSend.addToData("Right", setRightMotorSpeed);
    this->server->sendCommand(toSend);
}

void Roomba::sendSensorDataRequest()
{
    QList<QVariant> sensors;
    QVariant sendData;
    sensors.append(QVariant(19)); //Distance 2
    sensors.append(QVariant(20)); //Angle 2
    sensors.append(QVariant(21)); //Charging State 1
    sensors.append(QVariant(24)); //Temperature 1
    sensors.append(QVariant(25)); //Battery Charge 2
    sensors.append(QVariant(26)); //Battery Capacity 2
    sensors.append(QVariant(35)); //OI Mode 1

    sendData = QVariant::fromValue(sensors);

    jsonCommand toSend(JSONCOMMAND_SENDSENSORDATAREQUEST);
    toSend.addToData("Sensors", sendData);
    this->server->sendCommand(toSend);
    readDataTimer->start(1000);
}

void Roomba::readSensorData(eventSensor *theMessage)
{
    foreach(QVariant sensor, theMessage->getData("Sensors").toList())
    {
        QVariantMap sensorMap = sensor.toMap();
        this->controlling_roomba->allSensorData(sensorMap["id"].toInt(), sensorMap["value"].toInt());
    }
}

void Roomba::getMotorBrushVacuum()
{
    jsonCommand toSend(JSONCOMMAND_GETMOTORBRUSHVACUUM);
    this->server->sendCommand(toSend);
    getBrushVacuum->start(1000);
}

void Roomba::getCurrentAction()
{
    jsonCommand toSend(JSONCOMMAND_GETCURRENTACTION);
    this->server->sendCommand(toSend);
    getCurrentModeAction->start(1000);
}

void Roomba::getLogging()
{
    jsonCommand toSend(JSONCOMMAND_GETLOGS);
    this->server->sendCommand(toSend);
    getLogs->start(1000);
}

void Roomba::logsReceived(QVector<eventLogging::logEntry> entries){
    controlling_roomba->logsReceived(entries);
}

void Roomba::roombaConnected()
{
    this->hide();
    controlling_roomba->show();

    readDataTimer = new QTimer(this);
    connect(readDataTimer, SIGNAL(timeout()),
            this, SLOT(sendSensorDataRequest()));
    readDataTimer->start(1000);

    getBrushVacuum = new QTimer(this);
    connect(getBrushVacuum, SIGNAL(timeout()),
            this, SLOT(getMotorBrushVacuum()));
    getBrushVacuum->start(1000);

    getLogs = new QTimer(this);
    connect(getLogs, SIGNAL(timeout()),
            this, SLOT(getLogging()));
    getLogs->start(1000);


    getCurrentModeAction = new QTimer(this);
    connect(getCurrentModeAction, SIGNAL(timeout()),
            this, SLOT(getCurrentAction()));
    getCurrentModeAction->start(1000);

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

    connect(this->server, SIGNAL(logsReceived(QVector<eventLogging::logEntry>)),
            this, SLOT(logsReceived(QVector<eventLogging::logEntry>)));
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

void Roomba::disconnectDoIt(bool disconnectDo)
{
    if(disconnectDo == true)
    {
        this->server->doDisconnect();
    }
    readDataTimer->stop();
    getBrushVacuum->stop();
    getCurrentModeAction->stop();
    getLogs->stop();
}
