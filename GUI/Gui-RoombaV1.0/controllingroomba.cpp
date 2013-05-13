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

void Controllingroomba::on_pbClose_clicked()
{
    Roomba *roomba = new Roomba();
    roomba->show();
    this->close();
}

void Controllingroomba::on_pbUpload_clicked()
{
    QString Manualcommand = ui->txtManualcommands->toPlainText();

    this->log << Manualcommand << endl;
    emit ManualcommandReceived(Manualcommand);

    ui->txtManualcommands->clear();
}

void Controllingroomba::on_pbClean_clicked()
{
}

void Controllingroomba::on_pbCleanSpot_clicked()
{
}

void Controllingroomba::on_pbDock_clicked()
{
}

void Controllingroomba::on_pbDrive_clicked()
{
}

void Controllingroomba::on_pbResetRoomba_clicked()
{
}
