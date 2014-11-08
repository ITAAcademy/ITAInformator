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
