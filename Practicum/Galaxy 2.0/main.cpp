#include <iostream>
#include <cstring>
#include "Jedi.h"
#include "Stormtrooper.h"
#include "Planet.h" 

int main() {
	
	Planet sezer;
	printPlanet(sezer); //printing by default
	sezer.setName("Sezer"); //testing my setters 
	sezer.setPlanetSystem("Lunna");
	sezer.setRepublic("Dominic");
	sezer.setPlanetType(ice);
	printPlanet(sezer);
	

	std::cout << sezer.getName() << std::endl; //testing a getter
	
	Planet enise("Enise", "Solar", "GreenRepublic",ocean); //declaring parameters
	printPlanet(enise);
	enise = sezer; //using operator =  (enise is already initialized)
	printPlanet(enise);
	
	Stormtrooper sezer_trooper;
	sezer_trooper.setRank(corporal); //testing enum
	sezer_trooper.print();

	Jedi sezer_jedi;
	sezer_jedi.print();
	Jedi enise_jedi("Enise", youngling, 16.4, "Yoda", "Commander", enise);
	enise_jedi.print();
	Jedi anakin_jedi(sezer_jedi); //using copy constructor (initializing anakin) {this is the difference between operator= and copy constructor}
	anakin_jedi.print();

	std::cout << std::endl;
	std::cout << "///zadacha2///" << std::endl;
	std::cout << std::endl;

	Jedi jedi2;
	jedi2.zadacha2();

	Stormtrooper stormtrooper2;
	stormtrooper2.zadacha2();

	Planet planet2;
	planet2.zadacha2();


	return 0;
}