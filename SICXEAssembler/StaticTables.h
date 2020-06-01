#pragma once
#ifndef STATICTABLES_H
#define STATICTABLES_H
#include <string>
#include <map>
#include <iostream>
#include <vector>


class StaticTables {
private:
	std::map<std::string, int> regTable;
	std::map<std::string, std::string>  operationTable, format2;
	std::string keyWords[9];
	StaticTables();
	void fillingRegTable();
	void fillingOperationTable();
	void fillingKeyWordsTable();
	void fillingFormat2Table();

public:
	static StaticTables* getInstance();
	std::string getData(std::string);
	int occurrencesInOPTable(std::string);
	int occurrencesInFormat2(std::string operation);
	std::string getFormat2Data(std::string key);
	std::string getReg(std::string key);
	std::string* getKeyWords();
	bool operationsIsFound(std::string);
	bool regIsFound(std::string);
};

#endif // STATICTABLES_H