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
    settingsroomba.cpp \
    information.cpp \
    RoombaConnect.cpp \
    ../resources/jsoncommand.cpp \
    ../resources/json.cpp \
    ../resources/clslog.cpp \
    ../resources/clsevent.cpp \
    displaylogs.cpp

HEADERS  += roomba.h \
    controllingroomba.h \
    settingsroomba.h \
    information.h \
    RoombaConnect.h \
    ../resources/jsoncommand.h \
    ../resources/json.h \
    ../resources/clslog.h \
    ../resources/clsevent.h \
    displaylogs.h

FORMS    += roomba.ui \
    controllingroomba.ui \
    settingsroomba.ui \
    information.ui \
    displaylogs.ui
