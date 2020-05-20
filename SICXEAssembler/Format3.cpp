#include "Format.h"
#include "StaticTables.h"
#include "Auxillary.h"

Format3::Format3(string operation, string Operator)
{
	//ctor -- i.e Constructor
	//cout << "Format3 Object is being created" << endl;
	this->operation = operation;
	this->operand = operand;
}

string Format3::generateOpCode() {
	cout << "This is format 3" << endl;
	// Your implementation

	StaticTables* data = data->getInstance();
	transitions* t = new transitions();
	cout << data->getData(operation) << endl;
	string intermediate = t->hexaToBinary(data->getData(operation));
	intermediate = intermediate.substr(0, operation.size() - 3);
	opCode = opCode + intermediate;

	return opCode;
}

Format3::~Format3()
{
	//dtor -- i.e distructor
	cout << "Format3 Object is being deleted" << endl;
}
