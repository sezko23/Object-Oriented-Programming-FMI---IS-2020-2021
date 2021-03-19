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
	Stormtrooper(const char* id, const char* type, rank_stormtrooper rank_); //constructor with parameters
	Stormtrooper& operator=(const Stormtrooper& other); //operator=
	~Stormtrooper(); //destructor

	void setId(const char* _id) {
		this->id = new char[strlen(_id) + 1];
		strcpy_s(this->id, strlen(_id) + 1, _id);
	}
	const char* getId() {
		return id;
	}
	void setType(const char* _type) {
		this->type = new char[strlen(_type) + 1];
		strcpy_s(this->type, strlen(_type) + 1, _type);
	}
	const char* getType() {
		return type;
	}
	void setRank(rank_stormtrooper rank_) {
		_rank = rank_;
	}
	const rank_stormtrooper GetRank() {
		return _rank;
	}
};