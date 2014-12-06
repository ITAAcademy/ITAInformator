#include "temperature.h"
#include "ui_temperature.h"

// Begin(List_Opened_Windows)
#include "AdditionalFiles/appsettings.h"

static const QString windowName = "Temperature";
//  End

Temperature::Temperature(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Temperature)
{
    ui->setupUi(this);
    this->setFixedSize(375,150);

    ui->comboBoxTemperature->addItem("F to C");
    ui->comboBoxTemperature->addItem("K to C");
    ui->comboBoxTemperature->addItem("K to F");
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
// End

//----------Begin(Font_settings)
//void Temperature::setTemperatureFont(QFont &font)
//{
//    ui->l_temperature->setFont(font);
//}
//----------End

void Temperature::on_lineEdit_T_Left_textChanged(const QString)
{
   if(ui->lineEdit_T_Left->hasFocus())
   {
    if(ui->comboBoxTemperature->currentText() == "F to C")
        {
        double F = ui->lineEdit_T_Left->text().toDouble();
        double C = F;
        ui->lineEdit_T_right->setText(QString::number((C - 32)*5/9));;
        }
    if(ui->comboBoxTemperature->currentText() == "K to C")
        {
        double K = ui->lineEdit_T_Left->text().toDouble();
        double C = K;
        ui->lineEdit_T_right->setText(QString::number(C - 273.15 ));;
        }
    if(ui->comboBoxTemperature->currentText() == "K to F")
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
    if(ui->comboBoxTemperature->currentText() == "F to C")
        {
        double C = ui->lineEdit_T_right->text().toDouble();
        double F = C;
        ui->lineEdit_T_Left->setText(QString::number((F *9/5)+32 ));
        }
    if(ui->comboBoxTemperature->currentText() == "K to C")
        {
        double C = ui->lineEdit_T_right->text().toDouble();
        double K = C;
        ui->lineEdit_T_Left->setText(QString::number(K + 273.15 ));
        }
    if(ui->comboBoxTemperature->currentText() == "K to F")
        {
        double F = ui->lineEdit_T_right->text().toDouble();
        double K = F;
        ui->lineEdit_T_Left->setText(QString::number((K +459.67)*5/9 ));
        }
   }
}


void Temperature::on_comboBoxTemperature_activated(const QString )
{
    if(ui->comboBoxTemperature->currentText() == "F to C")
        {
        ui->lineEdit_T_Left->clear();
        ui->lineEdit_T_right->clear();
        ui->label_Left->setText("Fahrenheit");
        ui->label_Right->setText("Celsius");
        }
    if(ui->comboBoxTemperature->currentText() == "K to C")
        {
        ui->lineEdit_T_Left->clear();
        ui->lineEdit_T_right->clear();
        ui->label_Left->setText("Kelvin");
        ui->label_Right->setText("Celsius");
        }
    if(ui->comboBoxTemperature->currentText() == "K to F")
        {
        ui->lineEdit_T_Left->clear();
        ui->lineEdit_T_right->clear();
        ui->label_Left->setText("Kelvin");
        ui->label_Right->setText("Fahrenheit");
        }
}
