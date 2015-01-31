#include "oilprices.h"

static const QString windowName = "Oil Prices";

QString myURLOilPrices = "<div id=\"brent\" style=\"background:; width:186px; height:61px; border: 1x solid #808080; color:#84057A; text-decoration:none; text-align:left; top; overflow: hidden; font-style:normal; font-variant:normal; font-weight:normal; font-size:9px; font-family:Verdana, sans-serif;\"><a href=\"http://www.forexpf.ru/\" title=\"Цены на нефть\" target=\"_blank\" style=\"line-height:14px;color:#000000;text-decoration:none;padding-left: 50px;\">Цены на нефть</a><br><a href=\"http://www.forexpf.ru/chart/brent/\" title=\"Brent\" target=\"_blank\" style=\"line-height:15px;color:#000000;text-decoration:none;padding-left: 33px;\">Brent</a><a href=\"http://www.forexpf.ru/chart/lightsweet/\" title=\"Light Sweet\" target=\"_blank\" style=\"line-height:15px;color:#000000;text-decoration:none;padding-left: 63px;\">Light</a></div> <script src=\"http://www.forexpf.ru/_informer_/brent_.php\"></script>";

OilPrices::OilPrices(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OilPrices)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    setWindowTitle(tr("Oil Prices"));

    this->setFixedSize(205,75);
    this->setGeometry(QRect(113,240,205,75));
    QWebView *inform_view = new QWebView(this);
    inform_view->setHtml(myURLOilPrices);
    inform_view->show();

}

OilPrices::~OilPrices()
{
    delete ui;
}

void OilPrices::closeEvent(QCloseEvent *)
{
    appActiveWindows &ref = appActiveWindows::getInstance();
    ref.removeActiveWindow(windowName);
}
void OilPrices::showEvent(QShowEvent *)
{
    appActiveWindows &ref = appActiveWindows::getInstance();
    ref.addActiveWindowName(windowName);
}
