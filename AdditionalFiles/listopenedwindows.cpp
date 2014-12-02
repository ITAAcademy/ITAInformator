#include "listopenedwindows.h"
#include "ui_listopenedwindows.h"
#include "AdditionalFiles/appsettings.h"

ListOpenedWindows::ListOpenedWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListOpenedWindows)
{
    ui->setupUi(this);

    const QList<QString> &refList = appActiveWindows::getInstance().allActiveWindows();

    for(int i = 0; i < refList.count(); ++i)
        ui->textEdit->append(refList.at(i));
}

ListOpenedWindows::~ListOpenedWindows()
{
    delete ui;
}
