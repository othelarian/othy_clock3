#-------------------------------------------------
#
# Project created by QtCreator 2016-11-18T14:32:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = othy_clock
TEMPLATE = app


SOURCES += main.cpp\
        othyclock.cpp \
    othysettings.cpp \
    othycolorbutton.cpp \
    othykeeper.cpp

HEADERS  += othyclock.h \
    othysettings.h \
    othycolorbutton.h \
    othykeeper.h

CONFIG += mobility console
MOBILITY = 

