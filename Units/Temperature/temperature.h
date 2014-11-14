#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <QDialog>

namespace Ui {
class Temperature;
}

class Temperature : public QDialog
{
    Q_OBJECT

public:
    explicit Temperature(QWidget *parent = 0);
    ~Temperature();
//----------Begin(comment out it before merge)
    void setTemperatureFont(QFont &font);
//----------End
private:
    Ui::Temperature *ui;
};

#endif // TEMPERATURE_H
