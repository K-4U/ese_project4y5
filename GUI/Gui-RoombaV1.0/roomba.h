#ifndef ROOMBA_H
#define ROOMBA_H

#include <vector>
#include <QVector>
#include <QVariantMap>
#include <iostream>
#include <QMainWindow>
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

    struct sensordata{
        int r;
        int g;
    };
     QVector<int> sensors;
    QVariantMap toVariantMap() const;
    void setSensor(const int r, const int g);
    void setSensor(const sensordata &newSensorData);
    
private slots:
    void on_pbConnect_clicked();

    void RoombaModeChanged(Modes);

    void MotorBrushVacuumChanged(bool, bool, bool);

    void MotorSpeedChanged(int, int);

    void readSensorData();

    void disconnectDoIt(bool);

private:
    Ui::Roomba *ui;
    clsServerConn *server;
    QTimer *readDataTimer;
    sensordata uValue;

signals:
    void getStatus(int Status);
};

#endif // ROOMBA_H
