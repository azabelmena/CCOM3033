#-------------------------------------------------
#
# Project created by QtCreator 2014-05-24T12:21:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tessellations
TEMPLATE = app


SOURCES += main.cpp\
    tessellation.cpp \
    line.cpp \
    drawingWindow.cpp

HEADERS  += \
    tessellation.h \
    line.h \
    drawingWindow.h

FORMS    += \
    drawingWindow.ui
