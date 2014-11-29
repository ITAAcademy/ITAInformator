#ifndef CONV_TOOLS_H
#define CONV_TOOLS_H

#include <QList>
#include <QString>

class convTools
{
public:
    convTools();

    const QList<QString> &TaCB() const;
    const QList<QString> &LaCB() const;
    const QList<QString> &WaCB() const;
    const QList<QString> &IchCB() const;
    const QList<QString> &IaCB() const;
private:
    void fillTaCB();
    void fillLaCB();
    void fillWaCB();
    void fillIchCB();
    void fillIaCB();
private:
    QList<QString> mTaCB;
    QList<QString> mLaCB;
    QList<QString> mWaCB;
    QList<QString> mIchCB;
    QList<QString> mIaCB;
};

#endif // CONV_TOOLS_H
