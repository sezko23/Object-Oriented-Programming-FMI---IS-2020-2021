#pragma once
#include "Piece.h"

class King :public Piece {
public:
	King() :Piece() {}
	King(const String _name, const char _colour, const int _player) :Piece(_name, _colour, _player) {}
};