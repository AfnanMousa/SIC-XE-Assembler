#include "symbolTable.h"


void symbolTable::setAddress(string address)
{
	this->address = address;
}

void symbolTable::setLabel(string label)
{
	this->label = label;
}

void symbolTable::setOpcode(string opcode)
{
	this->opcode = opcode;
}

void symbolTable::setOperand(string operand)
{
	this->operand = operand;
}

void symbolTable::setOperation(string operation)
{
	this->operation = operation;
}

void symbolTable::setKey(string objectCode)
{
	this->key = objectCode;
}

void symbolTable::setType(string Type)
{
	this->type = Type;
}
void symbolTable::setError(bool err)
{
	this->error = err;
}

void symbolTable::setNextAddress(string nextAddress)
{
	this->nextAddress = nextAddress;
}

void symbolTable::setErrorStr(string errorStr){
    this->errorStr = errorStr;
}
string symbolTable::getAddress()
{
	return address;
}

string symbolTable::getLabel()
{
	return label;
}

string symbolTable::getOpcode()
{
	return opcode;
}

string symbolTable::getOperand()
{
	return operand;
}

string symbolTable::getOperation()
{
	return operation;
}

string symbolTable::getKey()
{
	return key;
}

string symbolTable::getNextAddress()
{
	return nextAddress;
}

string symbolTable::getType()
{
	return  type;
}

string symbolTable::getErrorStr()
{
	return  errorStr;
}

bool symbolTable::getError()
{
	return error;
}

symbolTable::symbolTable()
{
	address = "";
	label = "";
	opcode = "";
	operand = "";
	key = "";
	nextAddress = "";
	operation = "";
	type = "";
	error = false;
}

symbolTable::~symbolTable()
{
}
