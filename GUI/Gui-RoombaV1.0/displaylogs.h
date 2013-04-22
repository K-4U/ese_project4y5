#ifndef DISPLAYLOGS_H
#define DISPLAYLOGS_H

#include <QWidget>

namespace Ui {
class DisplayLogs;
}

class DisplayLogs : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayLogs(QWidget *parent = 0);
    ~DisplayLogs();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DisplayLogs *ui;
};

#endif // DISPLAYLOGS_H
