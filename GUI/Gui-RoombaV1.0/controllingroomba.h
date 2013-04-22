#ifndef CONTROLLINGROOMBA_H
#define CONTROLLINGROOMBA_H

#include <QWidget>

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

private:
    Ui::Controllingroomba *ui;
};

#endif // CONTROLLINGROOMBA_H
