#include "metals.h"

static const QString windowName = "Precious metals charts";

QString myURLDrahotsennemetals = "<div id=\"metals\" style=\"background:; width:186px; height:89px; border: 1x solid #808080; color:#84057A; text-decoration:none; text-align:left; top; overflow: hidden; font-style:normal; font-variant:normal; font-weight:normal; font-size:9px; font-family:Verdana, sans-serif;\"><a href=\"http://www.forexpf.ru/\" title=\"Драгоценные металлы\" target=\"_blank\" style=\"line-height:15px;color:#000000;text-decoration:none;padding-left: 35px;\">Драгоценные металлы</a><br><a href=\"http://www.forexpf.ru/chart/gold/\" title=\"Золото\" target=\"_blank\" style=\"line-height:15px;color:#000000;text-decoration:none;padding-left: 30px;\">Золото</a><br><a href=\"http://www.forexpf.ru/chart/palladium/\" title=\"Палладий\" target=\"_blank\" style=\"line-height:14px;color:#000000;text-decoration:none;padding-left: 23px;\">Палладий</a><br><a href=\"http://www.forexpf.ru/chart/platinum/\" title=\"Платина\" target=\"_blank\" style=\"line-height:15px;color:#000000;text-decoration:none;padding-left: 25px;\">Платина</a><br><a href=\"http://www.forexpf.ru/chart/silver/\" title=\"серебро\" target=\"_blank\" style=\"line-height:14px;color:#000000;text-decoration:none;padding-left: 26px;\">Серебро</a><br></div><script src=\"http://www.forexpf.ru/_informer_/metals_.php\"></script>";


Metals::Metals(QWidget *parent) :
	QDialog(parent),
    ui(new Ui::Metals)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    //QPixmap pixmap_Metals(":/imagin/no-internet.png");
    //ui->label_img->setPixmap(pixmap_Metals);

    this->setFixedSize(205,100);
    this->setGeometry(QRect(113,525,205,100));
    setWindowTitle(tr("Precious metals charts"));
    QWebView *inform_view = new QWebView(this);
    inform_view->setHtml(myURLDrahotsennemetals);
    inform_view->show();
}

Metals::~Metals()
{
    delete ui;
}

void Metals::closeEvent(QCloseEvent *)
{
    appActiveWindows &ref = appActiveWindows::getInstance();
    ref.removeActiveWindow(windowName);
}
void Metals::showEvent(QShowEvent *)
{
    appActiveWindows &ref = appActiveWindows::getInstance();
    ref.addActiveWindowName(windowName);
}
