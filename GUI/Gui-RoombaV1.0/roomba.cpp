#include "roomba.h"
#include "ui_roomba.h"
#include "controllingroomba.h"
#include "information.h"
#include "displaylogs.h"

Roomba::Roomba(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Roomba),
    server()
{
    this->server = new clsServerConn("145.74.196.221", 1337);
//    this->server = new clsServerConn("localhost", 1337);

    ui->setupUi(this);
}

Roomba::~Roomba()
{
    delete ui;
}

void Roomba::on_pbControlRoomba_clicked()
{
    Controllingroomba *controlling_roomba = new Controllingroomba();
    controlling_roomba->show();
    connect(controlling_roomba, SIGNAL(ModeChanged(Modes)),
            this, SLOT(RoombaModeChanged(Modes)));

    connect(controlling_roomba, SIGNAL(setMotorBrushVacuum(bool, bool, bool)),
            this, SLOT(MotorBrushVacuumChanged(bool, bool, bool)));

    connect(controlling_roomba, SIGNAL(setMotorSpeed(int, int)),
            this, SLOT(MotorSpeedChanged(int, int)));

    connect(controlling_roomba, SIGNAL(manualDriveForward(DriveForward)),
            this, SLOT(manualDriveForward(DriveForward)));

    connect(controlling_roomba, SIGNAL(manualDriveBackward(DriveBackward)),
            this, SLOT(manualDriveBackward(DriveBackward)));

    connect(controlling_roomba, SIGNAL(manualDriveLeft(DriveLeft)),
            this, SLOT(manualDriveLeft(DriveLeft)));

    connect(controlling_roomba, SIGNAL(manualDriveRight(DriveRight)),
            this, SLOT(manualDriveRight(DriveRight)));

    this->hide();

}

void Roomba::on_pbInformation_clicked()
{
    Information *information_roomba = new Information();
    information_roomba->show();
    this->hide();
}


void Roomba::on_pbDiplayLogs_clicked()
{
    DisplayLogs *display_logs = new DisplayLogs();
    display_logs->show();
    this->hide();
}

void Roomba::ManualcommandReceived(QString Manualcommand)
{
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

void Roomba::manualDriveForward(DriveForward setDriveForward)
{
    jsonCommand toSend(JSONCOMMAND_DRIVEFORWARD);
    toSend.addToData("DriveForward", setDriveForward);
    this->server->sendCommand(toSend);
}

void Roomba::manualDriveBackward(DriveBackward setDriveBackward)
{
    jsonCommand toSend(JSONCOMMAND_DRIVEBACKWARD);
    toSend.addToData("DriveBackward", setDriveBackward);
    this->server->sendCommand(toSend);
}

void Roomba::manualDriveLeft(DriveLeft setDriveLeft)
{
    jsonCommand toSend(JSONCOMMAND_DRIVELEFT);
    toSend.addToData("DriveLeft", setDriveLeft);
    this->server->sendCommand(toSend);
}

void Roomba::manualDriveRight(DriveRight setDriveRight)
{
    jsonCommand toSend(JSONCOMMAND_DRIVERIGHT);
    toSend.addToData("DriveRight", setDriveRight);
    this->server->sendCommand(toSend);
}

void Roomba::on_pbConnect_clicked()
{
    this->server->doConnect();
}

void Roomba::on_pbCloseRoomba_clicked()
{
}

void Roomba::on_pbDisonnect_clicked()
{
    this->server->doDisconnect();
}
