#-------------------------------------------------
#
# Project created by QtCreator 2016-05-07T12:27:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bisection
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    function.cpp \
    coefficient.cpp

HEADERS  += mainwindow.h \
    function.h \
    coefficient.h

FORMS    += mainwindow.ui
