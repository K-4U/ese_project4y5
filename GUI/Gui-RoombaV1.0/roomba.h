#ifndef ROOMBA_H
#define ROOMBA_H

#include <QString>
#include <QDebug>
#include <QtCore>
#include <vector>
#include <QVector>
#include <QVariantMap>
#include <iostream>
#include <QMainWindow>
#include <QObject>
#include <QVariantMap>
#include "RoombaConnect.h"
#include "controllingroomba.h"
#include "sensordata.h"
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

    void readSensorData();

    void sendSensorDataRequest();

    void disconnectDoIt(bool);

    void roombaConnected();

private:
    Ui::Roomba *ui;
    clsServerConn *server;
    QTimer *readDataTimer;
    Controllingroomba *controlling_roomba;

signals:
    void sensorData(int sensorID, int sensorValue);
};

#endif // ROOMBA_H
