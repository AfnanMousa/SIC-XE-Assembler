#pragma once
#include <string>
#include <map>
using namespace std;


#include "symbolTable.h"


class symbolTable
{
private:
	string address;
	string label;
	string opcode;
	string operand;
	string key;
	string nextAddress;
	string operation;
	bool error;

public:
	void setAddress(string address);
	void setLabel(string label);
	void setOpcode(string opcode);
	void setOperand(string operand);
	void setOperation(string operand);
	void setKey(string objectCode);
	void setError(bool err);
	void setNextAddress(string address);
	string getAddress();
	string getLabel();
	string getOpcode();
	string getOperand();
	string getOperation();
	string getKey();
	string getNextAddress();
	bool getError();



	symbolTable();
	~symbolTable();
};

class SYMTable {
private:
	SYMTable() {}
	virtual ~SYMTable() {}
	std::string BASE;
	std::map<std::string, symbolTable> SYMPOLTable;

public:
	static SYMTable* getInstance();
	symbolTable getLine(string);
	void addLine(string, symbolTable);
	bool isFound(string);
	int occurrences(string);
	void setBASE(string);
	std::string getBASE();
	std::map<std::string, symbolTable>& getTable();
};

