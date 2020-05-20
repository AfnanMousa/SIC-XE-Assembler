#include "DynamicTables.h"
#include "MakeAddress.h"
#include "StaticTables.h"
#include "StaticTables.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
DynamicTables::DynamicTables()
{
	//ctor
}
symbolTable DynamicTables::BuildDataTable(string& Label, string& Operation, string& Operand, string& address, string strings[3], int line_index) {
	int flag = 0;
	MakeAddress MakeSure;
	if ((Label.length() != 0) && (symbolMap->isFound(Label))) {
		if (MakeSure.equalIgnoreCase(Operation, "WORD")) {
			if (((Operand.length() > 0) && (Operand.length() < 5)) && (is_digits(Operand))) {
				flag = 1;
			}
			else if (((Operand.length() > 0) && (Operand.length() < 8)) && (Operand.find_first_not_of(' ') != std::string::npos)) {
				flag = 1;
			}
			else {
				cout << " ****** extra characters at end of statement" << '\n';
			}
		}
		else if (MakeSure.equalIgnoreCase(Operation, "BYTE")) {
			if ((Operand.at(0) == 'X') || (Operand.at(0) == 'x')) {
				if (((Operand.length() % 2 == 0) && ((Operand.length() > 0) && (Operand.length() < 15)))) {
					if (is_digits_of_Hexa(Operand)) {
						flag = 1;
					}
					else {
						cout << " ****** not a hexadecimal string" << '\n';
					}
				}
				else {
					cout << " ****** too long hexa-decimal string " << '\n';
				}
			}
			else if ((Operand.at(0) == 'C') || (Operand.at(0) == 'c')) {
				if ((Operand.length() > 0) && (Operand.length() < 16)) {
					flag = 1;
				}
				else {
					cout << " ****** too long character string " << '\n';
				}
			}
			else {
				cout << " ****** illegal operand" << '\n';
			}

		}
		else if (((MakeSure.equalIgnoreCase(Operation, "RESB")) || (MakeSure.equalIgnoreCase(Operation, "RESW"))) || (MakeSure.equalIgnoreCase(Operation, "START"))) {
			if ((Operand.length() > 0) && (Operand.length() < 5)) {
				if (is_digits(Operand)) {
					flag = 1;
				}
				else {
					cout << " ****** illegal operand" << '\n';
				}
			}
			else {
				cout << " ****** extra number at end of statement " << '\n';
			}
		}
		else {
			flag = 2;
		}
	}

	if (flag == 1) {
		dataTable.insert({ Label, address });
		//           return true;
	}
	int flag2 = 1;
	if ((flag == 2) || (Label.length() != 0)) {
		std::transform(Operation.begin(), Operation.end(), Operation.begin(),
			[](unsigned char c) { return std::toupper(c); });
		if ((((Operand.at(0) == '#') || (Operand.at(0) == '@')) || (Operand.at(0) == '*')) || (dataTable.find(Operand) == dataTable.end())) {
			if (((Operation.at(Operation.length() - 1) != 'R') && (!MakeSure.equalIgnoreCase(Operation, "RMO"))) && (!MakeSure.equalIgnoreCase(Operation, "SHIFTL"))) {
				if ((Operand.at(0) == '*') && (Operand.length() == 1)) {
					flag2 = 3;
				}
				else if (dataTable.find(Operand) == dataTable.end()) {
					flag2 = 3;
				}
				else {
					string temp = Operand.substr(1, (Operand.length() - 1));
					if ((is_digits(temp)) && (temp.length() < 4)) {
						flag2 = 3;
					}
					else if (dataTable.find(temp) == dataTable.end()) {
						flag2 = 3;
					}
				}
			}
		}
		else if (Operand.find(",") != std::string::npos) {
			std::vector<string> vect;
			std::stringstream ss(Operand);
			for (string i; ss >> i;) {
				vect.push_back(i);
				if (ss.peek() == ',')
					ss.ignore();
			}
			
			if ((vect.size() == 2) && (((Operation.at(Operation.length() - 1) == 'R') && (Operation.length() > 2)) || (((MakeSure.equalIgnoreCase(Operation, "RMO"))) || (MakeSure.equalIgnoreCase(Operation, "SHIFTL")))))
				if (statTables->regIsFound(vect[0]) && statTables->regIsFound(vect[1])) {
					flag2 = 3;
				}
		}
	}
	if ((flag2 == 3)) {
		if (flag == 2) {
			////insert in table label
	  //     lableTable.insert({ Label, Address });

		}
		//      return true;
	}
	DynamicTables::setting(strings, line_index, address);
	return symbolTable;
}

bool DynamicTables::is_digits_of_Hexa(const std::string& str) {
	return str.find_first_not_of("0123456789ABCDEF") == std::string::npos;
}
bool DynamicTables::is_digits(const std::string& str) {
	return str.find_first_not_of("0123456789") == std::string::npos;
}

void DynamicTables::setting(string strings[3], int line_index, string& address) {
	if (strings[1] == "ORG") {
		symbolTable.setAddress("");
	}
	else {
		symbolTable.setAddress(address);
	}
	address = makeAddress.LocationCounter(strings[1], strings[2]);
	symbolTable.setLabel(strings[0]);
	symbolTable.setNextAddress(address);
	symbolTable.setOperation(strings[1]);
	symbolTable.setOperand(strings[2]);
	if (strings[0].length() == 0)
		strings[0] = to_string(line_index);
	symbolMap->addLine(strings[0], symbolTable);

	//cout << symbolMap->getLine(strings[0]).getAddress() << "    " << symbolMap->getLine(strings[0]).getLabel() << "     " << symbolMap->getLine(strings[0]).getOperation() << "      " << symbolMap->getLine(strings[0]).getOperand() << "      " << symbolMap->getLine(strings[0]).getOpcode() <<endl;
}
