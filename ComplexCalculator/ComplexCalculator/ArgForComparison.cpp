#include "ArgForComparison.h"
#include <cmath>

const double Pi = 3.141592;

double ArgForComparison::GetArg(ComplexNumber Num)
{
    double Fi = 0;
    double a = Num.GetRealPart();
    double b = Num.GetImaginaryPart();

    if (a > 0 && b >= 0)
    {
        Fi = atan(b / a);
    }
    else if (a < 0 && b >= 0)
    {
        Fi = Pi - atan(abs(b / a));
    }
    else if (a < 0 && b < 0)
    {
        Fi = Pi + atan(abs(b / a));
    }
    else if (a > 0 && b < 0)
    {
        Fi = 2 * Pi - atan(abs(b / a));
    }
    else if (a == 0 && b > 0)
    {
        Fi = Pi / 2;
    }
    else if (a == 0 && b < 0)
    {
        Fi = 3 * Pi / 2;
    }

    return Fi;
}
