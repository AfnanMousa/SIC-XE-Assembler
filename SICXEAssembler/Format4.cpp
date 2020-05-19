#include "Format.h"
#include "StaticTables.h"

Format4::Format4(string operation, string Operator)
{
	//ctor -- i.e Constructor
	cout << "Format4 Object is being created" << endl;
	this->operation = operation;
	this->operand = Operator;
}

string Format4::generateOpCode() {
	cout << "This is format 4" << endl;
	// Your implementation
	operation = operation.substr(1, operation.size() - 1);

	StaticTables* data = data->getInstance();
	cout << data->getData(operation) << endl;
	opCode = opCode + data->getData(operation);

	return opCode;
}

Format4::~Format4()
{
	//dtor -- i.e distructor
	cout << "Format4 Object is being deleted" << endl;
}
