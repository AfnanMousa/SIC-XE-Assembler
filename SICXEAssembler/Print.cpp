#include "Auxillary.h"
#include "SymbolTable.h"
#include "LocationsTable.h"
#include <iomanip>
#include <iostream>

void Print::printSYMTABLE() {
	SYMTable* taable = taable->getInstance();
	std::map<std::string, symbolTable> table = taable->getTable();
	vector<string> keys = taable->getKeys();
	for (int i = 0;i < keys.size();i++) {
		symbolTable symbolMap = taable->getLine(keys.at(i));
		cout << std::left;
		cout << setw(10)<< symbolMap.getAddress() << setw(10)<< symbolMap.getLabel() <<  setw(10) << symbolMap.getOperation() << setw(10) << symbolMap.getOperand() << setw(30) << symbolMap.getOpcode() << setw(15)<<endl;
        if (symbolMap.getError()==true){
            cout << symbolMap.getErrorStr()<<endl;
        }
	}
}

void Print::printAddressSymbolTable(){
	Locations* locations = locations->getInstance();
	std::map<std::string, std::string> table = locations->getsymbolLocations();
	cout << "Address Symbol Table" << "\n";
	for (const auto& x : table)
        if (!is_digits(x.second ))
		std::cout << x.first << " : "<< x.second << "\n";
}

void Print::printForwardRefTable() {
	Locations* locations = locations->getInstance();
	std::map<std::string, LocationObject> table = locations->getLocationsTable();
	for (const auto& x : table) {
		LocationObject  vect = x.second;
		vector<string> vector = vect.getVector();
	}
}
bool Print::is_digits(const std::string& str) {
	return str.find_first_not_of("0123456789") == std::string::npos;
}
