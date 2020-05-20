#include "Format.h"
#include "StaticTables.h"
#include "Auxillary.h"

Format4::Format4(string operation, string Operator)
{
	//ctor -- i.e Constructor
	//cout << "Format4 Object is being created" << endl;
	this->operation = operation;
	this->operand = Operator;
}

string Format4::generateOpCode() {
	cout << "This is format 4" << endl;
	// Your implementation
	operation = operation.substr(1, operation.size() - 1);

	StaticTables* data = data->getInstance();
	transitions* t = new transitions();
	cout << data->getData(operation) << endl;
	string intermediate = t->hexaToBinary(data->getData(operation));
	intermediate = intermediate.substr(0, operation.size() - 3);
	opCode = opCode + intermediate;


	return opCode;
}

Format4::~Format4()
{
	//dtor -- i.e distructor
	cout << "Format4 Object is being deleted" << endl;
}
