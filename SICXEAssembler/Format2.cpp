#include "Format.h"
#include "StaticTables.h"
#include "Auxillary.h"

Format2::Format2()
{
}

string Format2::generateOpCode(symbolTable& ob) {
	cout << "This is format 2" << endl;
	string operation = ob.getOperation();
	string operand = ob.getOperand();
	string opCode = "";
	ConvertHexaToBinary* toBin = new ConvertHexaToBinary();
	StaticTables* data = data->getInstance();
	cout << data->getFormat2Data(operation) << endl;
	string intermediate = (data->getFormat2Data(operation));
	cout << "Intermediate " << intermediate << endl;
	opCode = opCode + intermediate;
	cout << "From format 2 the opcode is " << endl;
	if (operand.find(",") < operand.length()) {
		string temp = operand;
		std::string op1 = operand.substr(0, operand.find(","));
		std::string op2 = operand = operand.substr(operand.find(",") + 1, operand.length());
		opCode += data->getReg(op1);
		opCode += data->getReg(op2);
	}
	else {
		opCode += data->getReg(operand);
		opCode += "0";
	}
	return opCode;
}

Format2::~Format2()
{
	//dtor -- i.e distructor
//	cout << "Format2 Object is being deleted" << endl;
}
