#include "Piece.h"

Piece::Piece()
{
	name = "";
	colour = ' ';
}

Piece::Piece(const String _name, const char _colour,const int _player)
{
	name = _name;
	colour = _colour;
	player = _player;
}

void Piece::setName(const String _name)
{
	name = _name;
}

void Piece::setColour(const char _colour)
{
	colour = _colour;
}

void Piece::setPlayer(const int _player)
{
	player = _player;
}

String Piece:: getName() const
{
	return name;
}

char Piece::getColour() const
{
	return colour;
}

int Piece::getPlayer() const
{
	return player;
}
