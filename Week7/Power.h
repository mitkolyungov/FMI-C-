#ifndef POWER_H
#define POWER_H
#include <string>
using namespace::std;


class Power {
private:
	string name;
	int damage;

public:
	Power();
	Power(const string& n, int dam) {
		name = n;
		damage = dam;
	};

	const string& getName() {
		return name;
	};
	int getDamage() const {
		return damage;
	};

	bool operator<(const Power& other) {
		return damage < other.damage;
	};
};

#endif  // POWER_H
