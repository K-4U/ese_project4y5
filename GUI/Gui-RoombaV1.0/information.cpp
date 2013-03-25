#include "information.h"
#include "ui_information.h"
#include "roomba.h"

Information::Information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this);
}

Information::~Information()
{
    delete ui;
}

void Information::on_pushButton_clicked()
{
    Roomba *roomba = new Roomba();
    roomba->show();
    this->close();
}
