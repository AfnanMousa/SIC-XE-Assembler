#include "FormatChecker.h"

FormatChecker::FormatChecker(string operation, string Operator)
{
	//ctor -- i.e Constructor
	cout << "Format Object is being created" << endl;
	this->f2 = new Format2(operation, Operator);
	this->f3 = new Format3(operation, Operator);
	this->f4 = new Format4(operation, Operator);
}

string FormatChecker::format2GenOpCode() {
	return f2->generateOpCode();
}

string FormatChecker::format3GenOpCode() {
	return f3->generateOpCode();
}

string FormatChecker::format4GenOpCode() {
	return f4->generateOpCode();
}

FormatChecker::~FormatChecker()
{
	//dtor -- i.e distructor
	cout << "Format Object is being deleted" << endl;
	delete this->f2;
	delete this->f3;
	delete this->f4;
}
