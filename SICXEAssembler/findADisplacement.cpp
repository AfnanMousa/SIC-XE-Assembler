#include <string>
#include "SymbolTable.h"
#include "Auxillary.h"
#include "Command.h"
#include "LegalFlagsCombinations.h"


std::string findADisplacement::execute(std::string address, symbolTable* tableObject) {
	legalFlagsCombinations* flags = flags->getInstance();
	ConvertHexaToBinary* toBin = new ConvertHexaToBinary();
	string displacement;
	if ((*tableObject).getOperation().find('+') < (*tableObject).getOperation().size()) {
		//format4
		address = toBin->hexaToBinary(address);
		transitions* t = new transitions();
		address = t->addZeroes(address,20);
		displacement = (flags->getBPE("address")) + address;
	}
	else displacement = format3(address, tableObject);
	return displacement;
}

std::string findADisplacement::format3(std::string address, symbolTable* tableObject) {
	transitions* t = new transitions();
	SYMTable* SymbolTab = SymbolTab->getInstance();
	legalFlagsCombinations* flags = flags->getInstance();
	string BPE;
	std::string displacement = t->subtract(address, (*tableObject).getNextAddress(), 12);
	if (t->subtractDec(address, (*tableObject).getNextAddress())) {
		displacement = t->subtract(address, SymbolTab->getBASE(), 12);
		if (t->subtractDec(address, (*tableObject).getNextAddress())) {
			SymbolTab->getTable().at((*tableObject).getKey()).setError(true);
			SymbolTab->getTable().at((*tableObject).getKey()).setErrorStr("Addressing Out Of Range");
		}
		else {
			BPE = flags->getBPE("Base");
		}
	}
	else {
		BPE = flags->getBPE("PC");
	}
	displacement = t->addZeroes(displacement, 12);

	displacement = BPE + displacement;
	return displacement;
}
