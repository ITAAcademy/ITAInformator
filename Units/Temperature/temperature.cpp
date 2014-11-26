#include "temperature.h"
#include "ui_temperature.h"
#include <QLineEdit>
#include <QTextBrowser>
#include <QPushButton>

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

//----------Begin(Font_settings)
//void Temperature::setTemperatureFont(QFont &font)
//{
//    ui->l_temperature->setFont(font);
//}
//----------End



void Temperature::on_pushButton_Temperature_clicked()
{



}

