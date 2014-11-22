#ifndef WEIGHT_H
#define WEIGHT_H

#include <QDialog>

namespace Ui {
class Weight;
}

class Weight : public QDialog
{
    Q_OBJECT

public:
    explicit Weight(QWidget *parent = 0);
    ~Weight();
// Begin(List_Opened_Windows)
protected:
        void closeEvent(QCloseEvent *);
        void showEvent(QShowEvent *);
// End

private:
    Ui::Weight *ui;
};

#endif // WEIGHT_H
