#pragma once
#ifndef DYNAMICTABLES_H
#define DYNAMICTABLES_H
#include "StaticTables.h"
#include "MakeAddress.h"
#include <string>
#include <map>
using namespace std;
class DynamicTables
{
public:
	DynamicTables();
	symbolTable BuildDataTable(string& Label, string& Operation, string& Operand, string& address, string strings[3], int line_index);
	bool is_digits_of_Hexa(const std::string& str);
	bool is_digits(const std::string& str);
	void setting(string strings[3], int line_index, string& address);
	std::map<std::string, std::string> /*lableTable,*/ dataTable;
	MakeAddress makeAddress;
	symbolTable symbolTable;
	SYMTable* symbolMap = symbolMap->getInstance();
	StaticTables* statTables = statTables->getInstance();
protected:

private:
};

#endif // DYNAMICTABLES_H
