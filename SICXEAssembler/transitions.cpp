#include "transitions.h"
#include<sstream>
#include <iostream>
#include <map>

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
    return decToBin(dec);
}
string transitions::binToHexa(string bin) {
    //cout << "hna ";
    int l = bin.size();
    // cout <<l<< " ";
    int t = bin.find_first_of('.');
    //cout <<  t <<"  ";
    int len_left = t != -1 ? t : l;
    //cout << len_left<< "  ";
    for (long int i = 1; i <= (4 - len_left % 4) % 4; i++)
        bin = '0' + bin;
    if (t != -1)
    {
        cout << "true ";
        int len_right = l - len_left - 1;
        cout << len_right << "  " << bin << endl;
        for (int i = 1; i <= (4 - len_right % 4) % 4; i++) {
            bin = bin + '0';
            //cout << len_right << " " << i<< "  " << bin << endl;
        }

    }
    map<string, char> binHexaMap;
    HexaMap(&binHexaMap);
    int i = 0;
    string hex = "";

    while (1)
    {
        hex += binHexaMap[bin.substr(i, 4)];
        i += 4;
        if (i == bin.size())
            break;
        if (bin.at(i) == '.')
        {
            hex += '.';
            i++;
        }
    }

    return hex;

    /* int hex[1000]; string hexa=""; stringstream s;
     int i = 1, j = 0, rem, dec = 0, binaryNumber;
     long int n = bin.size() - 1;
     while (n>=0)
     {
         rem = ((int)bin[n]) % 2;
         cout << " reminder " << rem;
         dec = dec + rem * i;
         cout << " decimal " << dec;
         i = i * 2;
         n--;
     }
     i = 0;
     while (dec != 0)
     {
        cout << " char " << (char) dec % 16;
         if (dec % 16 > 9)
             s <<(char)(dec % 16 + 55);
         else
             s << (char)dec % 16;
         s>>hexa;
         cout << " hexa " << hexa <<endl ;
         dec = dec / 16;
         i++;
     }
     return hexa;*/
}
string transitions::hexaToBin(string hexa) {
    long int i = 0; string bin = "";

    while (hexa[i]) {
        switch (hexa[i]) {
        case '0':
            bin += "0000";
            break;
        case '1':
            bin += "0001";
            break;
        case '2':
            bin += "0010";
            break;
        case '3':
            bin += "0011";
            break;
        case '4':
            bin += "0100";
            break;
        case '5':
            bin += "0101";
            break;
        case '6':
            bin += "0110";
            break;
        case '7':
            bin += "0111";
            break;
        case '8':
            bin += "1000";
            break;
        case '9':
            bin += "1001";
            break;
        case 'A':
        case 'a':
            bin += "1010";
            break;
        case 'B':
        case 'b':
            bin += "1011";
            break;
        case 'C':
        case 'c':
            bin += "1100";
            break;
        case 'D':
        case 'd':
            bin += "1101";
            break;
        case 'E':
        case 'e':
            bin += "1110";
            break;
        case 'F':
        case 'f':
            bin += "1111";
            break;
        case '.':
            bin += ".";
            break;

        }
        i++;
    }
    return bin;
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
string transitions::decToHexa(int decimal) {
    string hexa = "", hexaTraverse = "";
    int i = 0;
    while (decimal != 0)
    {
        if (decimal % 16 < 10)
            hexaTraverse += (decimal % 16) + 48;
        else
            hexaTraverse += (decimal % 16) + 55;
        decimal = decimal / 16;
    }
    for (int j = hexaTraverse.size() - 1; j >= 0; j--)
        hexa += hexaTraverse[j];
    return hexa;
}
int transitions::binToDec(string bin)
{
    int len = bin.size();
    int base = 1;
    int dec = 0;
    for (int i = len - 1; i >= 0; i--)
    {
          dec += (bin[i] - 48) * base;
          base = base * 2;
    
    }

    return dec;
}
string transitions::decToBin(int decimal)
{
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
bool transitions::isOutOfRange(string s1) {
    int dec = hexaToDec(s1);
    if (dec > 2047 || dec < -2048)
        return true;
    return false;
}
transitions::transitions()
{
}

transitions::~transitions()
{
}
