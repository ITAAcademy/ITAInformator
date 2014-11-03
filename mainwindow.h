#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtWidgets>
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
    void on_action_settings_triggered();

private:
    Ui::MainWindow *ui;
    QMdiArea* mdiArea;
    QMenuBar* menuBar;


};

#endif // MAINWINDOW_H
