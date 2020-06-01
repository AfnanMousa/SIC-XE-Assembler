#include "objectProgram.h"
#include "Auxillary.h"
#include "symbolTable.h"

using namespace std;
objectProgram::objectProgram()
{
	//ctor
}

objectProgram::~objectProgram()
{
	//dtor
}

SYMTable* st = st->getInstance();
vector<string> address; vector<string> opcode; vector<string> objectCode;vector<string> labels;

void objectProgram::fillVectors() {
	vector<string> v = st->getKeys();
	for (int i = 0;i < v.size();i++) {
		address.push_back(st->getLine(v[i]).getAddress());
		opcode.push_back(st->getLine(v[i]).getOperation());
		objectCode.push_back(st->getLine(v[i]).getOpcode());
		labels.push_back(st->getLine(v[i]).getLabel());
	}
}

string objectProgram::createHeader() {
	string operation;
	int  i = 0;
	operation = opcode.at(i);
	i++;
	while (operation != "START") {
		operation = opcode.at(i);
		i++;
	}
	string name = labels.at(i - 1);
	while (name.length() < 6) {
		name = name + " ";
	}
	string start = address.at(0);
	while (start.length() < 6) {
		start = "0" + start;
	}
	string last = address.at(address.size() - 1);
	transitions t;
	int x = t.hexaToDec(last) - t.hexaToDec(start);
	string len = t.decToHexa(x);
	while (len.length() < 6) {
		len = "0" + len;
	}
	string header = "H" + name + start + len;
	return header;
}

vector<string> objectProgram::createText() {
	vector<string> allText;
	string text = "T";
	string start = "";
	string len;
	string code = "";
	transitions t;
	int k = 0;
	while (k < objectCode.size() && objectCode.at(k) == "")
	{
		k++;
	}
	start = address.at(k);
	while (start.length() < 6) {
		start = "0" + start;
	}
	while (k < objectCode.size())
	{
		code = "";
		string temp = "";
		while (k < objectCode.size() && opcode.at(k) != "END" && opcode.at(k) != "ORG" && opcode.at(k) != "EQU" && opcode.at(k) != "START" && opcode.at(k) != "RESW" && opcode.at(k) != "RESB" && opcode.at(k) != "ORG" && temp.length() < 61)
		{
			code = code + objectCode.at(k);
			temp = code + objectCode.at(k + 1);
			k++;
		}
		if (opcode.at(k) == "END")
		{
			int x = t.hexaToDec(address.at(k)) - t.hexaToDec(start);
			len = t.decToHexa(x);
			while (len.size() < 2) {
				len = "0" + len;
			}
			string finalText = text + start + len + code;
			allText.push_back(finalText);
		}
		if (!(k < objectCode.size()) || (objectCode.at(k) == "" && opcode.at(k) != "ORG" && opcode.at(k) != "EQU" && opcode.at(k) != "START" && opcode.at(k) != "RESW" && opcode.at(k) != "RESB" && opcode.at(k) != "ORG"))
		{
			break;
		}
		int x = t.hexaToDec(address.at(k)) - t.hexaToDec(start);
		len = t.decToHexa(x);
		while (len.size() < 2) {
			len = "0" + len;
		}
		string finalText = text + start + len + code;
		allText.push_back(finalText);
		while (k < objectCode.size() && objectCode.at(k) == "")
		{
			k++;
		}

		start = address.at(k);
		while (start.length() < 6) {
			start = "0" + start;
		}
	}

	return allText;
}

string objectProgram::createEnd() {
	int i = 0;
	string addressFirst;
	while (objectCode.at(i) == "") {
		i++;
	}
	addressFirst = address.at(i);
	while (addressFirst.length() < 6) {
		addressFirst = "0" + addressFirst;
	}
	return "E" + addressFirst;
}