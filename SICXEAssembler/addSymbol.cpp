#include <string>
#include <vector>
#include "Command.h"
#include "LocationsTable.h"
#include "symbolTable.h"
#include "Auxillary.h"

Locations* locations = locations->getInstance();
SYMTable* SymbolTab = SymbolTab->getInstance();

void forwRefFound::execute(std::string label, std::string address) {
	std::vector<std::string> tempV = locations->getLabel(label).getVector();
	for (int i = 0; i < tempV.size(); i++) {
		string key = locations->getsymbolLocations().at(tempV[i]);
		symbolTable symTab = SymbolTab->getLine(key);
		editOPCode((&symTab),address);
	}
	locations->eraseLocation(label);
}

void forwRefFound::editOPCode(symbolTable* symTab,std::string address) {
	string opCode = (*symTab).getOpcode();//operation OPCode + NIX
	findADisplacement* c = new findADisplacement();
	opCode = opCode + c->execute(address,symTab);
	transitions* t = new transitions();
	opCode = t->convertBinToHex(opCode);
	SymbolTab->getTable().at((*symTab).getKey()).setOpcode(opCode);
}
