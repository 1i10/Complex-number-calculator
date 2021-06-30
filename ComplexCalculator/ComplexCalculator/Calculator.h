#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "ComplexNumber.h"

class Calculator
{
private:
	std::string Result;
	std::string Expression;
public:
	Calculator();
	void SetResult(std::string Res);
	void SetExpression(std::string Expr);
	std::string GetResult();
	std::string GetExpression();
	char GetOperationFromExpression();//получить операцию между двумя комплексными числами
	std::vector <ComplexNumber> GetComplexNumbersFromExpression();//получить комплексные числа из выражения
};
