#include "controllingroomba.h"
#include "ui_controllingroomba.h"

ControllingRoomba::ControllingRoomba(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControllingRoomba)
{
    ui->setupUi(this);
}

ControllingRoomba::~ControllingRoomba()
{
    delete ui;
}
