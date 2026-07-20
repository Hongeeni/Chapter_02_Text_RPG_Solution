#ifndef _WARRIOR_H_
#define _WARRIOR_H_

#include "character.h"

class Warrior : public Player {
private:
	int specialAttackCost = 12;

public:
	Warrior(const string name, const int stats[]);

	//setter
	const void setSpecialAttackCost(int cost);
	//getter
	int getSpecialAttackCost(void);

	void getPumped(void);
	void attack(Monster* monster);

	~Warrior(void) {
		cout << "Thank you for playing!" << endl;
	}
};

#endif
