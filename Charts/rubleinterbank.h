#ifndef RUBLEINTERBANK_H
#define RUBLEINTERBANK_H

#include <QDialog>
#include <QtWebKitWidgets/QWebView>
#include <QString>

namespace Ui {
class rubleInterbank;
}

class rubleInterbank : public QDialog
{
    Q_OBJECT

public:
    explicit rubleInterbank(QWidget *parent = 0);
    ~rubleInterbank();
// Begin(List_Opened_Windows)
protected:
        void closeEvent(QCloseEvent *);
        void showEvent(QShowEvent *);
// End

//----------Begin(Font_settings
//    void setRubleInterbankFont(QFont &font);
//----------End

private:
    Ui::rubleInterbank *ui;
};

#endif // RUBLEINTERBANK_H
