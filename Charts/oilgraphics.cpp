#include "oilgraphics.h"

static const QString windowName = "Oil Graphics";

QString myURLOilgraphics = "<div id=\"oi1195543\" style=\"background:; width:210px; height:125; border: 1x solid #808080; color:#84057A; text-decoration:none; text-align:left; top; padding-left: 3px; overflow: hidden; font-style:normal; font-variant:normal; font-weight:bold; font-size:9px; font-family:Verdana, sans-serif;\"><a href=\"http://www.forexpf.ru/chart/brent/\" title=\"Нефть brent\" target=\"_blank\" style=\"color:#808080;text-decoration:none; \">Нефть brent</a></div><script type=\"text/javascript\" charset=\"cp1251\" src=\"http://informers.forexpf.ru/php/graphics.php?sym=CL_Brent&vsz=120&hsz=200&fxid=oi1195543&sz=60&tic=0&typ=0\"></script>";


OilGraphics::OilGraphics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OilGraphics)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    //QPixmap pixmap_OilGraphics(":/imagin/no-internet.png");
    //ui->label_img->setPixmap(pixmap_OilGraphics);

    setWindowTitle(tr("Oil Graphics"));

    this->setFixedSize(235,130);
    this->setGeometry(QRect(83,355,235,130));
    QWebView *inform_view = new QWebView(this);
    inform_view->setHtml(myURLOilgraphics);
    inform_view->show();
}

OilGraphics::~OilGraphics()
{
    delete ui;
}

void OilGraphics::closeEvent(QCloseEvent *)
{
    appActiveWindows &ref = appActiveWindows::getInstance();
    ref.removeActiveWindow(windowName);
}
void OilGraphics::showEvent(QShowEvent *)
{
    appActiveWindows &ref = appActiveWindows::getInstance();
    ref.addActiveWindowName(windowName);
}
