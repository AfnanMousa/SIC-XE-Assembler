#pragma once
#ifndef FORMAT_H
#define FORMAT_H

#include <iostream>
#include "symbolTable.h"

using namespace std;



class Format {

public:
	Format() {}
	virtual ~Format() {}
	virtual string generateOpCode(symbolTable&) = 0;
};

class Format2 : public Format {

public:
	Format2();
	~Format2();
	string generateOpCode(symbolTable&);
};

class Format3 : public Format {

public:
	Format3();
	~Format3();
	string generateOpCode(symbolTable&);
};

class Format4 : public Format {

public:
	Format4();
	~Format4();
	string generateOpCode(symbolTable&);
};

#endif // FORMAT_H
