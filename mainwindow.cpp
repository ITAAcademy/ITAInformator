#include "qmessagebox.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qmainwindow.h"
#include "QDialogButtonBox"

#include "AdditionalFiles/modal_window.h"
#include "AdditionalFiles/listopenedwindows.h"

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
    translator = new QTranslator;
    qAppTranslator = new QTranslator;
    ui->setupUi(this);
    this->setFixedSize(675,420);

        ui->TaCB->addItem("F/C");
        ui->TaCB->addItem("K/C");
        ui->TaCB->addItem("K/F");

        ui->LaCB->addItem("mm/cm");
        ui->LaCB->addItem("cm/m");
        ui->LaCB->addItem("m/km");

        ui->WaCB->addItem("g/kg");
        ui->WaCB->addItem("kg/p");
        ui->WaCB->addItem("p/g");


        ui->IchCB->addItem(tr("Oil Charts"));
        ui->IchCB->addItem(tr("Rubel Info"));
        ui->IchCB->addItem(tr("Oil graphics"));
        ui->IchCB->addItem(tr("Precious metals"));

        ui->IaCB->addItem("Oil Charts");
        ui->IaCB->addItem("Rubel Info");

    if(mSettings.FirstRun())
    {
        QMessageBox::information(this, "First run", "This is the first run of the program. \n Thank you for your choice");
        setWindowTitle("Some name");
        setGeometry(QRect(355,100,760,558));
        setFont(QFont("Times",10,1,false));
        pLang = "en";

        mSettings.setMainWindowRect(geometry());
        mSettings.setMainWindowTitle(windowTitle());
        mSettings.setMainWindowFont(font());
        mSettings.setAppLang(pLang);
    }
    else
    {
        setWindowTitle(mSettings.getMainWindowTitle());
        setGeometry(mSettings.getMainWindowRect());
        pLang = (mSettings.getAppLang());
        appChangeLanguage();
        reTranslateUi();
    }

    ui->menuBar->setFont(QFont("Times",10,1,false));


   // ui->menuBar->setNativeMenuBar(true);

    connect(ui->actionEn, SIGNAL(triggered()), this, SLOT(chLangEn()));
    connect(ui->actionUa, SIGNAL(triggered()), this, SLOT(chLangUa()));
    connect(ui->actionPl, SIGNAL(triggered()), this, SLOT(chLangPl()));
    connect(ui->actionRu, SIGNAL(triggered()), this, SLOT(chLangRu()));
}

MainWindow::~MainWindow()
{

    mSettings.setAppLang(pLang);
    mSettings.setMainWindowRect(geometry());
    mSettings.setMainWindowFont(font());
    delete ui;
}

void MainWindow::appChangeLanguage()
{
    if(pLang == QString("en"))
    {
        chLangEn();
        return;
    }
    if(pLang == QString("ua"))
    {
        chLangUa();
        return;
    }
    if(pLang == QString("pl"))
    {
        chLangPl();
        return;
    }
    if(pLang == QString("ru"))
    {
        chLangRu();
        return;
    }
}

void MainWindow::on_action_About_triggered()
{
    modal_window formmodal_window; // Specifies the new name of the class
    formmodal_window.setModal(true); // say that it is modal form
    formmodal_window.exec();
}

void MainWindow::on_actionTemperature_triggered()
{
    formTemperature = new Temperature (this);
    formTemperature->show();
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
void MainWindow::on_action_List_opened_windows_triggered()
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
    pLang = "en";
    appChangeLanguage();
    reTranslateUi();
}



void MainWindow::chLangEn()
{
    qApp->removeTranslator(translator);
    qApp->removeTranslator(qAppTranslator);
    reTranslateUi();
    pLang = "en";
}

void MainWindow::chLangUa()
{
    translator->load("ln_ua");
    qAppTranslator->load("qt_uk");
    qApp->installTranslator(translator);
    qApp->installTranslator(qAppTranslator);
    reTranslateUi();
    pLang = "ua";
}

void MainWindow::chLangPl()
{
    translator->load("ln_pl");
    qAppTranslator->load("qt_pl");
    qApp->installTranslator(translator);
    qApp->installTranslator(qAppTranslator);
    reTranslateUi();
    pLang = "pl";
}

void MainWindow::chLangRu()
{
    translator->load("ln_ru");
    qAppTranslator->load("qt_ru");
    qApp->installTranslator(translator);
    qApp->installTranslator(qAppTranslator);
    reTranslateUi();
    pLang = "ru";
}

