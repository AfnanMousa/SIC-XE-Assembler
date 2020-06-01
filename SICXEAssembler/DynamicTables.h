#pragma once
#ifndef DYNAMICTABLES_H
#define DYNAMICTABLES_H
#include "StaticTables.h"
#include "MakeAddress.h"
#include "symbolTable.h"
#include <string>
#include <map>
using namespace std;
class DynamicTables
{
public:
	DynamicTables();
	static DynamicTables* getInstance();
	symbolTable& BuildDataTable(string& Label, string& Operation, string& Operand, string& address, string strings[3], int line_index,bool error, string errorStr);
	bool is_digits_of_Hexa(const std::string& str);
	bool is_digits(const std::string& str);
	bool is_Aphabet(const std::string& str);
	symbolTable* setting(string strings[3], int line_index, string& address,bool error, string errorStr);
	std::map<std::string, std::string> /*lableTable,*/ dataTable;
	int extractOperands(string& operand);
    string  evaluateExp (string& Operand,bool error, string errorStr);
    void  split (string operand,vector<string>& operands,char op);
	MakeAddress makeAddress;
	//symbolTable symbolTable;
	vector<vector<string>> EquTable;
	symbolTable* sym = new symbolTable();
	SYMTable* symbolMap = symbolMap->getInstance();
	StaticTables* statTables = statTables->getInstance();
	string labelstart = "";
protected:

private:
};

#endif // DYNAMICTABLES_H
