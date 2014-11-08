#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtWidgets>
#include "temperature.h"
//QT_BEGIN_NAMESPACE
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

private:
    Ui::MainWindow *ui;
    QMdiArea* mdiArea;
    QMenuBar* menuBar;

    Temperature *formTemperature;


};

#endif // MAINWINDOW_H
