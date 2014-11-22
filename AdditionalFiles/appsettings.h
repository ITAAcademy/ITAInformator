#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QString>
#include <QList>

class appActiveWindows
{
public:
    static appActiveWindows &getInstance();

    void addActiveWindowName(const QString aName);
    void removeActiveWindow(const QString aName);
    const QList<QString> &allActiveWindows()const;

private:
    appActiveWindows();
    appActiveWindows(const appActiveWindows&);
    appActiveWindows &operator=(const appActiveWindows&);
    ~appActiveWindows();

private:
    QList<QString> mListActiveWindows;
};

#endif // APPSETTINGS_H
