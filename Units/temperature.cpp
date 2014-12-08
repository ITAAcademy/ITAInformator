#include "Units/temperature.h"

static const QString windowName = "Temperature";

Temperature::Temperature(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Temperature)
{
    ui->setupUi(this);
    this->setFixedSize(375,150);

    ui->comboBoxTemperature->addItem("f to c");
    ui->comboBoxTemperature->addItem("k to c");
    ui->comboBoxTemperature->addItem("k to f");
}

Temperature::~Temperature()
{
    delete ui;
}
// Begin(List_Opened_Windows)
void Temperature::closeEvent(QCloseEvent *)
{
    appActiveWindows &ref = appActiveWindows::getInstance();
    ref.removeActiveWindow(windowName);
}
void Temperature::showEvent(QShowEvent *)
{
    appActiveWindows &ref = appActiveWindows::getInstance();
    ref.addActiveWindowName(windowName);
}

void Temperature::on_lineEdit_T_Left_textChanged(const QString)
{
   if(ui->lineEdit_T_Left->hasFocus())
   {
    if(ui->comboBoxTemperature->currentText() == "f to c")
        {
        double F = ui->lineEdit_T_Left->text().toDouble();
        double C = F;
        ui->lineEdit_T_right->setText(QString::number((C - 32)*5/9));;
        }
    if(ui->comboBoxTemperature->currentText() == "k to c")
        {
        double K = ui->lineEdit_T_Left->text().toDouble();
        double C = K;
        ui->lineEdit_T_right->setText(QString::number(C - 273.15 ));;
        }
    if(ui->comboBoxTemperature->currentText() == "k to f")
        {
        double K = ui->lineEdit_T_Left->text().toDouble();
        double F = K;
        ui->lineEdit_T_right->setText(QString::number(F *9/5-459.67 ));;
        }
    }
}

void Temperature::on_lineEdit_T_right_textChanged(const QString)
{
   if(ui->lineEdit_T_right->hasFocus())
   {
    if(ui->comboBoxTemperature->currentText() == "f to c")
        {
        double C = ui->lineEdit_T_right->text().toDouble();
        double F = C;
        ui->lineEdit_T_Left->setText(QString::number((F *9/5)+32 ));
        }
    if(ui->comboBoxTemperature->currentText() == "k to c")
        {
        double C = ui->lineEdit_T_right->text().toDouble();
        double K = C;
        ui->lineEdit_T_Left->setText(QString::number(K + 273.15 ));
        }
    if(ui->comboBoxTemperature->currentText() == "k to f")
        {
        double F = ui->lineEdit_T_right->text().toDouble();
        double K = F;
        ui->lineEdit_T_Left->setText(QString::number((K +459.67)*5/9 ));
        }
   }
}

void Temperature::on_comboBoxTemperature_activated(const QString )
{
    if(ui->comboBoxTemperature->currentText() == "f to c")
        {
        ui->lineEdit_T_Left->clear();
        ui->lineEdit_T_right->clear();
        ui->label_Left->setText("Fahrenheit");
        ui->label_Right->setText("Celsius");
        }
    if(ui->comboBoxTemperature->currentText() == "k to c")
        {
        ui->lineEdit_T_Left->clear();
        ui->lineEdit_T_right->clear();
        ui->label_Left->setText("Kelvin");
        ui->label_Right->setText("Celsius");
        }
    if(ui->comboBoxTemperature->currentText() == "k to f")
        {
        ui->lineEdit_T_Left->clear();
        ui->lineEdit_T_right->clear();
        ui->label_Left->setText("Kelvin");
        ui->label_Right->setText("Fahrenheit");
        }
}
