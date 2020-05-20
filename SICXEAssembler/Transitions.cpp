#include <map>
#include <iostream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

#include "Auxillary.h"

void HexaMap(map<string, char>* mp)
{
	(*mp)["0000"] = '0';
	(*mp)["0001"] = '1';
	(*mp)["0010"] = '2';
	(*mp)["0011"] = '3';
	(*mp)["0100"] = '4';
	(*mp)["0101"] = '5';
	(*mp)["0110"] = '6';
	(*mp)["0111"] = '7';
	(*mp)["1000"] = '8';
	(*mp)["1001"] = '9';
	(*mp)["1010"] = 'A';
	(*mp)["1011"] = 'B';
	(*mp)["1100"] = 'C';
	(*mp)["1101"] = 'D';
	(*mp)["1110"] = 'E';
	(*mp)["1111"] = 'F';
}

string transitions::subtract(string s1, string s2, int bits)
{
	int dec = hexaToDec(s1) - hexaToDec(s2);
	if (dec < 0)
		dec = twoscomp(dec, bits);
	return decimalToBinary(dec);
}

int transitions::hexaToDec(string hexa)
{
	int len = hexa.size();
	int base = 1;
	int dec = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (hexa[i] >= '0' && hexa[i] <= '9')
		{
			dec += (hexa[i] - 48) * base;
			base = base * 16;
		}
		else if (hexa[i] >= 'A' && hexa[i] <= 'F')
		{
			dec += (hexa[i] - 55) * base;
			base = base * 16;
		}
	}

	return dec;

}

int transitions::twoscomp(int num, int bits) {
	//decimal to decimal
	num = abs(num);
	int result = 0, added = 1;
	int t = 0;
	while (num) {
		t++;
		int d = num % 2;
		num /= 2;
		if (!d) {
			result += added;
		}
		added *= 2;
	}
	while (t < bits) {
		result += added;
		t++;
		added *= 2;
	}
	return result + 1;
}

string transitions::decimalToBinary(int decimal) {
	string bin = "", binTraverse = "";
	int i = 0;
	while (decimal != 0)
	{
		binTraverse += (decimal % 2) + 48;
		decimal = decimal / 2;
	}
	for (int j = binTraverse.size() - 1; j >= 0; j--)
		bin += binTraverse[j];
	return bin;
}

string transitions::hexaToBinary(string s1) {
	return "";
}

bool transitions::isOutOfRange(string s1) {
	int dec = hexaToDec(s1);
	if (dec > 2047 || dec < -2048)
		return true;
	return false;
}

using namespace std;
ConvertHexaToBinary::ConvertHexaToBinary()
{

}
string ConvertHexaToBinary::hexaToBinary(string hexa)
{
	string binStr = "";
	for (int i = 0; i < hexa.length(); ++i)
	{
		switch (hexa[i])
		{
		case '0': binStr.append("0000"); break;
		case '1': binStr.append("0001"); break;
		case '2': binStr.append("0010"); break;
		case '3': binStr.append("0011"); break;
		case '4': binStr.append("0100"); break;
		case '5': binStr.append("0101"); break;
		case '6': binStr.append("0110"); break;
		case '7': binStr.append("0111"); break;
		case '8': binStr.append("1000"); break;
		case '9': binStr.append("1001"); break;
		case 'A': binStr.append("1010"); break;
		case 'B': binStr.append("1011"); break;
		case 'C': binStr.append("1100"); break;
		case 'D': binStr.append("1101"); break;
		case 'E': binStr.append("1110"); break;
		case 'F': binStr.append("1111"); break;
		}
	}
	return binStr;
}
ConvertToHexa::ConvertToHexa()
{
	//ctor
}

string ConvertToHexa::IntToHexa(int address) {
	char hexaDeciNum[100];

	// counter for hexadecimal number array
	int i = 0;
	while (address != 0)
	{
		// temporary variable to store remainder
		int temp = 0;

		// storing remainder in temp variable.
		temp = address % 16;

		// check if temp < 10
		if (temp < 10)
		{
			hexaDeciNum[i] = temp + 48;
			i++;
		}
		else
		{
			hexaDeciNum[i] = temp + 55;
			i++;
		}

		address = address / 16;
	}
	string Output;
	for (int j = i - 1; j >= 0; j--) {
		Output = Output + hexaDeciNum[j];
	}

	return Output;
}

int ConvertToHexa::hexaToInt(string hexa) {
	unsigned int x;
	stringstream ss;
	ss << hex << hexa;
	ss >> x;
	// output it as a signed type
	x = static_cast<int>(x);
	return x;
}
