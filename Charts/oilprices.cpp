#include "oilprices.h"
#include "ui_oilprices.h"
#include "QLabel"
// Begin(List_Opened_Windows)
#include "AdditionalFiles/appsettings.h"

static const QString windowName = "Oil Prices";
// End

QString myURLOilPrices = "<div id=\"brent\" style=\"background:; width:186px; height:61px; border: 1x solid #808080; color:#84057A; text-decoration:none; text-align:left; top; overflow: hidden; font-style:normal; font-variant:normal; font-weight:normal; font-size:9px; font-family:Verdana, sans-serif;\"><a href=\"http://www.forexpf.ru/\" title=\"Цены на нефть\" target=\"_blank\" style=\"line-height:14px;color:#000000;text-decoration:none;padding-left: 50px;\">Цены на нефть</a><br><a href=\"http://www.forexpf.ru/chart/brent/\" title=\"Brent\" target=\"_blank\" style=\"line-height:15px;color:#000000;text-decoration:none;padding-left: 33px;\">Brent</a><a href=\"http://www.forexpf.ru/chart/lightsweet/\" title=\"Light Sweet\" target=\"_blank\" style=\"line-height:15px;color:#000000;text-decoration:none;padding-left: 63px;\">Light</a></div> <script src=\"http://www.forexpf.ru/_informer_/brent_.php\"></script>";

OilPrices::OilPrices(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OilPrices)
{
    ui->setupUi(this);
    QPixmap pixmap_OilPrices(":/imagin/no-internet.png");
    ui->label_img->setPixmap(pixmap_OilPrices);
    this->resize(200,80);
    QWebView *inform_view = new QWebView(this);
    inform_view->resize(200,80);
    inform_view->setHtml(myURLOilPrices);
    inform_view->show();

}

OilPrices::~OilPrices()
{
    delete ui;
}
// Begin(List_Opened_Windows)
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
// End
//----------Begin(Font_settings)
//void OilPrices::setOilpricesFont(QFont& font)
//{
//    ui->l_oilprices->setFont(font);
//}
//----------End
