#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialogButtonBox>
#include <QTranslator>
#include <QMessageBox>
#include <QWebFrame>
#include <QFile>
#include <fstream>
#include <QList>
#include <QString>
#include "ui_mainwindow.h"
#include "qmainwindow.h"
#include "Units/distanceandlength.h"
#include "Units/weight.h"
#include "Units/temperature.h"
//#include "AdditionalFiles/listopenedwindows.h"
#include "AdditionalFiles/modal_window.h"
#include "AdditionalFiles/settings.h"
#include "Charts/oilprices.h"
#include "Charts/rubleinterbank.h"
#include <QNetworkInterface>
#include <QNetworkConfigurationManager>
#include <QVector>
#include "Charts/oilgraphics.h"
#include "Charts/metals.h"

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

private:
    void _setWebViewData(const int &aIndex);
    void _initControls();
    void _initChartsVectorData();
    void _placeHolderName();

    void closeEvent(QCloseEvent *);

public slots:

    void chLangEn();
    void chLangUa();
    void chLangPl();
    void chLangRu();
    void reTranslateUi();
    void appChangeLanguage();

private slots:

    void on_action_About_triggered();
    void on_actionTemperature_triggered();
    void on_action_Oil_Charts_triggered();
    void on_action_Currency_triggered();
    void on_actionDistance_and_Length_triggered();
    void on_actionWeight_weight_triggered();
    void on_action_Font_settings_triggered();
    //void on_action_List_opened_windows_triggered();
    void on_action_Default_settings_triggered();
    void on_actionExit_triggered();
    void on_lineEdit_TempRight_textChanged  (const QString );
    void on_lineEdit_TempLeft_textChanged   (const QString );
    void on_lineEdit_LenghtLeft_textChanged (const QString );
    void on_lineEdit_LenghtRight_textChanged(const QString );
    void on_lineEdit_WeightLeft_textChanged (const QString );
    void on_lineEdit_WeightRight_textChanged(const QString );
    void on_TaCB_activated                  (const QString);
    void on_LaCB_activated                  (const QString);
    void on_WaCB_activated                  (const QString );
    void on_LeftITE_textChanged             (const QString );
    void on_RightITE_textChanged            (const QString );
    void on_webView_loadFinished            (bool);


    void on_pushButton_ClearTemper_clicked();

    void on_pushButton_ClearLenght_clicked();

    void on_pushButton_ClearWeight_clicked();

    void on_pushButton_Clear_Many_clicked();

    void on_IaCB_activated(const QString);

    void on_IchCB_currentIndexChanged(int index);

    void on_actionOil_graphics_triggered();

    void on_actionPrecious_metals_charts_triggered();

    void on_actionEn_triggered();

    void on_actionUa_triggered();

    void on_actionPl_triggered();

    void on_actionRu_triggered();

private:

    Ui::MainWindow      *ui;
    QMdiArea            *mdiArea;
    QMenuBar            *menuBar;
    QString             pLang;

    QTranslator         *translator;
    QTranslator         *qAppTranslator;
    QFontDialog         mFontDialog;

    DistanceAndLength   *formDistanceAndLength;
    Weight              *formWeight;
    Temperature         *formTemperature;
    OilPrices           *formOilPrices;
    rubleInterbank      *formrubleInterbank;
    OilGraphics         *formOilGraphics;
    Metals              *formMetals;
    pSettings            mSettings;

    //ListOpenedWindows   *formListOpenedWindows;

//    QLineEdit           *lineEdit_TempLeft;
//    QLineEdit           *lineEdit_TempRight;

    double              mCoofRubToUsdBuy;
    double              mCoofRubToEurBuy;
    double              mCoofRubInUsdSale;
    double              mCoofRubInEurSale;
    double              sum1;

    QNetworkConfigurationManager mgr;

    QVector<QString> mvCharts;
};

#endif // MAINWINDOW_H
