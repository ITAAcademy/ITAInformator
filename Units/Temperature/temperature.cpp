#include "temperature.h"
#include "ui_temperature.h"

// Begin(List_Opened_Windows)
#include "QLabel"
#include "AdditionalFiles/appsettings.h"

static const QString windowName = "Temperature";
// End

Temperature::Temperature(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Temperature)
{
    ui->setupUi(this);

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
    if(ui->comboBoxTemperature->currentText() == "F to C")
        {
        double Farengate = ui->lineEdit_T_Left->text().toDouble();
        ui->lineEdit_T_down->setText(QString::number((Farengate - 32)*5/9));;
        }
    if(ui->comboBoxTemperature->currentText() == "K to C")
        {
        double Kelvin = ui->lineEdit_T_Left->text().toDouble();
        ui->lineEdit_T_down->setText(QString::number(Kelvin - 273.15 ));;
        }
    if(ui->comboBoxTemperature->currentText() == "K to F")
        {
        double Kelvin = ui->lineEdit_T_Left->text().toDouble();
        ui->lineEdit_T_down->setText(QString::number(Kelvin *9/5-459.67 ));;
        }

}

void Temperature::on_lineEdit_T_right_textChanged(const QString)
{
    if(ui->comboBoxTemperature->currentText() == "F to C")
        {
        double Celsius = ui->lineEdit_T_right->text().toDouble();
        ui->lineEdit_T_down->setText(QString::number((Celsius *9/5)+32 ));
        }
    if(ui->comboBoxTemperature->currentText() == "K to C")
        {
        double Celsius = ui->lineEdit_T_right->text().toDouble();
        ui->lineEdit_T_down->setText(QString::number(Celsius + 273.15 ));
        }
    if(ui->comboBoxTemperature->currentText() == "K to F")
        {
        double Farengate = ui->lineEdit_T_right->text().toDouble();
        ui->lineEdit_T_down->setText(QString::number((Farengate +459.67)*5/9 ));
        }
}


void Temperature::on_comboBoxTemperature_activated(const QString )
{
    if(ui->comboBoxTemperature->currentText() == "F to C")
        {
        ui->label_Left->setText("Fahrenheit");
        ui->label_Right->setText("Celsius");
        }
    if(ui->comboBoxTemperature->currentText() == "K to C")
        {
        ui->label_Left->setText("Kelvin");
        ui->label_Right->setText("Celsius");
        }
    if(ui->comboBoxTemperature->currentText() == "K to F")
        {
        ui->label_Left->setText("Kelvin");
        ui->label_Right->setText("Fahrenheit");
        }
}
