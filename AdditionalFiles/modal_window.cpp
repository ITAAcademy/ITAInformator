#include "modal_window.h"

modal_window::modal_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modal_window)
{
    logo_palette.setColor(QPalette::WindowText, Qt::blue);
    ui->setupUi(this);
    //this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint); //Hint only button '?'
    this->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint);

    setGeometry(QRect(450,250,180,510));
    ui->pushButton->setText(tr("Close"));

    ui->progName->setFont(QFont("Times",14,QFont::Bold,false));

    ui->sgTitle->setFont(QFont("Times",9,1,false));
    ui->sgTitle_2->setFont(QFont("Times",9,1,false));
    ui->sgTitle_3->setFont(QFont("Times",9,1,false));

    ui->pmTitle->setFont(QFont("Times",9,1,false));
    ui->pmName->setFont(QFont("Times",9,QFont::Bold,true));

    ui->sgName_AN->setFont(QFont("Times",9,QFont::Bold,true));
    ui->sgName_AS->setFont(QFont("Times",9,QFont::Bold,true));
    ui->sgName_DV->setFont(QFont("Times",9,QFont::Bold,true));
    ui->sgName_HD->setFont(QFont("Times",9,QFont::Bold,true));
    ui->sgName_IP->setFont(QFont("Times",9,QFont::Bold,true));
    ui->progName->setPalette(logo_palette);
}

modal_window::~modal_window()
{
    delete ui;
}
