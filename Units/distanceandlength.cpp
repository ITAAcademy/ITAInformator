#include "Units/distanceandlength.h"

static const QString windowName = "Distance and Length";

DistanceAndLength::DistanceAndLength(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DistanceAndLength)
{
    ui->setupUi(this);
    this->setFixedSize(320,100);
    this->setGeometry(QRect(1019,209,320,100));
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    ui->comboBoxDistance->addItem("mm to cm");
    ui->comboBoxDistance->addItem("cm to m");
    ui->comboBoxDistance->addItem("m to km");
    ui->lineEdit_D_Left->setPlaceholderText(tr("Value in mm"));
    ui->lineEdit_D_right->setPlaceholderText(tr("Value in cm"));
    ui->pushButton_clearLenght->setText(tr("Clear"));
    setWindowTitle(tr("Distance and Length"));

    ui->lineEdit_D_Left->setValidator(new QDoubleValidator(-9999.0,
        9999.0, 6, ui->lineEdit_D_Left));
    ui->lineEdit_D_right->setValidator(new QDoubleValidator(-9999.0,
        9999.0, 6, ui->lineEdit_D_right));

    ui->label_Left->setVisible(0);
    ui->label_Right->setVisible(0);
}

DistanceAndLength::~DistanceAndLength()
{
    delete ui;
}

void DistanceAndLength::closeEvent(QCloseEvent *)
{
    appActiveWindows &ref = appActiveWindows::getInstance();
    ref.removeActiveWindow(windowName);
}
void DistanceAndLength::showEvent(QShowEvent *)
{
    appActiveWindows &ref = appActiveWindows::getInstance();
    ref.addActiveWindowName(windowName);
}

void DistanceAndLength::on_lineEdit_D_Left_textChanged(const QString)
{  if(ui->lineEdit_D_Left->hasFocus())
    {
    if(ui->comboBoxDistance->currentText() == "mm to cm")
        {
        double Mm = ui->lineEdit_D_Left->text().toDouble();
        double Cm = Mm;
        ui->lineEdit_D_right->setText(QString::number(Cm /10 ));;
        }
    if(ui->comboBoxDistance->currentText() == "cm to m")
        {
        double Cm = ui->lineEdit_D_Left->text().toDouble();
        double M = Cm;
        ui->lineEdit_D_right->setText(QString::number(M /100 ));;
        }
    if(ui->comboBoxDistance->currentText() == "m to km")
        {
        double M = ui->lineEdit_D_Left->text().toDouble();
        double Km = M;
        ui->lineEdit_D_right->setText(QString::number(Km /1000 ));;
        }
    }
}

void DistanceAndLength::on_lineEdit_D_right_textChanged(const QString)
{  if(ui->lineEdit_D_right->hasFocus())
    {
    if(ui->comboBoxDistance->currentText() == "mm to cm")
        {
        double Cm = ui->lineEdit_D_right->text().toDouble();
        double Mm = Cm;
        ui->lineEdit_D_Left->setText(QString::number(Mm * 10));;
        }
    if(ui->comboBoxDistance->currentText() == "cm to m")
        {
        double M = ui->lineEdit_D_right->text().toDouble();
        double Cm = M;
        ui->lineEdit_D_Left->setText(QString::number(Cm * 100 ));;
        }
    if(ui->comboBoxDistance->currentText() == "m to km")
        {
        double Km = ui->lineEdit_D_right->text().toDouble();
        double M = Km;
        ui->lineEdit_D_Left->setText(QString::number(M *1000 ));;
        }
    }
}

void DistanceAndLength::on_comboBoxDistance_activated(const QString )
{
    if(ui->comboBoxDistance->currentText() == "mm to cm")
        {
        ui->lineEdit_D_Left->clear();
        ui->lineEdit_D_right->clear();
        //ui->label_Left->setText("Millimetr");
        ui->lineEdit_D_Left->setPlaceholderText(tr("Value in mm"));
        //ui->label_Right->setText("Centimeter");
        ui->lineEdit_D_right->setPlaceholderText(tr("Value in cm"));
        }
    if(ui->comboBoxDistance->currentText() == "cm to m")
        {
        ui->lineEdit_D_Left->clear();
        ui->lineEdit_D_right->clear();
        //ui->label_Left->setText("Centimeter");
        ui->lineEdit_D_Left->setPlaceholderText(tr("Value in cm"));
        //ui->label_Right->setText("Meter");
        ui->lineEdit_D_right->setPlaceholderText(tr("Value in mm"));
        }
    if(ui->comboBoxDistance->currentText() == "m to km")
        {
        ui->lineEdit_D_Left->clear();
        ui->lineEdit_D_right->clear();
        //ui->label_Left->setText("Meter");
        ui->lineEdit_D_Left->setPlaceholderText(tr("Value in m"));
        //ui->label_Right->setText("Kilometer");
        ui->lineEdit_D_right->setPlaceholderText(tr("Value in km"));
        }
}

void DistanceAndLength::on_pushButton_clearLenght_clicked()
{
    ui->lineEdit_D_Left->clear();
    ui->lineEdit_D_right->clear();
}
