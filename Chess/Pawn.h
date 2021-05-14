#pragma once
#include "Piece.h"

class Pawn :public Piece {
public:
	Pawn() :Piece(){}
	Pawn(const String _name, const char _colour, const int _player) :Piece(_name, _colour, _player) {}
};
