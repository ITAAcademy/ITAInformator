#include "modal_window.h"
#include "ui_modal_window.h"

modal_window::modal_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modal_window)
{
    ui->setupUi(this);
    setGeometry(QRect(520,250,200,600));
    ui->pushButton->setText(tr("Close"));
}

modal_window::~modal_window()
{
    delete ui;
}
