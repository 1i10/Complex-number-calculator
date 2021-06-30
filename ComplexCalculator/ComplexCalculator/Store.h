#pragma once
#include <list>
#include "Calculator.h"

class Store
{
private:
	std::list<Calculator> ResultTable;
public:
	Store();
	std::list<Calculator> GetResultTable();
	void AddInTable(Calculator Note);
	void ClearTable();
};
