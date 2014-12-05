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
    // Begin(List_Opened_Windows)
    protected:
        void closeEvent(QCloseEvent *);
        void showEvent(QShowEvent *);
    // End

//----------Begin(Font_settings)
//    void setOilpricesFont(QFont &font);
//----------End

private:
    Ui::OilPrices *ui;
};

#endif // OILPRICES_H
