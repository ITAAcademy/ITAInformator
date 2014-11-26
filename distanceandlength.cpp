#include "distanceandlength.h"
#include "ui_distanceandlength.h"

// Begin(List_Opened_Windows)
#include "AdditionalFiles/appsettings.h"

static const QString windowName = "Distance and Length";
// End

DistanceAndLength::DistanceAndLength(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DistanceAndLength)
{
    ui->setupUi(this);
    ui->comboBox_Distanceandlenght->addItem("Meter");
    ui->comboBox_Distanceandlenght->addItem("Km");

    ui->comboBox_Distanceandlenght_2->addItem("Meter");
    ui->comboBox_Distanceandlenght_2->addItem("Km");
}

DistanceAndLength::~DistanceAndLength()
{
    delete ui;
}
// Begin(List_Opened_Windows)
void DistanceAndLength::closeEvent(QCloseEvent *)
{
    appActiveWindows &ref = appActiveWindows::getInstance();
    ref.removeActiveWindow(windowName);
}
void DistanceAndLength::showEvent(QShowEvent *)
{
    appActiveWindows &ref = appActiveWindows::getInstance();
    ref.addActiveWindowName(windowName);
}
// End
