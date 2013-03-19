#ifndef CONTROLLINGROOMBA_H
#define CONTROLLINGROOMBA_H

#include <QWidget>

namespace Ui {
class ControllingRoomba;
}

class ControllingRoomba : public QWidget
{
    Q_OBJECT
    
public:
    explicit ControllingRoomba(QWidget *parent = 0);
    ~ControllingRoomba();
    
private:
    Ui::ControllingRoomba *ui;
};

#endif // CONTROLLINGROOMBA_H
