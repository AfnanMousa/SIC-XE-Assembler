#include "Format.h"
#include "StaticTables.h"
#include "Auxillary.h"

Format3::Format3()
{
}

string Format3::generateOpCode(symbolTable& ob) {
	string operation = ob.getOperation();
	string operand = ob.getOperand();
	string opCode;
	StaticTables* data = data->getInstance();
	ConvertHexaToBinary* toBin = new ConvertHexaToBinary();
	opCode = toBin->hexaToBinary(data->getData(operation));
	opCode = opCode.substr(0, opCode.size() - 2);;
	return opCode;
}

Format3::~Format3()
{
}
