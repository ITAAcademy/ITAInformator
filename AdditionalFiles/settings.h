#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QString>
#include <QRect>
#include <QFontDialog>
#include <QSettings>



class pSettings
{

public:

    pSettings();
    ~pSettings();


    const bool &FirstRun()const;

    void setMainWindowTitle(const QString &aTitle);
    void setMainWindowRect(const QRect &aRect);
    void setMainWindowFont (const QFont &aFont);
    void setAppLang(const QString &aLang);

    const QString   &getMainWindowTitle()const;
    const QRect     &getMainWindowRect()const;
    const QFont     &getMainWindowFont()const;
    const QString   &getAppLang()const;

    void saveAppLang();
    void loadAppLang();

private:

    void saveSettings();
    void loadSettings();

    bool        isFirstRun;
    QString     mainWindowTitle;
    QRect       mainWindowRect;
    QFont       mainWindowFont;
    QString     appLang;
    QSettings   *mSettings;
};


#endif // SETTINGS_H
