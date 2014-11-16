#include "weight.h"
#include "ui_weight.h"

Weight::Weight(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Weight)
{
    ui->setupUi(this);
}

Weight::~Weight()
{
    delete ui;
}
