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
    connect(controlling_roomba, SIGNAL(setBrushes(Brushes)),
            this, SLOT(BrushModeChanged(Brushes)));
    connect(controlling_roomba, SIGNAL(setVacuum(Vacuum)),
            this, SLOT(VacuumModeChanged(Vacuum)));
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
    jsonCommand toSend(JSONCOMMAND_MODECHANGED);
    toSend.addToData("newmode", newMode);
    this->server->sendCommand(toSend);
}

void Roomba::BrushModeChanged(Brushes setBrush)
{
    jsonCommand toSend(JSONCOMMAND_SETBRUSHES);
    toSend.addToData("BrushState", setBrush);
    this->server->sendCommand(toSend);
}

void Roomba::VacuumModeChanged(Vacuum setVacuum)
{
    jsonCommand toSend(JSONCOMMAND_SETVACUUM);
    toSend.addToData("VacuumState", setVacuum);
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
