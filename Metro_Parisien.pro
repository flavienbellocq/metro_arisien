#-------------------------------------------------
#
# Project created by QtCreator 2014-02-20T09:42:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Metro_Parisien
TEMPLATE = app


SOURCES += main.cpp\
        interface.cpp \
    station.cpp \
    ligne.cpp \
    trajetunit.cpp \
    reseauparis.cpp \
    dijkstra.cpp \
    estimdurees.cpp \
    ongletdetailtrajet.cpp

HEADERS  += interface.h \
    station.h \
    ligne.h \
    trajetunit.h \
    reseauparis.h \
    dijkstra.h \
    estimdurees.h \
    ongletdetailtrajet.h

FORMS    += interface.ui
