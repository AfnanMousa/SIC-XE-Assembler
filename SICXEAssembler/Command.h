#pragma once
#ifndef COMMAND_H
#define COMMAND_H


#include <iostream>
#include "LegalFlagsCombinations.h"

using namespace std;


class Command
{
public:
	Command() {}
	virtual ~Command() {}
	virtual string execute(int format, string opCode, string operand) = 0;
};

class calculateDisplacement : public Command {
public:
	calculateDisplacement();
	~calculateDisplacement();
	string execute(int format, string opCode, string operand);

};

class findFlags : public Command {
public:
	findFlags();
	~findFlags();
	string execute(int format, string opCode,string operand);

};

class toHexa : public Command{
public:
	toHexa();
	~toHexa();
	string execute(int format, string opCode, string operand);

};

#endif // COMMAND_H
