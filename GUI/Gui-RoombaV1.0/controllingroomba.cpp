#include "controllingroomba.h"
#include "ui_controllingroomba.h"
#include "roomba.h"

Controllingroomba::Controllingroomba(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Controllingroomba)
{
    ui->setupUi(this);
}

Controllingroomba::~Controllingroomba()
{
    delete ui;
}

void Controllingroomba::on_pushButton_6_clicked()
{
    Roomba *roomba = new Roomba();
    roomba->show();
    this->close();
}
