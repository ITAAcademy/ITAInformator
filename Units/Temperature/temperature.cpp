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
