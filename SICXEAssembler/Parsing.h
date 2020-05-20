#pragma once
#ifndef PARSING_H
#define PARSING_H
#include <string>
#include "StaticTables.h"
#include "symbolTable.h"
#include "MakeAddress.h"
#include "DynamicTables.h"
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
class Parsing
{
public:
	Parsing();
	symbolTable Check_Indecies(int& line_index, string operation);
	bool check(string operation);
	void setting(string strings[3], int line_index);
	vector<string> split(string Line);
	DynamicTables dynamicTables;
	string address;
	int index[3];

protected:

private:

};

#endif // PARSING_H
