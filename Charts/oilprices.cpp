#include "oilprices.h"
#include "ui_oilprices.h"

OilPrices::OilPrices(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OilPrices)
{
    ui->setupUi(this);
}

OilPrices::~OilPrices()
{
    delete ui;
}
//Begin (comment out it before merge)
void OilPrices::setOilpricesFont(QFont& font) //create function for OilPrices
{
    ui->l_oilprices->setFont(font);          //access to OilPrices (setFont)
}
//End
