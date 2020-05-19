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
	void format2GenOpCode();
	void format3GenOpCode();
	void format4GenOpCode();

};

#endif // FORMATCHECKER_H