void MainWindow::reTranslateUi()
{
    setWindowTitle(tr("Some name"));
    ui->menuAbout->setTitle(tr("Help"));
        ui->action_About->setText(tr("&About"));
    ui->menuTools->setTitle(tr("Tools"));
        ui->menuLang->setTitle(tr("&Language"));
            ui->actionEn->setText(tr("En"));
            ui->actionUa->setText(tr("Ua"));
            ui->actionPl->setText(tr("Pl"));
            ui->actionRu->setText(tr("Ru"));
        ui->menuSettings->setTitle(tr("&Settings"));
            ui->action_Font_settings->setText(tr("&Font settings"));
            ui->action_Default_settings->setText(tr("&Default settings"));
    ui->menuProgram->setTitle(tr("Program"));
        ui->menuConversion->setTitle(tr("Conversion"));
            ui->actionTemperature->setText(tr("Temperature"));
            ui->actionDistance_and_Length->setText(tr("Distance and Length"));
            ui->actionWeight_weight->setText(tr("Weight"));
        ui->action_Oil_Charts->setText(tr("&Oil Charts"));
            formOilPrices.setWindowTitle(tr("Oil Charts"));
        ui->action_Currency->setText(tr("&Currency"));
            formrubleInterbank.setWindowTitle(tr("Ruble Interbank"));
        ui->action_List_opened_windows->setText(tr("List opened windows"));
        ui->actionExit->setText(tr("&Exit"));
    ui->Weight->setTitle(tr("Weight conversion"));
    ui->Lenght->setTitle(tr("Lenght conversion"));
    ui->Temperature->setTitle(tr("Temperature conversion"));
    ui->Informer->setTitle(tr("Informer"));
    ui->Informer_block->setTitle(tr("Informer conversion"));
}
void MainWindow::on_actionExit_triggered()
{
    QApplication::closeAllWindows();
}
void MainWindow::on_lineEdit_TempLeft_textChanged(const QString)
{
    if(ui->lineEdit_TempLeft->hasFocus())
    {
    if(ui->TaCB->currentText() == "F/C")
        {

        double Farengate = ui->lineEdit_TempLeft->text().toDouble();
        ui->lineEdit_TempRight->setText(QString::number((Farengate - 32)*5/9));;
        }
    if(ui->TaCB->currentText() == "K/C")
        {
        double Kelvin = ui->lineEdit_TempLeft->text().toDouble();
        ui->lineEdit_TempRight->setText(QString::number(Kelvin - 273.15 ));;
        }
    if(ui->TaCB->currentText() == "K/F")
        {
        double Kelvin = ui->lineEdit_TempLeft->text().toDouble();
        ui->lineEdit_TempRight->setText(QString::number(Kelvin *9/5-459.67 ));;
        }
    }
}

void MainWindow::on_lineEdit_TempRight_textChanged(const QString)
{
   if(ui->lineEdit_TempRight->hasFocus())
   {
    if(ui->TaCB->currentText() == "F/C")
        {
        double Celsius = ui->lineEdit_TempRight->text().toDouble();
        ui->lineEdit_TempLeft->setText(QString::number((Celsius *9/5)+32 ));
        }
    if(ui->TaCB->currentText() == "K/C")
        {
        double Celsius = ui->lineEdit_TempRight->text().toDouble();
        ui->lineEdit_TempLeft->setText(QString::number(Celsius + 273.15 ));
        }
    if(ui->TaCB->currentText() == "K/F")
        {
        double Farengate = ui->lineEdit_TempRight->text().toDouble();
        ui->lineEdit_TempLeft->setText(QString::number((Farengate +459.67)*5/9 ));
        }
   }

}



void MainWindow::on_lineEdit_LenghtLeft_textChanged(const QString)
{  if(ui->lineEdit_LenghtLeft->hasFocus())
    {
    if(ui->LaCB->currentText() == "mm/cm")
        {
        double Mm = ui->lineEdit_LenghtLeft->text().toDouble();
        ui->lineEdit_LenghtRight->setText(QString::number(Mm /10 ));;
        }
    if(ui->LaCB->currentText() == "cm/m")
        {
        double Cm = ui->lineEdit_LenghtLeft->text().toDouble();
        ui->lineEdit_LenghtRight->setText(QString::number(Cm /100 ));;
        }
    if(ui->LaCB->currentText() == "m/km")
        {
        double M = ui->lineEdit_LenghtLeft->text().toDouble();
        ui->lineEdit_LenghtRight->setText(QString::number(M /1000 ));;
        }
    }
}

