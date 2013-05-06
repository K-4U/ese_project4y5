#ifndef CONTROLLINGROOMBA_H
#define CONTROLLINGROOMBA_H

#include "../resources/clslog.h"
#include <QWidget>
using namespace K4U;

namespace Ui {
class Controllingroomba;
}

class Controllingroomba : public QWidget
{
    Q_OBJECT
    
public:
    explicit Controllingroomba(QWidget *parent = 0);
    ~Controllingroomba();
    
private slots:
    void on_pushButton_6_clicked();

    void on_pbUpload_clicked();

private:
    Ui::Controllingroomba *ui;
    clsLog log;
};

#endif // CONTROLLINGROOMBA_H
