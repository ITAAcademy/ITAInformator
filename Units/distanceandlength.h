#ifndef DISTANCEANDLENGTH_H
#define DISTANCEANDLENGTH_H

#include <QDialog>
#include "ui_distanceandlength.h"
#include "AdditionalFiles/appsettings.h"

namespace Ui {
class DistanceAndLength;
}

class DistanceAndLength : public QDialog
{
    Q_OBJECT

public:

    explicit DistanceAndLength(QWidget *parent = 0);
    ~DistanceAndLength();

protected:

   void closeEvent  (QCloseEvent *);
   void showEvent   (QShowEvent *);

private slots:

   void on_lineEdit_D_Left_textChanged  (const QString );
   void on_lineEdit_D_right_textChanged (const QString );
   void on_comboBoxDistance_activated   (const QString );

   void on_pushButton_clearLenght_clicked();

private:
    Ui::DistanceAndLength *ui;
};

#endif // DISTANCEANDLENGTH_H
