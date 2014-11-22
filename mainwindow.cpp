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


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(mSettings.FirstRun())
    {
        QMessageBox::information(this, "First run", "This is the first run of the program. \n Thank you for your choice");
        setWindowTitle("Some name");
        setGeometry(QRect(100,100,200,600));
        setFont(QFont("Times",10,1,false));

        mSettings.setMainWindowRect(geometry());
        mSettings.setMainWindowTitle(windowTitle());
        mSettings.setMainWindowFont(font());
    }
    else
    {
        setWindowTitle(mSettings.getMainWindowTitle());
        setGeometry(mSettings.getMainWindowRect());
        setFont(mSettings.getMainWindowFont());
    }

    ui->menuBar->setFont(QFont("Times",10,1,false));


   // ui->menuBar->setNativeMenuBar(true);
}

MainWindow::~MainWindow()
{
    mSettings.setMainWindowRect(geometry());
    mSettings.setMainWindowFont(font());
    delete ui;
}

void MainWindow::on_action_Widget_you_triggered()
{

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
