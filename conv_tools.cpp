#include "conv_tools.h"

convTools::convTools()
{
    fillTaCB();
    fillLaCB();
    fillWaCB();
    fillIchCB();
    fillIaCB();
}

void convTools::fillTaCB()
{
    mTaCB.push_back("F/C");
    mTaCB.push_back("K/C");
    mTaCB.push_back("K/F");

}

void convTools::fillLaCB()
{
    mLaCB.push_back("mm/cm");
    mLaCB.push_back("cm/m");
    mLaCB.push_back("m/km");
}

void convTools::fillWaCB()
{
    mWaCB.push_back("g/kg");
    mWaCB.push_back("kg/p");
    mWaCB.push_back("p/g");
}

void convTools::fillIchCB()
{
    mIchCB.push_back("Oil Charts");
    mIchCB.push_back("Rubel Info");
}

void convTools::fillIaCB()
{
    mIaCB.push_back("Oil Charts");
    mIaCB.push_back("Rubel Info");
}

const QList<QString> &convTools::TaCB() const
{
    return mTaCB;
}

const QList<QString> &convTools::LaCB() const
{
    return mLaCB;
}

const QList<QString> &convTools::WaCB() const
{
    return mWaCB;
}

const QList<QString> &convTools::IchCB() const
{
    return mIchCB;
}

const QList<QString> &convTools::IaCB() const
{
    return mIaCB;
}
