#ifndef OILGRAPHICS_H
#define OILGRAPHICS_H

#include <QDialog>
#include <QtWebKitWidgets/QWebView>
#include <QString>
#include <QLabel>
#include "ui_oilgraphics.h"
#include "AdditionalFiles/appsettings.h"

namespace Ui {
class OilGraphics;
}

class OilGraphics : public QDialog
{
    Q_OBJECT
public:
    explicit OilGraphics(QWidget *parent = 0);
    ~OilGraphics();

protected:

    void closeEvent (QCloseEvent *);
    void showEvent  (QShowEvent *);

private:
    Ui::OilGraphics *ui;

};

#endif // OILGRAPHICS_H
