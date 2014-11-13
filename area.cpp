#include "area.h"
#include "ui_area.h"

Area::Area(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Area)
{
    ui->setupUi(this);
}

Area::~Area()
{
    delete ui;
}
