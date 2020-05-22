#include "Parsing.h"
#include "DynamicTables.h"
#include "FinalTable.h"
#include "MakeAddress.h"
#include "symbolTable.h"
#include <cstring>
#include <iostream>
#include <string>
#include <regex>
using namespace std;
Parsing::Parsing()
{

}
symbolTable Parsing::Check_Indecies(int& line_index, string line) {
	bool error = false;
	string strings[3];
	std::regex rgx1("\\s*([a-zA-Z0-9]+)\\s+(\\+?[a-zA-Z]+)(\\s+[\\#||\\@]?[\\'a-zA-Z0-9]+)\\s*");
	std::regex rgx2("(\\s*)(\\+?[a-zA-Z]+)(\\s+[\\#||\\@]?[\\'a-zA-Z0-9]+)\\s*");
	std::regex rgx3("(\\s*)(RSUB)(\\s*)");
	smatch matches;
	if (regex_search(line, matches, rgx3) || regex_search(line, matches, rgx1) || std::regex_search(line, matches, rgx2)) {
		for (size_t i = 1; i < matches.size(); ++i) {
			regex space("\\s+");
			string finalTableStrings = matches[i].str();
			finalTableStrings = regex_replace(finalTableStrings, space, "");
			strings[i - 1] = finalTableStrings;
			if (i == 2) {
				bool validOperation = check(finalTableStrings);
				if (validOperation == 0) {
					cout << "Invalid operation in line " << line_index;
					error = true;
					break;
				}
			}
		}
		if (line_index == 1) {

			address = strings[2];
		}
	}
	else {
		cout << "ERROR";
		error = true;
	}
	symbolTable& tableObject = dynamicTables.BuildDataTable(strings[0], strings[1], strings[2], address, strings, line_index);
	cout << "IS " <<(tableObject).getAddress() << "    " << (tableObject).getLabel() << "     " << (tableObject).getOperation() << "      " << (tableObject).getOperand() << "      " << (tableObject).getOpcode() << endl;
	(tableObject).setError(error);
	string label = tableObject.getLabel();
	cout << "From Parser " << label << endl;
	if (tableObject.getLabel().length() == 0) {
		label = to_string(line_index);
	}
	SYMTable* symbolMap = symbolMap->getInstance();

	//symbolMap->getLine
	//symbolMap->SYMPOLTable.at(label).setOperation("HAHAHAHAHAHAHAH");
	line_index++;
	return *(&tableObject);
}

bool Parsing::check(string operation) {
	StaticTables* data = data->getInstance();
	if (data->occurrencesInOPTable(operation) == 1 || count(data->getKeyWords(), data->getKeyWords() +9, operation) ==1)
		return true;
	return false;
}