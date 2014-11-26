#include "temperature.h"
#include "ui_temperature.h"
#include <QLineEdit>
#include <QTextBrowser>
#include <QPushButton>

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

    ui->comboBox_Temperature->addItem("Cel");
    ui->comboBox_Temperature->addItem("Fare");

    ui->comboBox_Temperature_2->addItem("Cel");
    ui->comboBox_Temperature_2->addItem("Fare");

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



void Temperature::on_pushButton_Temperature_clicked()
{



}

