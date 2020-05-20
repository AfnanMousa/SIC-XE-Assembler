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
#include <regex>
#include "Controller.h"

ReadFromFile f;

void Controller::findOPCode (symbolTable tableObject){
	string operation = tableObject.getOperation();
	string operand = tableObject.getOperand();
	static FormatChecker* f = new FormatChecker(operation, operand);
	static string opCode = "";
	Command* c = new findFlags();

	if (operation.find('+') < operation.size()) {
		opCode = f->format4GenOpCode();
		opCode += c->execute(4, tableObject);
	}
	else {
		opCode = f->format3GenOpCode();
		opCode += c->execute(3, tableObject);
	}
	tableObject.setOpcode(opCode);
}