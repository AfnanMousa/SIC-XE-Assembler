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
	FormatChecker() = default;
	FormatChecker(string, string);
	~FormatChecker();
	string format2GenOpCode();
	string format3GenOpCode();
	string format4GenOpCode();

};

#endif // FORMATCHECKER_H