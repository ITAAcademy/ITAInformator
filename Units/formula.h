#ifndef FORMULA_H
#define FORMULA_H

#include "unit.h"
class Formula
{
public:
    Formula();
    virtual float calculate(float);
private:
    Unit fromUnit;
    Unit toUnit;
};

#endif // FORMULA_H
