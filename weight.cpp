#include "weight.h"
#include "ui_weight.h"

Weight::Weight(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Weight)
{
    ui->setupUi(this);

    ui->comboBox_Weight->addItem("Gram");
    ui->comboBox_Weight->addItem("Kg");

    ui->comboBox_Weight_2->addItem("Gram");
    ui->comboBox_Weight_2->addItem("Kg");
}

Weight::~Weight()
{
    delete ui;
}
