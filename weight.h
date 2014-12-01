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

private slots:
        void on_lineEdit_W_Left_textChanged(const QString &arg1);

        void on_lineEdit_W_right_textChanged(const QString &arg1);

private:
    Ui::Weight *ui;
};

#endif // WEIGHT_H
