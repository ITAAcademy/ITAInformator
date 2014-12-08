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
