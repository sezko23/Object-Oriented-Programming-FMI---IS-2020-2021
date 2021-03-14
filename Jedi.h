#pragma once
#include <iostream>
#include <cstring>


class Jedi {

public:
	enum rank { youngling, knight, master };
	struct Planet {
		char* name;
		int size;
	};
	
	void print() const; //print
	Jedi(); //default constructor
	Jedi(const char* name, rank _rank, double midichlorian, const char* species,const char* militaryRank); //constructor with parameters
	~Jedi(); //destructor
	
private:
	char* name;
	Jedi::rank _rank;
	double midichlorian;
	Planet planet;
	char* species;
	char* militaryRank;
public:
	void setRank(Jedi::rank rank){
		_rank = rank;
	}
	const Jedi::rank GetRank() {
		return _rank;
	}
	void setName(char* _name) {
		name = _name;
	}
	const char* getName() {
		return name;
	}
	void setMidichlorian(double _midichlorian) {
		midichlorian = _midichlorian;
	}
	const double getMidichlorian() {
		return midichlorian;
	}
	void setPlanetName(Planet& _planet) {
		planet.name = _planet.name;
	}
	const char* getPlanetName() {
		return planet.name;
	}
	void setPlanetSize(Planet& _planet) {
		planet.size = _planet.size;
	}
	const int getPlanetSize() {
		return planet.size;
	}
	void setSpecies(char* _species) {
		species = _species;
	}
	const char* getSpecies() {
		return species;
	}
	void setMilitaryRank(char* _militaryRank) {
		militaryRank = _militaryRank;
	}
	const char* getMilitaryRank() {
		return militaryRank;
	}
	


};


