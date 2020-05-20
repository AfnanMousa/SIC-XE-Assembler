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
	firstPart.insert({ "indirect","100" });
	firstPart.insert({ "immediate","010" });
	firstPart.insert({ "directNoIndexing","110" });
	firstPart.insert({ "directIndexing","111" });
}

void legalFlagsCombinations::generateSecondPart() {
	secondPart.insert({ "address","001" });
	secondPart.insert({ "displacement","000" });
	secondPart.insert({ "PC","010" });
	secondPart.insert({ "Base","100" });
}