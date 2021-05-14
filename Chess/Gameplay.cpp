#include "Gameplay.h"

Gameplay::Gameplay()
{
}

Gameplay::~Gameplay()
{
}

void Gameplay::setBoard()
{
	Pawn wP1("Pawn", 'w', 1);
	Pawn wP2("Pawn", 'w', 1);
	Pawn wP3("Pawn", 'w', 1);
	Pawn wP4("Pawn", 'w', 1);
	Pawn wP5("Pawn", 'w', 1);
	Pawn wP6("Pawn", 'w', 1);
	Pawn wP7("Pawn", 'w', 1);
	Pawn wP8("Pawn", 'w', 1);
	Rook wR1("Rook", 'w', 1);
	Rook wR2("Rook", 'w', 1);
	Knight wN1("Knight", 'w', 1);
	Knight wN2("Knight", 'w', 1);
	Bishop wB1("Bishop", 'w', 1);
	Bishop wB2("Bishop", 'w', 1);
	Queen wQ("Queen", 'w', 1);
	King wK("King", 'w', 1);

	Pawn bP1("Pawn", 'b', 2);
	Pawn bP2("Pawn", 'b', 2);
	Pawn bP3("Pawn", 'b', 2);
	Pawn bP4("Pawn", 'b', 2);
	Pawn bP5("Pawn", 'b', 2);
	Pawn bP6("Pawn", 'b', 2);
	Pawn bP7("Pawn", 'b', 2);
	Pawn bP8("Pawn", 'b', 2);
	Rook bR1("Rook", 'b', 2);
	Rook bR2("Rook", 'b', 2);
	Knight bN1("Knight", 'b', 2);
	Knight bN2("Knight", 'b', 2);
	Bishop bB1("Bishop", 'b', 2);
	Bishop bB2("Bishop", 'b', 2);
	Queen bQ("Queen", 'b', 2);
	King bK("King", 'b', 2);

	// coloumns rows 
	//white player side
	board[0][1].piece = &wP1;
	board[1][1].piece = &wP2;
	board[2][1].piece = &wP3;
	board[3][1].piece = &wP4;
	board[4][1].piece = &wP5;
	board[5][1].piece = &wP6;
	board[6][1].piece = &wP7;
	board[7][1].piece = &wP8;

	board[0][0].piece = &wR1;
	board[1][0].piece = &wN1;
	board[2][0].piece = &wB1;
	board[3][0].piece = &wQ;
	board[4][0].piece = &wK;
	board[5][0].piece = &wB2;
	board[6][0].piece = &wN2;
	board[7][0].piece = &wR2;

	//black player side
	board[0][6].piece = &bP1;
	board[1][6].piece = &bP2;
	board[2][6].piece = &bP3;
	board[3][6].piece = &bP4;
	board[4][6].piece = &bP5;
	board[5][6].piece = &bP6;
	board[6][6].piece = &bP7;
	board[7][6].piece = &bP8;

	board[0][7].piece = &bR1;
	board[1][7].piece = &bN1;
	board[2][7].piece = &bB1;
	board[3][7].piece = &bQ;
	board[4][7].piece = &bK;
	board[5][7].piece = &bB2;
	board[6][7].piece = &bN2;
	board[7][7].piece = &bR2;
	



}

bool Gameplay::isMoveCommandValid(String move)
{
	//example command: move d2 d4 
	if (move.getLen() != 10) {
		return false;
	}
	else if (move[0] != 'm' || move[1] != 'o' || move[2] != 'v' || move[3] != 'e' || move[4] != ' ' || move[7] != ' ') {
		return false;
	}
	else if (move[5] < 'a' || move[5] > 'h' || move[6] < '1' || move[6] > '8' || move[8] < 'a' || move[8] > 'h' || move[9] < '1' || move[9] > '8') {
		return false;
	}
	return true;
}

