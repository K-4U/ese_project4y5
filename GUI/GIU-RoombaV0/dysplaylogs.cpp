#include "dysplaylogs.h"
#include "ui_dysplaylogs.h"

DysplayLogs::DysplayLogs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DysplayLogs)
{
    ui->setupUi(this);
}

DysplayLogs::~DysplayLogs()
{
    delete ui;
}
