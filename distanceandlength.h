#ifndef DISTANCEANDLENGTH_H
#define DISTANCEANDLENGTH_H

#include <QDialog>

namespace Ui {
class DistanceAndLength;
}

class DistanceAndLength : public QDialog
{
    Q_OBJECT

public:
    explicit DistanceAndLength(QWidget *parent = 0);
    ~DistanceAndLength();
// Begin(List_Opened_Windows)
protected:
   void closeEvent(QCloseEvent *);
   void showEvent(QShowEvent *);
// End

private slots:
   void on_lineEdit_D_Left_textChanged(const QString &arg1);

   void on_lineEdit_D_right_textChanged(const QString &arg1);

private:
    Ui::DistanceAndLength *ui;
};

#endif // DISTANCEANDLENGTH_H
