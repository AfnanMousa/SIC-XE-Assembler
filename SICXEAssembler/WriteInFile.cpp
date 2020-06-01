#include "ReadFromFile.h"
#include "ObjectProgram.h"
#include "LocationsTable.h"

#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

bool error = false;

void WriteInFile::write() {
	ofstream outfile;
	outfile.open("Object Program.txt");

	cout << "Writing to the file" << endl;

	if (error) {
		outfile << "There is an error in your program please check the intermediate file for more details " << endl;
		return;
	}
	string out;
	// write inputted data into the file.
	objectProgram* ob = new objectProgram();
	ob->fillVectors();
	out = ob->createHeader()+"\n";
	vector<string> v = ob->createText();
	for (int j = 0;j < v.size();j++)
		out+= (v[j]+"\n");
	out += (ob->createEnd()+"\n");

	outfile << out;
	outfile.close();
}

void WriteInFile::writeTable() {
	Locations* locations = locations->getInstance();
	ofstream outfile;
	SYMTable* taable = taable->getInstance();
	outfile.open("IntermediateFile.txt");

	cout << "Writing to the file" << endl;

	std::map<std::string, LocationObject> ltable = locations->getLocationsTable();
	std::map<std::string, std::string> Atable = locations->getsymbolLocations();
	if (ltable.size() > 0) {
		outfile << "Error : Undefeined Operands " << "\n";
		for (const auto& x : ltable) {
			outfile << "(" << x.first << ") at lines : ";
			LocationObject  vect = x.second;
			vector<string> vector = vect.getVector();
			for (std::vector<string>::const_iterator i = vector.begin(); i != vector.end(); ++i) {
				string key = locations->getsymbolLocations().at(*i);
				symbolTable symTab = taable->getLine(key);
				taable->getTable().at((symTab).getKey()).setError(true);
				taable->getTable().at((symTab).getKey()).setErrorStr("****** Undefined Operand");
				outfile << Atable.at(*i) << "\t";
			}
			outfile << "\n";
		}
	}


	// write inputted data into the file.

	std::map<std::string, symbolTable> table = taable->getTable();
	vector<string> keys = taable->getKeys();
	outfile << "\n\n\nSymbol table with Object Codes" << endl;
	for (int i = 0;i < keys.size();i++) {
		symbolTable symbolMap = taable->getLine(keys.at(i));
		outfile << std::left;
		outfile << setw(10) << symbolMap.getAddress() << setw(10) << symbolMap.getLabel() << setw(10) << symbolMap.getOperation() << setw(10) << symbolMap.getOperand() << setw(30) << symbolMap.getOpcode() << setw(15) << endl;
		if (symbolMap.getError() == true) {
			outfile << symbolMap.getErrorStr() << endl;
			if(symbolMap.getOperation()!="RSUB")
				error = true;
		}
	}
}

bool WriteInFile::is_digits(const std::string& str) {
	return str.find_first_not_of("0123456789") == std::string::npos;
}