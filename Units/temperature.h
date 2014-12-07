#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <QDialog>
#include "ui_temperature.h"
#include "AdditionalFiles/appsettings.h"

namespace Ui {
class Temperature;
}

class Temperature : public QDialog
{
    Q_OBJECT

public:

    explicit Temperature(QWidget *parent = 0);
    ~Temperature();

protected:

    void closeEvent (QCloseEvent *);
    void showEvent  (QShowEvent *);

private slots:

        void on_lineEdit_T_Left_textChanged     (const QString );
        void on_lineEdit_T_right_textChanged    (const QString );
        void on_comboBoxTemperature_activated   (const QString );

private:
    Ui::Temperature *ui;
};

#endif // TEMPERATURE_H
