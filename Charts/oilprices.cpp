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
//----------Begin(Font_settings)
//void OilPrices::setOilpricesFont(QFont& font)
//{
//    ui->l_oilprices->setFont(font);
//}
//----------End