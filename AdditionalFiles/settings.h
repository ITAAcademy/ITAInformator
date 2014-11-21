#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QString>
#include <QRect>
#include <QFontDialog>
#include <QSettings>



class pSettings : public  QObject
{
    Q_OBJECT

public:

    pSettings(QObject *parent = 0);
    ~pSettings();


    const bool &FirstRun()const;

    void setMainWindowTitle(const QString &aTitle);
    void setMainWindowRect(const QRect &aRect);
    void setMainWindowFont (const QFont &aFont);

    const QString   &getMainWindowTitle()const;
    const QRect     &getMainWindowRect()const;
    const QFont     &getMainWindowFont()const;

    void fontSettings();

private:

    void saveSettings();
    void loadSettings();

    bool        isFirstRun;
    QString     mainWindowTitle;
    QRect       mainWindowRect;
    QFont       mainWindowFont;

    QSettings   *mSettings;
};


#endif // SETTINGS_H
