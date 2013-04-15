//-----------------------------------------------------------------------
// File           : main.cpp
// Part of module : example warme drankenautomaat
// Version        : 0.1
// Date           : 2010-05-10
// Authors        : Ruud Elsinghorst
// Description    : main for the GUI of the warmedrankenautomaat,
//                  this GUI is using a tcp socket to connect with the
//                  domain logic made with Rose RealTime
//                  The GUI has been build with Qt Creator using the
//                  GUI editor.
// Change history :
//       date:      who:   changes:
//       --------   ----   -------
//       20100510   esgr   initial version
//-----------------------------------------------------------------------

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
