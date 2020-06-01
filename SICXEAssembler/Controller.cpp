#include "FormatChecker.h"
#include "symbolTable.h"
#include <iostream>
#include "StaticTables.h"
#include "Parsing.h"
#include "ReadFromFile.h"
#include "Auxillary.h"
#include "Command.h"
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>
#include <string>
#include <regex>
#include "Controller.h"
#include <iomanip>
#include <iostream>

ReadFromFile f;

void Controller::findOPCode (symbolTable& tableObject,int i){
	transitions* t = new transitions();
	string operation = (tableObject).getOperation();
	string operand = (tableObject).getOperand();
	static FormatChecker* f = new FormatChecker();
	static string opCode = "";
	Command* c = new findFlags();
	SYMTable* symbolMap = symbolMap->getInstance();
	StaticTables* st = st->getInstance();

	if(operation == "RSUB"){
		opCode = "4F0000";
	}
	else if (operation.find('+') < operation.size()) {
		opCode = f->format4GenOpCode(tableObject);
		opCode += c->execute(4, &tableObject);
		if (opCode.length() == 32)//Not forward ref
			opCode = t->convertBinToHex(opCode);
	}
	else if (st->occurrencesInFormat2(operation) > 0) {
		opCode = f->format2GenOpCode(tableObject);
		cout << opCode << endl;
	}
	else {
		opCode = f->format3GenOpCode(tableObject);
		opCode += c->execute(3, (&tableObject));
		(tableObject).setOpcode(opCode);
		if (opCode.length()==24)//Not forward ref
			opCode = t->convertBinToHex(opCode);
	}
	string key = tableObject.getLabel();
	if (tableObject.getLabel().length() == 0)  key = std::to_string(i);
	symbolMap->getTable().at(key).setOpcode(opCode);
}
