#include "distanceandlength.h"
#include "ui_distanceandlength.h"

DistanceAndLength::DistanceAndLength(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DistanceAndLength)
{
    ui->setupUi(this);
}

DistanceAndLength::~DistanceAndLength()
{
    delete ui;
}
