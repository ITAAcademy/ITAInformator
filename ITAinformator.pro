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
    Units/formula.cpp \
    Units/unit.cpp \
    Units/Temperature/temperature.cpp \
    Units/feetstometer.cpp \
    Charts/oilprices.cpp \
    Charts/rubleinterbank.cpp \
    AdditionalFiles/modal_window.cpp \
    Units/Temperature/farengtocel.cpp \
    Units/conversion.cpp


HEADERS  += mainwindow.h \
    Units/formula.h \
    Units/unit.h \
    Units/Temperature/temperature.h \
    Units/feetstometer.h \
    modal_window.h \
    Charts/oilprices.h \
    Charts/rubleinterbank.h \
    AdditionalFiles/modal_window.h \
    Units/Temperature/farengtocel.h \
    Units/conversion.h


CONFIG   += c++11

FORMS += \
    mainwindow.ui \
    Units/Temperature/temperature.ui \
    Charts/oilprices.ui \
    Charts/rubleinterbank.ui \
    AdditionalFiles/modal_window.ui


win32:RC_FILE = IcoConvert.rc
