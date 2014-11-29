#include "distanceandlength.h"
#include "mainwindow.h"
#include "qmessagebox.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "distanceandlength.h"

#include "weight.h"
#include "ui_mainwindow.h"
#include "qmainwindow.h"

#include "AdditionalFiles/modal_window.h"

#include "Charts/oilprices.h"
#include "Charts/rubleinterbank.h"

#include "Units/Temperature/temperature.h"
#include "AdditionalFiles/listopenedwindows.h"

#include <QWebFrame>
#include <qfile.h>
#include <fstream>
#include <QList>
#include <QString>

QString myURLOilPrices2 = "<div id=\"brent\" style=\"background:; width:186px; height:61px; border: 1x solid #808080; color:#84057A; text-decoration:none; text-align:left; top; overflow: hidden; font-style:normal; font-variant:normal; font-weight:normal; font-size:9px; font-family:Verdana, sans-serif;\"><a href=\"http://www.forexpf.ru/\" title=\"Цены на нефть\" target=\"_blank\" style=\"line-height:14px;color:#000000;text-decoration:none;padding-left: 50px;\">Цены на нефть</a><br><a href=\"http://www.forexpf.ru/chart/brent/\" title=\"Brent\" target=\"_blank\" style=\"line-height:15px;color:#000000;text-decoration:none;padding-left: 33px;\">Brent</a><a href=\"http://www.forexpf.ru/chart/lightsweet/\" title=\"Light Sweet\" target=\"_blank\" style=\"line-height:15px;color:#000000;text-decoration:none;padding-left: 63px;\">Light</a></div> <script src=\"http://www.forexpf.ru/_informer_/brent_.php\"></script>";
QString myURLrubleInterbank2 = "<table width=\"210\"border=\"1\" style=\"border-collapse: collapse; text-align:center; font-size:11px; color:#000000; \"><tr bgcolor=\"\"><td height=\"10\" valign=\"top\" colspan=\"3\"><style>A.forexpf_ { text-decoration: none;} A.forexpf_:visited {color: #000000;} </style><a href=\"http://www.forexpf.ru/\" title=\"Курсы валют\"target=\"_blank\" class=\"forexpf_\">Курсы валют</a></td></tr><tr bgcolor=\"F6EDDD\"><td></td><td>Покупка</td><td>Продажа</td></tr><tr bgcolor=\"\"><td><a href=\"http://www.forexpf.ru/chart/usdrub/\" title=\"Курс доллара\" target=\"_blank\" class=\"forexpf_\">USD/RUB</a></td><td id=\"usdrubbid\">0.00</td><td id=\"usdrubask\">0.00</td></tr><tr bgcolor=\"F6EDDD\"><td><a href=\"http://www.forexpf.ru/chart/eurrub/\"title=\"Курс Евро\"target=\"_blank\" class=\"forexpf_\">EUR/RUB</a></td><td id=\"eurrubbid\">0.00</td><td id=\"eurrubask\">0.00</td></tr><tr bgcolor=\"\"><td colspan=\"3\"id=\"euusrutm\">Данные на</td></tr></table><script type=\"text/javascript\" charset=\"utf-8\"src=\"http://informers.forexpf.ru/export/euusrub.js\"></script>";
QString myURLOilgraphics = "<div id=\"oi1195543\" style=\"background:; width:210px; height:180; border: 1x solid #808080; color:#84057A; text-decoration:none; text-align:left; top; padding-left: 3px; overflow: hidden; font-style:normal; font-variant:normal; font-weight:bold; font-size:9px; font-family:Verdana, sans-serif;\"><a href=\"http://www.forexpf.ru/chart/brent/\" title=\"Нефть brent\" target=\"_blank\" style=\"color:#808080;text-decoration:none; \">Нефть brent</a></div><script type=\"text/javascript\" charset=\"cp1251\" src=\"http://informers.forexpf.ru/php/graphics.php?sym=CL_Brent&vsz=120&hsz=200&fxid=oi1195543&sz=60&tic=0&typ=0\"></script>";
QString myURLDrahotsennemetals = "<div id=\"metals\" style=\"background:; width:186px; height:89px; border: 1x solid #808080; color:#84057A; text-decoration:none; text-align:left; top; overflow: hidden; font-style:normal; font-variant:normal; font-weight:normal; font-size:9px; font-family:Verdana, sans-serif;\"><a href=\"http://www.forexpf.ru/\" title=\"Драгоценные металлы\" target=\"_blank\" style=\"line-height:15px;color:#000000;text-decoration:none;padding-left: 35px;\">Драгоценные металлы</a><br><a href=\"http://www.forexpf.ru/chart/gold/\" title=\"Золото\" target=\"_blank\" style=\"line-height:15px;color:#000000;text-decoration:none;padding-left: 30px;\">Золото</a><br><a href=\"http://www.forexpf.ru/chart/palladium/\" title=\"Палладий\" target=\"_blank\" style=\"line-height:14px;color:#000000;text-decoration:none;padding-left: 23px;\">Палладий</a><br><a href=\"http://www.forexpf.ru/chart/platinum/\" title=\"Платина\" target=\"_blank\" style=\"line-height:15px;color:#000000;text-decoration:none;padding-left: 25px;\">Платина</a><br><a href=\"http://www.forexpf.ru/chart/silver/\" title=\"серебро\" target=\"_blank\" style=\"line-height:14px;color:#000000;text-decoration:none;padding-left: 26px;\">Серебро</a><br></div><script src=\"http://www.forexpf.ru/_informer_/metals_.php\"></script>";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    appDefaultLang = ("EN");
    ui->setupUi(this);
    this->setFixedSize(675,420);
    fillTaCB();
    fillLaCB();
    fillWaCB();
    fillIchCB();
    fillIaCB();

    if(mSettings.FirstRun())
    {
        QMessageBox::information(this, "First run", "This is the first run of the program. \n Thank you for your choice");
        setWindowTitle("Some name");
        setGeometry(QRect(355,100,760,558));
        setFont(QFont("Times",10,1,false));
        pLang = appDefaultLang;

        mSettings.setMainWindowRect(geometry());
        mSettings.setMainWindowTitle(windowTitle());
        mSettings.setMainWindowFont(font());
        mSettings.setAppLang(appDefaultLang);
    }
    else
    {
        setWindowTitle(mSettings.getMainWindowTitle());
        setGeometry(mSettings.getMainWindowRect());
        setFont(mSettings.getMainWindowFont());
        pLang = (mSettings.getAppLang());
    }

    ui->menuBar->setFont(QFont("Times",10,1,false));

    ui->webView->setHtml(myURLrubleInterbank2);

   // ui->menuBar->setNativeMenuBar(true);
}

