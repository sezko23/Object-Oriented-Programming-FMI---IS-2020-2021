#pragma once
#include "Piece.h"

class Knight :public Piece {
public:
	Knight() :Piece() {}
	Knight(const String _name, const char _colour, const int _player) :Piece(_name, _colour, _player) {}
};