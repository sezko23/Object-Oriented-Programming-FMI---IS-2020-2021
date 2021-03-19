#pragma once
#include <iostream>
#include <cstring>
#include "Planet.h"
enum rank_jedi { youngling, knight, master };

class Jedi {
private:
	char* name;
	rank_jedi _rank;
	double midichlorian;
	Planet planet;
	char* species;
	char* militaryRank;
	void copy(const Jedi& other); //since i am using the same code in copy constructor and operator=, i made a copy function to write less code instead of writing the same thing
	void destroy(); //same reason as the copy function (for deleting)
public:
	void zadacha2();
	void print(); //print
	Jedi(); //default constructor
	Jedi(const Jedi& other); //copy constructor
	Jedi(const char* name, rank_jedi _rank, double midichlorian, const char* species,const char* militaryRank,Planet planet); //constructor with parameters
	Jedi& operator=(const Jedi& other); //operator=
	~Jedi(); //destructor

	void setRank(rank_jedi rank){
		_rank = rank;
	}
	const rank_jedi getRank() {
		return _rank;
	}
	void setName(const char* _name) {
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
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


