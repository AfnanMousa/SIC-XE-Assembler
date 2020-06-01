#include <iostream>
#include<string>
#include <math.h>
#include <map>

#define ll long long
#define SPACE " "
#define nLINE '\n'

using namespace std;


//#include "FormatChecker.h"
#include "Command.h"
#include "StaticTables.h"
#include "FormatChecker.h"
#include "symbolTable.h"
#include <iostream>
#include "StaticTables.h"
#include "Parsing.h"
#include "ReadFromFile.h"
#include "Auxillary.h"
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>
#include <regex>

int main(void)
{
    ReadFromFile f;
    string filename;
    cout << "Enter the file name in form filename.txt :" << '\n';
    cin >> filename;
    vector<string> book = f.read(filename);


    /*string operation = "+LDA";
    string operand = "#0";

    SYMTable* table = table->getInstance();
    symbolTable* s = new symbolTable();

    s->setLabel("FFFF");

    table->addLine("0", *s);

    cout << table->getLine("0").getLabel() << endl;

    Command* c = new findFlags();

    FormatChecker* f = new FormatChecker(operation, operand);
    cout << operation.find('+') << SPACE << operation.size() << nLINE;
    if (operation.find('+') < operation.size()) {
        string opCode = f->format4GenOpCode();
        opCode += c->execute(4,operation,operand);
    }*/

/*
    Command* c1 = new toHexa();
    c1->execute();
    delete c1;

    Command* c2 = new calculateDisplacement();
    c2->execute();
    delete c2;

    Command* c3 = new findFlags();
    c3->execute();
    delete c3;
*/
    return 0;
}
