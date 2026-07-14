#ifndef _MAGICIAN_H_
#define _MAGICIAN_H_

#include "monster.h"

class Magician : public Player {
public:
	Magician(const string name, const int stats[]) : Player(name, stats) {
		cout << "* You became a Mage! (MP +30)" << endl;
		this->job = "Mage";
		this->mp += 30;
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
