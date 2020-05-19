#include "symbolTable.h"

static SYMTable* instance;

SYMTable* SYMTable::getInstance() {
	if (!instance)
		instance = new SYMTable;
	return instance;
}

symbolTable* SYMTable::getLine(string index) {
	return SYMPOLTable.at(index);
}

void SYMTable::addLine(string i, symbolTable* line) {
	SYMPOLTable.insert({i,line});
}
