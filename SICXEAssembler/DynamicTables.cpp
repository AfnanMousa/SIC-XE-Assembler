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
static DynamicTables* instance;

DynamicTables* DynamicTables::getInstance() {
    if (!instance)
        instance = new DynamicTables;
    return instance;
}
ConvertToHexa Convert;
Locations* locationsTable = locationsTable->getInstance();
symbolTable& DynamicTables::BuildDataTable(string& Label, string& Operation, string& Operand, string& address, string strings[3], int line_index,bool error, string errorStr) {
	string exp = evaluateExp(Operand, error, errorStr);
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
                error = true;
				errorStr = " ****** extra characters at end of statement";
	//			cout << " ****** extra characters at end of statement" << '\n';
			}
		}
		else if (MakeSure.equalIgnoreCase(Operation, "BYTE")) {
			string temp = Operand;
			if ((Operand.at(0) == 'X') || (Operand.at(0) == 'x')) {
				temp.erase(temp.begin() + 0);
				if (temp.find("\'") == 0) {
					temp.erase(temp.begin() + 0);
					if (temp.find("\'") == temp.length() - 1) {
						temp.erase(temp.length() - 1);
						if (((temp.length() % 2 == 0) && ((temp.length() > 0) && (temp.length() < 15)))) {
							if (is_digits_of_Hexa(temp)) {
								flag = 1;
							}
							else {
                                    error = true;
                                    errorStr = "  ****** not a hexadecimal string";
						//		cout << " ****** not a hexadecimal string" << '\n';
							}
						}
						else {
                                error = true;
                                errorStr = "too long hexa-decimal string";
					//		cout << " ****** too long hexa-decimal string " << '\n';
						}
					}
					else {
                             error = true;
                            errorStr = " ****** illegal operand ";
					//	cout << " ****** illegal operand " << '\n';
					}
				}
				else {
                        error = true;
                    errorStr = " ****** extra characters at end of statement";
				//	cout << " ****** extra characters at end of statement" << '\n';
				}
			}
			else if ((Operand.at(0) == 'C') || (Operand.at(0) == 'c')) {
				string temp2 = Operand;
				temp2.erase(temp2.begin() + 0);
				if (temp2.find("\'") == 0) {
					temp2.erase(temp2.begin() + 0);
					if (temp2.find("\'") == temp2.length() - 1) {
						temp2.erase(temp2.length() - 1);
						if ((temp2.length() > 0) && (temp2.length() < 16)) {
							flag = 1;
						}
						else {
                            error = true;
                        errorStr = " ****** too long character string ";
						//	cout << " ****** too long character string " << '\n';
						}
					}
					else {
                            error = true;
                        errorStr = " ****** illegal operand";
				//		cout << " ****** illegal operand" << '\n';
					}
				}

				else {
                        error = true;
                        errorStr = " ****** extra characters at end of statement";
				//	cout << " ****** extra characters at end of statement" << '\n';
				}
			}
		}
		else if (((MakeSure.equalIgnoreCase(Operation, "RESB")) || (MakeSure.equalIgnoreCase(Operation, "RESW")))) {
			if ((Operand.length() > 0) && (Operand.length() < 5)) {
				if (is_digits(Operand)) {
					flag = 1;
				}
				else {
                        error = true;
                        errorStr = " ****** illegal operand";
				//	cout << " ****** illegal operand" << '\n';
				}
			}
			else {
                    error = true;
                        errorStr = " ****** extra number at end of statement ";
			//	cout << " ****** extra number at end of statement " << '\n';
			}
		}
		else {
			flag = 2;
			if (locationsTable->isFound(Label)) {
				forwRefFound* c = new forwRefFound();
				c->execute(Label, address);
			}
		}
	}



	if (flag == 1) {
		dataTable.insert({ Label, address });
		if (locationsTable->isFound(Label)) {
			forwRefFound* c = new forwRefFound();
			c->execute(Label, address);
		}
		sym = DynamicTables::setting(strings, line_index, address,error, errorStr);
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
					 error = true;
                        errorStr = " ****** undefined symbol in operand ";
				//	cout << " ****** undefined symbol in operand " << '\n';
				}
			}
			else if (MakeSure.equalIgnoreCase(Operation, "RSUB")) {
				if ((Operand.length() == 0)) {
					flag2 = 3;
				}
				else {
					flag1 = 1;
					 error = true;
                        errorStr = " ****** undefined symbol in operand ";
					//cout << " ****** undefined symbol in operand " << '\n';
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
					if ((MakeSure.equalIgnoreCase(Operation, "TIXR")) && !(statTables->regIsFound(Operand))) {
						flag2 = 3;
					}
					else if ((((Operation.at(Operation.length() - 1) != 'R') && (!MakeSure.equalIgnoreCase(Operation, "RMO"))) && (!MakeSure.equalIgnoreCase(Operation, "SHIFTL")))) {
						flag2 = 3;
					}

				}
				else {
					if (Label.length() == 0) Label = to_string(line_index);
					flag2 = 3;
					//locationsTable->getsymbolLocations().insert({address,Label});
					locationsTable->addLocation(address, Label);
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
				 error = true;
                        errorStr = " ****** undefined symbol in operand ";
			//	cout << " ****** undefined symbol in operand " << '\n';
			}
		}
		else if ((((Operand.at(0) == '#') || (Operand.at(0) == '@')) || (Operand.at(0) == '*'))) {
			//cout << "HERE ******************FFFFFFFFFFFFFFFFFFF" << endl;
			if (((Operation.at(Operation.length() - 1) != 'R') && (!MakeSure.equalIgnoreCase(Operation, "RMO"))) && (!MakeSure.equalIgnoreCase(Operation, "SHIFTL"))) {
				//cout << "HERE ******************FFFFFFFFFFFFFFFFFFF" << endl;
				if ((Operand.at(0) == '*')) {
					if ((Operand.length() == 1)) {
						flag2 = 3;
					}
					else {
                             error = true;
                        errorStr = " ****** undefined symbol in operand ";
					//	cout << " ****** undefined symbol in operand " << '\n';
					}
					//cout << "HERE 11111111111111111111111111111111111" << endl;
				}
				else {
					string temp = Operand.substr(1, (Operand.length() - 1));
					if ((is_digits(temp)) && (temp.length() < 4)) {
						flag2 = 3;
	//					cout << "1 Here " << temp << " " << address << " " << Label << endl;
					}
					else if (dataTable.find(temp) == dataTable.end()) {
						flag2 = 3;
						//cout << "2 Here " << temp << " " << address << " " << Label << endl;
						if (Label.length() == 0) Label = to_string(line_index);
	//					cout << "*******Adding " << Label << "at address " << address << endl;
						//locationsTable->getsymbolLocations().insert({ address,Label });
						locationsTable->addLocation(address, Label);
					}
					else if (is_Aphabet(temp)) {
						flag2 = 3;
						if (Label.length() == 0) Label = to_string(line_index);
//						cout << "*******Adding " << Label << "at address " << address << endl;
						//locationsTable->getsymbolLocations().insert({ address,Label });
						locationsTable->addLocation(address, Label);
					}
					else {
	//					cout << "3 Here " << temp << " " << address << " " << Label << endl;
                        error = true;
                        errorStr = " ****** undefined symbol in operand ";
			//			cout << " ****** undefined symbol in operand " << '\n';
					}
					//cout << "HERE2222222222222222222222222222222222222" << endl;
				}
			}
		}
		else if (Operand.find(",") != std::string::npos) {
			vector<string> result;
			stringstream s_stream(Operand); //create string stream from the string
			while (s_stream.good()) {
				string substr;
				getline(s_stream, substr, ','); //get first string delimited by comma
				result.push_back(substr);
			}

			if ((result.size() == 2) && (((Operation.at(Operation.length() - 1) == 'R') && (Operation.length() > 2)) || (((MakeSure.equalIgnoreCase(Operation, "RMO"))) || (MakeSure.equalIgnoreCase(Operation, "SHIFTL"))))) {
				if (!(statTables->regIsFound(result.at(0))) && !(statTables->regIsFound(result.at(1)))) {
					flag2 = 3;
				}
			}
			else if ((result.size() == 2) && (((Operation.at(Operation.length() - 1) != 'R') && (!MakeSure.equalIgnoreCase(Operation, "RMO"))) && (!MakeSure.equalIgnoreCase(Operation, "SHIFTL")))) {
				if (((result.at(1) == "X") || (result.at(1) == "x")) && (is_Aphabet(result.at(0)))) {
					if (dataTable.find(result.at(0)) != dataTable.end()) {
						flag2 = 3;
					}
					else if (is_Aphabet(result.at(0))) {
						flag2 = 3;
						if (Label.length() == 0) Label = to_string(line_index);
						//locationsTable->getsymbolLocations().insert({ address,Label });
						locationsTable->addLocation(address, Label);
					}
					else {
                             error = true;
                        errorStr = " ****** undefined symbol in operand ";
					//	cout << " ****** undefined symbol in operand " << '\n';
					}
				}
			}
		}
	}

	if(Operation=="EQU"){
            if (exp==""){
                exp =to_string(extractOperands(Operand));
            }
            vector<string> row ;
            row.push_back(Label);
            row.push_back(exp);
        EquTable.push_back(row);
        address = exp;
    }
