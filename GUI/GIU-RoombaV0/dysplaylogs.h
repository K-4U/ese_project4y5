#ifndef DYSPLAYLOGS_H
#define DYSPLAYLOGS_H

#include <QWidget>

namespace Ui {
class DysplayLogs;
}

class DysplayLogs : public QWidget
{
    Q_OBJECT
    
public:
    explicit DysplayLogs(QWidget *parent = 0);
    ~DysplayLogs();
    
private:
    Ui::DysplayLogs *ui;
};

#endif // DYSPLAYLOGS_H
