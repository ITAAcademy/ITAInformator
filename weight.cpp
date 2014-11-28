#include "weight.h"
#include "ui_weight.h"

// Begin(List_Opened_Windows)
#include "AdditionalFiles/appsettings.h"

static const QString windowName = "Weight";
// End

Weight::Weight(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Weight)
{
    ui->setupUi(this);


}

Weight::~Weight()
{
    delete ui;
}
// Begin(List_Opened_Windows)
void Weight::closeEvent(QCloseEvent *)
{
    appActiveWindows &ref = appActiveWindows::getInstance();
    ref.removeActiveWindow(windowName);
}
void Weight::showEvent(QShowEvent *)
{
    appActiveWindows &ref = appActiveWindows::getInstance();
    ref.addActiveWindowName(windowName);
}
// End

void Weight::on_lineEdit_Weight_textChanged(const QString &arg1)
{
    double Kg = ui->lineEdit_Weight->text().toDouble();
    ui->lineEdit_Weight_2->setText(QString::number(Kg * 2.2));
}

void Weight::on_lineEdit_Weight_2_textChanged(const QString &arg1)
{
    double Funt = ui->lineEdit_Weight->text().toDouble();
    ui->lineEdit_Weight_2->setText(QString::number(Funt / 2.2));
}
