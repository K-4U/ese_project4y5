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
    MODEDRIVEFORWARD,
    MODEDRIVELEFT,
    MODEDRIVERIGHT,
    MODEDRIVEBACKWARD,
    MODECLEAN,
    MODECLEANONSPOT,
    MODEDOCK
};

enum MainBrush{
    MAINBRUSH = 0x00
};

enum SideBrush{
    SIDEBRUSH = 0x00
};

enum Vacuum{
    VACUUM = 0x00
};

enum Motor{
    MOTOR = 0x00
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
    void on_pbDriveForward_clicked();

    void on_pbStop_clicked();

    void cbMainBrushHandler();

    void cbSideBrushHandler();

    void cbVacuumHandler();

    void hsVacuumValueChanged();

    void hsMotorValueChanged();

private slots:
    void on_pbClean_clicked();

    void on_pbCleanSpot_clicked();

    void on_pbClose_clicked();

    void on_pbDock_clicked();

    void on_pbResetRoomba_clicked();

    void on_pbUpload_clicked();

    void on_pbDriveLeft_clicked();

    void on_pbDriveBackward_clicked();

    void on_pbDriveRight_clicked();

private:
    Ui::Controllingroomba *ui;
    clsLog log;
    QTcpSocket *sock;
    QWidget *parent;


signals:
    void ManualcommandReceived(QString Manualcommand);
    void ModeChanged(Modes newMode);
    void setMainBrush(MainBrush setMainBrush);
    void setSideBrush(SideBrush setSideBrush);
    void readMainBrush(MainBrush readMainBrush);
    void readSideBrush(SideBrush readSideBrush);
    void setVacuum(Vacuum setVacuum);
    void readVacuum(Vacuum readVacuum);
    void setMotorSpeed(Motor setMotor);
    void readMotorSpeed(Motor readMotor);
};

#endif // CONTROLLINGROOMBA_H
