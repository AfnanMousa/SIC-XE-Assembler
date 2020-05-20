#pragma once
#ifndef FINALTABLE_H
#define FINALTABLE_H
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>

using namespace std;
class FinalTable
{
public:
	FinalTable();
	vector<vector<string>> fillingTable(int& line_index, string address, string lable, string operation, string operand);
	vector<vector<string>> finalTable;

protected:

private:
};

#endif // FINALTABLE_H
