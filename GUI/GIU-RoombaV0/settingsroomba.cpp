#include "settingsroomba.h"
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
