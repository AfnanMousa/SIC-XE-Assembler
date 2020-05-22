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

ReadFromFile f;

void Controller::findOPCode (symbolTable& tableObject,int i){
	transitions* t = new transitions();
	cout << "\nPROCESSING" << endl;
	cout << tableObject.getAddress() << "    " << tableObject.getLabel() << "     " << tableObject.getOperation() << "      " << tableObject.getOperand() << "      " << tableObject.getOpcode() << endl;
	cout << "---------------------------------------------------" << endl;
	string operation = (tableObject).getOperation();
	string operand = (tableObject).getOperand();
	static FormatChecker* f = new FormatChecker();
	static string opCode = "";
	Command* c = new findFlags();
	SYMTable* symbolMap = symbolMap->getInstance();

	if (operation.find('+') < operation.size()) {
	//	opCode = f->format4GenOpCode();
	//	opCode += c->execute(4, tableObject);
	}
	else {
		opCode = f->format3GenOpCode(tableObject);
		//(tableObject).setOpcode(opCode);
		opCode += c->execute(3, (&tableObject));
		(tableObject).setOpcode(opCode);
		if (opCode.length()==24)//Not forward ref
			opCode = t->convertBinToHex(opCode);
	}
	cout << "OPCode is " << opCode << endl;

	cout << tableObject.getAddress() << "    " << tableObject.getLabel() << "     " << tableObject.getOperation() << "      " << tableObject.getOperand() << "      " << tableObject.getOpcode() << endl;
	string key = tableObject.getLabel();
	if (tableObject.getLabel().length() == 0)  key = std::to_string(i);
	symbolMap->getTable().at(key).setOpcode(opCode);
	//symbolMap->addLine(key, tableObject);

	cout << "---------------------------------------------------" << endl;
}