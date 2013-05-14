#include "controllingroomba.h"
#include "ui_controllingroomba.h"
#include "roomba.h"

// close button not working

Controllingroomba::Controllingroomba(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Controllingroomba),
    log(LOGTAGS_ROOMBA),
    parent(parent)
{
    ui->setupUi(this);
}

Controllingroomba::~Controllingroomba()
{
    delete ui;
}

void Controllingroomba::on_pbClose_clicked()
{
    this->parent->show();
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
    emit ModeChanged(MODECLEAN);
}

void Controllingroomba::on_pbCleanSpot_clicked()
{
    emit ModeChanged(MODECLEANONSPOT);
}

void Controllingroomba::on_pbDock_clicked()
{
    emit ModeChanged(MODEDOCK);
}

void Controllingroomba::on_pbDrive_clicked()
{
    emit ModeChanged(MODEDRIVE);
}

void Controllingroomba::on_pbResetRoomba_clicked()
{
}

void Controllingroomba::on_pbStop_clicked()
{
    emit ModeChanged(MODESTOPPED);
}

void Controllingroomba::on_cbMainBrush_stateChanged(int arg1)
{
    emit setBrushes(MAIN);
}
