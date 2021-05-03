#pragma once
#include <iostream>
#include <cstring>
#include "Jedi.h"
#include "Stormtrooper.h"
#include "MyVector.h"

enum Equipment { light, medium, heavy };
template<typename T>
class BattleShip {
private:
	int speed;
	int numberOfWeapons;
	bool hyperJump;
	double size;
	double fuel;
	Equipment equipment;
	int armor;
	T pilot;
	void copy(const BattleShip& other) {
		speed = other.speed;
		numberOfWeapons = other.numberOfWeapons;
		hyperJump = other.hyperJump;
		size = other.size;
		fuel = other.fuel;
		equipment = other.equipment;
		armor = other.armor;
		pilot = other.pilot;
	}
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
		std::cout << "Fuel: " << fuel << "%" << std::endl;
		std::cout << "Equipment: ";
		switch (equipment) {
		case 0:
			std::cout << "Light" << std::endl;
			break;
		case 1:
			std::cout << "Medium" << std::endl;
			break;
		case 2:
			std::cout << "Heavy" << std::endl;
			break;
		default:
			std::cout << "Invalid equipment type!" << std::endl;
			break;
		}
		std::cout << "Armor: " << armor << "%" << std::endl;
		std::cout << "Pilot of the Battleship information: " << std::endl;
		std::cout << pilot << std::endl;
	}
	

	BattleShip(){
		speed = 0;
		numberOfWeapons = 0;
		hyperJump = false;
		size = 0;
		fuel = 0;
		equipment = light;
		armor = 0;
		pilot = {};
	}
	
	BattleShip(const int _speed, const int _numberOfWeapons, const bool _hyperJump, const double _size, const int _fuel, const Equipment _equipment, const int _armor, const T _pilot) {
		speed = _speed;
		numberOfWeapons = _numberOfWeapons;
		hyperJump = _hyperJump;
		size = _size;
		fuel = _fuel;
		equipment = _equipment;
		armor = _armor;
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
		copy(other);

	}

	BattleShip& operator=(const BattleShip& other) {
		copy(other);
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
		os << "Fuel: " << _BattleShip.fuel << "%" << std::endl;
		os << "Equipment: ";
		switch (_BattleShip.equipment) {
		case 0:
			std::cout << "Light" << std::endl;
			break;
		case 1:
			std::cout << "Medium" << std::endl;
			break;
		case 2:
			std::cout << "Heavy" << std::endl;
			break;
		default:
			std::cout << "Invalid equipment type!" << std::endl;
			break;
		}
		os << "Armor: " << _BattleShip.armor << "%" << std::endl;
		os << "Pilot of the Battleship information: " << std::endl;
		os << _BattleShip.pilot << std::endl;

		return os;
	}
	
	friend std::istream& operator>> (std::istream& is, BattleShip& _BattleShip) {
		int equipment_number;
	
		std::cout << "Enter speed: ";
		is >> _BattleShip.speed;
		std::cout << "Enter number of weapons: ";
		is >> _BattleShip.numberOfWeapons;
		std::cout << "Enter 1 for \"true\" and 0 for \"false\" for Hyper Jump: ";
		is >> _BattleShip.hyperJump;
		std::cout << "Enter size: ";
		is >> _BattleShip.size;
		std::cout << "Enter fuel: ";
		is >> _BattleShip.fuel;
		std::cout << "Numbers for equipment: ";
		std::cout << "light = 0, medium = 1, heavy = 2" << std::endl;
		std::cout << "Enter number for equipment:";
		is >> equipment_number;
		_BattleShip.equipment = Equipment(equipment_number);
		std::cout << "Enter armor: ";
		is >> _BattleShip.armor;
		std::cout << "Enter pilot: ";
		is >> _BattleShip.pilot;

		return is;
	}

	void refuel() {
		fuel = 100;
	}

	void changeEquipment(const Equipment _equipment) {
		if (equipment = _equipment) {
			std::cout << "Battleship already has this equipment!" << std::endl;
		}
		else {
			if (equipment < _equipment) {
				speed -= 20 * _equipment;
				equipment = _equipment;
			}
			else {
				speed += 50 + (20 * _equipment);
				equipment = _equipment;
			}
			
		}
	}


};

