#-------------------------------------------------
#
# Project created by QtCreator 2014-10-25T20:29:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ITAinformator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    conversion.cpp \
    Units/formula.cpp \
    Units/unit.cpp \
    settings.cpp

HEADERS  += mainwindow.h \
    conversion.h \
    Units/formula.h \
    Units/unit.h \
    settings.h


CONFIG   += c++11

FORMS += \
    mainwindow.ui \
    settings.ui

win32:RC_FILE = IcoConvert.rc
