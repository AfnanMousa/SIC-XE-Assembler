#pragma once
#ifndef FORMAT_H
#define FORMAT_H

#include <iostream>

using namespace std;



class Format {

public:
	Format() = default;
	Format(string operation, string Operator);
	virtual ~Format() {}
	virtual string generateOpCode() = 0;
};

class Format2 : public Format {
private:
	string operation;
	string operand;
	string opCode = "";

public:
	Format2(string operation, string Operator);
	~Format2();
	string generateOpCode();
};

class Format3 : public Format {
private:
	string operation;
	string operand;
	string opCode = "";

public:
	Format3(string operation, string Operator);
	~Format3();
	string generateOpCode();
};

class Format4 : public Format {
private:
	string operation;
	string operand;
	string opCode = "";

public:
	Format4(string operation, string Operator);
	~Format4();
	string generateOpCode();
};

#endif // FORMAT_H
