#include <string>
#include "ComparisonOperation.h"

std::string ComparisonOperation::ComparisonResult(double ResultNum1, double ResultNum2)
{
    if (ResultNum1 > ResultNum2)
    {
        return std::to_string(ResultNum1) + " > " + std::to_string(ResultNum2);
    }
    else if (ResultNum1 < ResultNum2)
    {
        return std::to_string(ResultNum1) + " < " + std::to_string(ResultNum2);
    }
    else
    {
        return std::to_string(ResultNum1) + " == " + std::to_string(ResultNum2);
    }
}
