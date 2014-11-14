#ifndef RUBLEINTERBANK_H
#define RUBLEINTERBANK_H

#include <QDialog>

namespace Ui {
class rubleInterbank;
}

class rubleInterbank : public QDialog
{
    Q_OBJECT

public:
    explicit rubleInterbank(QWidget *parent = 0);
    ~rubleInterbank();
//----------Begin(comment out it before merge)
    void setRubleInterbankFont(QFont &font);
//----------End
private:
    Ui::rubleInterbank *ui;
};

#endif // RUBLEINTERBANK_H
