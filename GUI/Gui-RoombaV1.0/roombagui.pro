#-------------------------------------------------
#
# Project created by QtCreator 2013-03-25T11:01:01
#
#-------------------------------------------------

QT       += core network gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        roomba.cpp \
    controllingroomba.cpp \
    RoombaConnect.cpp \
    ../resources/jsoncommand.cpp \
    ../resources/json.cpp \
    ../resources/clslog.cpp \
    ../resources/clsevent.cpp \
    displayLogs.cpp \
    sensordata.cpp

HEADERS  += roomba.h \
    controllingroomba.h \
    RoombaConnect.h \
    ../resources/jsoncommand.h \
    ../resources/json.h \
    ../resources/clslog.h \
    ../resources/clsevent.h \
    displayLogs.h \
    sensordata.h

FORMS    += roomba.ui \
    controllingroomba.ui \
    displaylogs.ui