void MainWindow::on_lineEdit_LenghtRight_textChanged(const QString)
{  if(ui->lineEdit_LenghtRight->hasFocus())
    {
    if(ui->LaCB->currentText() == "mm/cm")
        {
        double Cm = ui->lineEdit_LenghtRight->text().toDouble();
        ui->lineEdit_LenghtLeft->setText(QString::number(Cm * 10));;
        }
    if(ui->LaCB->currentText() == "cm/m")
        {
        double M = ui->lineEdit_LenghtRight->text().toDouble();
        ui->lineEdit_LenghtLeft->setText(QString::number(M * 100 ));;
        }
    if(ui->LaCB->currentText() == "m/km")
        {
        double Km = ui->lineEdit_LenghtRight->text().toDouble();
        ui->lineEdit_LenghtLeft->setText(QString::number(Km *1000 ));;
        }
    }
}

void MainWindow::on_lineEdit_WeightLeft_textChanged(const QString)
{  if(ui->lineEdit_WeightLeft->hasFocus())
    {
    if(ui->WaCB->currentText() == "g/kg")
        {
        double G = ui->lineEdit_WeightLeft->text().toDouble();
        ui->lineEdit_WeightRight->setText(QString::number(G /1000));;
        }
    if(ui->WaCB->currentText() == "kg/p")
        {
        double Kg = ui->lineEdit_WeightLeft->text().toDouble();
        ui->lineEdit_WeightRight->setText(QString::number(Kg * 2.205 ));;
        }
    if(ui->WaCB->currentText() == "p/g")
        {
        double F = ui->lineEdit_WeightLeft->text().toDouble();
        ui->lineEdit_WeightRight->setText(QString::number((F *1000)/2.205 ));;
        }
    }
}

void MainWindow::on_lineEdit_WeightRight_textChanged(const QString)
{  if(ui->lineEdit_WeightRight->hasFocus())
    {
    if(ui->WaCB->currentText() == "g/kg")
        {
        double Kg = ui->lineEdit_WeightRight->text().toDouble();
        ui->lineEdit_WeightLeft->setText(QString::number(Kg * 1000));;
        }
    if(ui->WaCB->currentText() == "kg/p")
        {
        double F = ui->lineEdit_WeightRight->text().toDouble();
        ui->lineEdit_WeightLeft->setText(QString::number(F /2.205 ));;
        }
    if(ui->WaCB->currentText() == "p/g")
        {
        double G = ui->lineEdit_WeightRight->text().toDouble();
        ui->lineEdit_WeightLeft->setText(QString::number((G *2.205) /1000 ));;
        }
    }
}

void MainWindow::on_TaCB_activated(const QString )
{
    if(ui->TaCB->currentText() == "F/C")
    {
       ui->lineEdit_TempLeft->clear();
       ui->lineEdit_TempRight->clear();
    }
    if(ui->TaCB->currentText() == "K/C")
    {
       ui->lineEdit_TempLeft->clear();
       ui->lineEdit_TempRight->clear();
    }
    if(ui->TaCB->currentText() == "K/F")
    {
       ui->lineEdit_TempLeft->clear();
       ui->lineEdit_TempRight->clear();
    }
}

void MainWindow::on_LaCB_activated(const QString )
{
    if(ui->LaCB->currentText() == "mm/cm")
    {
       ui->lineEdit_LenghtLeft->clear();
       ui->lineEdit_LenghtRight->clear();
    }
    if(ui->TaCB->currentText() == "cm/m")
    {
       ui->lineEdit_LenghtLeft->clear();
       ui->lineEdit_LenghtRight->clear();
    }
    if(ui->TaCB->currentText() == "m/km")
    {
       ui->lineEdit_LenghtLeft->clear();
       ui->lineEdit_LenghtRight->clear();
    }
}

void MainWindow::on_WaCB_activated(const QString)
{
    if(ui->WaCB->currentText() == "g/kg")
    {
       ui->lineEdit_WeightLeft->clear();
       ui->lineEdit_WeightRight->clear();
    }
    if(ui->WaCB->currentText() == "kg/p")
    {
       ui->lineEdit_WeightLeft->clear();
       ui->lineEdit_WeightRight->clear();
    }
    if(ui->WaCB->currentText() == "p/g")
    {
       ui->lineEdit_WeightLeft->clear();
       ui->lineEdit_WeightRight->clear();
    }
}
void MainWindow::on_IchCB_currentTextChanged(const QString )
{
    if(ui->IchCB->currentText() == "Oil Charts")
        {
            ui->webView->setHtml(myURLOilPrices2);
        }
        if(ui->IchCB->currentText() == "Rubel Info")
        {
            ui->webView->setHtml(myURLrubleInterbank2);
        }
        if(ui->IchCB->currentText() == "Oil graphics")
        {
            ui->webView->setHtml(myURLOilgraphics);
        }
        if(ui->IchCB->currentText() == "Precious metals")
        {
            ui->webView->setHtml(myURLDrahotsennemetals);
        }
        ui->webView->reload();
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



