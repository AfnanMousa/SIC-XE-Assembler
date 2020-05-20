#include "Command.h"
#include "LegalFlagsCombinations.h"
#include "Auxillary.h"
#include <iostream> 
#include <sstream> 
#include "symbolTable.h"

//using namespace std;

findFlags::findFlags()
{
	//ctor -- i.e Constructor
	cout << "Command findFlags Object is being created" << endl;
}

legalFlagsCombinations* l = l->getInstance();
transitions* t = new transitions();
string address;
string displacement;
SYMTable* table = table->getInstance();

string findFlags::execute(int format, symbolTable tableObject) {
	string opCode;
	string NIX;
	string BPE;
	cout << "executing findFlags " << endl;
	cout << "PC " << tableObject.getNextAddress() << endl;
	NIX = findNiX(tableObject.getOperand());

	if (format == 3) {
		//IF BASE LESSA
		string intermediate = t->subtract(address,tableObject.getNextAddress(),12);
		if (t->isOutOfRange(intermediate)) {
			BPE = l->getBPE("Base");
			cout << "OUT OF RANGE" << endl;
			intermediate = t->subtract(address,table->getBASE(),12);
			if (t->isOutOfRange(intermediate)) {
				tableObject.setError(true);
			}
		}
		else {
			BPE = l->getBPE("PC");
			displacement = intermediate;//should be binary
		}
		cout << "INTERMEDIATE " << intermediate << endl;
	}
	else if (format == 4) {
		BPE = l->getBPE("address");
		displacement = address;
	}
	opCode = NIX + BPE+ displacement;
	cout << "FROM FIND FLAGS THE OPCODE IS " << opCode << endl;
	// Your implementation
	return opCode;
}

string findFlags::findNiX(string operand) {
	SYMTable* table = table->getInstance();
	
	string NIX;
	if (operand.find("#") < operand.size()) {
		NIX = l->getNIX("immediate");
		operand = operand.substr(1, operand.size() - 1);
		stringstream geek(operand);
		int x = 0;
		geek >> x;
		address = t->decimalToBinary(x);
	}
	else if (operand.find("@") < operand.size()) {
		NIX = l->getNIX("indirect");
		operand = operand.substr(1, operand.size() - 1);
		address = table->getLine(operand).getAddress();
	}
	else if (operand.find(",") < operand.size()) {
		NIX = l->getNIX("directIndexing");
		operand = operand.substr(0, operand.find(","));
		address = table->getLine(operand).getAddress();
	}
	else {
		NIX = l->getNIX("directNoIndexing");
		address = table->getLine(operand).getAddress();
	}
	cout << "adress is " << address << endl;
	return NIX;
}

findFlags::~findFlags()
{
	//dtor -- i.e distructor
	cout << "Command findFlags Object is being deleted" << endl;
	delete l;
	delete t;
	//delete r;
}
