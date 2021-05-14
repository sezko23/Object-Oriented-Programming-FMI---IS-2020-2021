#include <iostream>
#include "Board.h"
#include "Gameplay.h"

int main() {
	String name("move d2 d4");
	std::cout << name.getLen() << std::endl;
	Gameplay g;
	std::cout << g.isMoveCommandValid(name) << std::endl;
}