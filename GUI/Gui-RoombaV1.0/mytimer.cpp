#include "mytimer.h"
#include "QtCore"

myTimer::myTimer()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL (timeout()), this , SLOT(MyTimerSlot()));

            timer->start(500);
}

void myTimer::MyTimerSlot()
{
    ;
}
