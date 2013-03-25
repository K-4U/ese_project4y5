#include "roomba.h"
#include "ui_roomba.h"
#include "controllingroomba.h"
#include "settingsroomba.h"
#include "information.h"
#include "dysplaylogs.h"

Roomba::Roomba(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Roomba)
{
    ui->setupUi(this);
}

Roomba::~Roomba()
{
    delete ui;
}

void Roomba::on_pushButton_2_clicked()
{
    Controllingroomba *controlling_roomba = new Controllingroomba();
    controlling_roomba->show();
    this->close();
}

void Roomba::on_pushButton_3_clicked()
{
    SettingsRoomba *settings_roomba = new SettingsRoomba();
    settings_roomba->show();
    this->close();
}

void Roomba::on_pushButton_4_clicked()
{
    Information *information_roomba = new Information();
    information_roomba->show();
    this->close();
}


void Roomba::on_pushButton_5_clicked()
{
    DysplayLogs *dysplay_logs = new DysplayLogs();
    dysplay_logs->show();
    this->close();
}
