#ifndef MYTIMER_H
#define MYTIMER_H
#include <QtCore>


class myTimer : public QObject
{
    Q_OBJECT


public:
    myTimer();
    QTimer *timer;

public slots:
    void MyTimerSlot();

signals:
    void readStatus(int Status);
};

#endif // MYTIMER_H
