#include <iostream>
#include <cstring>
#include "Jedi.h"
#include "Stormtrooper.h"
#include "Planet.h" 

int main() {
	Jedi sezer;
	Jedi enise("Enise", Jedi::youngling, 16.4, "Yoda", "Commander");
	sezer.print();
	enise.print();

	Stormtrooper player;
	Stormtrooper traicho("Traicho", "Asistent", Stormtrooper::sergeant);
	traicho.print();
	//player.print();
	
	Planet fmi;
	Planet earth("Earth", "Sluncheva", "BG");
	fmi.print();


	return 0;
}