#ifndef METALS_H
#define METALS_H

#include <QDialog>
#include <QtWebKitWidgets/QWebView>
#include <QString>
#include <QLabel>
#include "ui_metals.h"
#include "AdditionalFiles/appsettings.h"

namespace Ui {
class Metals;
}

class Metals : public QDialog
{
    Q_OBJECT
public:
    explicit Metals(QWidget *parent = 0);
    ~Metals();

protected:

    void closeEvent (QCloseEvent *);
    void showEvent  (QShowEvent *);

private:
    Ui::Metals *ui;

};

#endif // METALS_H
