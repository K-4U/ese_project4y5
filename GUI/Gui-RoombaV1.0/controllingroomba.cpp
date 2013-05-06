#include "controllingroomba.h"
#include "ui_controllingroomba.h"
#include "roomba.h"

Controllingroomba::Controllingroomba(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Controllingroomba),
    log(LOGTAGS_ROOMBA)
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

void Controllingroomba::on_pbUpload_clicked()
{

    QString Manualcommand = ui->txtManualcommands->toPlainText();

    this->log << Manualcommand << endl;



    ui->txtManualcommands->clear();
}
