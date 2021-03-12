#pragma once
#include <iostream>
#include <cstring>

class Planet {
private:
	char* name;
	char* planetSystem;
	char* republic;
public:
	void print();
	Planet();
	Planet(char* _name, char* _planetSystem, char* _republic);
	~Planet();

	void setName(char* _name) {
		name = _name;
	}
	const char* getName() {
		return name;
	}
	void setPlanetSystem(char* _planetSystem) {
		planetSystem = _planetSystem;
	}
	const char* getPlanetSystem() {
		return planetSystem;
	}
	void setRepublic(char* _republic) {
		republic = _republic;
	}
	const char* getRepublic() {
		return republic;
	}
};
