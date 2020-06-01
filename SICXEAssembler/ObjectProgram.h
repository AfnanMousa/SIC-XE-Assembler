#pragma once
#ifndef OBJECTPROGRAM_H
#define OBJECTPROGRAM_H
#include <vector>
#include <string>

using namespace std;

class objectProgram
{
public:
	objectProgram();
	virtual ~objectProgram();
	string createHeader ();
	vector<string> createText();
	string createEnd ();
	void fillVectors();

protected:

private:
};

#endif // OBJECTPROGRAM_H