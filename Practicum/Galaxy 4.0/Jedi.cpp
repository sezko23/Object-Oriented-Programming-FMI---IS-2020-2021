#include "Jedi.h"
#include "Planet.h"

void Jedi::zadacha2() {
	std::cout << this->name << std::endl;
	switch (this->_rank) {
	case 0:
		std::cout << "Youngling";
		break;
	case 1:
		std::cout << "Knight";
		break;
	case 2:
		std::cout << "Master";
		break;
	default:
		std::cout << "Error! Invalid rank!" << std::endl;
		break;
	}
	std::cout << std::endl;
	std::cout << this->midichlorian << std::endl;
	std::cout << this->planet.getName() << std::endl;
	std::cout << this->species << std::endl;
	std::cout << this->militaryRank << std::endl;
	std::cout << std::endl;
}

void Jedi::print(){
	std::cout << "Name: " << this->name << ", Midichlorian: " << this->midichlorian << ", Species: " << this->species << ", Military Rank: " << this->militaryRank << ", Rank: ";
	switch (this->_rank) {
	case 0:
		std::cout << "Youngling";
		break;
	case 1:
		std::cout << "Knight";
		break;
	case 2:
		std::cout << "Master";
		break;
	default:
		std::cout << "Error! Invalid rank!" << std::endl;
	}
	std::cout << ", Planet info: ";
	printPlanet(this->planet);
	
}

void Jedi::copy(const Jedi& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
	this->_rank = other._rank;
	this->midichlorian = other.midichlorian;
	this->species = new char[strlen(other.species) + 1];
	strcpy_s(this->species, strlen(other.species) + 1, other.species);
	this->militaryRank = new char[strlen(other.militaryRank) + 1];
	strcpy_s(this->militaryRank, strlen(other.militaryRank) + 1, other.militaryRank);
	this->planet = (other.planet);
}

Jedi::Jedi()
{
	this->name = new char[6];
	strcpy_s(this->name, 6, "Sezer");
	this->_rank = master;
	this->midichlorian = 23.4;
	this->species = new char[8];
	strcpy_s(this->species, 8, "Wookies");
	this->militaryRank = new char[8];
	strcpy_s(this->militaryRank, 8, "General");
}

Jedi::Jedi(const Jedi& other) {
	copy(other);
}

void Jedi::destroy() {
	delete[] this->name;
	delete[] this->species;
	delete[] this->militaryRank;
}

Jedi::Jedi(const char* _name, rank_jedi __rank, double _midichlorian, const char* _species, const char* _militaryRank,Planet _planet){
	this->name = new char[strlen(_name) + 1];
	strcpy_s(this->name, strlen(_name) + 1, _name);
	this->_rank = __rank;
	this->midichlorian = _midichlorian;
	this->species = new char[strlen(_species) + 1];
	strcpy_s(this->species, strlen(_species) + 1, _species);
	this->militaryRank = new char[strlen(_militaryRank) + 1];
	strcpy_s(this->militaryRank, strlen(_militaryRank) + 1, _militaryRank);
	this->planet = _planet;

}

Jedi& Jedi::operator=(const Jedi& other) {
	if (this != &other) {
		destroy();
		copy(other);
	}
	return*this;
}

Jedi::~Jedi() {
	destroy();
 }


std::ostream& operator<< (std::ostream& os, const Jedi& _jedi) {
	os << "Jedi name: " << _jedi.name << std::endl;
	os << "Jedi rank: ";
	switch (_jedi._rank) {
	case 0:
		os << "Youngling";
		break;
	case 1:
		os << "Knight";
		break;
	case 2:
		os << "Master";
		break;
	default:
		os << "Error! Invalid rank!";
		break;
	}
	std::cout << std::endl;
	os << "Jedi midichlorian: " << _jedi.midichlorian << std::endl;
	os << "Jedi planet: " << _jedi.planet.getName() << std::endl;
	os << "Jedi species: " << _jedi.species << std::endl;
	os << "Jedi military rank: " << _jedi.militaryRank << std::endl;
	return os;
}

std::istream& operator>> (std::istream& is, Jedi& _jedi) {
	delete[] _jedi.name;
	delete[] _jedi.species;
	delete[] _jedi.militaryRank;

	
	char* buffer = new char[128];
	int rank_number;

	is.ignore();

	std::cout << "Enter jedi name: ";
	is.getline(buffer, 128);
	_jedi.name = new char[strlen(buffer) + 1];
	strcpy_s(_jedi.name, strlen(buffer) + 1, buffer);

	std::cout << "Numbers for Jedi rank: " << std::endl;
	std::cout << "youngling = 0, knight = 1, master = 2" << std::endl;
	std::cout << "Enter number for Jedi rank: ";
	is >> rank_number;
	_jedi._rank = rank_jedi (rank_number);

	std::cout << "Enter jedi midichlorian:";
	is >> _jedi.midichlorian;

	is.ignore();

	std::cout << "Enter jedi planet:";
	is >> _jedi.planet;
	
	is.ignore();

	std::cout << "Enter jedi species: ";
	is.getline(buffer, 128);
	_jedi.species = new char[strlen(buffer) + 1];
	strcpy_s(_jedi.species, strlen(buffer) + 1, buffer);

	std::cout << "Enter jedi military rank: ";
	is.getline(buffer, 128);
	_jedi.militaryRank = new char[strlen(buffer) + 1];
	strcpy_s(_jedi.militaryRank, strlen(buffer) + 1, buffer);
	
	delete[] buffer;
	
	return is;
}
