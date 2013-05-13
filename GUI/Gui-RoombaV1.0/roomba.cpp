#include "roomba.h"
#include "ui_roomba.h"
#include "controllingroomba.h"
#include "settingsroomba.h"
#include "information.h"
#include "displaylogs.h"

Roomba::Roomba(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Roomba),
    server()
{
//    this->server = new clsServerConn("145.74.199.121", 1337);
    this->server = new clsServerConn("localhost", 1337);

    ui->setupUi(this);

    connect(this->server, SIGNAL(ManualcommandReceived(QString)),
            this, SLOT(ManualcommandReceived(QString)));
}

Roomba::~Roomba()
{
    delete ui;
}

void Roomba::on_pbControlRoomba_clicked()
{
    Controllingroomba *controlling_roomba = new Controllingroomba();
    controlling_roomba->show();
    this->close();
}

void Roomba::on_pbSettingRoomba_clicked()
{
    SettingsRoomba *settings_roomba = new SettingsRoomba();
    settings_roomba->show();
    this->close();
}

void Roomba::on_pbInformation_clicked()
{
    Information *information_roomba = new Information();
    information_roomba->show();
    this->close();
}


void Roomba::on_pbDiplayLogs_clicked()
{
    DisplayLogs *display_logs = new DisplayLogs();
    display_logs->show();
    this->close();
}

void Roomba::ManualcommandReceived(QString Manualcommand)
{
}


void Roomba::on_pbConnect_clicked()
{
    this->server->doConnect();
}

void Roomba::on_pbCloseRoomba_clicked()
{
}

/*void Roomba::ManualcommandReceived(QString Manualcommand)
{
    this->server->sendCommand();
}*/
