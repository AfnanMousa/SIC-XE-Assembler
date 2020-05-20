#include"Command.h"

calculateDisplacement::calculateDisplacement()
{
	//ctor -- i.e Constructor
	cout << "Command calculateDisplacement Object is being created" << endl;
}

string calculateDisplacement::execute(int format, string opCode, string operand) {
	cout << "executing calculateDisplacement" << endl;
	// Your implementation
	


	return opCode;
}

calculateDisplacement::~calculateDisplacement()
{
	//dtor -- i.e distructor
	cout << "Command calculateDisplacement Object is being deleted" << endl;
}
