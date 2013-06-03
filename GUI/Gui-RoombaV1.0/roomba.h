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

    void RoombaModeChanged(Modes);

    void MotorBrushVacuumChanged(bool, bool, bool);

    void MotorSpeedChanged(int, int);

    void readSensorData(int);

    void disconnectDoIt(bool);

private:
    Ui::Roomba *ui;
    clsServerConn *server;

signals:
    void Status(int batteryStatus, int temperature);
};

#endif // ROOMBA_H
