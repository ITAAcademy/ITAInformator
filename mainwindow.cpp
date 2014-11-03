#include "mainwindow.h"
#include "ui_mainwindow.h"

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
        QMessageBox::about(this, tr("Settings"),
            tr("Here will be <b>Settings</b> "));
}
