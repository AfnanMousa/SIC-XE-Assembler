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
symbolTable Parsing::Check_Indecies(int& line_index, string line,bool& err) {
	bool error = false;
	string errorStr = "";
	transform(line.begin(), line.end(), line.begin(), ::toupper);
	string strings[3];
	std::regex rgx1("\\s*([a-zA-Z0-9]+)\\s+(\\+?[a-zA-Z]+)(\\s+[\\#||\\@]?[\\+\\-\\/\\*\\'\\,a-zA-Z0-9]+)\\s*");
	std::regex rgx2("(\\s*)(\\+?[a-zA-Z]+)(\\s+[\\#||\\@]?[\\+\\-\\/\\*\\'\\,a-zA-Z0-9]+)\\s*");
	std::regex rgx3("(\\s*)(RSUB)(\\s*)");
	std::regex rgx4("(\\s*)(END)(\\s*)");
	std::regex rgx5("(\\s*)(ORG)(\\s*)");
	smatch matches;
	if (regex_search(line, matches, rgx3) || regex_search(line, matches, rgx1) || std::regex_search(line, matches, rgx2) || regex_search(line, matches, rgx4) || regex_search(line, matches, rgx5)) {
		for (size_t i = 1; i < matches.size(); ++i) {
			regex space("\\s+");
			string finalTableStrings = matches[i].str();
			finalTableStrings = regex_replace(finalTableStrings, space, "");
			strings[i - 1] = finalTableStrings;
			if (i == 2) {
                if (strings[i - 1]=="RSUB"&&matches[i].str()!=""){
                    errorStr = "****** RSUB doesn't need an operand";
					error = true;
                }
				bool validOperation = check(finalTableStrings);
				if (validOperation == 0) {
                    errorStr = "****** Invalid operation Or The operand is missed in line " + to_string(line_index);
					error = true;
                    err = true;
					break;
				}
				if (line_index==1&&finalTableStrings!="START"){
                    cout << "****** The first operation must be 'START' " <<endl;
                    err = true;
                    error = true;
				}
			}
		}
		if (line_index == 1) {

			address = strings[2];
		}
	}
	else {
		cout << " ******* Invalid Instruction in line "<< line_index<<endl;
		err = true;
	}
	symbolTable& tableObject = dynamicTables.BuildDataTable(strings[0], strings[1], strings[2], address, strings, line_index,error, errorStr);
	(tableObject).setError(error);
	(tableObject).setErrorStr(errorStr);
	string label = tableObject.getLabel();
	if (tableObject.getLabel().length() == 0) {
		label = to_string(line_index);
	}
	SYMTable* symbolMap = symbolMap->getInstance();
	line_index++;
	return *(&tableObject);
}

bool Parsing::check(string operation) {
	StaticTables* data = data->getInstance();
	if (data->occurrencesInOPTable(operation) == 1 || count(data->getKeyWords(), data->getKeyWords() + 9, operation) == 1 || data->occurrencesInFormat2(operation) == 1)
		return true;
	return false;
}