MainWindow::~MainWindow()
{

    mSettings.setAppLang(pLang);
    mSettings.setMainWindowRect(geometry());
    mSettings.setMainWindowFont(font());
    delete ui;
}

void MainWindow::on_action_Widget_you_2_triggered()
{
    modal_window formmodal_window; // указываем новое имя класса
    formmodal_window.setModal(true); // говорим форме что она модальна
    formmodal_window.exec();
}

void MainWindow::on_actionTemperature_triggered()
{
    //formTemperature = new Temperature (this);
    //wow
    formTemperature.show();
}

void MainWindow::on_action_Oil_Charts_triggered()
{
    //formOilPrices = new OilPrices(this);
    formOilPrices.show();
}

void MainWindow::on_action_Currency_triggered()
{
    //formrubleInterbank = new rubleInterbank(this);
    formrubleInterbank.show();
}

void MainWindow::on_actionDistance_and_Length_triggered()
{
    formDistanceAndLength = new DistanceAndLength (this);
    formDistanceAndLength -> show();
}

void MainWindow::on_actionWeight_weight_triggered()
{
    formWeight = new Weight;
    formWeight -> show();
}

void MainWindow::on_action_Font_settings_triggered()
{
    bool ok;
    QFont font;
    font = QFontDialog::getFont(&ok, QFont( "Times", 10 ), this);
    if (!ok)
        return;
    setFont(font);
}

// Begin(List_Opened_Windows)
void MainWindow::on_actionList_opened_windows_triggered()
{
    formListOpenedWindows = new ListOpenedWindows (this);
    formListOpenedWindows->show();
}
// End
void MainWindow::on_action_Default_settings_triggered()
{
    setWindowTitle("Some name");
    setGeometry(QRect(355,100,760,558));
    setFont(QFont("Times",10,1,false));
    pLang = appDefaultLang;
}

void MainWindow::fillTaCB()
{
    const QList<QString> &ref = mConvTool.TaCB();

    for(int i = 0; i < ref.size(); ++i)
        ui->TaCB->addItem(ref.at(i));
}

void MainWindow::fillLaCB()
{
    const QList<QString> &ref = mConvTool.LaCB();

    for(int i = 0; i < ref.size(); ++i)
        ui->LaCB->addItem(ref.at(i));
}

void MainWindow::fillWaCB()
{
    const QList<QString> &ref = mConvTool.WaCB();

    for(int i = 0; i < ref.size(); ++i)
        ui->WaCB->addItem(ref.at(i));
}

void MainWindow::fillIchCB()
{
    const QList<QString> &ref = mConvTool.IchCB();

    for(int i = 0; i < ref.size(); ++i)
        ui->IchCB->addItem(ref.at(i));
}

void MainWindow::fillIaCB()
{
    const QList<QString> &ref = mConvTool.IaCB();

    for(int i = 0; i < ref.size(); ++i)
        ui->IaCB->addItem(ref.at(i));
}



void MainWindow::on_webView_loadFinished(bool )
{
    QVariant var;
    var = ui->webView->page()->currentFrame()->evaluateJavaScript("document.getElementById('usdrubbid').innerHTML");

    mCoofRubToUsd = var.toDouble();
}

void MainWindow::on_LeftITE_textChanged(const QString )
{
    double rub = ui->LeftITE->text().toDouble();
    ui->RightITE->setText(QString::number(rub / mCoofRubToUsd));

}

void MainWindow::on_RightITE_textChanged(const QString )
{
    double usd = ui->RightITE->text().toDouble();
    ui->LeftITE->setText(QString::number(usd * mCoofRubToUsd));
}

