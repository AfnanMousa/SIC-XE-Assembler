#include "Format.h"
#include "StaticTables.h"
#include "Auxillary.h"

Format4::Format4()
{
}

string Format4::generateOpCode(symbolTable& ob) {
	string operation = ob.getOperation();
	string operand = ob.getOperand();
	string opCode = "";
	StaticTables* data = data->getInstance();
	ConvertHexaToBinary* toBin = new ConvertHexaToBinary();
	string intermediate = toBin->hexaToBinary(data->getData(operation));
	intermediate = intermediate.substr(0, intermediate.size() - 2);
	opCode = opCode + intermediate;
	return opCode;
}

Format4::~Format4()
{
}
