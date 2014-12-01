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

    ui->comboBoxWeight->addItem("G to Kg");
    ui->comboBoxWeight->addItem("Kg to P");
    ui->comboBoxWeight->addItem("P to G");
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

void Weight::on_lineEdit_W_Left_textChanged(const QString)
{
    if(ui->comboBoxWeight->currentText() == "G to Kg")
        {
        double G = ui->lineEdit_W_Left->text().toDouble();
        ui->lineEdit_W_down->setText(QString::number(G /1000));;
        }
    if(ui->comboBoxWeight->currentText() == "Kg to P")
        {
        double Kg = ui->lineEdit_W_Left->text().toDouble();
        ui->lineEdit_W_down->setText(QString::number(Kg * 2.205 ));;
        }
    if(ui->comboBoxWeight->currentText() == "P to G")
        {
        double F = ui->lineEdit_W_Left->text().toDouble();
        ui->lineEdit_W_down->setText(QString::number((F *1000)/2.205 ));;
        }
}

void Weight::on_lineEdit_W_right_textChanged(const QString)
{
    if(ui->comboBoxWeight->currentText() == "G to Kg")
        {
        double Kg = ui->lineEdit_W_right->text().toDouble();
        ui->lineEdit_W_down->setText(QString::number(Kg * 1000));;
        }
    if(ui->comboBoxWeight->currentText() == "Kg to P")
        {
        double F = ui->lineEdit_W_right->text().toDouble();
        ui->lineEdit_W_down->setText(QString::number(F /2.205 ));;
        }
    if(ui->comboBoxWeight->currentText() == "P to G")
        {
        double G = ui->lineEdit_W_right->text().toDouble();
        ui->lineEdit_W_down->setText(QString::number((G *2.205) /1000 ));;
        }
}

void Weight::on_comboBoxWeight_activated(const QString)
{
    if(ui->comboBoxWeight->currentText() == "G to Kg")
        {
        ui->label_Left->setText("Gram");
        ui->label_Right->setText("Kilogram");
        }
    if(ui->comboBoxWeight->currentText() == "Kg to P")
        {
     ui->label_Left->setText("Kilogram");
     ui->label_Right->setText("Pound");
        }
    if(ui->comboBoxWeight->currentText() == "P to G")
        {
        ui->label_Left->setText("Pound");
        ui->label_Right->setText("Gram");
        }
}
