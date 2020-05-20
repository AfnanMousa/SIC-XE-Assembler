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
	std::map<std::string, std::string>  operationTable;
	std::string keyWords[7];
	StaticTables();
	void fillingRegTable();
	void fillingOperationTable();
	void fillingKeyWordsTable();

public:
	static StaticTables* getInstance();
	std::string getData(std::string );
	int occurrencesInOPTable(std::string);
	std::string* getKeyWords();
	bool operationsIsFound(std::string);
	bool regIsFound(std::string);
};

#endif // STATICTABLES_H