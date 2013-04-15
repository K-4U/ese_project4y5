//-----------------------------------------------------------------------
// File           : mainwindow.h
// Part of module : example warme drankenautomaat
// Version        : 0.1
// Date           : 2010-05-10
// Authors        : Ruud Elsinghorst
// Description    : interface for the GUI of the warmedrankenautomaat,
//                  this GUI is using a tcp socket to connect with the
//                  domain logic made with Rose RealTime
// Change history :
//       date:      who:   changes:
//       --------   ----   -------
//       20100510   esgr   initial version
//-----------------------------------------------------------------------

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTcpSocket>
#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT


private:
    Ui::MainWindow *ui;
    QTcpSocket tcpClient;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

signals:
    void makeCacao(QString s);

private slots:
    void on_pushButton_clicked();
    // added uer made slots
    // the slot names are starting with "on_" simular to the names generated
    // by Qt Creator
    void on_makeCacaoButton_clicked();
    void on_dataReceived(void);
    void on_connectionAvailable(void);
    void on_connectionNotAvailable(void);
};

#endif // MAINWINDOW_H
