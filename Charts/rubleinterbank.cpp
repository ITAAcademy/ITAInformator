#include "rubleinterbank.h"


static const QString windowName = "ruble Interbank";

QString myURLrubleInterbank = "<table width=\"210\"border=\"1\" style=\"border-collapse: collapse; text-align:center; font-size:11px; color:#000000; \"><tr bgcolor=\"\"><td height=\"10\" valign=\"top\" colspan=\"3\"><style>A.forexpf_ { text-decoration: none;} A.forexpf_:visited {color: #000000;} </style><a href=\"http://www.forexpf.ru/\" title=\"Курсы валют\"target=\"_blank\" class=\"forexpf_\">Курсы валют</a></td></tr><tr bgcolor=\"F6EDDD\"><td></td><td>Покупка</td><td>Продажа</td></tr><tr bgcolor=\"\"><td><a href=\"http://www.forexpf.ru/chart/usdrub/\" title=\"Курс доллара\" target=\"_blank\" class=\"forexpf_\">USD/RUB</a></td><td id=\"usdrubbid\">0.00</td><td id=\"usdrubask\">0.00</td></tr><tr bgcolor=\"F6EDDD\"><td><a href=\"http://www.forexpf.ru/chart/eurrub/\"title=\"Курс Евро\"target=\"_blank\" class=\"forexpf_\">EUR/RUB</a></td><td id=\"eurrubbid\">0.00</td><td id=\"eurrubask\">0.00</td></tr><tr bgcolor=\"\"><td colspan=\"3\"id=\"euusrutm\">Данные на</td></tr></table><script type=\"text/javascript\" charset=\"utf-8\"src=\"http://informers.forexpf.ru/export/euusrub.js\"></script>";

rubleInterbank::rubleInterbank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rubleInterbank)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    QPixmap pixmap_ruble(":/imagin/no-internet.png");
    ui->label_pic->setPixmap(pixmap_ruble);

    this->resize(225,106);
    QWebView *inform_view = new QWebView(this);
    inform_view->resize(225,106);
    inform_view->setHtml(myURLrubleInterbank);
    inform_view->show();
}

rubleInterbank::~rubleInterbank()
{
    delete ui;
}

void rubleInterbank::closeEvent(QCloseEvent *)
{
    appActiveWindows &ref = appActiveWindows::getInstance();
    ref.removeActiveWindow(windowName);
}
void rubleInterbank::showEvent(QShowEvent *)
{
    appActiveWindows &ref = appActiveWindows::getInstance();
    ref.addActiveWindowName(windowName);
}
