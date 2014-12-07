#ifndef LISTOPENEDWINDOWS_H
#define LISTOPENEDWINDOWS_H

#include <QDialog>
#include "ui_listopenedwindows.h"
#include "AdditionalFiles/appsettings.h"

namespace Ui {
class ListOpenedWindows;
}

class ListOpenedWindows : public QDialog
{
    Q_OBJECT

public:

    explicit ListOpenedWindows(QWidget *parent = 0);
    ~ListOpenedWindows();

private:

    Ui::ListOpenedWindows *ui;
};

#endif // LISTOPENEDWINDOWS_H
