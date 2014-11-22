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
    Units/formula.cpp \
    Units/unit.cpp \
    Units/Temperature/temperature.cpp \
    Charts/oilprices.cpp \
    Charts/rubleinterbank.cpp \
    AdditionalFiles/modal_window.cpp \
    Units/Temperature/farengtocel.cpp \
    Units/conversion.cpp \
    distanceandlength.cpp \
    weight.cpp \
    AdditionalFiles/settings.cpp
    modal_window.cpp \
    Units/Temperature/CelToDelisle.cpp \
    Units/Temperature/delisletocel.cpp \
    Units/length/feetstometer.cpp \
    Units/length/metertofeets.cpp \
    Units/Temperature/celtofareng.cpp \
    Units/Temperature/celtokelvin.cpp \
    Units/Temperature/celtonewton.cpp \
    Units/Temperature/celtorankline.cpp \
    Units/Temperature/kelvintocel.cpp \
    Units/Temperature/newtontocel.cpp \
    Units/Temperature/rankinetocel.cpp \
    Units/weight/GramsToOunces.cpp \
    Units/weight/KgToPounds.cpp \
    Units/weight/OuncesToGrams.cpp \
    Units/weight/PoundsToKg.cpp \
    Units/length/InchToSm.cpp \
    Units/length/KmToMiles.cpp \
    Units/length/MetrToYard.cpp \
    Units/length/MilesToKm.cpp \
    Units/length/SmToInch.cpp \
    Units/length/YardToMetr.cpp \
    Units/Temperature/ReaumurToCel.cpp \
    Units/Temperature/RomerToCel.cpp \
    Units/Temperature/CelToReaumur.cpp \
    Units/Temperature/CelToRomer.cpp \
    Units/length/FurToMetr.cpp \
    Units/length/FutToRod.cpp \
    Units/length/LeaToMetr.cpp \
    Units/length/LinkToMetr.cpp \
    Units/length/MetrToFur.cpp \
    Units/length/RodToFut.cpp \
    Units/length/MetrToLea.cpp \
    Units/length/MetrToLink.cpp


HEADERS  += mainwindow.h \
    Units/formula.h \
    Units/unit.h \

    Units/Temperature/temperature.h \

    modal_window.h \
    Charts/oilprices.h \
    Charts/rubleinterbank.h \
    AdditionalFiles/modal_window.h \
    Units/Temperature/farengtocel.h \
    Units/conversion.h \
    distanceandlength.h \
    weight.h \
    AdditionalFiles/settings.h

    modal_window.h \
    Units/Temperature/celtodelisle.h \
    Units/Temperature/celtokelvin.h \
    Units/Temperature/celtonewton.h \
    Units/Temperature/delisletocel.h \
    Units/Temperature/celtorankline.h \
    Units/Temperature/kelvintocel.h \
    Units/Temperature/newtontocel.h \
    Units/Temperature/rankinetocel.h \
    Units/Temperature/celtofareng.h \
    Units/length/feetstometer.h \
    Units/length/metertofeets.h \
    Units/weight/GramsToOunces.h \
    Units/weight/KgToPounds.h \
    Units/weight/OuncesToGrams.h \
    Units/weight/PoundsToKg.h \
    Units/length/InchToSm.h \
    Units/length/KmToMiles.h \
    Units/length/MetrToYard.h \
    Units/length/MilesToKm.h \
    Units/length/SmToInch.h \
    Units/length/YardToMetr.h \
    Units/Temperature/ReaumurToCel.h \
    Units/Temperature/CelToRomer.h \
    Units/Temperature/CelToReaumur.h \
    Units/length/FurToMetr.h \
    Units/length/FutToRod.h \
    Units/length/LeaToMetr.h \
    Units/length/LinkToMetr.h \
    Units/length/MetrToFur.h \
    Units/length/RodToFut.h \
    Units/length/MetrToLea.h \
    Units/length/MetrToLink.h \
    Units/Temperature/RomerToCel.h



CONFIG   += c++11

FORMS += \
    mainwindow.ui \
    Units/Temperature/temperature.ui \
    Charts/oilprices.ui \
    Charts/rubleinterbank.ui \
    AdditionalFiles/modal_window.ui \
    distanceandlength.ui \
    weight.ui


win32:RC_FILE = IcoConvert.rc

RESOURCES += \
    Img.qrc
