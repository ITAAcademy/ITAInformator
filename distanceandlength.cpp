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
    ui->comboBoxDistance->addItem("Mm to Cm");
    ui->comboBoxDistance->addItem("Cm to M");
    ui->comboBoxDistance->addItem("M to Km");
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

void DistanceAndLength::on_lineEdit_D_Left_textChanged(const QString)
{
    if(ui->comboBoxDistance->currentText() == "Mm to Cm")
        {
        double Mm = ui->lineEdit_D_Left->text().toDouble();
        ui->lineEdit_D_down->setText(QString::number(Mm /10 ));;
        }
    if(ui->comboBoxDistance->currentText() == "Cm to M")
        {
        double Cm = ui->lineEdit_D_Left->text().toDouble();
        ui->lineEdit_D_down->setText(QString::number(Cm /100 ));;
        }
    if(ui->comboBoxDistance->currentText() == "M to Km")
        {
        double M = ui->lineEdit_D_Left->text().toDouble();
        ui->lineEdit_D_down->setText(QString::number(M /1000 ));;
        }
}

void DistanceAndLength::on_lineEdit_D_right_textChanged(const QString)
{
    if(ui->comboBoxDistance->currentText() == "Mm to Cm")
        {
        double Cm = ui->lineEdit_D_right->text().toDouble();
        ui->lineEdit_D_down->setText(QString::number(Cm * 10));;
        }
    if(ui->comboBoxDistance->currentText() == "Cm to M")
        {
        double M = ui->lineEdit_D_right->text().toDouble();
        ui->lineEdit_D_down->setText(QString::number(M * 100 ));;
        }
    if(ui->comboBoxDistance->currentText() == "M to Km")
        {
        double Km = ui->lineEdit_D_right->text().toDouble();
        ui->lineEdit_D_down->setText(QString::number(Km *1000 ));;
        }
}

void DistanceAndLength::on_comboBoxDistance_activated(const QString )
{
    if(ui->comboBoxDistance->currentText() == "Mm to Cm")
        {
        ui->label_Left->setText("Millimetr");
        ui->label_Right->setText("Centimeter");
        }
    if(ui->comboBoxDistance->currentText() == "Cm to M")
        {
        ui->label_Left->setText("Centimeter");
        ui->label_Right->setText("Meter");
        }
    if(ui->comboBoxDistance->currentText() == "M to Km")
        {
        ui->label_Left->setText("Meter");
        ui->label_Right->setText("Kilometer");
        }
}
