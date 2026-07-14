#ifndef _ARCHER_H_
#define _ARCHER_H_

#include "monster.h"

class Archer : public Player {
public:
	Archer(const string name, const int stats[], const int potions[]) : Player(name, stats, potions) {
		cout << "* You became a Archer! (HP +30)" << endl;
		this->job = "Archer";
		this->stats[0] += 30;
	}

	void attack(void);

	~Archer(void) {
		cout << "See you!" << endl;
	}
};

void Archer::attack(void) {
	cout << "* Shoot a bow!" << endl;
}

#endif
