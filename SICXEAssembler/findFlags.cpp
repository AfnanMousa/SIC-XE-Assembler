#include "Command.h"
#include "LegalFlagsCombinations.h"

//using namespace std;

findFlags::findFlags()
{
	//ctor -- i.e Constructor
	cout << "Command findFlags Object is being created" << endl;
}

string findFlags::execute(int format,string opCode,string operand) {
	legalFlagsCombinations* l = l->getInstance();
	string NIX;
	string BPE;
	cout << "executing findFlags " << endl;
	if (format == 3) {
		if (operand.find("#") < operand.size()) {
			BPE = l->getBPE("immediate");
		}
		else if (operand.find("@") < operand.size()) {
			BPE = l->getBPE("indirect");
		}
		else if (operand.find(",") < operand.size()) {
			BPE = l->getBPE("directIndexing");
		}
		else {
			BPE = l->getBPE("directNoIndexing");
		}
	}
	else if (format == 4) {
		NIX = l->getNIX("address");
		opCode = opCode + NIX;
	}
	// Your implementation
	return opCode;
}

findFlags::~findFlags()
{
	//dtor -- i.e distructor
	cout << "Command findFlags Object is being deleted" << endl;
}
