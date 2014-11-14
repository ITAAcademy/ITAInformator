#ifndef OILPRICES_H
#define OILPRICES_H

#include <QDialog>

namespace Ui {
class OilPrices;
}

class OilPrices : public QDialog
{
    Q_OBJECT

public:
    explicit OilPrices(QWidget *parent = 0);
    ~OilPrices();
    void setOilpricesFont(QFont &font); //ad function (comment out it before merge)
private:
    Ui::OilPrices *ui;
};

#endif // OILPRICES_H
