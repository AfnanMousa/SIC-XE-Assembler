#include <string>
#include "SymbolTable.h"
#include "Auxillary.h"
#include "Command.h"
#include "LegalFlagsCombinations.h"


std::string findADisplacement::execute(std::string address, symbolTable* tableObject) {
	legalFlagsCombinations* flags = flags->getInstance();
	string displacement;
	if ((*tableObject).getOperation().find('+') < (*tableObject).getOperation().size()) {
		//format4
		displacement = flags->getBPE(address) + address;
	}
	else displacement = format3(address, tableObject);
	return displacement;
}

std::string findADisplacement::format3(std::string address, symbolTable* tableObject) {
	transitions* t = new transitions();
	SYMTable* SymbolTab = SymbolTab->getInstance();
	legalFlagsCombinations* flags = flags->getInstance();
	string BPE;
	cout << "TA = " << address << "\t" << " PC of " << (*tableObject).getOperation() << " is " << (*tableObject).getNextAddress() << endl;
	std::string displacement = t->subtract(address, (*tableObject).getNextAddress(), 12);
	cout << "Displacement is " << displacement << endl;
	if (t->isOutOfRange(displacement)) {
		cout << "Will be Base" << endl;
		displacement = t->subtract(address, SymbolTab->getBASE(), 12);
		if (t->isOutOfRange(displacement)) {
			(*tableObject).setError(true);
		}
		else {
			BPE = flags->getBPE("Base");
		}
	}
	else {
		BPE = flags->getBPE("PC");
	}
	displacement = t->addZeroes(displacement, 12);
	cout << "After adding zeroes " << displacement << endl;

	displacement = BPE + displacement;
	return displacement;
}