#pragma once
#include <iostream>
class ComplexNumber
{
private:
	double RealPart;
	double ImaginaryPart;
public:
	ComplexNumber();
	ComplexNumber(double Part1, double Part2);
	double GetRealPart();
	double GetImaginaryPart();
	void SetRealPart(double Part1);
	void SetImaginaryPart(double Part2);
	std::string ConvertComplexNumberToString();//конвертировать комплексное число класса ComplexNumber в строку
	ComplexNumber operator+(const ComplexNumber Num);
	ComplexNumber operator-(const ComplexNumber Num);
	ComplexNumber operator*(const ComplexNumber Num);
	ComplexNumber operator/(const ComplexNumber Num);
};