#include "Store.h"

Store::Store()
{
	Calculator Start;
	this->ResultTable.push_front(Start);
}

std::list<Calculator> Store::GetResultTable()
{
	return this->ResultTable;
}

void Store::AddInTable(Calculator Note)
{
	this->ResultTable.push_front(Note);
}

void Store::ClearTable()
{
	this->ResultTable.clear();
}
