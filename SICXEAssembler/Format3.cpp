#include "Format.h"

Format3::Format3(string operation, string Operator)
{
	//ctor -- i.e Constructor
	cout << "Format3 Object is being created" << endl;
	this->operation = operation;
	this->operand = operand;
}

string Format3::generateOpCode() {
	cout << "This is format 3" << endl;
	// Your implementation
	return opCode;
}

Format3::~Format3()
{
	//dtor -- i.e distructor
	cout << "Format3 Object is being deleted" << endl;
}
