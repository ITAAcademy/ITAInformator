#-------------------------------------------------
#
# Project created by QtCreator 2014-10-25T20:29:46
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += webkit
QT       += webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ITAinformator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Charts/oilprices.cpp \
    Charts/rubleinterbank.cpp \
    AdditionalFiles/modal_window.cpp \
    AdditionalFiles/settings.cpp \
    AdditionalFiles/listopenedwindows.cpp \
    AdditionalFiles/appsettings.cpp \
    conv_tools.cpp \
    distanceandlength.cpp \
    weight.cpp \
    Units/Temperature/temperature.cpp


HEADERS  += mainwindow.h \
    modal_window.h \
    Charts/oilprices.h \
    Charts/rubleinterbank.h \
    AdditionalFiles/modal_window.h \
    AdditionalFiles/settings.h \
    AdditionalFiles/listopenedwindows.h \
    AdditionalFiles/appsettings.h \
    conv_tools.h \
    distanceandlength.h \
    weight.h \
    Units/Temperature/temperature.h


CONFIG   += c++11

FORMS += \
    mainwindow.ui \
    Charts/oilprices.ui \
    Charts/rubleinterbank.ui \
    AdditionalFiles/modal_window.ui \
    AdditionalFiles/listopenedwindows.ui \
    distanceandlength.ui \
    weight.ui \
    Units/Temperature/temperature.ui

TRANSLATIONS += \
    ln_ua.ts \
    ln_pl.ts


win32:RC_FILE = IcoConvert.rc

RESOURCES += \
    Img.qrc

OTHER_FILES += \
    ln_pl.ts \
    ln_ua.ts \
    qt_uk.ts \
    qt_pl.ts

