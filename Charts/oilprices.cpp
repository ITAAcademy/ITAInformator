#include "oilprices.h"
#include "ui_oilprices.h"

OilPrices::OilPrices(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OilPrices)
{
    ui->setupUi(this);
    this->resize(200,80);
    QWebView *inform_view = new QWebView(this);
    inform_view->resize(200,80);
    inform_view->load(QUrl("http://cvant-dveri-vorota.ru/Informer_OilPrices.html"));
    inform_view->show();

}

OilPrices::~OilPrices()
{
    delete ui;
}
