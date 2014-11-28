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

void DistanceAndLength::on_lineEdit_Distanceandlenght_textChanged(const QString &arg1)
{
    double Km = ui->lineEdit_Distanceandlenght->text().toDouble();
    ui->lineEdit_Distanceandlenght_2->setText(QString::number(Km * 1.8));
}

void DistanceAndLength::on_lineEdit_Distanceandlenght_2_textChanged(const QString &arg1)
{
    double Mile = ui->lineEdit_Distanceandlenght_2->text().toDouble();
    ui->lineEdit_Distanceandlenght->setText(QString::number(Mile / 1.8));
}

void DistanceAndLength::on_lineEdit_Distanceandlenght_3_textChanged(const QString &arg1)
{
    double Km = ui->lineEdit_Distanceandlenght_3->text().toDouble();
    ui->lineEdit_Distanceandlenght_4->setText(QString::number(Km * 1000000));
}

void DistanceAndLength::on_lineEdit_Distanceandlenght_4_textChanged(const QString &arg1)
{
    double mm = ui->lineEdit_Distanceandlenght_4->text().toDouble();
    ui->lineEdit_Distanceandlenght_3->setText(QString::number(mm / 1000000));
}
