#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "distanceandlength.h"
#include "weight.h"

#include "AdditionalFiles/modal_window.h"
#include "AdditionalFiles/settings.h"

#include "Charts/oilprices.h"
#include "Charts/rubleinterbank.h"

#include "Units/Temperature/temperature.h"
#include <QPicture>
#include <QImage>
#include <QPainter>

// Begin(List_Opened_Windows)
#include "AdditionalFiles/listopenedwindows.h"
// End


class QMdiArea;
class QSignalMapper;
class DocWindow;
//QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_Widget_you_2_triggered();
    void on_actionTemperature_triggered();
    void on_action_Oil_Charts_triggered();
    void on_action_Currency_triggered();
    void on_actionDistance_and_Length_triggered();
    void on_actionWeight_weight_triggered();
    void on_action_Font_settings_triggered();
    void on_actionList_opened_windows_triggered();
    void on_action_Default_settings_triggered();

    void on_pic_distance_linkActivated(const QString &link);
    void on_pic_weight_linkActivated(const QString &link);
    void on_pic_volume_linkActivated(const QString &link);
    void on_pic_area_linkActivated(const QString &link);
    void on_pic_temperature_linkActivated(const QString &link);
    void on_pic_data_linkActivated(const QString &link);
    void on_pic_time_linkActivated(const QString &link);
    void on_pic_speed_linkActivated(const QString &link);
    void on_pic_power_linkActivated(const QString &link);

protected:
    void paintEvent(QPaintEvent *); // override virtual functions

private:

    Ui::MainWindow      *ui;
    QMdiArea            *mdiArea;
    QMenuBar            *menuBar;
    QString             appDefaultLang;
    QString             pLang;


    DistanceAndLength   *formDistanceAndLength;
    Weight              *formWeight;
    Temperature         formTemperature;
    OilPrices           formOilPrices;
    rubleInterbank      formrubleInterbank;
    pSettings            mSettings;

    // Begin(List_Opened_Windows)
    ListOpenedWindows   *formListOpenedWindows;
    // End
};

#endif // MAINWINDOW_H
