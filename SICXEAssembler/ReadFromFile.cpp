#include "ReadFromFile.h"
#include "FinalTable.h"
#include "Parsing.h"
#include "DynamicTables.h"
#include "Auxillary.h"
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
	vector<string> book;
	Controller* controller = new Controller();
	SYMTable* sym = sym->getInstance();
	StaticTables* tables = tables->getInstance();
	FileInput.open(FileName);
	Parsing pars;
	int line_index = 1;
	if (FileInput) {
		while (getline(FileInput, Line)) {
			book.push_back(Line);
			if (Line[0] != '.') {              //egnore it

				//symbolTable* tableObject = pars.Check_Indecies(line_index, Line);
				//bool error = (*tableObject).getError();


				symbolTable tableObject = pars.Check_Indecies(line_index, Line);
				bool error = (tableObject).getError();
				this->printTable(tableObject);

				if (error == true) {
					cout << "ERROR";
					FileInput.close();
				}
				else if (tables->occurrencesInOPTable((tableObject).getOperation()) != 0 && (tableObject).getOperation()!="BASE") {
					controller->findOPCode(tableObject, line_index-1);
				}


				/*if (error == true) {
					cout << "ERROR";
					FileInput.close();
				}*/
				//line_index++;
			}
			
		}
		FileInput.close();

		Print* p = new Print();
		p->printSYMTABLE();
		p->printForwardRefTable();
		p->printAddressSymbolTable();

		/*cout << '\n' << "Effect Of EQU Directive" << endl;
		vector<vector<string>>table = dynamicTables->EquTable;
		for (int i = 0;i < table.size();i++) {
			cout << table[i][0] << " = " << table[i][1];
			cout << '\n';
		}*/
	}
	else {
		cout << "Error openning file " << '\n';
	}
	//    pars.setting();
	return book;
}

void ReadFromFile::printTable(symbolTable symbolMap) {
	//SYMTable* symbolMap = symbolMap->getInstance();
	cout << symbolMap.getAddress() << "    " << symbolMap.getLabel() << "     " << symbolMap.getOperation() << "      " << symbolMap.getOperand() << "      " << symbolMap.getOpcode() << endl;
}