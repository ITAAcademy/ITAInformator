#include "modal_window.h"
#include "ui_modal_window.h"

modal_window::modal_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modal_window)
{
    ui->setupUi(this);
}

modal_window::~modal_window()
{
    delete ui;
}
