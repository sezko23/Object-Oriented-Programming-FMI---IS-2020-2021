#pragma once
#include <iostream>
#include <cstring>
#include "Planet.h"
enum rank_stormtrooper { fighter, cadet, corporal, sergeant };

class Stormtrooper {
private:
	char* id;
	char* type;
	rank_stormtrooper _rank;
	Planet planet;
	void copy(const Stormtrooper& other); //since i am using the same code in copy constructor and operator=, i made a copy function to write less code instead of writing the same thing
	void destroy(); //same reason as the copy function (for deleting)
public:
	void zadacha2();
	void print(); //print
	Stormtrooper(); //default constructor
	Stormtrooper(const Stormtrooper& other); //copy constructor
	Stormtrooper(const char* _id, const char* _type, rank_stormtrooper rank_, Planet planet); //constructor with parameters
	Stormtrooper& operator=(const Stormtrooper& other); //operator=
	~Stormtrooper(); //destructor
	friend std::ostream& operator<< (std::ostream& os, const Stormtrooper& _stormtrooper);
	friend std::istream& operator>> (std::istream& is, Stormtrooper& _stormtrooper);
	

	void setId(const char* _id) {
		this->id = new char[strlen(_id) + 1];
		strcpy_s(this->id, strlen(_id) + 1, _id);
	}
	const char* getId() const {
		return this->id;
	}
	void setType(const char* _type) {
		this->type = new char[strlen(_type) + 1];
		strcpy_s(this->type, strlen(_type) + 1, _type);
	}
	const char* getType() const {
		return this->type;
	}
	void setRank(rank_stormtrooper rank_) {
		this->_rank = rank_;
	}
	const rank_stormtrooper GetRank() const {
		return this->_rank;
	}
};