cout <<EquTable.size()<<endl;
	if ((flag2 == 3) || (flag == 2)) {
		sym = DynamicTables::setting(strings, line_index, address, error, errorStr);
	//	cout << "After Settings " << endl;
	//	cout << (*sym).getAddress() << "    " << (*sym).getLabel() << "     " << (*sym).getOperation() << "      " << (*sym).getOperand() << "      " << (*sym).getOpcode() << endl;
		//symbolTable sym = symbolMap->getLine(strings[0]);
	}else if(error ==true){
        cout << errorStr +" in line "+ to_string(line_index) <<endl;
	}

	return *sym;
}

string DynamicTables:: evaluateExp (string& Operand, bool error, string errorStr){
    int x = 0,op1,op2;
    int ans=0;
    char op;
    string typ1,typ2;
    vector<string> operands;
       if (Operand.find("+") != std::string::npos) {
            op = '+';
       }else if (Operand.find("-") != std::string::npos) {
            op = '-';
       }else if (Operand.find("*") != std::string::npos) {
            op = '*';
       }else if (Operand.find("/") != std::string::npos){
        op = '/';
       }else {
            return "";
       }
       split (Operand,operands,op);
        if (!is_digits(operands[0]))
       typ1=symbolMap->getLine(operands[0]).getType() ;
        if (!is_digits(operands[1]))
       typ2=symbolMap->getLine(operands[1]).getType();

       if ((typ1==typ2&&typ1=="A")||((typ1==typ2&&typ1=="R")&&(op=='-'))){
            sym->setType("A");
       }else if ((op!='*'&&op!='/')&&(((typ1=="R")&&(typ2=="A"))||((typ1=="A")&&(typ2=="R")&&(op=='+')))){
            sym->setType("R");
       }else {
            error = true;
            errorStr = "****** undefined Expression in operand ";
            cout<< "****** undefined Expression in operand "<<endl;
       }
    string hexa ="";
       if (error==false){
       op1 = extractOperands(operands[0]);
       op2 = extractOperands(operands[1]);

        if (op=='+'){
            ans = op1+op2;
        }else if (op=='-'){
            ans = op1-op2;
        }else if (op=='*'){
            ans = op1*op2;
        }else{
            ans = op1/op1;
        }

        hexa = Convert.IntToHexa(ans);}

        return hexa;
}

 int DynamicTables::extractOperands(string& operand){
     string x;
     int op;
     if (is_digits_of_Hexa(operand)){
                x = operand;
            }/*else if (dataTable.count(operand)==1){
                stringstream geek(dataTable.at(operand));
                geek >> x;
            }*/else if (!(symbolMap->isFound(operand))){
                x =(symbolMap->getLine(operand).getAddress());
            }
        op = Convert.hexaToInt(x);
        return op;
 }
