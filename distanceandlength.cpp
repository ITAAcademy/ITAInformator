#include "distanceandlength.h"
#include "ui_distanceandlength.h"

DistanceAndLength::DistanceAndLength(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DistanceAndLength)
{
    ui->setupUi(this);
    ui->comboBox_Distanceandlenght->addItem("Meter");
    ui->comboBox_Distanceandlenght->addItem("Km");

    ui->comboBox_Distanceandlenght_2->addItem("Meter");
    ui->comboBox_Distanceandlenght_2->addItem("Km");
}

DistanceAndLength::~DistanceAndLength()
{
    delete ui;
}
