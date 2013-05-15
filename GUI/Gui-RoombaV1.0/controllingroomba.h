#ifndef CONTROLLINGROOMBA_H
#define CONTROLLINGROOMBA_H

#include "../resources/json.h"
#include "../resources/jsoncommand.h"
#include "../resources/clslog.h"
#include <QWidget>
#include <QTcpSocket>
using namespace K4U;

enum Modes{
    MODESTOPPED = 0x00,
    MODEDRIVE,
    MODECLEAN,
    MODECLEANONSPOT,
    MODEDOCK
};

enum Brushes{
    MAINBRUSH = 0x00,
    SIDEBRUSH
};

enum Vacuum{
    VACUUM = 0x00
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
    void on_pbDrive_clicked();

    void on_pbStop_clicked();

    void cbMainBrushHandler();

    void cbSideBrushHandler();

    void cbVacuumHandler();

private slots:
    void on_pbClean_clicked();

    void on_pbCleanSpot_clicked();

    void on_pbClose_clicked();

    void on_pbDock_clicked();

    void on_pbResetRoomba_clicked();

    void on_pbUpload_clicked();

private:
    Ui::Controllingroomba *ui;
    clsLog log;
    QTcpSocket *sock;
    QWidget *parent;


signals:
    void ManualcommandReceived(QString Manualcommand);
    void ModeChanged(Modes newMode);
    void setBrushes(Brushes setBrush);
    void readBrushes(Brushes readBrush);
    void setVacuum(Vacuum setVacuum);
    void readVacuum(Vacuum setVacuum);
};

#endif // CONTROLLINGROOMBA_H
