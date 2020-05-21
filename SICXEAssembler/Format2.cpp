#include "Format.h"
#include "StaticTables.h"
#include "Auxillary.h"

Format2::Format2()
{
	//ctor -- i.e Constructor
	//cout << "Format2 Object is being created" << endl;
}

string Format2::generateOpCode(symbolTable& ob) {
	cout << "This is format 2" << endl;
	// Your implementation
	string operation = ob.getOperation();
	string operand = ob.getOperand();
	string opCode;

	StaticTables* data = data->getInstance();
	transitions* t = new transitions();
	cout << data->getData(operation) << endl;
	string intermediate = t->hexaToBinary(data->getData(operation));
	opCode = opCode + intermediate;

	return opCode;
}

Format2::~Format2()
{
	//dtor -- i.e distructor
	cout << "Format2 Object is being deleted" << endl;
}
