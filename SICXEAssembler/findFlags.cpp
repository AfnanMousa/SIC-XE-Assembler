#include "Command.h"
#include "LegalFlagsCombinations.h"
#include "Auxillary.h"
#include <iostream>
#include <sstream>
#include "symbolTable.h"
#include "LocationsTable.h"

using namespace std;

findFlags::findFlags()
{

}

legalFlagsCombinations* l = l->getInstance();
transitions* t = new transitions();
string address;
string displacement;
SYMTable* table = table->getInstance();
bool forRef = false;
bool isLabel = false;
bool immediateAdd = false;
int Format;

string findFlags::execute(int format, symbolTable* tableObject) {
	string opCode;
	string NIX;
	string BPE;
	Format = format;
	ConvertHexaToBinary* toBin = new ConvertHexaToBinary();
	if (tableObject->getOperand().length() == 0) return "000000000000000000";
	NIX = findNiX((*tableObject).getOperand(), tableObject);
	if (forRef) return opCode + NIX;
	if (format == 3) {
			bool intermediate = t->subtractDec(address, (*tableObject).getNextAddress());//bta5od hexa
			if (immediateAdd) {
				displacement = toBin->hexaToBinary(address);
				BPE = l->getBPE("displacement");
			}
			else if ((intermediate)) {
				BPE = l->getBPE("Base");
				intermediate = t->subtractDec(address, table->getBASE());
				if (table->getBASE() != "") {
					string base = table->getLine(table->getBASE()).getAddress();
					displacement = t->subtract(address, (base), 12);
					//cout << toBin->hexaToBinary(base) << endl;
					if ((intermediate)) {
						table->getTable().at((*tableObject).getKey()).setError(true);
						table->getTable().at((*tableObject).getKey()).setErrorStr("Addressing Out Of Range");
						BPE = "000";
					}
				}
				else {
					table->getTable().at((*tableObject).getKey()).setError(true);
					table->getTable().at((*tableObject).getKey()).setErrorStr("Addressing Out Of Range And Base isn't specified");
					BPE = "000";
				}
			}
			else{
				BPE = l->getBPE("PC");
				displacement = t->subtract(address, (*tableObject).getNextAddress(), 12);
			}
			displacement = t->addZeroes(displacement, 12);
	}
	else if (format == 4) {
		BPE = l->getBPE("address");
		address = t->addZeroes(address, 5);
		displacement = toBin->hexaToBinary(address);
	}
	opCode = NIX + BPE+ displacement;
	return opCode;
}

string findFlags::findNiX(string operand,symbolTable* tableObject) {
	SYMTable* table = table->getInstance();
	string NIX;
	immediateAdd = false;
	if (operand.find("#") < operand.size()) {
		NIX = l->getNIX("immediate");
		operand = operand.substr(1, operand.size() - 1);
		if (operand.find_first_not_of("0123456789")) {
			ConvertHexaToBinary* toBin = new ConvertHexaToBinary();
			stringstream geek(operand);
			int x = 0;
			geek >> x;
			address = t->decToHexa(x);
			forRef = false;
			immediateAdd = true;
		}
		else {
			if (!table->isFound(operand)) {
				address = table->getLine(operand).getAddress();
				forRef = false;
			}
			else {
				forWRef(operand, tableObject);
			}
		}
		return NIX;
	}

	else if (operand.find("@") < operand.size()) {
		NIX = l->getNIX("indirect");
		operand = operand.substr(1, operand.size() - 1);
	}

	else if (operand.find(",") < operand.size()) {
		NIX = l->getNIX("directIndexing");
		operand = operand.substr(0, operand.find(","));
	}

	else {
		NIX = l->getNIX("directNoIndexing");
	}

	if (!table->isFound(operand)) {
		address = table->getLine(operand).getAddress();
		forRef = false;
	}
	else {
		forWRef(operand, tableObject);
		forRef = true;
	}
	return NIX;
}

string findFlags::forWRef(string operand, symbolTable* tableObject){
	Locations* lo = lo->getInstance();
	if (!lo->isFound(operand)) {
		LocationObject* ob = new LocationObject();
		ob->setStar("*");
		ob->addInVector((string)((*tableObject).getAddress()));
		if (operand.at(0) == '#' || operand.at(0) == '@') operand = operand.substr(1, operand.size() - 1);
		lo->addLocation(operand, *ob);
	}
	else if (operand.length() == 0)
		address = "000000000000";
	else {
		LocationObject ob = lo->getLabel(operand);
		if ((*tableObject).getAddress() == "A")
//			cout << "HERE" << endl;
		ob.getVector().push_back((*tableObject).getAddress());
		lo->getLabel(operand).linkedList.push_back((*tableObject).getAddress());
	}
	forRef = true;
	return l->getNIX("directNoIndexing");
}

findFlags::~findFlags()
{
	delete l;
	delete t;
	//delete r;
}
