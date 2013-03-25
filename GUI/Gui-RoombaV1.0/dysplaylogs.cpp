#include "dysplaylogs.h"
#include "ui_dysplaylogs.h"
#include "roomba.h"

DysplayLogs::DysplayLogs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DysplayLogs)
{
    ui->setupUi(this);
}

DysplayLogs::~DysplayLogs()
{
    delete ui;
}

void DysplayLogs::on_pushButton_clicked()
{
    Roomba *roomba = new Roomba();
    roomba->show();
    this->close();
}