bool Gameplay::canMove(String move, Board board[8][8])
{
	//converting the move command to integers
	int fromLetter;
	int fromNumber;
	int toLetter;
	int toNumber;
	int currentPlayer = 1;
	if (isMoveCommandValid(move)) {
		if (move[5] == 'a') {
			fromLetter = 0;
		}
		else if (move[5] == 'b') {
			fromLetter = 1;
		}
		else if (move[5] == 'c') {
			fromLetter = 2;
		}
		else if (move[5] == 'd') {
			fromLetter = 3;
		}
		else if (move[5] == 'e') {
			fromLetter = 4;
		}
		else if (move[5] == 'f') {
			fromLetter = 5;
		}
		else if (move[5] == 'g') {
			fromLetter = 6;
		}
		else {
			fromLetter = 7;
		}

		if (move[6] == '1') {
			fromNumber = 0;
		}
		else if (move[6] == '2') {
			fromNumber = 1;
		}
		else if (move[6] == '3') {
			fromNumber = 2;
		}
		else if (move[6] == '4') {
			fromNumber = 3;
		}
		else if (move[6] == '5') {
			fromNumber = 4;
		}
		else if (move[6] == '6') {
			fromNumber = 5;
		}
		else if (move[6] == '7') {
			fromNumber = 6;
		}
		else {
			fromNumber = 7;
		}

		if (move[8] == 'a') {
			toLetter = 0;
		}
		else if (move[8] == 'b') {
			toLetter = 1;
		}
		else if (move[8] == 'c') {
			toLetter = 2;
		}
		else if (move[8] == 'd') {
			toLetter = 3;
		}
		else if (move[8] == 'e') {
			toLetter = 4;
		}
		else if (move[8] == 'f') {
			toLetter = 5;
		}
		else if (move[8] == 'g') {
			toLetter = 6;
		}
		else {
			toLetter = 7;
		}

		if (move[9] == '1') {
			toNumber = 0;
		}
		else if (move[9] == '2') {
			toNumber = 1;
		}
		else if (move[9] == '3') {
			toNumber = 2;
		}
		else if (move[9] == '4') {
			toNumber = 3;
		}
		else if (move[9] == '5') {
			toNumber = 4;
		}
		else if (move[9] == '6') {
			toNumber = 5;
		}
		else if (move[9] == '7') {
			toNumber = 6;
		}
		else {
			toNumber = 7;
		}
	}

	else {
		std::cout << "Invalid move command" << std::endl;
		return false;
	}

	if (board[fromLetter][fromNumber].piece == nullptr) {
		std::cout << "There is no piece on that square" << std::endl;
		return false;
	}

	if (board[fromLetter][fromNumber].piece->getPlayer() != currentPlayer) {
		std::cout << "You cant move your opponents's pieces" << std::endl;
		return false;
	}

	if (board[fromLetter][fromNumber].piece->getPlayer() == board[toLetter][toNumber].piece->getPlayer()) {
		std::cout << "You cant land on your pieces" << std::endl;
		return false;
	}

	//helper ints to determine how many squares did the piece move
	//for example: if a pawns colDiff is bigger than 2 after first move or bigger than 1 after a move(!=first)
	int colDiff = abs(toLetter - fromLetter);
	int rowlDiff = abs(toNumber - fromNumber);


	//checking for every piece
	if (board[fromLetter][fromNumber].piece->getName() == "Pawn" ) {

	}

	if (board[fromLetter][fromNumber].piece->getName() == "Rook") {

	}

	if (board[fromLetter][fromNumber].piece->getName() == "Knight") {

	}

	if (board[fromLetter][fromNumber].piece->getName() == "Bishop") {

	}

	if (board[fromLetter][fromNumber].piece->getName() == "Queen") {

	}

	if (board[fromLetter][fromNumber].piece->getName() == "King") {

	}

	

	//to be realised
	
	
	 // currPlayer = 2, currPlayer = 1 (after every move)
	/*
	 for(int i = 0 ; i < toLetter; i++) for(int j = 0; j < toNumber; j++)  if board[][].piece != nullptr
	 std::cout << "There is a piece at [i][j] blocking your move;
	 
	*/
	/*if (board[toLetter][toNumber].piece != nullptr && board[toLetter][toNumber].piece->getPlayer() != currPlayer) {

			std::cout << "You have taken the " << board[toLetter][toNumber].piece.getName() << " of your opponent" << std::endl;

			board[toLetter][toNumber].piece = board[fromLetter][fromNumber].piece;	//our piece from starting position is now on new position
			board[fromLetter][fromNumber].piece = nullptr; //our starting position is now empty

			return true;
		}

		else {
			board[toLetter][toNumber].piece = board[fromLetter][fromNumber].piece;	//our piece from starting position is now on new position
			board[fromLetter][fromNumber].piece = nullptr; //our starting position is now empty

			return true;


		}*/
}
