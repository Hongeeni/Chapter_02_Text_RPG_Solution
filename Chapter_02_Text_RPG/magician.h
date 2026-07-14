#ifndef _MAGICIAN_H_
#define _MAGICIAN_H_

#include "monster.h"

class Magician : public Player {
public:
	Magician(const string name, const int stats[], const int potions[]) : Player(name, stats, potions) {
		cout << "* You became a Mage! (MP +30)" << endl;
		this->job = "Mage";
		this->stats[1] += 30;
	}

	void attack(void);

	~Magician(void) {
		cout << "See you!" << endl;
	}
};

void Magician::attack(void) {
	cout << "* Fires a fireball!" << endl;
}

#endif
