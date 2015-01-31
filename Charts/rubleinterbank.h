#ifndef RUBLEINTERBANK_H
#define RUBLEINTERBANK_H

#include <QDialog>
#include <QtWebKitWidgets/QWebView>
#include <QLabel>
#include <QString>
#include "ui_rubleinterbank.h"
#include "AdditionalFiles/appsettings.h"
#include <QRect>

namespace Ui {
class rubleInterbank;
}

class rubleInterbank : public QDialog
{
    Q_OBJECT

public:

    explicit rubleInterbank(QWidget *parent = 0);
    ~rubleInterbank();

protected:

    void closeEvent (QCloseEvent *);
    void showEvent  (QShowEvent *);

private:
    Ui::rubleInterbank *ui;
};

#endif // RUBLEINTERBANK_H
