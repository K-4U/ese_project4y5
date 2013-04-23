/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 10. May 17:03:29 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *makeCacaoButton;
    QTextEdit *display;
    QPushButton *pushButton;
    QLineEdit *ipAddress;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *portAddress;
    QLabel *status;
    QMenuBar *menuBar;
    QMenu *menuWarme_drankenautomaat;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(383, 185);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        makeCacaoButton = new QPushButton(centralWidget);
        makeCacaoButton->setObjectName(QString::fromUtf8("makeCacaoButton"));
        makeCacaoButton->setGeometry(QRect(10, 10, 75, 23));
        display = new QTextEdit(centralWidget);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(10, 70, 161, 64));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 10, 171, 23));
        ipAddress = new QLineEdit(centralWidget);
        ipAddress->setObjectName(QString::fromUtf8("ipAddress"));
        ipAddress->setGeometry(QRect(200, 70, 91, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 50, 61, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 46, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(290, 50, 151, 16));
        portAddress = new QLineEdit(centralWidget);
        portAddress->setObjectName(QString::fromUtf8("portAddress"));
        portAddress->setGeometry(QRect(290, 70, 81, 20));
        status = new QLabel(centralWidget);
        status->setObjectName(QString::fromUtf8("status"));
        status->setGeometry(QRect(200, 100, 141, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 383, 18));
        menuWarme_drankenautomaat = new QMenu(menuBar);
        menuWarme_drankenautomaat->setObjectName(QString::fromUtf8("menuWarme_drankenautomaat"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuWarme_drankenautomaat->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Warme drankenautomaat", 0, QApplication::UnicodeUTF8));
        makeCacaoButton->setText(QApplication::translate("MainWindow", "maak cacao", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "connect", 0, QApplication::UnicodeUTF8));
        ipAddress->setText(QApplication::translate("MainWindow", "localhost", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "<ip-adres>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Display", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "<poortnummer>", 0, QApplication::UnicodeUTF8));
        portAddress->setText(QApplication::translate("MainWindow", "11223", 0, QApplication::UnicodeUTF8));
        status->setText(QApplication::translate("MainWindow", "verbinding niet beschikbaar", 0, QApplication::UnicodeUTF8));
        menuWarme_drankenautomaat->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
