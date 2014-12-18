#ifndef WEIGHT_H
#define WEIGHT_H

#include <QDialog>
#include "ui_weight.h"
#include "AdditionalFiles/appsettings.h"

namespace Ui {
class Weight;
}

class Weight : public QDialog
{
    Q_OBJECT

public:
    explicit Weight(QWidget *parent = 0);
    ~Weight();

protected:

    void closeEvent(QCloseEvent *);
    void showEvent(QShowEvent *);

private slots:

    void on_lineEdit_W_Left_textChanged (const QString );
    void on_lineEdit_W_right_textChanged(const QString );
    void on_comboBoxWeight_activated    (const QString );

    void on_pushButton_ClearWeight_clicked();

private:

    Ui::Weight *ui;
};

#endif // WEIGHT_H
