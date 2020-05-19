#include <iostream>
#include<string>
#include <math.h>
#include <map>

#define ll long long
#define SPACE " "
#define nLINE '\n'

using namespace std;


//#include "FormatChecker.h"
#include "Command.h"
#include "StaticTables.h"
#include "FormatChecker.h"

int main(void)
{
	string operation = "+LDA";
	string operand = "#0";
	FormatChecker* f = new FormatChecker(operation, operand);
	cout << operation.find('+') << SPACE << operation.size() << nLINE;
	if (operation.find('+') < operation.size()) {
		f->format4GenOpCode();
	}
	
/*
	Command* c1 = new toHexa();
	c1->execute();
	delete c1;

	Command* c2 = new calculateDisplacement();
	c2->execute();
	delete c2;

	Command* c3 = new findFlags();
	c3->execute();
	delete c3;
*/
	return 0;
}
