#include "FormatChecker.h"

FormatChecker::FormatChecker()
{
	//ctor -- i.e Constructor
	cout << "Format Object is being created" << endl;
	this->f2 = new Format2();
	this->f3 = new Format3();
	this->f4 = new Format4();
}

string FormatChecker::format2GenOpCode(symbolTable& ob) {
	return f2->generateOpCode(ob);
}

string FormatChecker::format3GenOpCode(symbolTable& ob) {
	return f3->generateOpCode(ob);
}

string FormatChecker::format4GenOpCode(symbolTable& ob) {
	return f4->generateOpCode(ob);
}

FormatChecker::~FormatChecker()
{
	//dtor -- i.e distructor
	cout << "Format Object is being deleted" << endl;
	delete this->f2;
	delete this->f3;
	delete this->f4;
}
