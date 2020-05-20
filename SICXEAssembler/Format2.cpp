#include "Format.h"
#include "StaticTables.h"
#include "Auxillary.h"

Format2::Format2(string operation, string Operator)
{
	//ctor -- i.e Constructor
	//cout << "Format2 Object is being created" << endl;
	this->operation = operation;
	this->operand = operand;
}

string Format2::generateOpCode() {
	cout << "This is format 2" << endl;
	// Your implementation

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
