#include "MakeAddress.h"
#include "staticTables.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include<stdio.h>
#include "Auxillary.h"
#include "StaticTables.h"
using namespace std;

StaticTables* staticTables = staticTables->getInstance();

MakeAddress::MakeAddress()
{
	//ctor
}
bool MakeAddress::equalIgnoreCase(string str1, string str2)
{
	int i = 0;
	std::transform(str1.begin(), str1.end(), str1.begin(),
		[](unsigned char c) { return std::tolower(c); });
	std::transform(str2.begin(), str2.end(), str2.begin(),
		[](unsigned char c) { return std::tolower(c); });
	// Comparing both using inbuilt function
	int x = str1.compare(str2);

	// if strings are equal,
	// return true otherwise false
	if (x != 0)
		return false;
	else
		return true;
}
int addressBeforeORG;
string MakeAddress::LocationCounter(string Operation, string Operand) {
	ConvertToHexa temp;
	string Output;
	int x;
	if (Operand.length() == 0) {
		if (equalIgnoreCase(Operation, "RSUB")) {
			LOC = LOC + 3;
		}
		else {
			/////////////////////
		}
	}
	else if (staticTables->occurrencesInFormat2(Operation) == 1) {
		LOC = LOC + 2;
	}
	else {
		stringstream geek(Operand);
		if (equalIgnoreCase(Operation, "START")) {
			unsigned int y;
			std::stringstream ss;
			ss << std::hex << Operand;
			ss >> y;
			LOC = static_cast<int>(y);
		}
		else if (equalIgnoreCase(Operation, "RESB")) {
			geek >> x;
			LOC = x + LOC;
		}
		else if (equalIgnoreCase(Operation, "RESW")) {
			geek >> x;
			LOC = x * 3 + LOC;
		}
		else if (Operation.at(0)== '+') {
			LOC = 4 + LOC;
		}
		else if (equalIgnoreCase(Operation, "WORD")) {
			LOC = LOC + 3;
		}
		else if (equalIgnoreCase(Operation, "BYTE")) {

			if ((Operand.at(0) == 'X') || (Operand.at(0) == 'x')) {
				x = ((Operand.length() - 3) / 2);
				LOC = x + LOC;
			}
			else if ((Operand.at(0) == 'C') || (Operand.at(0) == 'c')) {
				x = (Operand.length()) - 3;
				LOC = x + LOC;
			}
		}
		else if (equalIgnoreCase(Operation, "ORG")) {
			addressBeforeORG = LOC;
            if (Operand.length()==0){
                LOC= addressBeforeORG;

            }else if (!symbolMap->isFound(Operand)){
                Operand = symbolMap->getLine(Operand).getAddress();
            }
            else if (checkIfHexa(Operand)){

            }else {
               cout<<"ERROR, SYMBOL TABLE DOESN'T CONTAIN THIS OPERAND"<<endl;
            }

            if (Operand.length()!=0)
                LOC = temp.hexaToInt(Operand);
		}else if (!equalIgnoreCase(Operation, "EQU")){
			LOC = LOC + 3;
		}

	}
	Output = temp.IntToHexa(LOC);
	return Output;
}

bool MakeAddress::checkIfHexa(string str) {
	if (std::all_of(str.begin(), str.end(), ::isxdigit)) {
		return true;
	}
	return false;
}
