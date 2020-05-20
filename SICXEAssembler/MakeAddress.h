#pragma once
#ifndef MAKEADDRESS_H
#define MAKEADDRESS_H
#include "symbolTable.h"
#include <string>

class MakeAddress
{
public:
	MakeAddress();
	std::string LocationCounter(std::string Operation, std::string Operand);
	bool equalIgnoreCase(std::string str1, std::string str2);
	bool checkIfHexa(string str);
	SYMTable* symbolMap = symbolMap->getInstance();
	int LOC;

protected:

private:

};

#endif // MAKEADDRESS_H
