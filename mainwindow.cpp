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

     //beginning conclusion of pictures

    QPixmap pic_distance(":/imagin/length.png");
    ui->pic_distance->setPixmap(pic_distance);

    QPixmap pic_weight(":/imagin/mass.png");
    ui->pic_weight->setPixmap(pic_weight);

    QPixmap pic_volume(":/imagin/volume.png");
    ui->pic_volume->setPixmap(pic_volume);
    //
    QPixmap pic_area(":/imagin/area.png");
    ui->pic_area->setPixmap(pic_area);

    QPixmap pic_temperature(":/imagin/temperature.png");
    ui->pic_temperature->setPixmap(pic_temperature);

    QPixmap pic_data(":/imagin/data.png");
    ui->pic_data->setPixmap(pic_data);
    //
    QPixmap pic_time(":/imagin/time.png");
    ui->pic_time->setPixmap(pic_time);

    QPixmap pic_speed(":/imagin/speed.png");
    ui->pic_speed->setPixmap(pic_speed);

    QPixmap pic_power(":/imagin/power.png");
    ui->pic_power->setPixmap(pic_power);
    //end conclusion of pictures

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

void MainWindow::paintEvent(QPaintEvent *)
{
    QImage img(":/imagin/fon.jpg");
    QPainter painter(this);
    painter.drawImage(0, 0, img.scaled(this->size()));
}



void MainWindow::on_pic_distance_linkActivated(const QString &link)
{

}

void MainWindow::on_pic_weight_linkActivated(const QString &link)
{

}

void MainWindow::on_pic_volume_linkActivated(const QString &link)
{

}

void MainWindow::on_pic_area_linkActivated(const QString &link)
{

}

void MainWindow::on_pic_temperature_linkActivated(const QString &link)
{

}

void MainWindow::on_pic_data_linkActivated(const QString &link)
{

}

void MainWindow::on_pic_time_linkActivated(const QString &link)
{

}

void MainWindow::on_pic_speed_linkActivated(const QString &link)
{

}

void MainWindow::on_pic_power_linkActivated(const QString &link)
{

}
