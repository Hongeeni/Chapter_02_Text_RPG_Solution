#ifndef _THIEF_H_
#define _THIEF_H_

#include "monster.h"

class Thief : public Player {
public:
	Thief(const string name, const int stats[]) : Player(name, stats) {
		cout << "* You became a Rogue! (Attack +30)" << endl;
		this->job = "Rogue";
		this->power += 30;
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
