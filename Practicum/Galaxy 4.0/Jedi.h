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
	void setRank(rank_jedi rank) {
		this->_rank = rank;
	}
	const rank_jedi getRank() const {
		return this->_rank;
	}
	void setName(const char* _name) {
		this->name = new char[strlen(_name) + 1];
		strcpy_s(this->name, strlen(_name) + 1, _name);
	}
	const char* getName() const {
		return this->name;
	}
	void setMidichlorian(double _midichlorian) {
		this->midichlorian = _midichlorian;
	}
	const double getMidichlorian() const {
		return this->midichlorian;
	}
	void setSpecies(char* _species) {
		this->species = _species;
	}
	const char* getSpecies() const {
		return this->species;
	}
	void setMilitaryRank(char* _militaryRank) {
		this->militaryRank = _militaryRank;
	}
	const char* getMilitaryRank() const {
		return this->militaryRank;
	}

	void zadacha2();
	void print(); //print
	Jedi(); //default constructor
	Jedi(const Jedi& other); //copy constructor
	Jedi(const char* name, rank_jedi _rank, double midichlorian, const char* species,const char* militaryRank,Planet planet); //constructor with parameters
	Jedi& operator=(const Jedi& other); //operator=
	~Jedi(); //destructor
	friend std::ostream& operator<< (std::ostream& os, const Jedi& _jedi);
	friend std::istream& operator>> (std::istream& is, Jedi& _jedi);

	
};


