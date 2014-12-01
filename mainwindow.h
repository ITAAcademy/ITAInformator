#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "conv_tools.h"
#include "QTranslator"

#include "AdditionalFiles/modal_window.h"
#include "AdditionalFiles/settings.h"

#include "Charts/oilprices.h"
#include "Charts/rubleinterbank.h"

// Begin(List_Opened_Windows)
#include "AdditionalFiles/listopenedwindows.h"
// End


class QMdiArea;
class QSignalMapper;
class DocWindow;
//QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void chLangEn();
    void chLangUa();
    void chLangPl();
    void reTranslateUi();

private slots:

    void on_action_About_triggered();

    void on_action_Oil_Charts_triggered();

    void on_action_Currency_triggered();

    void on_action_Font_settings_triggered();

    void on_action_List_opened_windows_triggered();

    void on_action_Default_settings_triggered();

private:
    void fillTaCB();
    void fillLaCB();
    void fillWaCB();
    void fillIchCB();
    void fillIaCB();
    void converterfunc(int);

private:

    Ui::MainWindow      *ui;
    QMdiArea            *mdiArea;
    QMenuBar            *menuBar;
    QString             appDefaultLang;
    QString             pLang;
    convTools           mConvTool;

    QTranslator         *translator;

    OilPrices           formOilPrices;
    rubleInterbank      formrubleInterbank;
    pSettings            mSettings;

    // Begin(List_Opened_Windows)
    ListOpenedWindows   *formListOpenedWindows;
    // End
};

#endif // MAINWINDOW_H
