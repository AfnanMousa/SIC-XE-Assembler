#pragma once
#ifndef COMMAND_H
#define COMMAND_H


#include <iostream>
#include "LegalFlagsCombinations.h"
#include "symbolTable.h"

using namespace std;


class Command
{
public:
	Command() {}
	virtual ~Command() {}
	virtual string execute(int format, symbolTable*) = 0;
};

class findFlags : public Command {
private:
	string findNiX(string,symbolTable*);
	string forWRef(string operand, symbolTable* tableObject);
public:
	findFlags();
	~findFlags();
	string execute(int, symbolTable*);

};

class findADisplacement {
public:
	findADisplacement() {}
	virtual ~findADisplacement() {}
	std::string execute(string,symbolTable*);

private:
	std::string format3(string,symbolTable*);
};

class forwRefFound {
private: 
	void editOPCode(symbolTable*,string);

public:
	forwRefFound() {}
	virtual ~forwRefFound() {}
	void execute(string,string);
};
#endif // COMMAND_H
