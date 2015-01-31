#include "Units/temperature.h"

static const QString windowName = "Temperature";

Temperature::Temperature(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Temperature)
{
    ui->setupUi(this);
    this->setFixedSize(320,100);
    this->setGeometry(QRect(1019,69,320,100));
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    ui->comboBoxTemperature->addItem("f to c");
    ui->comboBoxTemperature->addItem("k to c");
    ui->comboBoxTemperature->addItem("k to f");

    ui->lineEdit_T_Left->setPlaceholderText(tr("Value in fahr"));
    ui->lineEdit_T_right->setPlaceholderText(tr("Value in cel"));

    ui->pushButton_clearTemper->setText(tr("Clear"));
    setWindowTitle(tr("Temperature"));

    ui->lineEdit_T_Left->setValidator(new QDoubleValidator(-9999.0,
        9999.0, 6, ui->lineEdit_T_Left));
    ui->lineEdit_T_right->setValidator(new QDoubleValidator(-9999.0,
        9999.0, 6, ui->lineEdit_T_right));

    ui->label_Left->setVisible(0);
    ui->label_Right->setVisible(0);
}

Temperature::~Temperature()
{
    delete ui;
}
// Begin(List_Opened_Windows)
void Temperature::closeEvent(QCloseEvent *)
{
    appActiveWindows &ref = appActiveWindows::getInstance();
    ref.removeActiveWindow(windowName);
}
void Temperature::showEvent(QShowEvent *)
{
    appActiveWindows &ref = appActiveWindows::getInstance();
    ref.addActiveWindowName(windowName);
}

void Temperature::on_lineEdit_T_Left_textChanged(const QString)
{
   if(ui->lineEdit_T_Left->hasFocus())
   {
    if(ui->comboBoxTemperature->currentText() == "f to c")
        {
        double F = ui->lineEdit_T_Left->text().toDouble();
        double C = F;
        ui->lineEdit_T_right->setText(QString::number((C - 32)*5/9));;
        }
    if(ui->comboBoxTemperature->currentText() == "k to c")
        {
        double K = ui->lineEdit_T_Left->text().toDouble();
        double C = K;
        ui->lineEdit_T_right->setText(QString::number(C - 273.15 ));;
        }
    if(ui->comboBoxTemperature->currentText() == "k to f")
        {
        double K = ui->lineEdit_T_Left->text().toDouble();
        double F = K;
        ui->lineEdit_T_right->setText(QString::number(F *9/5-459.67 ));;
        }
    }
}

void Temperature::on_lineEdit_T_right_textChanged(const QString)
{
   if(ui->lineEdit_T_right->hasFocus())
   {
    if(ui->comboBoxTemperature->currentText() == "f to c")
        {
        double C = ui->lineEdit_T_right->text().toDouble();
        double F = C;
        ui->lineEdit_T_Left->setText(QString::number((F *9/5)+32 ));
        }
    if(ui->comboBoxTemperature->currentText() == "k to c")
        {
        double C = ui->lineEdit_T_right->text().toDouble();
        double K = C;
        ui->lineEdit_T_Left->setText(QString::number(K + 273.15 ));
        }
    if(ui->comboBoxTemperature->currentText() == "k to f")
        {
        double F = ui->lineEdit_T_right->text().toDouble();
        double K = F;
        ui->lineEdit_T_Left->setText(QString::number((K +459.67)*5/9 ));
        }
   }
}

void Temperature::on_comboBoxTemperature_activated(const QString )
{
    if(ui->comboBoxTemperature->currentText() == "f to c")
        {
        ui->lineEdit_T_Left->clear();
        ui->lineEdit_T_right->clear();
        //ui->label_Left->setText("Fahrenheit");
        ui->lineEdit_T_Left->setPlaceholderText(tr("Value in fahr"));
        //ui->label_Right->setText("Celsius");
        ui->lineEdit_T_right->setPlaceholderText(tr("Value in cel"));
        }
    if(ui->comboBoxTemperature->currentText() == "k to c")
        {
        ui->lineEdit_T_Left->clear();
        ui->lineEdit_T_right->clear();
        //ui->label_Left->setText("Kelvin");
        ui->lineEdit_T_Left->setPlaceholderText(tr("Value in kel"));
        //ui->label_Right->setText("Celsius");
        ui->lineEdit_T_right->setPlaceholderText(tr("Value in cel"));
        }
    if(ui->comboBoxTemperature->currentText() == "k to f")
        {
        ui->lineEdit_T_Left->clear();
        ui->lineEdit_T_right->clear();
        //ui->label_Left->setText("Kelvin");
        ui->lineEdit_T_Left->setPlaceholderText(tr("Value in kel"));
        //ui->label_Right->setText("Fahrenheit");
        ui->lineEdit_T_right->setPlaceholderText(tr("Value in fahr"));
        }
}

void Temperature::on_pushButton_clearTemper_clicked()
{
    ui->lineEdit_T_Left->clear();
    ui->lineEdit_T_right->clear();
}
