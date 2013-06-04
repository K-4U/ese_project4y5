#include "roomba.h"
#include "ui_roomba.h"
#include "controllingroomba.h"
#include "displaylogs.h"
#include "mytimer.h"
#include <QtGui>

Roomba::Roomba(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Roomba),
    server()
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

void Roomba::readSensorData()
{
    QVector<int> sensors;
    sensors.append(19);
    sensors.append(22);
    sensors.append(24);



    readDataTimer->start(1000);
    jsonCommand toSend(JSONCOMMAND_READSENSORDATA);
    toSend.addToData("Sensors", sensors);
    this->server->sendCommand(toSend);
}

void Roomba::disconnectDoIt(bool disconnectDo)
{
    if(disconnectDo == true)
    {
        this->server->doDisconnect();
    }
    readDataTimer->stop();
}

void Roomba::on_pbConnect_clicked()
{
    char *IP = ui->leIP->text().toLatin1().data();
//    this->server = new clsServerConn("145.74.196.221", 11223);
    this->server = new clsServerConn(IP, 1337);


    Controllingroomba *controlling_roomba = new Controllingroomba(this);
    controlling_roomba->show();

    connect(controlling_roomba, SIGNAL(ModeChanged(Modes)),
            this, SLOT(RoombaModeChanged(Modes)));

    connect(controlling_roomba, SIGNAL(setMotorBrushVacuum(bool, bool, bool)),
            this, SLOT(MotorBrushVacuumChanged(bool, bool, bool)));

    connect(controlling_roomba, SIGNAL(setMotorSpeed(int, int)),
            this, SLOT(MotorSpeedChanged(int, int)));

    connect(controlling_roomba, SIGNAL(disconnectDo(bool)),
            this, SLOT(disconnectDoIt(bool)));


    readDataTimer = new QTimer(this);
    connect(readDataTimer, SIGNAL(timeout()), this, SLOT(readSensorData()));
    readDataTimer->start(1000);

    this->hide();

    this->server->doConnect();
}
