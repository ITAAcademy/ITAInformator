#include "temperature.h"
#include "ui_temperature.h"
#include <QLineEdit>
#include <fstream>
#include <QString>

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




void Temperature::on_lineEdit_Temperature_textChanged(const QString &arg1)
{
    double Farengate = ui->lineEdit_Temperature->text().toDouble();
    ui->lineEdit_Temperature_2->setText(QString::number(Farengate * 1.8 + 32));
}

void Temperature::on_lineEdit_Temperature_2_textChanged(const QString &arg1)
{
    double Celsius = ui->lineEdit_Temperature_2->text().toDouble();
    ui->lineEdit_Temperature->setText(QString::number((Celsius - 32) / 1.8 ));
}

void Temperature::on_lineEdit_Temperature_3_textChanged(const QString &arg1)
{
    double Celsius = ui->lineEdit_Temperature_3->text().toDouble();
    ui->lineEdit_Temperature_4->setText(QString::number(Celsius+273));
}

void Temperature::on_lineEdit_Temperature_4_textChanged(const QString &arg1)
{
    double Kelvin = ui->lineEdit_Temperature_4->text().toDouble();
    ui->lineEdit_Temperature_3->setText(QString::number(Kelvin-273));
}
