#pragma once
#include "Piece.h"

class Bishop :public Piece {
public:
	Bishop() :Piece() {}
	Bishop(const String _name, const char _colour, const int _player) :Piece(_name, _colour, _player) {}
};
