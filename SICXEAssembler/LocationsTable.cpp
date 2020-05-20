#include "symbolTable.h"

static Locations* instance;

Locations* Locations::getInstance() {
	if (!instance)
		instance = new Locations;
	return instance;
}

string Locations::getLabel(string index) {
	return LocationsTable.at(index);
}

void Locations::addLocation(string i, string line) {
	LocationsTable.insert({ i,line });
}