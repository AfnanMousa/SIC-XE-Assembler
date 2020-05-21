#include "ReadFromFile.h"
#include "FinalTable.h"
#include "Parsing.h"
#include "Controller.h"
#include <iostream>
#include <vector>
#include <String>
#include <fstream>
#include <vector>
#include <regex>
using namespace std;
ReadFromFile::ReadFromFile()
{

}
vector<string> ReadFromFile::read(string FileName) {
	string Line;
	ifstream FileInput;
	Controller* controller = new Controller();
	StaticTables* tables = tables->getInstance();
	vector<string> book;
	FileInput.open(FileName);
	Parsing pars;
	int line_index = 1;
	if (FileInput) {
		while (getline(FileInput, Line)) {
			book.push_back(Line);
			if (Line[0] != '.') {              //egnore it
				symbolTable tableObject = pars.Check_Indecies(line_index, Line);
				bool error = tableObject.getError();

				if (error == true) {
					cout << "ERROR";
					FileInput.close();
				}
			//	else if (tables->occurrencesInOPTable(tableObject.getOperation()) != 0){
			//		controller->findOPCode(tableObject);
			//	}
			//	this->printTable(tableObject);
			}

		}
		FileInput.close();
	}
	else {
		cout << "Error openning file " << '\n';
	}
	//    pars.setting();
	return book;
}

void ReadFromFile::printTable(symbolTable symbolMap){
	//SYMTable* symbolMap = symbolMap->getInstance();
	cout << symbolMap.getAddress() << "    " << symbolMap.getLabel() << "     " << symbolMap.getOperation() << "      " << symbolMap.getOperand() << "      " << symbolMap.getOpcode() << endl;
}
