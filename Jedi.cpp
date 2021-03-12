#include "Jedi.h"


void Jedi::print() const
{
	std::cout << "Name: " << name << " ,Rank: " << _rank << " ,Midichlorian: " << midichlorian << " ,Species: " << species << " ,militaryRank: " << militaryRank << std::endl;
}


Jedi::Jedi()
{
	name = new char[6];
	strcpy_s(name, 6, "Sezer");
	_rank = master;
	midichlorian = 23.4;
	//planet.name = new char[6];
	//strcpy_s(planet.name, 6, "Earth");
	//planet.size = 100000;
	species = new char[8];
	strcpy_s(species, 8, "Wookies");
	militaryRank = new char[8];
	strcpy_s(militaryRank, 8, "General");



}

Jedi::Jedi(const char* _name, rank __rank, double _midichlorian, const char* _species, const char* _militaryRank){
	_rank = __rank;
	midichlorian = _midichlorian;
	//planet.size = _planet.size;

	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
	//planet.name = new char[strlen(_planet.name) + 1];
	//strcpy_s(planet.name, strlen(_planet.name) + 1, _planet.name);
	//planet = _planet;
	species = new char[strlen(_species) + 1];
	strcpy_s(species, strlen(_species) + 1, _species);
	militaryRank = new char[strlen(_militaryRank) + 1];
	strcpy_s(militaryRank, strlen(_militaryRank) + 1, _militaryRank);



}



Jedi::~Jedi() {
	delete[] name;
	delete[] species;
	delete[] militaryRank;
	//delete[] planet.name;


 }

