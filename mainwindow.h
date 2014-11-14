#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtWidgets>
#include <QFontDialog>

#include "Units/Temperature/temperature.h"

#include "Charts/oilprices.h"
#include "Charts/rubleinterbank.h"

#include "AdditionalFiles/modal_window.h"



class QMdiArea;
class QSignalMapper;
class DocWindow;
//QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:

    void on_action_Widget_you_triggered();

    void on_action_Widget_you_2_triggered();


    void on_actionTemperature_triggered();


    void on_action_Oil_Charts_triggered();

    void on_action_Currency_triggered();


    void on_action_Font_settings_triggered();

private:
    Ui::MainWindow *ui;
    QMdiArea* mdiArea;
    QMenuBar* menuBar;   

    Temperature *formTemperature;
private:
    OilPrices *formOilPrices;
    rubleInterbank *formrubleInterbank;
};

#endif // MAINWINDOW_H
