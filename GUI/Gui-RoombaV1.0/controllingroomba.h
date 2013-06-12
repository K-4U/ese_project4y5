#ifndef CONTROLLINGROOMBA_H
#define CONTROLLINGROOMBA_H

#include "../resources/json.h"
#include "../resources/jsoncommand.h"
#include "RoombaConnect.h"
#include "../resources/clslog.h"
#include "../resources/clsevent.h"
#include <QWidget>
#include <QTcpSocket>
#include <QSlider>
#include <QtCore>
#include "loggingdata.h"

using namespace K4U;
using namespace client;

enum Modes{
    MODESTOPPED = 0x00,
    MODECLEAN,
    MODECLEANONSPOT,
    MODEDOCK
};

namespace Ui {
class Controllingroomba;
}

class Controllingroomba : public QWidget
{
    Q_OBJECT

public:
    explicit Controllingroomba(QWidget *parent = 0);
    ~Controllingroomba();

    void allSensorData(int, int);
    void logsReceived(QVector<eventLogging::logEntry> entries);

public slots:
    void on_pbStop_clicked();

    void cbMotorBrushVacuumHandler();

private slots:
    void on_pbClean_clicked();

    void on_pbCleanSpot_clicked();

    void on_pbClose_clicked();

    void on_pbDock_clicked();

    void on_pbDriveLeft_pressed();

    void on_pbDriveBackward_pressed();

    void on_pbDriveRight_pressed();

    void on_pbDriveForward_pressed();

    void on_pbDriveForward_released();

    void on_pbDriveBackward_released();

    void on_pbDriveLeft_released();

    void on_pbDriveRight_released();

    void on_pbDisonnect_clicked();

    void on_pbDisplayLogs_clicked();

private:
    Ui::Controllingroomba *ui;
    clsLog log;
    QTcpSocket *sock;
    QWidget *parent;
    int totalDistance;
    int batteryCharge;

    QVector<eventLogging::logEntry> logEntries;

signals:
    void disconnectDo(bool disconnect);
    void ModeChanged(Modes newMode);
    void setMotorBrushVacuum(bool MainBrush, bool SideBrush, bool Vacuum);
    void setMotorSpeed(int setLeftMotorSpeed, int setRightMotorSpeed);
};

#endif // CONTROLLINGROOMBA_H
