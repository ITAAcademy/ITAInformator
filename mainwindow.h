#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "distanceandlength.h"
#include "weight.h"
#include "conv_tools.h"

#include "AdditionalFiles/modal_window.h"
#include "AdditionalFiles/settings.h"

#include "Charts/oilprices.h"
#include "Charts/rubleinterbank.h"

#include "Units/Temperature/temperature.h"

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

    void on_lineEdit_TempRight_textChanged(const QString &arg1);

    void on_lineEdit_TempLeft_textChanged(const QString &arg1);

    void on_lineEdit_LenghtLeft_textChanged(const QString &arg1);

    void on_lineEdit_LenghtRight_textChanged(const QString &arg1);

    void on_lineEdit_WeightLeft_textChanged(const QString &arg1);

    void on_lineEdit_WeightRight_textChanged(const QString &arg1);


private:
    void fillTaCB();
    void fillLaCB();
    void fillWaCB();
    void fillIchCB();
    void fillIaCB();

private:

    Ui::MainWindow      *ui;
    QMdiArea            *mdiArea;
    QMenuBar            *menuBar;
    QString             appDefaultLang;
    QString             pLang;
    convTools           mConvTool;

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
