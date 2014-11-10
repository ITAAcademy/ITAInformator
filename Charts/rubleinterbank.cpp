#include "rubleinterbank.h"
#include "ui_rubleinterbank.h"

rubleInterbank::rubleInterbank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rubleInterbank)
{
    ui->setupUi(this);
    this->resize(225,106);
    QWebView *inform_view = new QWebView(this);
    inform_view->resize(225,106);
    inform_view->load(QUrl("http://cvant-dveri-vorota.ru/Informer_RubleInterbankMarket.html"));
    inform_view->show();
}

rubleInterbank::~rubleInterbank()
{
    delete ui;
}
