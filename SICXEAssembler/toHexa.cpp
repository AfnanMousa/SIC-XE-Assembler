#include "Command.h"

toHexa::toHexa()
{
	//ctor -- i.e Constructor
	cout << "Command toHexa Object is being created" << endl;
}

string toHexa::execute(int format, string opCode, string operand) {
	cout << "executing toHexa" << endl;
	// Your implementation
	return opCode;
}

toHexa::~toHexa()
{
	//dtor -- i.e distructor
	cout << "Command toHexa Object is being deleted" << endl;
}
