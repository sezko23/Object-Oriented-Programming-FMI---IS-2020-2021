#include <iostream>
#include <cstring>
#include <functional>
#include "Jedi.h"
#include "Stormtrooper.h"
#include "Planet.h" 
#include "Battleship.h"
#include "MyVector.h"
#include "MyString.h"
#include "LList.h"


template<typename T>
void refuel(BattleShip<T>& battleship, LList<MyString>& activityLog) 
{
	battleship.setFuel(100);
	activityLog.pushBack("Refuelled ship.");
}

template <typename T>
void changeEquipment(BattleShip<T>& battleship, Equipment equipment, LList<MyString>& activityLog)
{
	if (battleship.getEquipment() == equipment) 
	{
		std::cout << "Battleship already has this equipment!" << std::endl;
	}
	else if (battleship.getEquipment() < equipment)
	{
		if (equipment == heavy) 
		{
			battleship.setSpeed(battleship.getSpeed() / 4);
			battleship.setEquipment(equipment);
		}
		else 
		{
			battleship.setSpeed(battleship.getSpeed() / 2);
			battleship.setEquipment(equipment);
		}
	}
	else
	{
		if(equipment == light)
		{
			battleship.setSpeed(battleship.getSpeed() * 4);
			battleship.setEquipment(equipment);
		}
		else 
		{
			battleship.setSpeed(battleship.getSpeed() * 2);
			battleship.setEquipment(equipment);
		}
	}
	activityLog.pushBack("Changed equipment of ship");
}

template<typename T>
void removeWeakShips(myVector<BattleShip<T>>& ships, LList<MyString>& activityLog) {
	for (int i = 0;i < ships.getSize();i++) {
		if (ships[i].getArmor() < 50) {
			ships.removeThisIndex(i);
		}
	}
	activityLog.pushBack("Removed weak ships.");
}




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

	LList<MyString> ActivityLog;
	ActivityLog.pushBack("Test1");
	ActivityLog.pushBack("Test2");
	ActivityLog.pushBack("Test3");
	ActivityLog.pushBack("Test4");
	ActivityLog.pushBack("Test5");
	ActivityLog.printLog();
	ActivityLog.reverse();
	ActivityLog.printLog();

	Planet enise("Enise", "Solar", "GreenRepublic", ocean);
	Jedi enise_jedi("Enise", youngling, 16.4, "Yoda", "Commander", enise);
	BattleShip<Jedi>eni;
	eni.setHyperJump(true);
	eni.setNumberOfWeapons(16);
	eni.setSize(50);
	eni.setSpeed(90);
	eni.setFuel(100);
	eni.setEquipment(light);
	eni.setArmor(99);
	eni.setPilot(enise_jedi);
	//eni.print();


	Stormtrooper sezer("SEZER-23", "Student", sergeant, enise);

	BattleShip<Stormtrooper>sez;
	sez.setSpeed(120);
	sez.setNumberOfWeapons(23);
	sez.setHyperJump(false);
	sez.setSize(80);
	sez.setFuel(30);
	sez.setEquipment(heavy);
	sez.setArmor(70);
	sez.setPilot(sezer);

	BattleShip<Stormtrooper>sez1(50, 10, true, 90, 70, medium, 40, sezer);
	BattleShip<Stormtrooper>sez2(40, 20, true, 80, 80, light, 70, sezer);
	BattleShip<Stormtrooper>sez3(30, 30, false, 70, 90, medium, 20, sezer);
	BattleShip<Stormtrooper>sez4(20, 40, false, 60, 100, heavy, 50, sezer);

	myVector <BattleShip<Stormtrooper>>ships;
	ships.push_back(sez);
	ships.push_back(sez1);
	ships.push_back(sez2);
	ships.push_back(sez3);
	ships.push_back(sez4);
	std::cout << ships << std::endl;
	std::cout << "----Removing weak ships----" << std::endl;
	std::cout << std::endl;
 	removeWeakShips(ships,ActivityLog);
	std::cout << ships << std::endl;
	std::cout << "----Refueling ships----" << std::endl;
	for (int i = 0;i < ships.getSize();i++) {
		refuel(ships[i], ActivityLog);
	}
	std::cout << "----Changing equipment----" << std::endl;
	changeEquipment(sez, light, ActivityLog);
	std::cout << ships << std::endl;

	ActivityLog.printLog();


	//std::cout << sez;
	/*
	sez.refuel();
	sez.changeEquipment(light);
	//std::cout << sez;


	BattleShip<Stormtrooper>alkan;
	BattleShip<Stormtrooper>alkan1;
	BattleShip<Stormtrooper>alkan2;
	BattleShip<Stormtrooper>alkan3;


	myVector<BattleShip<Stormtrooper>>ships;

	ships.push_back(alkan);
	ships.push_back(sez);
	ships.push_back(alkan1);
	ships.push_back(alkan2);
	ships.push_back(alkan3);
	
	ships.removeThisIndex(1);
	std::cout << ships;

	*/

	/*
	std::cout << sez;
	refuel(sez);
	changeEquipment(sez, light);
	std::cout << sez;
	*/

	
	/*
	std::cout << ships << std::endl;
	std::cout << ships.getSize() << std::endl;
	ships.pop_back();
	std::cout << ships << std::endl;
	std::cout << ships.getSize() << std::endl;
	*/
	//std::cout << ships[1];

	

	


	

	return 0;
}