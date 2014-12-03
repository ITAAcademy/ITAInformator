#include "modal_window.h"
#include "ui_modal_window.h"

modal_window::modal_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modal_window)
{
    ui->setupUi(this);
    setGeometry(QRect(520,250,200,600));
    QPixmap pixmap_0(":/imagin/pic.png");
    ui->label_pict_0->setPixmap(pixmap_0);

    QPixmap pixmap_1(":/imagin/konverter.png");
    ui->label_pict_1->setPixmap(pixmap_1);

    QPixmap pixmap_2(":/imagin/Converter-2014.png");
    ui->label_pict_2->setPixmap(pixmap_2);

}

modal_window::~modal_window()
{
    delete ui;
}
