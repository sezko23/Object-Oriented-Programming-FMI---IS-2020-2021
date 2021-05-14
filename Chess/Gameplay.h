#pragma once
#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

class Gameplay {
public:
	Board board[8][8];
	Gameplay();
	~Gameplay();
	void playGame();
	void setBoard();
	void printBoard();
	bool isMoveCommandValid(String move);
	bool canMove(String move, Board board[8][8]);

};


