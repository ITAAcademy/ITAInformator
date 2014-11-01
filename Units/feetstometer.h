#ifndef FEETSTOMETER_H
#define FEETSTOMETER_H
#include "formula.h"
class FeetsToMeter : public Formula
{
public:
    FeetsToMeter();
    float calculate(float);
};

#endif // FEETSTOMETER_H
