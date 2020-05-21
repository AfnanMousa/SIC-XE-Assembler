#include "LocationsTable.h"

static Locations* instance;

Locations* Locations::getInstance() {
	if (!instance)
		instance = new Locations;
	return instance;
}

LocationObject Locations::getLabel(string index) {
	return LocationsTable.at(index);
}

void Locations::addLocation(string i, LocationObject line) {
	LocationsTable.insert({ i,line });
}

bool Locations::isFound(string label) {
	return LocationsTable.find(label) != LocationsTable.end();
}

std::map<std::string, std::string> Locations::getsymbolLocations() {
	return symbolLocations;
}

vector<string> LocationObject::getVector() {
	return linkedList;
}
void LocationObject::setStar(string s) {

}
string LocationObject::getStar() {
	return star;
}