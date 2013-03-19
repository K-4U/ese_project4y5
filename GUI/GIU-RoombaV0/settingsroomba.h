#ifndef SETTINGSROOMBA_H
#define SETTINGSROOMBA_H

#include <QWidget>

namespace Ui {
class SettingsRoomba;
}

class SettingsRoomba : public QWidget
{
    Q_OBJECT
    
public:
    explicit SettingsRoomba(QWidget *parent = 0);
    ~SettingsRoomba();
    
private:
    Ui::SettingsRoomba *ui;
};

#endif // SETTINGSROOMBA_H
