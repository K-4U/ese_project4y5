#include "roomba.h"
#include "ui_roomba.h"

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

void Roomba::on_pushButton_5_clicked()
{
    this->close();

}

void Roomba::on_pushButton_3_clicked()
{
    this->close();
    controllingroomba->show();
}
