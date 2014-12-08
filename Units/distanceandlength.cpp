#include "Units/distanceandlength.h"

static const QString windowName = "Distance and Length";

DistanceAndLength::DistanceAndLength(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DistanceAndLength)
{
    ui->setupUi(this);
    this->setFixedSize(375,150);

    ui->comboBoxDistance->addItem(tr("mm to cm"));
    ui->comboBoxDistance->addItem(tr("cm to m"));
    ui->comboBoxDistance->addItem(tr("m to km"));
}

DistanceAndLength::~DistanceAndLength()
{
    delete ui;
}

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

void DistanceAndLength::on_lineEdit_D_Left_textChanged(const QString)
{  if(ui->lineEdit_D_Left->hasFocus())
    {
    if(ui->comboBoxDistance->currentText() == "mm to cm")
        {
        double Mm = ui->lineEdit_D_Left->text().toDouble();
        double Cm = Mm;
        ui->lineEdit_D_right->setText(QString::number(Cm /10 ));;
        }
    if(ui->comboBoxDistance->currentText() == "cm to m")
        {
        double Cm = ui->lineEdit_D_Left->text().toDouble();
        double M = Cm;
        ui->lineEdit_D_right->setText(QString::number(M /100 ));;
        }
    if(ui->comboBoxDistance->currentText() == "m to km")
        {
        double M = ui->lineEdit_D_Left->text().toDouble();
        double Km = M;
        ui->lineEdit_D_right->setText(QString::number(Km /1000 ));;
        }
    }
}

void DistanceAndLength::on_lineEdit_D_right_textChanged(const QString)
{  if(ui->lineEdit_D_right->hasFocus())
    {
    if(ui->comboBoxDistance->currentText() == "mm to cm")
        {
        double Cm = ui->lineEdit_D_right->text().toDouble();
        double Mm = Cm;
        ui->lineEdit_D_Left->setText(QString::number(Mm * 10));;
        }
    if(ui->comboBoxDistance->currentText() == "cm to m")
        {
        double M = ui->lineEdit_D_right->text().toDouble();
        double Cm = M;
        ui->lineEdit_D_Left->setText(QString::number(Cm * 100 ));;
        }
    if(ui->comboBoxDistance->currentText() == "m to km")
        {
        double Km = ui->lineEdit_D_right->text().toDouble();
        double M = Km;
        ui->lineEdit_D_Left->setText(QString::number(M *1000 ));;
        }
    }
}

void DistanceAndLength::on_comboBoxDistance_activated(const QString )
{
    if(ui->comboBoxDistance->currentText() == "mm to cm")
        {
        ui->lineEdit_D_Left->clear();
        ui->lineEdit_D_right->clear();
        ui->label_Left->setText("Millimetr");
        ui->label_Right->setText("Centimeter");
        }
    if(ui->comboBoxDistance->currentText() == "cm to m")
        {
        ui->lineEdit_D_Left->clear();
        ui->lineEdit_D_right->clear();
        ui->label_Left->setText("Centimeter");
        ui->label_Right->setText("Meter");
        }
    if(ui->comboBoxDistance->currentText() == "m to km")
        {
        ui->lineEdit_D_Left->clear();
        ui->lineEdit_D_right->clear();
        ui->label_Left->setText("Meter");
        ui->label_Right->setText("Kilometer");
        }
}
