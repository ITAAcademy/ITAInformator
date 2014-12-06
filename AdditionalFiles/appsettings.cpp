#include "appsettings.h"


appActiveWindows::appActiveWindows()
{
}
appActiveWindows::appActiveWindows(const appActiveWindows &)
{
}
appActiveWindows &appActiveWindows::operator=(const appActiveWindows&)
{
    return *this;
}
appActiveWindows::~appActiveWindows()
{
}
appActiveWindows &appActiveWindows::getInstance()
{
    static appActiveWindows instance;
    return instance;
}
void appActiveWindows::addActiveWindowName(const QString aName)
{
    mListActiveWindows.push_back(aName);
}
void appActiveWindows::removeActiveWindow(const QString aName)
{
    mListActiveWindows.removeOne(aName);
}
const QList<QString> &appActiveWindows::allActiveWindows()const
{
    return mListActiveWindows;
}















