#ifndef OILPRICES_H
#define OILPRICES_H

#include <QDialog>
#include <QtWebKitWidgets/QWebView>
#include <QString>

namespace Ui {
class OilPrices;
}

class OilPrices : public QDialog
{
    Q_OBJECT

public:
    explicit OilPrices(QWidget *parent = 0);
    ~OilPrices();

private:
    Ui::OilPrices *ui;
};

#endif // OILPRICES_H
