#include "DynamicTables.h"
#include "MakeAddress.h"
#include "LocationsTable.h"
#include "StaticTables.h"
#include "Command.h"
#include "Auxillary.h"
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

Locations* locationsTable = locationsTable->getInstance();
symbolTable& DynamicTables::BuildDataTable(string& Label, string& Operation, string& Operand, string& address, string strings[3], int line_index) {
	int flag = 0;
	symbolTable* sym = new symbolTable;
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
		else if (((MakeSure.equalIgnoreCase(Operation, "RESB")) || (MakeSure.equalIgnoreCase(Operation, "RESW")))) {
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
			if (locationsTable->isFound(Label)) {
				forwRefFound* c = new forwRefFound();
				c->execute(Label,address);
			}
		}
	}



	if (flag == 1) {
		dataTable.insert({ Label, address });
		if (locationsTable->isFound(Label)) {
			forwRefFound* c = new forwRefFound();
			c->execute(Label,address);
		}
		sym = DynamicTables::setting(strings, line_index, address);
		//           return true;
	}
	int flag2 = 1;
	int flag1 = 0;
	if ((flag == 2) || (Label.length() == 0)) {
		std::transform(Operation.begin(), Operation.end(), Operation.begin(),
			[](unsigned char c) { return std::toupper(c); });
		if ((Operand.length() == 0) || (is_Aphabet(Operand))) {
			if (((MakeSure.equalIgnoreCase(Operation, "END")) && (Label.length() == 0))) {
				if ((Operand.length() != 0) && (!MakeSure.equalIgnoreCase(Operand, labelstart))) {
					flag2 = 3;
				}
				else if ((Operand.length() != 0) && (MakeSure.equalIgnoreCase(Operand, labelstart))) {
					flag1 = 1;
					cout << " ****** undefined symbol in operand " << '\n';
				}
			}
			else if (MakeSure.equalIgnoreCase(Operation, "RSUB")) {
				if ((Operand.length() == 0)) {
					flag2 = 3;
				}
				else {
					flag1 = 1;
					cout << " ****** undefined symbol in operand " << '\n';
				}
			}
			else if ((MakeSure.equalIgnoreCase(Operation, "Base")) && (Label.length() == 0)) {
				if (dataTable.find(Operand) != dataTable.end()) {
					flag2 = 3;
				}
				symbolMap->setBASE(Operand);
			}
			else {
				if ((dataTable.find(Operand) != dataTable.end())) {

					if ((((Operation.at(Operation.length() - 1) != 'R') && (!MakeSure.equalIgnoreCase(Operation, "RMO"))) && (!MakeSure.equalIgnoreCase(Operation, "SHIFTL")))) {
						flag2 = 3;
					}

				}
				else {
					if (Label.length() == 0) Label = to_string(line_index);
					flag2 = 3;
					//locationsTable->getsymbolLocations().insert({address,Label});
					locationsTable->addLocation(address,Label);
				}
			}
		}
		else if ((Operand.length() != 0) && (is_digits(Operand))) {
			if (MakeSure.equalIgnoreCase(Operation, "START") && (Operand.length() < 5)) {
				if (Label.length() != 0) {
					labelstart = Label;
				}
				flag2 = 3;
			}
			else if ((((Operation.at(Operation.length() - 1) != 'R') && (!MakeSure.equalIgnoreCase(Operation, "RMO"))) && (!MakeSure.equalIgnoreCase(Operation, "SHIFTL"))) && (Operand.length() < 5)) {
				flag2 = 3;

			}
			else {
				flag1 = 1;
				cout << " ****** undefined symbol in operand " << '\n';
			}
		}
		else if ((((Operand.at(0) == '#') || (Operand.at(0) == '@')) || (Operand.at(0) == '*'))) {
			if (((Operation.at(Operation.length() - 1) != 'R') && (!MakeSure.equalIgnoreCase(Operation, "RMO"))) && (!MakeSure.equalIgnoreCase(Operation, "SHIFTL"))) {
				if ((Operand.at(0) == '*')) {
					if ((Operand.length() == 1)) {
						flag2 = 3;
					}
					else {
						cout << " ****** undefined symbol in operand " << '\n';
					}
				}
				else {
					string temp = Operand.substr(1, (Operand.length() - 1));
					if ((is_digits(temp)) && (temp.length() < 4)) {
						flag2 = 3;
					}
					else if (dataTable.find(temp) == dataTable.end()) {
						flag2 = 3;
					}
					else if(is_Aphabet(temp)) {
						flag2 = 3;
						if (Label.length() == 0) Label = to_string(line_index);
						//locationsTable->getsymbolLocations().insert({ address,Label });
						locationsTable->addLocation(address, Label);
					}
					else {
						cout << " ****** undefined symbol in operand " << '\n';
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

			if ((vect.size() == 2) && (((Operation.at(Operation.length() - 1) == 'R') && (Operation.length() > 2)) || (((MakeSure.equalIgnoreCase(Operation, "RMO"))) || (MakeSure.equalIgnoreCase(Operation, "SHIFTL"))))) {
				if (statTables->regIsFound(vect[0]) && statTables->regIsFound(vect[1])) {
					flag2 = 3;
				}
			}
			else if ((vect.size() == 2) && (((Operation.at(Operation.length() - 1) != 'R') && (!MakeSure.equalIgnoreCase(Operation, "RMO"))) && (!MakeSure.equalIgnoreCase(Operation, "SHIFTL")))) {
				if (((vect[1] == "X") || (vect[1] == "x")) && (is_Aphabet(vect[0]))) {
					if (dataTable.find(vect[0]) != dataTable.end()) {
						flag2 = 3;
					}
					else if (is_Aphabet(vect[0])) {
						flag2 = 3;
						if (Label.length() == 0) Label = to_string(line_index);
						//locationsTable->getsymbolLocations().insert({ address,Label });
						locationsTable->addLocation(address, Label);
					}
					else {
						cout << " ****** undefined symbol in operand " << '\n';
					}
				}
			}
		}
	}


	if ((flag2 == 3) || (flag == 2)) {
		sym = DynamicTables::setting(strings, line_index, address);
		cout << "After Settings " << endl;
		cout << (*sym).getAddress() << "    " << (*sym).getLabel() << "     " << (*sym).getOperation() << "      " << (*sym).getOperand() << "      " << (*sym).getOpcode() << endl;
		//symbolTable sym = symbolMap->getLine(strings[0]);
	}

	return *sym;
}

bool DynamicTables::is_digits_of_Hexa(const std::string& str) {
	return str.find_first_not_of("0123456789ABCDEF") == std::string::npos;
}
bool DynamicTables::is_digits(const std::string& str) {
	return str.find_first_not_of("0123456789") == std::string::npos;
}
bool DynamicTables::is_Aphabet(const std::string& str) {
	return str.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") == std::string::npos;
}

symbolTable* DynamicTables::setting(string strings[3], int line_index, string& address) {
	symbolTable* sym = new symbolTable();
	if (strings[1] == "ORG") {
		sym->setAddress("");
	}
	else {
		sym->setAddress(address);
	}
	address = makeAddress.LocationCounter(strings[1], strings[2]);
	sym->setLabel(strings[0]);
	sym->setNextAddress(address);
	sym->setOperation(strings[1]);
	sym->setOperand(strings[2]);
	if (strings[0].length() == 0 || is_digits(strings[0])) {
		strings[0] = to_string(line_index);
		sym->setLabel("");
	}
	sym->setKey(strings[0]);
	//cout <<"************************* " <<strings[0]<<endl;
	symbolMap->addLine(strings[0], *sym);

	cout << "\nFROM DYNAMIC TABLES " << endl;

	cout << symbolMap->getLine(strings[0]).getAddress() << "    " << symbolMap->getLine(strings[0]).getLabel() << "     " << symbolMap->getLine(strings[0]).getOperation() << "      " << symbolMap->getLine(strings[0]).getOperand() << "      " << symbolMap->getLine(strings[0]).getOpcode() << endl;

	return sym;
}
