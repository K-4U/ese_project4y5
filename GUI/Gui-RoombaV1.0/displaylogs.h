#ifndef DISPLAYLOGS_H
#define DISPLAYLOGS_H

#include <QWidget>
#include "loggingdata.h"

using namespace shared;
using namespace events;

namespace Ui {
class DisplayLogs;
}

class DisplayLogs : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayLogs(QVector<eventLogging::logEntry> logEntries);
    ~DisplayLogs();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DisplayLogs *ui;
};

#endif // DISPLAYLOGS_H
