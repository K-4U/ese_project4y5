//-----------------------------------------------------------------------
// File           : mainwindow.cpp
// Part of module : example warme drankenautomaat
// Version        : 0.1
// Date           : 2010-05-10
// Authors        : Ruud Elsinghorst
// Description    : implementation for the GUI of the warmedrankenautomaat,
//                  this GUI is using a tcp socket to connect with the
//                  domain logic made with Rose RealTime
//                  remark:
//                  sunny-day scenario: everything goes right.
//                  The implementation is a simple example assuming the programmer,
//                  using this example, will extend the code with the extra tests
//                  needed.
// Change history :
//       date:      who:   changes:
//       --------   ----   -------
//       20100510   esgr   initial version
//-----------------------------------------------------------------------


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(this,SIGNAL(makeCacao(QString)),
                     ui->display,SLOT(append(QString)));

    QObject::connect(&tcpClient,SIGNAL(readyRead(void)),
                     this,SLOT(on_dataReceived(void)));

    QObject::connect(&tcpClient,SIGNAL(connected()),
                     this,SLOT(on_connectionAvailable()));

    QObject::connect(&tcpClient,SIGNAL(disconnected()),
                     this,SLOT(on_connectionNotAvailable()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_makeCacaoButton_clicked()
{
    // using a SIGNAL to send text
    // in this example connected to the text edit field: "display"
    // see the constructor of MainWindow
    emit makeCacao("start maken drank");

    // send command to the domain logic
    // asuming connection with domain logic is available
    tcpClient.write("cacao");
}

void MainWindow::on_pushButton_clicked()
{
    bool resultOK = false;

    // get ip address from ipAddress field
    // this can be text: xxx.com or 11.22.33.44
    QString host = ui->ipAddress->text();

    // get port number from portAddress field
    unsigned int port = ui->portAddress->text().toUInt(&resultOK,10);
    if (!resultOK)
    {
        // use default number
        port = 11223;
    }
    ui->display->append("connect to " + host + " " + QString::number(port,10));
    tcpClient.connectToHost(host,port,QIODevice::ReadWrite);
}

void MainWindow::on_dataReceived(void)
{
    ui->display->append(tcpClient.readAll());
}

void MainWindow::on_connectionAvailable(void)
{
    ui->status->setText("verbinding beschikbaar");
}

void MainWindow::on_connectionNotAvailable(void)
{
    ui->status->setText("verbinding niet beschikbaar");

}

