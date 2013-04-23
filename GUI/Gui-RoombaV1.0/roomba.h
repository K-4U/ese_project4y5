#ifndef ROOMBA_H
#define ROOMBA_H

#include <QMainWindow>
#include "RoombaConnect.h"
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
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pbConnect_clicked();

private:
    Ui::Roomba *ui;
    clsServerConn *server;
};

#endif // ROOMBA_H
