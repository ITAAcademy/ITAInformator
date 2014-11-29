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

private:
    Ui::DistanceAndLength *ui;
};

#endif // DISTANCEANDLENGTH_H
