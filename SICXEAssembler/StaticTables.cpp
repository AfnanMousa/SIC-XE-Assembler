#include "StaticTables.h"

StaticTables::StaticTables() {
	fillingRegTable();
	fillingOperationTable();
	fillingKeyWordsTable();
}

static StaticTables* instance;

StaticTables* StaticTables::getInstance() {
	if (!instance) 
		instance = new StaticTables;
	return instance;
}

std::string StaticTables::getData(std::string key) {
	return this->operationTable.at(key);
}

int StaticTables::occurrencesInOPTable(std::string operation) {
	return operationTable.count(operation);
}

std::string* StaticTables::getKeyWords() {
	return keyWords;
}

bool StaticTables::regIsFound(std::string r) {
	return regTable.find(r) == regTable.end();
}

bool StaticTables::operationsIsFound(std::string r) {
	return operationTable.find(r) == operationTable.end();
}

void StaticTables::fillingRegTable() {
	regTable.insert({ "A",0 });
	regTable.insert({ "X",1 });
	regTable.insert({ "L",2 });
	regTable.insert({ "B",3 });
	regTable.insert({ "S",4 });
	regTable.insert({ "T",5 });
	regTable.insert({ "F",6 });
	regTable.insert({ "PC",8 });
	regTable.insert({ "SW",9 });
}

void StaticTables::fillingOperationTable() {
	operationTable.insert({ "SVC","B0" });
	operationTable.insert({ "SUBR","94" });
	operationTable.insert({ "TIXR","B8" });
	operationTable.insert({ "SHIFTL","A4" });
	operationTable.insert({ "SHIFTR","A8" });
	operationTable.insert({ "RMO","AC" });
	operationTable.insert({ "ADDR","90" });
	operationTable.insert({ "CLEAR","B4" });
	operationTable.insert({ "ADD","18" });
	operationTable.insert({ "+ADD","18" });
	operationTable.insert({ "ADDF","58" });
	operationTable.insert({ "AND","40" });
	operationTable.insert({ "+AND","40" });
	operationTable.insert({ "COMP","28" });
	operationTable.insert({ "+COMP","28" });
	operationTable.insert({ "COMPF","88" });
	operationTable.insert({ "COMPR","A0" });
	operationTable.insert({ "DIV","24" });
	operationTable.insert({ "+DIV","24" });
	operationTable.insert({ "DIVF","64" });
	operationTable.insert({ "DIVR","9C" });
	operationTable.insert({ "J","3C" });
	operationTable.insert({ "+J","3C" });
	operationTable.insert({ "JEQ","30" });
	operationTable.insert({ "+JEQ","30" });
	operationTable.insert({ "JGT","34" });
	operationTable.insert({ "+JGT","34" });
	operationTable.insert({ "JLT","38" });
	operationTable.insert({ "+JLT","38" });
	operationTable.insert({ "JSUB","48" });
	operationTable.insert({ "+JSUB","48" });
	operationTable.insert({ "LDA","00" });
	operationTable.insert({ "+LDA","00" });
	operationTable.insert({ "LDB","68" });
	operationTable.insert({ "LDCH","50" });
	operationTable.insert({ "LDCH+","50" });
	operationTable.insert({ "LDF","70" });
	operationTable.insert({ "LDL","08" });
	operationTable.insert({ "+LDL","08" });
	operationTable.insert({ "LDS","6C" });
	operationTable.insert({ "LDT","74" });
	operationTable.insert({ "LDX","04" });
	operationTable.insert({ "+LDX","04" });
	operationTable.insert({ "LPS","D0" });
	operationTable.insert({ "MUL","20" });
	operationTable.insert({ "+MUL","20" });
	operationTable.insert({ "MULF","60" });
	operationTable.insert({ "MULR","98" });
	operationTable.insert({ "OR","44" });
	operationTable.insert({ "+OR","44" });
	operationTable.insert({ "RD","D8" });
	operationTable.insert({ "+RD","D8" });
	operationTable.insert({ "RSUB","4C" });
	operationTable.insert({ "+RSUB","4C" });
	operationTable.insert({ "SSK","EC" });
	operationTable.insert({ "STA","0C" });
	operationTable.insert({ "+STA","0C" });
	operationTable.insert({ "STB","78" });
	operationTable.insert({ "STCH","54" });
	operationTable.insert({ "+STCH","54" });
	operationTable.insert({ "STF","80" });
	operationTable.insert({ "STI","D4" });
	operationTable.insert({ "STL","14" });
	operationTable.insert({ "+STL","14" });
	operationTable.insert({ "STS","7C" });
	operationTable.insert({ "STSW","E8" });
	operationTable.insert({ "+STSW","E8" });
	operationTable.insert({ "STT","84" });
	operationTable.insert({ "STX","10" });
	operationTable.insert({ "+STX","10" });
	operationTable.insert({ "SUB","1C" });
	operationTable.insert({ "+SUB","1C" });
	operationTable.insert({ "SUBF","5C" });
	operationTable.insert({ "TD","E0" });
	operationTable.insert({ "+TD","E0" });
	operationTable.insert({ "TIX","2C" });
	operationTable.insert({ "+TIX","2C" });
	operationTable.insert({ "WD","DC" });
	operationTable.insert({ "+WD","DC" });
}


void StaticTables::fillingKeyWordsTable() {
	keyWords[0] = "START";
	keyWords[1] = "RESW";
	keyWords[2] = "RESB";
	keyWords[3] = "BYTE";
	keyWords[4] = "WORD";
	keyWords[5] = "ORG";
	keyWords[6] = "EQU";
}


