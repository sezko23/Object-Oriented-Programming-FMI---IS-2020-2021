#include "Planet.h"

/*void Planet::print(){
	std::cout << "Name of the planet: " << this->name << ", System: " << this->planetSystem << ", Republic: " << this->republic;
	std::cout << ", Type of the planet: ";
	switch (this->type) {
	case 0:
		std::cout << "Carbon" << std::endl;
		break;
	case 1:
		std::cout << "Desert" << std::endl;
		break;
	case 2:
		std::cout << "Helium" << std::endl;
		break;
	case 3:
		std::cout << "Ice" << std::endl;
		break;
	case 4:
		std::cout << "Lava" << std::endl;
		break;
	case 5:
		std::cout << "Ocean" << std::endl;
		break;
	}
}
*/

void Planet::zadacha2() {
	std::cout << this->name << std::endl;
	std::cout << this->planetSystem << std::endl;
	std::cout << this->republic << std::endl;
	switch (this->type) {
	case 0:
		std::cout << "Carbon" << std::endl;
		break;
	case 1:
		std::cout << "Desert" << std::endl;
		break;
	case 2:
		std::cout << "Helium" << std::endl;
		break;
	case 3:
		std::cout << "Ice" << std::endl;
		break;
	case 4:
		std::cout << "Lava" << std::endl;
		break;
	case 5:
		std::cout << "Ocean" << std::endl;
		break;
	default:
		std::cout << "Error! Invalid type!" << std::endl;
		break;
	}
	std::cout << std::endl;
}



void Planet::copy(const Planet& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
	this->planetSystem = new char[strlen(other.planetSystem) + 1];
	strcpy_s(this->planetSystem, strlen(other.planetSystem) + 1, other.planetSystem);
	this->republic = new char[strlen(other.republic) + 1];
	strcpy_s(this->republic, strlen(other.republic) + 1, other.republic);
	this->type = other.type;
}

void Planet::destroy() {
	delete[] this->name;
	delete[] this->planetSystem;
	delete[] this->republic;
}

Planet::Planet() {
	this->name = new char[4];
	strcpy_s(this->name, 4 , "FMI");
	this->planetSystem = new char[17];
	strcpy_s(this->planetSystem, 17 , "Sofia University");
	this->republic = new char[9];
	strcpy_s(this->republic, 9, "Bulgaria");
	this->type = lava;
}

Planet::Planet(const Planet& other) {
	copy(other);
}

Planet::Planet(const char* _name,const char* _planetSystem,const char* _republic,const planet_type _type) {
	this->name = new char[strlen(_name) + 1];
	strcpy_s(this->name, strlen(_name) + 1, _name);
	this->planetSystem = new char[strlen(_planetSystem) + 1];
	strcpy_s(this->planetSystem, strlen(_planetSystem) + 1, _planetSystem);
	this->republic = new char[strlen(_republic) + 1];
	strcpy_s(this->republic, strlen(_republic) + 1, _republic);
	this->type = _type;
}

Planet& Planet::operator=(const Planet& other) {
	if (this != &other) {
		destroy();
		copy(other);
	}
	return*this;
}

Planet::~Planet() {
	destroy();
}


std::ostream& operator<< (std::ostream& os, const Planet& _planet) {
	os << "Planet name: " << _planet.name << std::endl;
	os << "Planet system: " << _planet.planetSystem << std::endl;
	os << "Planet republic: " << _planet.republic << std::endl;
	os << "Planet type: ";
	switch (_planet.type) {
	case 0:
		os << "Carbon" << std::endl;
		break;
	case 1:
		os << "Desert" << std::endl;
		break;
	case 2:
		os << "Helium" << std::endl;
		break;
	case 3:
		os << "Ice" << std::endl;
		break;
	case 4:
		os << "Lava" << std::endl;
		break;
	case 5:
		os << "Ocean" << std::endl;
		break;
	default:
		os << "Error! Invalid type!" << std::endl;
		break;
	}
	return os;
}
	
std::istream& operator >> (std::istream& is, Planet& _planet) {
		delete[] _planet.name;
		delete[] _planet.planetSystem;
		delete[] _planet.republic;

		char* buffer = new char[128];
		
		std::cout << "Enter planet name:";
		is.getline(buffer, 128);
		_planet.name = new char[strlen(buffer) + 1];
		strcpy_s(_planet.name, strlen(buffer) + 1, buffer);

		std::cout << "Enter planet system:";
		is.getline(buffer, 128);
		_planet.planetSystem = new char[strlen(buffer) + 1];
		strcpy_s(_planet.planetSystem, strlen(buffer) + 1, buffer);

		std::cout << "Enter republic:";
		is.getline(buffer, 128);
		_planet.republic = new char[strlen(buffer) + 1];
		strcpy_s(_planet.republic, strlen(buffer) + 1, buffer);

		std::cout << "Enter planet type:";
		//i dont know what to do here
		

		delete[] buffer;
		return is;
	}

