#include "rubleinterbank.h"
#include "ui_rubleinterbank.h"

rubleInterbank::rubleInterbank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rubleInterbank)
{
    ui->setupUi(this);
}

rubleInterbank::~rubleInterbank()
{
    delete ui;
}

//Begin (comment out it before merge)
void rubleInterbank::setRubleInterbankFont(QFont &font)
{
    ui->l_rubleInterbank->setFont(font);          //access to RubleInterbank (setFont)
}
//End
