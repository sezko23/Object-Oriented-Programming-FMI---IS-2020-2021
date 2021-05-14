#include "Board.h"

Board::Board()
{
	piece = nullptr;
}

Board::~Board()
{
}

Board::Board(Piece* _piece)
{
	piece = _piece;
}



