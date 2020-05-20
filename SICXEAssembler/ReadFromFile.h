#pragma once
#ifndef READFROMFILE_H
#define READFROMFILE_H
#include <vector>
#include <string>
#include "symbolTable.h"

class ReadFromFile
{
public:
	ReadFromFile();
	std::vector<std::string> read(std::string FileName);
	void printTable(symbolTable);

protected:

private:
};

#endif // READFROMFILE_H
