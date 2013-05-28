#ifndef CONTROLLINGROOMBA_H
#define CONTROLLINGROOMBA_H

#include "../resources/json.h"
#include "../resources/jsoncommand.h"
#include "../resources/clslog.h"
#include <QWidget>
#include <QTcpSocket>
#include <QSlider>

using namespace K4U;

enum Modes{
    MODESTOPPED = 0x00,
    MODECLEAN,
    MODECLEANONSPOT,
    MODEDOCK
};

enum DriveForward{
    STOPDRIVEFORWARD = 0x00,
    DRIVEFORWARD

};

enum DriveBackward{
    STOPDRIVEBACKWARD = 0x00,
    DRIVEBACKWARD
};

enum DriveLeft{
    STOPDRIVELEFT = 0x00,
    DRIVELEFT
    };

enum DriveRight{
    STOPDRIVERIGHT = 0x00,
    DRIVERIGHT
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

public slots:
    void on_pbStop_clicked();

    void cbMotorBrushVacuumHandler();

    void hsMotorValueChanged();

private slots:
    void on_pbClean_clicked();

    void on_pbCleanSpot_clicked();

    void on_pbClose_clicked();

    void on_pbDock_clicked();

    void on_pbResetRoomba_clicked();

    void on_pbUpload_clicked();

    void on_pbDriveLeft_pressed();

    void on_pbDriveBackward_pressed();

    void on_pbDriveRight_pressed();

    void on_pbDriveForward_pressed();

    void on_pbDriveForward_released();

    void on_pbDriveBackward_released();

    void on_pbDriveLeft_released();

    void on_pbDriveRight_released();

private:
    Ui::Controllingroomba *ui;
    clsLog log;
    QTcpSocket *sock;
    QWidget *parent;


signals:
    void ManualcommandReceived(QString Manualcommand);
    void ModeChanged(Modes newMode);
    void setMotorBrushVacuum(bool MainBrush, bool SideBrush, bool Vacuum);
    void setMotorSpeed(int setLeftMotorSpeed, int setRightMotorSpeed);
    void manualDriveForward(DriveForward setDriveForward);
    void manualDriveBackward(DriveBackward setDriveBackward);
    void manualDriveLeft(DriveLeft setDriveLeft);
    void manualDriveRight(DriveRight setDriveRight);
};

#endif // CONTROLLINGROOMBA_H
