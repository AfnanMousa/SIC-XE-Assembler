#include "Auxillary.h"
#include "SymbolTable.h"
#include "LocationsTable.h"

void Print::printSYMTABLE() {
	SYMTable* taable = taable->getInstance();
	std::map<std::string, symbolTable> table = taable->getTable();
	cout << "Symbol Table" << "\n";
	cout << "Key\tLocation\tLabel\tOperation\tOperand\tOPCode"<< "\n\n";
	for (const auto& x : table) {
		std::cout << x.first << ": ";
		symbolTable symbolMap = x.second;
		cout << symbolMap.getAddress() << "    " << symbolMap.getLabel() << "     " << symbolMap.getOperation() << "      " << symbolMap.getOperand() << "      " << symbolMap.getOpcode() << endl;
	}

	cout << "\n\n\n\n";
}

void Print::printAddressSymbolTable(){
	Locations* locations = locations->getInstance();
	std::map<std::string, std::string> table = locations->getsymbolLocations();
	cout << "Address Symbol Table" << "\n";
	cout << "Address\tSymbol" << "\n\n";
	for (const auto& x : table) 
		std::cout << x.first << " : "<< x.second << "\n";

	cout << "\n\n\n\n";
}

void Print::printForwardRefTable() {
	Locations* locations = locations->getInstance();
	std::map<std::string, LocationObject> table = locations->getLocationsTable();

	cout << "Forward Refrencing Table" << "\n";
	cout << "Symbol\tLinked List" << "\n\n";
	for (const auto& x : table) {
		std::cout << x.first << ": ";
		LocationObject  vect = x.second;
		vector<string> vector = vect.getVector();
		for (std::vector<string>::const_iterator i = vector.begin(); i != vector.end(); ++i)
			std::cout << *i << ' ';
		cout << "\n";
	}

	cout << "\n\n\n\n";
}