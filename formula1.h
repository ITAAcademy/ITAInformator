#ifndef FORMULA1_H
#define FORMULA1_H
#include "unit1.h"
class formula1
{
public:
    formula1();
    virtual float calculate(float);
private:
    Unit1 fromUnit1;
    Unit1 toUnit1;
};

#endif // FORMULA1_H


