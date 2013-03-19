#-------------------------------------------------
#
# Project created by QtCreator 2013-03-18T13:35:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GIU-RoombaV0
TEMPLATE = app


SOURCES += main.cpp\
        roomba.cpp \
    controllingroomba.cpp \
    settingsroomba.cpp \
    dysplaylogs.cpp \
    information.cpp

HEADERS  += roomba.h \
    controllingroomba.h \
    settingsroomba.h \
    dysplaylogs.h \
    information.h

FORMS    += roomba.ui \
    controllingroomba.ui \
    settingsroomba.ui \
    dysplaylogs.ui \
    information.ui
