#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace::std;
#include "Power.h";

class Student {
private:
	string name;
	string house;
	const Power *power;
	int health;

public:
	Student();
	Student(const string& n) {
		name = n;
	};

	const string& getName() {
		return name;
	};
	const string& getHouse() {
		return house;
	};

	void setHouse(const string& house) {
		this->house = house;
	};

	int getHealth() {
		return health;
	};

	void takeDamage(int damage) {
		health -= damage;
	};
	void setPower(const Power* power) {
		this->power = power;
	};
	const Power* getPower() {
		return power;
	};
	bool isAlive() {
		return health > 0;
	};
	int attack() {
		if (power == nullptr) {
			return 0;
		};

		return power->getDamage();
	};
};

#endif // STUDENT_H
