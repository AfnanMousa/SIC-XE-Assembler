#pragma once
#include <map>
#include <iostream>
#include <vector>
using namespace std;

class LocationObject {
private :
	vector<string> linkedList;
	string star;
public:
	LocationObject() {}
	virtual ~LocationObject() {}
	vector<string> getVector();
	void setStar(string);
	string getStar();

};

class Locations {
private:
	Locations() {}
	virtual ~Locations() {}
	std::map<std::string, LocationObject> LocationsTable;
	std::map<std::string, std::string> symbolLocations;

public:
	static Locations* getInstance();
	LocationObject getLabel(string);
	void addLocation(string, LocationObject);
	bool isFound(string);
	std::map<std::string, std::string> getsymbolLocations();
};