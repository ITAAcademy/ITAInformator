#include "Units/weight.h"

static const QString windowName = "Weight";

Weight::Weight(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Weight)
{
    ui->setupUi(this);
    this->setFixedSize(375,150);

    ui->comboBoxWeight->addItem("g to kg");
    ui->comboBoxWeight->addItem("kg to p");
    ui->comboBoxWeight->addItem("p to g");
}

Weight::~Weight()
{
    delete ui;
}

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

void Weight::on_lineEdit_W_Left_textChanged(const QString)
{  if(ui->lineEdit_W_Left->hasFocus())
    {

    if(ui->comboBoxWeight->currentText() == "g to kg")
        {
        double G = ui->lineEdit_W_Left->text().toDouble();
        double Kg = G;
        ui->lineEdit_W_right->setText(QString::number(Kg /1000));;
        }
    if(ui->comboBoxWeight->currentText() == "kg to p")
        {
        double Kg = ui->lineEdit_W_Left->text().toDouble();
        double P = Kg;
        ui->lineEdit_W_right->setText(QString::number(P * 2.205 ));;
        }
    if(ui->comboBoxWeight->currentText() == "p to g")
        {
        double P = ui->lineEdit_W_Left->text().toDouble();
        double G = P;
        ui->lineEdit_W_right->setText(QString::number((G *1000)/2.205 ));;
        }
    }
}

void Weight::on_lineEdit_W_right_textChanged(const QString)
{  if(ui->lineEdit_W_right->hasFocus())
    {
    if(ui->comboBoxWeight->currentText() == "g to kg")
        {
        double Kg = ui->lineEdit_W_right->text().toDouble();
        double G = Kg;
        ui->lineEdit_W_Left->setText(QString::number(G * 1000));;
        }
    if(ui->comboBoxWeight->currentText() == "kg to p")
        {
        double P = ui->lineEdit_W_right->text().toDouble();
        double Kg = P;
        ui->lineEdit_W_Left->setText(QString::number(Kg /2.205 ));;
        }
    if(ui->comboBoxWeight->currentText() == "p to g")
        {
        double G = ui->lineEdit_W_right->text().toDouble();
        double P = G;
        ui->lineEdit_W_Left->setText(QString::number((P *2.205) /1000 ));;
        }
    }
}

void Weight::on_comboBoxWeight_activated(const QString)
{

    if(ui->comboBoxWeight->currentText() == "g to kg")
        {
        ui->lineEdit_W_Left->clear();
        ui->lineEdit_W_right->clear();
        ui->label_Left->setText(tr("Gram"));
        ui->label_Right->setText(tr("Kilogram"));
        }
    if(ui->comboBoxWeight->currentText() == "kg to p")
        {
        ui->lineEdit_W_Left->clear();
        ui->lineEdit_W_right->clear();
        ui->label_Left->setText(tr("Kilogram"));
        ui->label_Right->setText(tr("Pound"));
        }
    if(ui->comboBoxWeight->currentText() == "p to g")
        {
        ui->lineEdit_W_Left->clear();
        ui->lineEdit_W_right->clear();
        ui->label_Left->setText(tr("Pound"));
        ui->label_Right->setText(tr("Gram"));
        }

}