void DynamicTables:: split (string operand,vector<string>& operands,char op){
    stringstream test(operand);
    string segment;

while(getline(test, segment, op))
{
   operands.push_back(segment);
}
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

symbolTable* DynamicTables::setting(string strings[3], int line_index, string& address,bool error, string errorStr) {
//	symbolTable* sym = new symbolTable();
	if (strings[1] == "ORG") {
		sym->setAddress("");
	}
	else {
		sym->setAddress(address);
	}
	if (strings[1]=="RESB"||strings[1]=="RESW"){
            sym->setType("R");
    }else if (strings[1]=="WORD"){
            sym->setType("A");
    }
	address = makeAddress.LocationCounter(strings[1], strings[2]);
	sym->setLabel(strings[0]);
	sym->setNextAddress(address);
	sym->setOperation(strings[1]);
	sym->setOperand(strings[2]);
	sym->setError(error);
	sym->setErrorStr(errorStr);
	if (strings[0].length() == 0 || is_digits(strings[0])) {
		strings[0] = to_string(line_index);
		sym->setLabel("");
	}
	sym->setKey(strings[0]);
	//cout <<"************************* " <<strings[0]<<endl;
	symbolMap->addLine(strings[0], *sym);

//	cout << "\nFROM DYNAMIC TABLES " << endl;

//	cout << symbolMap->getLine(strings[0]).getAddress() << "    " << symbolMap->getLine(strings[0]).getLabel() << "     " << symbolMap->getLine(strings[0]).getOperation() << "      " << symbolMap->getLine(strings[0]).getOperand() << "      " << symbolMap->getLine(strings[0]).getOpcode() << endl;

	return sym;
}
