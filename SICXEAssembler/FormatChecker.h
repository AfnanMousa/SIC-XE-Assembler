#pragma once
#ifndef FORMATCHECKER_H
#define FORMATCHECKER_H

#include <iostream>
#include "Format.h"

using namespace std;

class FormatChecker {
private:
	Format* f2;
	Format* f3;
	Format* f4;
	string operation;
	string operand;

public:
	FormatChecker();
	~FormatChecker();
	string format2GenOpCode(symbolTable&);
	string format3GenOpCode(symbolTable&);
	string format4GenOpCode(symbolTable&);

};

#endif // FORMATCHECKER_H