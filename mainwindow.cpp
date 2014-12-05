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


void MainWindow::on_lineEdit_textChanged(const QString)
{

}

void MainWindow::on_lineEdit_2_textChanged(const QString)
{

}
