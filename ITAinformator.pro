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
    Units/Temperature/temperature.cpp \
    settings.cpp \
    Units/feetstometer.cpp \
    modal_window.cpp \
    oilprices.cpp \
    rubleinterbank.cpp \
    farengtocel.cpp \
    Charts/oilprices.cpp \
    Charts/rubleinterbank.cpp \
    AdditionalFiles/modal_window.cpp \
    AdditionalFiles/settings.cpp \
    Units/Temperature/farengtocel.cpp \
    Units/conversion.cpp


HEADERS  += mainwindow.h \
    conversion.h \
    Units/formula.h \
    Units/unit.h \
    Units/Temperature/temperature.h \
    settings.h  \
    Units/feetstometer.h \
    modal_window.h \
    oilprices.h \
    rubleinterbank.h \
    farengtocel.h \
    Charts/oilprices.h \
    Charts/rubleinterbank.h \
    AdditionalFiles/modal_window.h \
    AdditionalFiles/settings.h \
    Units/Temperature/farengtocel.h \
    Units/conversion.h


CONFIG   += c++11

FORMS += \
    mainwindow.ui \
    settings.ui    \
    modal_window.ui \
    Units/Temperature/temperature.ui \
    oilprices.ui \
    rubleinterbank.ui \
    Charts/oilprices.ui \
    Charts/rubleinterbank.ui \
    AdditionalFiles/modal_window.ui \
    AdditionalFiles/settings.ui


win32:RC_FILE = IcoConvert.rc
