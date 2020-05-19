#pragma once
#ifndef LEGALFLAGSCOMBINATIONS_H
#define LEGALFLAGSCOMBINATIONS_H
#include <string>
#include <map>
#include <iostream>


class legalFlagsCombinations
{
private:
	std::map<std::string, std::string>  firstPart;
	std::map<std::string, std::string>  secondPart;
	legalFlagsCombinations();
	void generateFirstPart();
	void generateSecondPart();

public:
	static legalFlagsCombinations* getInstance();
	std::string getNIX(std::string key);
	std::string getBPE(std::string key);
};

#endif // LEGALFLAGSCOMBINATIONS_H
