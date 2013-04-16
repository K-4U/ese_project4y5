#ifndef CONTROLLINGROOMBA_H
#define CONTROLLINGROOMBA_H

#include <QWidget>
#include <QTcpSocket>
#include <QMainWindow>
// include de source en header files van jason (irc client)

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

    void on_pbConnect_clicked();

private:
    Ui::Controllingroomba *ui;
    QTcpSocket tcpClient;

protected:
    void changeEvent(QEvent *e);

signals:
    void makeCacao(QString s);

private slots:
    // added uer made slots
    // the slot names are starting with "on_" simular to the names generated
    // by Qt Creator
    void on_dataReceived(void);
    void on_connectionAvailable(void);
    void on_connectionNotAvailable(void);
};

#endif // CONTROLLINGROOMBA_H
