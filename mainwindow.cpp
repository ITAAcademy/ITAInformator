#include "area.h"
#include "distanceandlength.h"
#include "mainwindow.h"
#include "qmessagebox.h"
#include "volumecapacity.h"
#include "weight.h"
#include "ui_mainwindow.h"

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

    settings = new QSettings("settings.ini", QSettings::IniFormat, this);
    loadSettings();
}

MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}

void MainWindow::saveSettings()
{

    settings->setValue("MainWindow/title", windowTitle());
    settings->setValue("MainWindow/position", geometry());
}

void MainWindow::loadSettings()
{
    if (settings->value("FirstRun/IsRunFirst").toBool() == false)
    {
        QMessageBox::information(this, "First run",
                                       "This is the first run of the program. \n Thank you for your choice");
        settings->setValue("FirstRun/IsRunFirst", true);
    }
    setWindowTitle(settings->value("MainWindow/title", "MainFormITA").toString());
    setGeometry(settings->value("MainWindow/position", QRect(200, 200, 300, 300)).toRect());
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
void MainWindow::on_actionArea_triggered()
{
    formArea = new Area (this);
    formArea -> show();
}

void MainWindow::on_actionVolume_capacity_triggered()
{
    formVolumeCapacity = new VolumeCapacity (this);
    formVolumeCapacity -> show();
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

