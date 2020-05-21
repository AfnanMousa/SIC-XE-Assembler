#ifndef READFROMFILE_H
#define READFROMFILE_H
#include <vector>
#include <string>
#include "DynamicTables.h"

class ReadFromFile
{
    public:
        ReadFromFile();
        std::vector<std::string> read(std::string FileName);
       // DynamicTables *dynamicTables = dynamicTables->getInstance();
		void printTable(symbolTable);
    protected:

    private:

};

#endif // READFROMFILE_H