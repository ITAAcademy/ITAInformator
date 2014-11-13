#include "Units/unit.h"
#include "formula.h"
#include "celtorankline.h"

CelToRankline::CelToRankline()
{
}

float CelToRankline::calculate(float X)
{
    //test function please fix it
    return  (X+273.15)*9/5;
}
