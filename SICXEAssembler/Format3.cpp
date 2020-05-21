#include "Format.h"
#include "StaticTables.h"
#include "Auxillary.h"

Format3::Format3()
{
	//ctor -- i.e Constructor
	//cout << "Format3 Object is being created" << endl;
}

string Format3::generateOpCode(symbolTable& ob) {
	string operation = ob.getOperation();
	string operand = ob.getOperand();
	string opCode;
	cout << "\n\n" << "************" << endl;
	cout << "This is format 3" << endl;
	// Your implementation

	StaticTables* data = data->getInstance();
	ConvertHexaToBinary* toBin = new ConvertHexaToBinary();
	opCode = toBin->hexaToBinary(data->getData(operation));
	 
	cout << "OPCODE IN HEXA " << data->getData(operation)  <<  " IN BINARY " <<opCode;
	opCode = opCode.substr(0, opCode.size() - 2);;
	cout << " AFTER SUBSTRING " << opCode << endl;
	cout << "end of format 3" << endl;
	cout << "************" << "\n\n";
	return opCode;
}

Format3::~Format3()
{
	//dtor -- i.e distructor
	cout << "Format3 Object is being deleted" << endl;
}
