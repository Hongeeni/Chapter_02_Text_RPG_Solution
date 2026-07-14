#ifndef _WARRIOR_H_
#define _WARRIOR_H_

#include "monster.h"

class Warrior : public Player {
public:
	Warrior(const string name, const int stats[], const int potions[]) : Player(name, stats, potions) {
		cout << "* You became a Warrior! (Defence +30)" << endl;
		this->job = "Warrior";
		this->stats[3] += 30;
	}

	void attack(void);

	~Warrior(void) {
		cout << "See you!" << endl;
	}
};

void Warrior::attack(void) {
	cout << "* Wield a shield!" << endl;
}

#endif
