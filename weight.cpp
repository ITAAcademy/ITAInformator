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

    ui->comboBox_Weight->addItem("Gram");
    ui->comboBox_Weight->addItem("Kg");

    ui->comboBox_Weight_2->addItem("Gram");
    ui->comboBox_Weight_2->addItem("Kg");
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
