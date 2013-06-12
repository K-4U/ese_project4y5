#include "controllingroomba.h"
#include "ui_controllingroomba.h"
#include "roomba.h"
#include "mytimer.h"
#include "QtCore"

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

void Controllingroomba::allSensorData(int sensorID, int sensorValue)
{
    QString temp;
    switch(sensorID)
    {
        case 19:
            totalDistance += sensorValue;
            temp = "Distance: %1";
            temp = temp.arg(sensorValue);
            ui->lbDistance->setText(temp);

            temp = "Total distance: %1";
            temp = temp.arg(totalDistance);
            ui->lbTotalDistance->setText(temp);
            break;
        case 20:
            temp = "Angle: %1";
            temp = temp.arg(sensorValue);
            // angle needs fix
            break;
        case 21:
            temp = "Battery charge state: %1";
            temp = temp.arg(sensorValue);
            ui->lbBatteryChargingState->setText(temp);
            break;
        case 24:
            temp = "Temperature: %1";
            temp = temp.arg(sensorValue);
            ui->lbTemperature->setText(temp);
            break;
        case 25:
            batteryCharge = sensorValue;
            break;
        case 26:
            ui->prBattery->setValue((100*batteryCharge)/sensorValue);
            break;
        case 35:
            if(sensorValue == 0)
            {
                temp = "Operating mode OFF";
                ui->lbOperatingMode->setText(temp);
            }
            else if(sensorValue == 1)
            {
                temp = "Operating mode PASSIVE";
                ui->lbOperatingMode->setText(temp);
            }
            else if(sensorValue == 2)
            {
                temp = "Operating mode SAFE";
                ui->lbOperatingMode->setText(temp);
            }
            else if(sensorValue == 3)
            {
                temp = "Operating mode FULL";
                ui->lbOperatingMode->setText(temp);
            }
            break;
    }
}

void Controllingroomba::logsReceived(QVector<eventLogging::logEntry> entries){
    this->logEntries = entries;
    if(logsOpened == true)
    {
        display_logs->logsUpdated(entries);
    }
}

void Controllingroomba::on_pbDisonnect_clicked()
{
    emit disconnectDo(true);
}

void Controllingroomba::on_pbDisplayLogs_clicked()
{
    display_logs = new DisplayLogs(this->logEntries);
    logsOpened = true;

    display_logs->show();
}
