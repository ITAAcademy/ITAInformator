#include "qmessagebox.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qmainwindow.h"
#include "QDialogButtonBox"

#include "AdditionalFiles/modal_window.h"
#include "AdditionalFiles/listopenedwindows.h"

#include "Charts/oilprices.h"
#include "Charts/rubleinterbank.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    translator = new QTranslator;
    qAppTranslator = new QTranslator;
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
}

void MainWindow::on_action_About_triggered()
{
    modal_window formmodal_window; // указываем новое имя класса
    formmodal_window.setModal(true); // говорим форме что она модальна
    formmodal_window.exec();
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
        ui->menuSettings->setTitle(tr("&Settings"));
            ui->action_Font_settings->setText(tr("&Font settings"));
            ui->action_Default_settings->setText(tr("&Default settings"));
    ui->menuProgram->setTitle(tr("Program"));
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
