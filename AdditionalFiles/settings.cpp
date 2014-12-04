#include "qmessagebox.h"
#include "settings.h"



pSettings::pSettings() :
    isFirstRun(false)
    ,mSettings(0)
{
    mSettings = new QSettings("settings.ini", QSettings::IniFormat);
    loadSettings();
    loadAppLang();
}

pSettings::~pSettings()
{
    saveSettings();
    saveAppLang();
    if(mSettings != 0)
        delete mSettings;
}

void pSettings::saveSettings()
{
    mSettings->remove("MainWindow/font");
    mSettings->setValue("FirstRun/IsRunFirst",  true);
    mSettings->setValue("MainWindow/title",     mainWindowTitle);
    mSettings->setValue("MainWindow/position",  mainWindowRect);
    mSettings->setValue("MainWindow/font",      mainWindowFont.toString());
}

void pSettings::saveAppLang()
{
    mSettings->setValue("AppLang/Lang",         appLang);
}

void pSettings::loadSettings()
{

    if(mSettings->value("FirstRun/IsRunFirst").toBool() == false)
        isFirstRun = true;

    mainWindowTitle = mSettings->value("MainWindow/title")              .toString();
    mainWindowRect  = mSettings->value("MainWindow/position")           .toRect();
    mainWindowFont.fromString(mSettings->value("MainWindow/font")       .toString());
}

void pSettings::loadAppLang()
{
    appLang         = mSettings->value("AppLang/Lang")                  .toString();
}

void pSettings::setMainWindowTitle(const QString &aTitle)
{
    mainWindowTitle = aTitle;
}

void pSettings::setMainWindowRect(const QRect &aRect)
{
    mainWindowRect = aRect;
}

void pSettings::setMainWindowFont(const QFont &aFont)
{
    mainWindowFont = aFont;
}

void pSettings::setAppLang(const QString &aLang)
{
    appLang = aLang;
}

const bool &pSettings::FirstRun()const
{
    return isFirstRun;
}

const QString &pSettings::getMainWindowTitle()const
{
    return mainWindowTitle;
}

const QRect &pSettings::getMainWindowRect()const
{
    return mainWindowRect;
}

const QFont &pSettings::getMainWindowFont()const
{
    return mainWindowFont;
}

const QString &pSettings::getAppLang()const
{
    return appLang;
}

