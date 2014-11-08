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
    Units/feetstometer.cpp \
    modal_window.cpp \
    oilprices.cpp \
    rubleinterbank.cpp

HEADERS  += mainwindow.h \
    conversion.h \
    Units/formula.h \
    Units/unit.h \
    Units/feetstometer.h \
    modal_window.h \
    oilprices.h \
    rubleinterbank.h


CONFIG   += c++11

FORMS += \
    mainwindow.ui \
    modal_window.ui \
    oilprices.ui \
    rubleinterbank.ui

win32:RC_FILE = IcoConvert.rc
