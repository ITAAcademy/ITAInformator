#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtWidgets>
#include <QFontDialog>
#include <QSettings>

#include "area.h"
#include "distanceandlength.h"
#include "volumecapacity.h"
#include "weight.h"

#include "AdditionalFiles/modal_window.h"

#include "Charts/oilprices.h"
#include "Charts/rubleinterbank.h"

#include "Units/Temperature/temperature.h"


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

    void saveSettings();
    void loadSettings();

private slots:

    void on_action_Widget_you_triggered();

    void on_action_Widget_you_2_triggered();

    void on_actionTemperature_triggered();

    void on_action_Oil_Charts_triggered();

    void on_action_Currency_triggered();

    void on_action_Font_settings_triggered();

    void on_actionArea_triggered();

    void on_actionVolume_capacity_triggered();

    void on_actionDistance_and_Length_triggered();

    void on_actionWeight_weight_triggered();

private:

    Ui::MainWindow      *ui;
    QMdiArea            *mdiArea;
    QMenuBar            *menuBar;

    Area                *formArea;
    VolumeCapacity      *formVolumeCapacity;
    DistanceAndLength   *formDistanceAndLength;
    Weight              *formWeight;
    QSettings           *settings;
    Temperature         formTemperature;
    OilPrices           formOilPrices;
    rubleInterbank      formrubleInterbank;
};

#endif // MAINWINDOW_H
