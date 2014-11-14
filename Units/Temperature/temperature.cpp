#include "temperature.h"
#include "ui_temperature.h"

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

//Begin (comment out it before merge)
void Temperature::setTemperatureFont(QFont &font)
{
    ui->l_temperature->setFont(font);          //access to Temperature (setFont)
}
//End
