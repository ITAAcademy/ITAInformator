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

//----------Begin(Font_settings)
//    void setTemperatureFont(QFont &font);
//----------End

private slots:
    void on_comboBox_Temperature_activated(const QString &arg1);

    void on_pushButton_Temperature_clicked();

    void on_textBrowser_objectNameChanged(const QString &objectName);

private:
    Ui::Temperature *ui;
};

#endif // TEMPERATURE_H
