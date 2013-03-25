#include "roomba.h"
#include "controllingroomba.h"
#include "ui_roomba.h"
#include <QtCore>
#include <QtGui>
#include <iostream>
using namespace std;

Roomba::Roomba(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Roomba)
{
    ui->setupUi(this);
}

Roomba::~Roomba()
{
    delete ui;
}

void Roomba::on_pushButton_2_clicked()
{
    cout << "pushed button 2" << endl;
}

void Roomba::on_pushButton_5_clicked()
{
    cout << "pushed button" << endl;
    ControllingRoomba *controlling_roomba = new ControllingRoomba();
    controlling_roomba->show();
    this->close();
}
