#pragma once
#include "String.h"

class Piece {
private:
	String name;
	char colour;
	int player;
public:
	Piece();
	Piece(const String _name, const char _colour, const int _player);
	void setName(const String _name);
	void setColour(const char _colour);
	void setPlayer(const int _player);
	String getName() const;
	char getColour() const;
	int getPlayer() const;
};
