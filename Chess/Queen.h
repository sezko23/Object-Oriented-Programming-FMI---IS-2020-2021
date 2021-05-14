#pragma once
#include "Piece.h"


class Queen : public Piece {
public:
	Queen() :Piece() {}
	Queen(const String _name, const char _colour, const int _player) :Piece(_name, _colour, _player) {}
};