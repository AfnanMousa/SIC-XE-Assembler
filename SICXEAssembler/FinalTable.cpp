#include "FinalTable.h"
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>

using namespace std;
FinalTable::FinalTable()
{

}
vector<vector<string>> FinalTable::fillingTable(int& line_index, string address, string lable, string operation, string operand) {
	vector<string> rows;
	rows = { address, lable, operation, operand };
	finalTable.push_back(rows);
	return finalTable;
}
