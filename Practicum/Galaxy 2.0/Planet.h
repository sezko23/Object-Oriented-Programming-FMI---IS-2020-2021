#pragma once
#include <iostream>
#include <cstring>

enum planet_type {carbon, desert, helium, ice, lava, ocean};

template <typename T>
void printPlanet(T planet) {
	std::cout << planet;
}

class Planet {
private:
	char* name;
	char* planetSystem;
	char* republic;
	enum planet_type type;
	void copy(const Planet& other); //since i am using the same code in copy constructor and operator=, i made a copy function to write less code instead of writing the same thing
	void destroy(); //same reason as the copy function (for deleting)
public:
	void zadacha2();
	//void print(); //print function
	Planet(); //default constructor
	Planet(const Planet& other); //copy constructor
	Planet(const char* _name,const char* _planetSystem,const char* _republic, planet_type _type); //constructor with parameters
	Planet& operator=(const Planet& other); //operator=
	~Planet(); //destructor
	friend std::ostream& operator<< (std::ostream& os, const Planet& _planet);
	friend std::istream& operator>> (std::istream& is, Planet& _planet);

	void setName(const char* _name) {
		this->name = new char[strlen(_name) + 1];
		strcpy_s(this->name, strlen(_name) + 1, _name);
	}
	const char* getName() {
		return this->name;
	}
	void setPlanetSystem(const char* _planetSystem) {
		this->planetSystem = new char[strlen(_planetSystem) + 1];
		strcpy_s(this->planetSystem, strlen(_planetSystem) + 1, _planetSystem);
	}
	const char* getPlanetSystem() {
		return this->planetSystem;
	}
	void setRepublic(const char* _republic) {
		this->republic = new char[strlen(_republic) + 1];
		strcpy_s(this->republic, strlen(_republic) + 1, _republic);
	}
	const char* getRepublic() {
		return this->republic;
	}
	void setPlanetType(const planet_type _type) {
		type = _type;
	}
	const planet_type getPlanetType() {
		return type;
	}
};
