#include "symbolTable.h"
#include <iostream>

static SYMTable* instance;

SYMTable* SYMTable::getInstance() {
	if (!instance)
		instance = new SYMTable;
	return instance;
}

symbolTable SYMTable::getLine(string index) {
	return SYMPOLTable.at(index);
}

void SYMTable::addLine(string i, symbolTable line) {
	SYMPOLTable.insert({i,line});
}

bool SYMTable::isFound(string label) {
	return SYMPOLTable.find(label) == SYMPOLTable.end();
}

int SYMTable::occurrences(string operand) {
	return SYMPOLTable.count(operand);
}

void SYMTable::setBASE(string base) {
	this->BASE = base;
}

string SYMTable::getBASE() {
	return this->BASE;
}

std::map<std::string, symbolTable> SYMTable::getTable() {
	return SYMPOLTable;
}
