#include <iostream>
#include<string>
#include <math.h>
#include <map>

#define ll long long
#define SPACE " "
#define nLINE '\n'

using namespace std;


//#include "FormatChecker.h"
#include "Command.h"
#include "StaticTables.h"
#include "FormatChecker.h"
#include "symbolTable.h"
#include <iostream>
#include "StaticTables.h"
#include "Parsing.h"
#include "ReadFromFile.h"
#include "Auxillary.h"
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>
#include <regex>

int main(void)
{
	ReadFromFile f;
	string filename;
	cout << "Enter the file name in form 'filename.txt' :" << '\n'<<endl;
	cin >> filename;
	cout<<endl;
	vector<string> book = f.read(filename);
	return 0;
}
