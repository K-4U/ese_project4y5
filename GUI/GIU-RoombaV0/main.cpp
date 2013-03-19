#include "roomba.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Roomba w;
    w.show();
    
    return a.exec();
}
