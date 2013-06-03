#include "mytimer.h"
#include "QtCore"
#include <QDebug>

myTimer::myTimer()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL (timeout()), this , SLOT(MyTimerSlot()));

            timer->start(1000);
}

void myTimer::MyTimerSlot()
{
    qDebug() << "Timer executed";
}
