#include "LegalFlagsCombinations.h"

legalFlagsCombinations::legalFlagsCombinations() {
	generateFirstPart();
	generateSecondPart();
}


static legalFlagsCombinations* instance;

legalFlagsCombinations* legalFlagsCombinations::getInstance() {
	if (!instance)
		instance = new legalFlagsCombinations;
	return instance;
}

std::string legalFlagsCombinations::getNIX(std::string key) {
	return this->firstPart.at(key);
}

std::string legalFlagsCombinations::getBPE(std::string key) {
	return this->secondPart.at(key);
}

void legalFlagsCombinations::generateFirstPart() {
	firstPart.insert({ "address","001" });
	firstPart.insert({ "displacement","000" });
	firstPart.insert({ "PC","010" });
	firstPart.insert({ "Base","100" });
}

void legalFlagsCombinations::generateSecondPart() {
	secondPart.insert({ "indirect","100" });
	secondPart.insert({ "immediate","010" });
	secondPart.insert({ "directNoIndexing","110" });
	secondPart.insert({ "directIndexing","111" });
}