#include "controllingroomba.h"
#include "ui_controllingroomba.h"
#include "roomba.h"

Controllingroomba::Controllingroomba(QWidget *parent) :
    QWidget(),
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

void Controllingroomba::on_pbDriveForward_pressed()
{
    emit setMotorSpeed(ui->hsMotorSpeed->value(), ui->hsMotorSpeed->value());
}

void Controllingroomba::on_pbDriveForward_released()
{
    emit setMotorSpeed(0,0);
}

void Controllingroomba::on_pbDriveLeft_pressed()
{
    emit setMotorSpeed((ui->hsMotorSpeed->value()* -1), ui->hsMotorSpeed->value());
}

void Controllingroomba::on_pbDriveLeft_released()
{
    emit setMotorSpeed(0,0);
}

void Controllingroomba::on_pbDriveBackward_pressed()
{
    emit setMotorSpeed((ui->hsMotorSpeed->value() * -1), (ui->hsMotorSpeed->value()* -1));
}

void Controllingroomba::on_pbDriveBackward_released()
{
    emit setMotorSpeed(0,0);
}

void Controllingroomba::on_pbDriveRight_pressed()
{
    emit setMotorSpeed(ui->hsMotorSpeed->value(), (ui->hsMotorSpeed->value()* -1));
}

void Controllingroomba::on_pbDriveRight_released()
{
    emit setMotorSpeed(0,0);
}

void Controllingroomba::on_pbResetRoomba_clicked()
{
}

void Controllingroomba::on_pbStop_clicked()
{
    emit ModeChanged(MODESTOPPED);
}

void Controllingroomba::cbMotorBrushVacuumHandler()
{
    emit setMotorBrushVacuum(ui->cbMainBrush->checkState() == Qt::Checked,
            ui->cbSideBrush->checkState() == Qt::Checked,
            ui->cbVacuum->checkState() == Qt::Checked);
}
