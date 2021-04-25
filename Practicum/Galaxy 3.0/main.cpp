#include <iostream>
#include <cstring>
#include "Jedi.h"
#include "Stormtrooper.h"
#include "Planet.h" 
#include "Battleship.h"



int main() {
	
	/*Planet sezer;
	//printPlanet(sezer); //printing by default
	sezer.setName("Sezer"); //testing my setters 
	sezer.setPlanetSystem("Lunna");
	sezer.setRepublic("Dominic");
	sezer.setPlanetType(ice);
	printPlanet(sezer);
	
	Planet test;
	printPlanet(test);

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
	*/
	/*Planet eni;
	std::cin >> eni;
	std::cout << eni;
	
	
	Jedi sez;
	std::cin >> sez;
	std::cout << sez;

	Stormtrooper str;
	std::cin >> str;
	std::cout << str;
    */

	Planet enise("Enise", "Solar", "GreenRepublic", ocean);
	Jedi enise_jedi("Enise", youngling, 16.4, "Yoda", "Commander", enise);
	BattleShip<Jedi>eni;
	eni.setHyperJump(true);
	eni.setNumberOfWeapons(16);
	eni.setSize(50);
	eni.setSpeed(90);
	eni.setPilot(enise_jedi);
	eni.print();
	
	Stormtrooper sezer("SEZER-23", "Student", sergeant, enise);
	BattleShip<Stormtrooper>sez;
	sez.setHyperJump(false);
	sez.setNumberOfWeapons(23);
	sez.setSize(80);
	sez.setSpeed(120);
	sez.setPilot(sezer);
	std::cout << sez;





	

	return 0;
}