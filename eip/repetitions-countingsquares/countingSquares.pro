#-------------------------------------------------
#
# Project created by QtCreator 2014-09-07T18:12:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = countingSquares
TEMPLATE = app

CONFIG += c++11
SOURCES += main.cpp \
    maingamewindow.cpp \
    genericscrollingobject.cpp


RESOURCES += \
    countingSquares.qrc


HEADERS += \
    maingamewindow.h \
    genericscrollingobject.h

INCLUDEPATH += /usr/local/Cellar/box2d/2.3.0/include


DEFINES += QT_NO_DEBUG_OUTPUT
