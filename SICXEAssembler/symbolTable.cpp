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

void symbolTable::setObjectCode(string objectCode)
{
	this->objectCode = objectCode;
}

void symbolTable::setError(bool err)
{
	this->error = err;
}

void symbolTable::setNextAddress(string nextAddress)
{
	this->nextAddress = nextAddress;
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

string symbolTable::getObjectCode()
{
	return objectCode;
}

string symbolTable::getNextAddress()
{
	return nextAddress;
}

bool symbolTable::getError()
{
	return error;
}

symbolTable::symbolTable()
{
}

symbolTable::~symbolTable()
{
}