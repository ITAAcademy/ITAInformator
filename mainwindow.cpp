#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AdditionalFiles/settings.h"
#include "AdditionalFiles/modal_window.h"
#include "Units/Temperature/temperature.h"
#include "Charts/oilprices.h"
#include "Charts/rubleinterbank.h"


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


void MainWindow::on_action_settings_triggered()
{
    Settings formSettings;
    formSettings.setModal(true);
    formSettings.exec();
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
    formTemperature = new Temperature (this);
    formTemperature -> show();
}

void MainWindow::on_action_Oil_Charts_triggered()
{
       formOilPrices = new OilPrices(this);
       formOilPrices->show();


}

void MainWindow::on_action_Currency_triggered()
{
    formrubleInterbank = new rubleInterbank(this);
    formrubleInterbank->show();
}
