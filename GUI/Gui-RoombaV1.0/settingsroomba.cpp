#include "settingsroomba.h"
#include "roomba.h"
#include "ui_settingsroomba.h"

SettingsRoomba::SettingsRoomba(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsRoomba)
{
    ui->setupUi(this);
}

SettingsRoomba::~SettingsRoomba()
{
    delete ui;
}

void SettingsRoomba::on_pushButton_clicked()
{
    Roomba *roomba = new Roomba();
    roomba->show();
    this->close();
}
