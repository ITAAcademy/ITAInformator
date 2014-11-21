#include "mainwindow.h"
#include "ui_mainwindow.h"


#include "distanceandlength.h"
#include "weight.h"

#include "AdditionalFiles/modal_window.h"

#include "Charts/oilprices.h"
#include "Charts/rubleinterbank.h"

#include "Units/Temperature/temperature.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // ui->menuBar->setNativeMenuBar(true);
}

MainWindow::~MainWindow()
{
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
//-----------------------------Begin(Font_settings)
void MainWindow::on_action_Font_settings_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont( "Helvetica [Cronyx]", 10 ), this );
    if (!ok)
        return;
//    ui->l_main_window->setFont(font);
//    formOilPrices.setOilpricesFont(font);
//    formrubleInterbank.setRubleInterbankFont(font);
//    formTemperature.setTemperatureFont(font);
}
//-----------------------------End




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


