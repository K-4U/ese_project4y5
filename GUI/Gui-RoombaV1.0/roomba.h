#ifndef ROOMBA_H
#define ROOMBA_H

#include <QMainWindow>
#include "RoombaConnect.h"
#include "controllingroomba.h"
#include "../resources/jsoncommand.h"
#include "../resources/json.h"
#include "../resources/clslog.h"
#include "../resources/clsevent.h"

using namespace client;

namespace Ui {
class Roomba;
}

class Roomba : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Roomba(QWidget *parent = 0);
    ~Roomba();
    
private slots:
    void on_pbConnect_clicked();

    void on_pbCloseRoomba_clicked();

    void on_pbControlRoomba_clicked();

    void on_pbInformation_clicked();

    void on_pbDiplayLogs_clicked();

    void ManualcommandReceived(QString Manualcommand);

    void RoombaModeChanged(Modes);

    void MotorBrushVacuumChanged(bool, bool, bool);

    void MotorSpeedChanged(int, int);

    void on_pbDisonnect_clicked();

    void readSensorData(int);

private:
    Ui::Roomba *ui;
    clsServerConn *server;

signals:
    void Status(int batteryStatus, int temperature);
};

#endif // ROOMBA_H
