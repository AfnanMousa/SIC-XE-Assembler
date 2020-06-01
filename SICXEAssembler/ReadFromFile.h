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
        DynamicTables *dynamicTables = dynamicTables->getInstance();
    protected:

    private:

};

class WriteInFile
{
public:
	WriteInFile() {}
	void write();
	void writeTable();
	bool is_digits(const std::string& str);
protected:

private:

};

#endif // READFROMFILE_H
