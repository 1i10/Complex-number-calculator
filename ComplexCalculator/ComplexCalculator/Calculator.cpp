#include "Calculator.h"

Calculator::Calculator()
{
	this->Result = "0";
	this->Expression = "???";
}

void Calculator::SetResult(std::string Res)
{
	this->Result = Res;
}

void Calculator::SetExpression(std::string Expr)
{
	this->Expression = Expr;
}

std::string Calculator::GetResult()
{
	return this->Result;
}

std::string Calculator::GetExpression()
{
	return this->Expression;
}

char Calculator::GetOperationFromExpression()
{
	int i = 0;
	while (this->Expression[i] != ')')
	{
		i++;
	}

	return this->Expression[i + 1];
}

std::vector<ComplexNumber> Calculator::GetComplexNumbersFromExpression()
{
	std::vector<ComplexNumber> Temp;
	ComplexNumber Num;
	std::string Part;

	for (unsigned int i = 0; i < this->Expression.size(); i++)
	{
		if (this->Expression[i] == '(')
		{
			Part = "";
			i++;
			if (this->Expression[i] == '-')
			{
				Part = "-";
				i++;
			}
			while (this->Expression[i] != '+' && this->Expression[i] != '-')
			{
				Part += this->Expression[i];
				i++;
			}
			Num.SetRealPart(stod(Part));
			Part = "";
			if (this->Expression[i] == '+')
			{
				i++;
			}
			while (this->Expression[i] != 'i')
			{
				Part += this->Expression[i];
				i++;
			}

			Num.SetImaginaryPart(stod(Part));
			Temp.push_back(Num);
		}
	}

	return Temp;
}
