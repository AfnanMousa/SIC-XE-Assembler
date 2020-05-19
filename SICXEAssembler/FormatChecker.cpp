#include "FormatChecker.h"

FormatChecker::FormatChecker(string operation, string Operator)
{
	//ctor -- i.e Constructor
	cout << "Format Object is being created" << endl;
	this->f2 = new Format2(operation, Operator);
	this->f3 = new Format3(operation, Operator);
	this->f4 = new Format4(operation, Operator);
}

void FormatChecker::format2GenOpCode() {
	f2->generateOpCode();
}

void FormatChecker::format3GenOpCode() {
	f3->generateOpCode();
}

void FormatChecker::format4GenOpCode() {
	f4->generateOpCode();
}

FormatChecker::~FormatChecker()
{
	//dtor -- i.e distructor
	cout << "Format Object is being deleted" << endl;
	delete this->f2;
	delete this->f3;
	delete this->f4;
}
