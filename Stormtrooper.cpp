#include "Stormtrooper.h"

void Stormtrooper::print() const
{
	std::cout << "Id of Stormtrooper: " << id << ", Type of Stormtrooper: " << type << ", Rank of Stormtrooper: " << _rank << std::endl;
}

Stormtrooper::Stormtrooper() {
	id = nullptr;
	type = nullptr;
	_rank = sergeant;
	
}

Stormtrooper::Stormtrooper(const char* _id,const char* _type, rank rank_) {
	id = new char[strlen(_id) + 1];
	strcpy_s(id, strlen(_id) + 1, _id);
	type = new char[strlen(_type) + 1];
	strcpy_s(type, strlen(_type) + 1, _type);
	_rank = rank_;
}

Stormtrooper::~Stormtrooper() {
	delete[] id;
	delete[] type;
}