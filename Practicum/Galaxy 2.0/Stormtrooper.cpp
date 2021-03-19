#include "Stormtrooper.h"
#include "Planet.h"

void Stormtrooper::zadacha2() {
	//id rank type planetname
	std::cout << this->id << std::endl;
	switch (_rank) {
	case 0:
		std::cout << "Fighter";
		break;
	case 1:
		std::cout << "Cadet";
		break;
	case 2:
		std::cout << "Corporal";
		break;
	case 3:
		std::cout << "Sergeant";
		break;
	default:
		std::cout << "Error! Invalid rank!" << std::endl;
		break;
	}
	std::cout << std::endl;
	std::cout << this->type << std::endl;
	std::cout << this->planet.getName() << std::endl;
	std::cout << std::endl;
}

void Stormtrooper::print() {
	std::cout << "Id of Stormtrooper: " << id << ", Type of Stormtrooper: " << type << ", Rank of Stormtrooper: ";
	switch (_rank) {
	case 0:
		std::cout << "Fighter";
		break;
	case 1:
		std::cout << "Cadet";
		break;
	case 2:
		std::cout << "Corporal";
		break;
	case 3:
		std::cout << "Sergeant";
		break;
	default:
		std::cout << "Error! Invalid rank!" << std::endl;
	}
	std::cout << ", Planet info: ";
	printPlanet(this->planet);
}

void Stormtrooper::copy(const Stormtrooper& other) {
	this->id = new char[strlen(other.id) + 1];
	strcpy_s(this->id, strlen(other.id) + 1, other.id);
	this->type = new char[strlen(other.type) + 1];
	strcpy_s(this->type, strlen(other.type) + 1, other.type);
	this->_rank = other._rank;
}

void Stormtrooper::destroy() {
	delete[] this->id;
	delete[] this->type;
}

Stormtrooper::Stormtrooper() {
	this->id = new char[9];
	strcpy_s(this->id, 9, "Sezer-23");
	this->type = new char[10];
	strcpy_s(this->type, 10, "Otlichnik");
	this->_rank = sergeant;
	this->planet.setName("Earth");
	this->planet.setPlanetSystem("Sluncheva");
	this->planet.setRepublic("Bulgaria");

}

Stormtrooper::Stormtrooper(const Stormtrooper& other) {
	copy(other);
}

Stormtrooper::Stormtrooper(const char* _id,const char* _type, rank_stormtrooper rank_) {
	id = new char[strlen(_id) + 1];
	strcpy_s(id, strlen(_id) + 1, _id);
	type = new char[strlen(_type) + 1];
	strcpy_s(type, strlen(_type) + 1, _type);
	_rank = rank_;
}

Stormtrooper& Stormtrooper::operator=(const Stormtrooper& other) {
	if(this!=&other){
		destroy();
		copy(other);
	}
	return*this;
}

Stormtrooper::~Stormtrooper() {
	destroy();
}