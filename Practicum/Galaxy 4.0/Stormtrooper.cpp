#include "Stormtrooper.h"
#include "Planet.h"

void Stormtrooper::zadacha2() {
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
	std::cout << "Id of Stormtrooper: " << id << std::endl;
	std::cout << "Type of Stormtrooper: " << type << std::endl;
	std::cout << "Rank of Stormtrooper : ";
	switch (_rank) {
	case 0:
		std::cout << "Fighter" << std::endl;
		break;
	case 1:
		std::cout << "Cadet" << std::endl;
		break;
	case 2:
		std::cout << "Corporal" << std::endl;
		break;
	case 3:
		std::cout << "Sergeant" << std::endl;
		break;
	default:
		std::cout << "Error! Invalid rank!" << std::endl;
	}
	std::cout << "Planet info: ";
	std::cout << planet;
}

void Stormtrooper::copy(const Stormtrooper& other) {
	this->id = new char[strlen(other.id) + 1];
	strcpy_s(this->id, strlen(other.id) + 1, other.id);
	this->type = new char[strlen(other.type) + 1];
	strcpy_s(this->type, strlen(other.type) + 1, other.type);
	this->_rank = other._rank;
	this->planet = other.planet;
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

Stormtrooper::Stormtrooper(const char* _id,const char* _type, rank_stormtrooper rank_,Planet _planet) {
	id = new char[strlen(_id) + 1];
	strcpy_s(id, strlen(_id) + 1, _id);
	type = new char[strlen(_type) + 1];
	strcpy_s(type, strlen(_type) + 1, _type);
	_rank = rank_;
	planet = _planet;
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

std::ostream& operator<< (std::ostream& os, const Stormtrooper& _stormtrooper) {
	os << "Stormtrooper id: " << _stormtrooper.id << std::endl;
	os << "Stormtrooper type: " << _stormtrooper.type << std::endl;
	os << "Stormtrooper rank: ";
	switch (_stormtrooper._rank) {
	case 0:
		os << "Fighter";
		break;
	case 1:
		os << "Cadet";
		break;
	case 2:
		os << "Corporal";
		break;
	case 3:
		os << "Sergeant";
		break;
	default:
		os << "Error! Invalid rank!";
		break;
	}
	std::cout << std::endl;
	os << "Stormtrooper planet: " << _stormtrooper.planet.getName() << std::endl;
	return os;
}

std::istream& operator>> (std::istream& is, Stormtrooper& _stormtrooper) {
	delete[] _stormtrooper.id;
	delete[] _stormtrooper.type;

	char* buffer = new char[128];
	int rank_number;

	is.ignore();
	std::cout << "Enter stormtrooper id:";
	is.getline(buffer, 128);
	_stormtrooper.id = new char[strlen(buffer) + 1];
	strcpy_s(_stormtrooper.id,strlen(buffer)+1, buffer);
	

	std::cout << "Numbers for stormtrooper rank:" << std::endl;
	std::cout << "fighter = 0 , cadet = 1, corporal = 2, sergeant = 3" << std::endl;
	is >> rank_number;
	_stormtrooper._rank = rank_stormtrooper(rank_number);

	is.ignore();
	std::cout << "Enter stormtrooper type:";
	is.getline(buffer, 128);
	_stormtrooper.type = new char[strlen(buffer) + 1];
	strcpy_s(_stormtrooper.type,strlen(buffer)+1, buffer);
	

	std::cout << "Enter stormtrooper planet: ";
	is >> _stormtrooper.planet;

	delete[] buffer;
	
	
	return is;
}