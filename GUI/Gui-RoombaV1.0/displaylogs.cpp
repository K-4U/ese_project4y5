#include "displaylogs.h"
#include "ui_displaylogs.h"
#include "roomba.h"
#include <QStandardItemModel>


DisplayLogs::DisplayLogs(QVector<eventLogging::logEntry> logEntries):
    QWidget(0),
    ui(new Ui::DisplayLogs)
{
    ui->setupUi(this);

    QStandardItemModel *model = new QStandardItemModel(logEntries.size(),0);
    int i = logEntries.size()-1;
    foreach(eventLogging::logEntry entry, logEntries){
        QString str = entry.time + " " + entry.entry;
        QStandardItem *item = new QStandardItem(str);
        model->setItem(i, item);
        i--;
    }
    this->ui->lvLogs->setModel(model);
}

DisplayLogs::~DisplayLogs()
{
    delete ui;
}

void DisplayLogs::on_pbCloseDisplayLogs_clicked()
{
    this->close();
}


void DisplayLogs::logsUpdated(QVector<eventLogging::logEntry> logEntries)
{
//    QStandardItemModel *model = new QStandardItemModel(logEntries.size(),0);
//    int i = logEntries.size()-1;
//    foreach(eventLogging::logEntry entry, logEntries){
//        QString str = entry.time + " " + entry.entry;
//        QStandardItem *item = new QStandardItem(str);
//        model->setItem(i, item);
//        i--;
//    }
//    this->ui->lvLogs->setModel(model);
}
