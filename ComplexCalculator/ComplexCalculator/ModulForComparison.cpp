#include "ModulForComparison.h"
#include <cmath>

double ModulForComparison::GetModul(ComplexNumber Num)
{
	double r = sqrt(Num.GetRealPart() * Num.GetRealPart() + Num.GetImaginaryPart() * Num.GetImaginaryPart());

	return r;
}
