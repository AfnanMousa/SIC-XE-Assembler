#include "ReadFromFile.h"
#include "FinalTable.h"
#include "Parsing.h"
#include "DynamicTables.h"
#include "Auxillary.h"
#include "Controller.h"
#include "ObjectProgram.h"
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
	bool error ;
	int line_index = 1;
	if (FileInput) {
		while (getline(FileInput, Line)) {
			book.push_back(Line);
			if (Line[0] != '.') {              //egnore it
				symbolTable tableObject = pars.Check_Indecies(line_index, Line,error);

				if (error == true) {
					FileInput.close();
				}
				else if ((tables->occurrencesInOPTable((tableObject).getOperation()) != 0 || tables->occurrencesInFormat2((tableObject).getOperation())&& (tableObject).getOperation()!="BASE")) {
					controller->findOPCode(tableObject, line_index-1);
				}
			}

		}
		FileInput.close();
		Print* p = new Print();
		p->printSYMTABLE();
		vector<vector<string>>table = dynamicTables->EquTable;
		cout <<table.size();
	}
	else {
		cout << "Error openning file " << '\n';
	}
	WriteInFile* w = new WriteInFile();
	w->writeTable();
	w->write();
	return book;
}
