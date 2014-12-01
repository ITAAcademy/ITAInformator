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
    // Begin(List_Opened_Windows)
    protected:
        void closeEvent(QCloseEvent *);
        void showEvent(QShowEvent *);
    // End

//----------Begin(Font_settings)
//    void setTemperatureFont(QFont &font);
//----------End

private slots:
        void on_lineEdit_T_Left_textChanged(const QString &arg1);

        void on_lineEdit_T_right_textChanged(const QString &arg1);

private:
    Ui::Temperature *ui;
};

#endif // TEMPERATURE_H
