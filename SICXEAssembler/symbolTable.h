#pragma once
#pragma once
#include <string>
#include <map>
using namespace std;


#include "symbolTable.h"

class SYMTable {
private:
	SYMTable() {}
	~SYMTable() {}
	std::map<string,symbolTable*> SYMPOLTable;

public:
	static SYMTable* getInstance();
	symbolTable* getLine(string);
	void addLine(string ,symbolTable*);
};


class symbolTable
{
private:
	string address;
	string label;
	string opcode;
	string operand;
	string objectCode;
	string nextAddress;
	bool error;

public:
	void setAddress(string address);
	void setLabel(string label);
	void setOpcode(string opcode);
	void setOperand(string operand);
	void setObjectCode(string objectCode);
	void setError(bool err);
	void setNextAddress(string address);
	string getAddress();
	string getLabel();
	string getOpcode();
	string getOperand();
	string getObjectCode();
	string getNextAddress();
	bool getError();



	symbolTable();
	~symbolTable();
};