#pragma once
#include <iostream>
#include <cstring>

class Stormtrooper {
public:
	enum rank { fighter,cadet,corporal,sergeant };
	struct Planet {
		char* name;
		int size;
	};
private:
	char* id;
	char* type;
	rank _rank;
	Planet planet;
public:
	void print() const; //print
	Stormtrooper(); //default constructor
	Stormtrooper(const char* id, const char* type, rank rank_); //constructor with parameters
	~Stormtrooper(); //destructor

	void setId(char* _id) {
		id = _id;
	}
	const char* getId() {
		return id;
	}
	void setType(char* _type) {
		type = _type;
	}
	const char* getType() {
		return type;
	}
	void setRank(Stormtrooper::rank rank_) {
		_rank = rank_;
	}
	const Stormtrooper::rank GetRank() {
		return _rank;
	}
};