#pragma once
#include <string>
using namespace std;
class transitions
{
public:
	string subtract(string s1, string s2,int bits);
	string binToHexa(string bin);
	string hexaToBin(string hexa);
	int hexaToDec(string hexa);
	string decToHexa(int decimal);
	int binToDec(string hexa);
	string decToBin(int decimal);
	int twoscomp(int num, int bits);
	bool isOutOfRange(string s1);
	transitions();
	~transitions();
};

