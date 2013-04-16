#include "controllingroomba.h"
#include "ui_controllingroomba.h"
#include "roomba.h"

Controllingroomba::Controllingroomba(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Controllingroomba)
{
    ui->setupUi(this);

    QObject::connect(&tcpClient,SIGNAL(readyRead(void)),
                     this,SLOT(on_dataReceived(void)));

    QObject::connect(&tcpClient,SIGNAL(connected()),
                     this,SLOT(on_connectionAvailable()));

    QObject::connect(&tcpClient,SIGNAL(disconnected()),
                     this,SLOT(on_connectionNotAvailable()));
}

Controllingroomba::~Controllingroomba()
{
    delete ui;
}

void Controllingroomba::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Controllingroomba::on_pushButton_6_clicked()
{
    Roomba *roomba = new Roomba();
    roomba->show();
    this->close();
}

void Controllingroomba::on_pbConnect_clicked()
{
    ui->textEdit->setText("connect ingedrukt");
    bool resultOK = false;
    // get ip address from ipAddress field
    // this can be text: xxx.com or 11.22.33.44
    QString host = ui->leHost->text();

    // get port number from portAddress field
    unsigned int port = ui->lePoort->text().toUInt(&resultOK,10);
    if (!resultOK)
    {
        // use default number
        port = 11223;
    }
    ui->textEdit->append("connect to " + host + " " + QString::number(port,10));
    tcpClient.connectToHost(host,port,QIODevice::ReadWrite);
}

void Controllingroomba::on_dataReceived(void)
{
    ui->textEdit->append(tcpClient.readAll());
}

void Controllingroomba::on_connectionAvailable(void)
{
    ui->stud->setText("verbinding beschikbaar");
}

void Controllingroomba::on_connectionNotAvailable(void)
{
    ui->stud->setText("verbinding niet beschikbaar");

}
