#include "displaylogs.h"
#include "ui_displaylogs.h"
#include "roomba.h"


DisplayLogs::DisplayLogs(QWidget *parent):
    QWidget(parent),
    ui(new Ui::DisplayLogs)
{
    ui->setupUi(this);
}

DisplayLogs::~DisplayLogs()
{
    delete ui;
}

void DisplayLogs::on_pushButton_clicked()
{
    Roomba *roomba = new Roomba();
    roomba->show();
    this->close();
}
