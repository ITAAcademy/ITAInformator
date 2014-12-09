#ifndef OILPRICES_H
#define OILPRICES_H

#include <QDialog>
#include <QtWebKitWidgets/QWebView>
#include <QString>
#include <QLabel>
#include "ui_oilprices.h"
#include "AdditionalFiles/appsettings.h"

namespace Ui {
class OilPrices;
}

class OilPrices : public QDialog
{
    Q_OBJECT

public:

    explicit OilPrices(QWidget *parent = 0);
    ~OilPrices();
protected:

    void closeEvent (QCloseEvent *);
    void showEvent  (QShowEvent *);

private:
    Ui::OilPrices *ui;
};

#endif // OILPRICES_H
