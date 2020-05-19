#include "Format.h"

Format2::Format2(string operation, string Operator)
{
	//ctor -- i.e Constructor
	cout << "Format2 Object is being created" << endl;
	this->operation = operation;
	this->operand = operand;
}

string Format2::generateOpCode() {
	cout << "This is format 2" << endl;
	// Your implementation
	return opCode;
}

Format2::~Format2()
{
	//dtor -- i.e distructor
	cout << "Format2 Object is being deleted" << endl;
}
