#ifndef ROOMBA_H
#define ROOMBA_H

#include <QMainWindow>
#include "RoombaConnect.h"
#include "controllingroomba.h"
#include "../resources/jsoncommand.h"
#include "../resources/json.h"
#include "../resources/clslog.h"

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

    void MainBrushModeChanged(MainBrush);

    void SideBrushModeChanged(SideBrush);

    void VacuumModeChanged(Vacuum);

    void MotorModeChanged(Motor);

    void on_pbDisonnect_clicked();

    void manualDriveForward(DriveForward);

    void manualDriveBackward(DriveBackward);

    void manualDriveLeft(DriveLeft);

    void manualDriveRight(DriveRight);

private:
    Ui::Roomba *ui;
    clsServerConn *server;
};

#endif // ROOMBA_H
