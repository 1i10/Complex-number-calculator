#include "ComplexNumber.h"
#include <string>

ComplexNumber::ComplexNumber()
{
	this->RealPart = 0;
	this->ImaginaryPart = 0;
}

ComplexNumber::ComplexNumber(double Part1, double Part2)
{
	this->RealPart = Part1;
	this->ImaginaryPart = Part2;
}

double ComplexNumber::GetRealPart()
{
	return this->RealPart;
}

double ComplexNumber::GetImaginaryPart()
{
	return this->ImaginaryPart;
}

void ComplexNumber::SetRealPart(double Part1)
{
	this->RealPart = Part1;
}

void ComplexNumber::SetImaginaryPart(double Part2)
{
	this->ImaginaryPart = Part2;
}

std::string ComplexNumber::ConvertComplexNumberToString()
{
	std::string Temp1 = std::to_string(this->RealPart);
	//убираем лишние нули после запятой
	Temp1.erase(Temp1.find_last_not_of('0') + 1, std::string::npos);
	Temp1.erase(Temp1.find_last_not_of('.') + 1, std::string::npos);//если в конце останется точка
	std::string Temp2 = std::to_string(this->ImaginaryPart);
	Temp2.erase(Temp2.find_last_not_of('0') + 1, std::string::npos);
	Temp2.erase(Temp2.find_last_not_of('.') + 1, std::string::npos);

	if (this->ImaginaryPart < 0)
	{
		return Temp1 + Temp2 + "i";
	}
	return Temp1 + "+" + Temp2 + "i";
}


ComplexNumber ComplexNumber::operator+(const ComplexNumber Num)
{
	double Real = this->RealPart + Num.RealPart;
	double Imag = this->ImaginaryPart + Num.ImaginaryPart;

	ComplexNumber Temp(Real, Imag);

	return Temp;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber Num)
{
	double Real = this->RealPart - Num.RealPart;
	double Imag = this->ImaginaryPart - Num.ImaginaryPart;

	ComplexNumber Temp(Real, Imag);

	return Temp;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber Num)
{
	double Real = this->RealPart * Num.RealPart - this->ImaginaryPart * Num.ImaginaryPart;
	double Imag = this->RealPart * Num.ImaginaryPart + this->ImaginaryPart * Num.RealPart;

	ComplexNumber Temp(Real, Imag);

	return Temp;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber Num)
{
	double Denominator = Num.RealPart * Num.RealPart + Num.ImaginaryPart * Num.ImaginaryPart;

	double Real = (this->RealPart * Num.RealPart + this->ImaginaryPart * Num.ImaginaryPart) / Denominator;
	double Imag = (this->ImaginaryPart * Num.RealPart - this->RealPart * Num.ImaginaryPart) / Denominator;

	ComplexNumber Temp(Real, Imag);

	return Temp;
}