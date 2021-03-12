#include "Planet.h"

void Planet::print()
{
	std::cout << "Name of the planet: " << name << ", System: " << planetSystem << ", Republic: " << republic;
}

Planet::Planet() {
	name = new char[4];
	strcpy_s(name, 4 , "FMI");
	planetSystem = new char[17];
	strcpy_s(planetSystem, 17 , "Sofia University");
	republic = new char[9];
	strcpy_s(republic, 9, "Bulgaria");
}

Planet::Planet(char* _name, char* _planetSystem, char* _republic) {
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
	planetSystem = new char[strlen(_planetSystem) + 1];
	strcpy_s(planetSystem, strlen(_planetSystem) + 1, _planetSystem);
	republic = new char[strlen(_republic) + 1];
	strcpy_s(republic, strlen(_republic) + 1, _republic);
}

Planet::~Planet() {
	delete[] name;
	delete[] planetSystem;
	delete[] republic;
}