#include "volumecapacity.h"
#include "ui_volumecapacity.h"

VolumeCapacity::VolumeCapacity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VolumeCapacity)
{
    ui->setupUi(this);
}

VolumeCapacity::~VolumeCapacity()
{
    delete ui;
}
