#ifndef _THIEF_H_
#define _THIEF_H_

#include "monster.h"

class Thief : public Player {
public:
	Thief(const string name, const int stats[], const int potions[]) : Player(name, stats, potions) {
		cout << "* You became a Rogue! (Attack +30)" << endl;
		this->job = "Rogue";
		this->stats[2] += 30;
	}

	void attack(void);

	~Thief(void) {
		cout << "See you!" << endl;
	}
};

void Thief::attack(void) {
	cout << "* Wield a dagger!" << endl;
}

#endif
