#pragma once
#include <iostream>
#include <cstring>
#include "Jedi.h"
#include "Stormtrooper.h"

enum Equipment { heavy, medium, light };
template<typename T>
class BattleShip {
private:
	int speed;
	int numberOfWeapons;
	bool hyperJump;
	double size;
	T pilot;
	double fuel;
	Equipment equipment;
	int armor;
	
public:
	void setSpeed(int _speed) {
		speed = _speed;
	}
	int getSpeed() const {
		return speed;
	}
	void setNumberOfWeapons(int _numberOfWeapons) {
		numberOfWeapons = _numberOfWeapons;
	}
	int getNumberOfWeapons() const {
		return numberOfWeapons;
	}
	void setHyperJump(bool _hyperJump) {
		hyperJump = _hyperJump;
	}
	bool getHyperJump() const {
		return hyperJump;
	}
	void setSize(int _size) {
		size = _size;
	}
	int getSize() const {
		return size;
	}
	void setPilot(T _pilot) {
		try {
			if (typeid(pilot) == typeid(Jedi) || typeid(pilot) == typeid(Stormtrooper)) {
				pilot = _pilot;
			}
			else {
				throw("Invalid pilot");
			}
		}
		catch (const char* error) {
			std::cout << error << std::endl;
		}
	}
	T getPilot() const {
		return pilot;
	}
	void setFuel(double _fuel) {
		fuel = _fuel;
	}
	double getFuel() const {
		return fuel;
	}
	void setEquipment(Equipment _equipment) {
		equipment = _equipment;
	}
	Equipment getEquipment() const {
		return equipment;
	}
	void setArmor(int _armor) {
		armor = _armor;
	}
	int getArmor() const {
		return armor;
	}

	void print() const{
		std::cout << "Battleship information:" << std::endl;
		std::cout << "Speed: " << speed << std::endl;
		std::cout << "Number of weapons: " << numberOfWeapons << std::endl;
		std::cout << "Has ability to Hyper Jump: ";
		if (hyperJump) {
			std::cout << "Yes" << std::endl;
		}
		else {
			std::cout << "No" << std::endl;
		}
		std::cout << "Size: " << size << std::endl;
		std::cout << "Pilot of the Battleship information: " << std::endl;
		std::cout << pilot << std::endl;
	}
	

	BattleShip(){
		speed = 0;
		numberOfWeapons = 0;
		hyperJump = false;
		size = 0;
		pilot = {};
	}
	
	BattleShip(const int _speed, const int _numberOfWeapons, const bool _hyperJump, const double _size, const T _pilot) {
		speed = _speed;
		numberOfWeapons = _numberOfWeapons;
		hyperJump = _hyperJump;
		size = _size;
		try {
			if (typeid(pilot) == typeid(Jedi) || typeid(pilot) == typeid(Stormtrooper)) {
				pilot = _pilot;
			}
			else {
				throw("Invalid pilot");
			}
		}
		catch (const char* error) {
			std::cout << error << std::endl;
		}
	}
	BattleShip(const BattleShip& other) {
		speed = other.speed;
		numberOfWeapons = other.numberOfWeapons;
		hyperJump = other.hyperJump;
		size = other.size;
		pilot = other.pilot;
	}

	BattleShip& operator=(const BattleShip& other) {
		if (this != other) {
			speed = other.speed;
			numberOfWeapons = other.numberOfWeapons;
			hyperJump = other.hyperJump;
			size = other.size;
			pilot = other.pilot;
		}
		return *this;
	}

	
	friend std::ostream& operator<< (std::ostream& os, const BattleShip& _BattleShip) {
		std::cout << "Battleship information:" << std::endl;
		os << "Speed: " << _BattleShip.speed << std::endl;
		os << "Number of weapons: " << _BattleShip.numberOfWeapons << std::endl;
		os << "Has ability to Hyper Jump: ";
		if (_BattleShip.hyperJump) {
			os << "Yes" << std::endl;
		}
		else {
			os << "No" << std::endl;
		}
		os << "Size: " << _BattleShip.size << std::endl;
		os << "Pilot of the Battleship information: " << std::endl;
		os << _BattleShip.pilot << std::endl;

		return os;
	}
	
	friend std::istream& operator>> (std::istream& is, BattleShip& _BattleShip) {
		std::cout << "Please enter: speed, number of weapons, hyperjump, size, pilot" << std::endl;
		is >> _BattleShip.speed >> _BattleShip.numberOfWeapons;
		std::cout << "Enter 1 for \"true\" and 0 for \"false\": ";
		is >> _BattleShip.hyperJump >> _BattleShip.size >> _BattleShip.pilot;
		return is;
	}



};

