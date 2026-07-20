#ifndef _ARCHER_H_
#define _ARCHER_H_

#include "character.h"

class Archer : public Player {
	int specialAttackCost = 13;

public:
	Archer(const string name, const int stats[]);

	//setter
	const void setSpecialAttackCost(int cost);
	//getter
	int getSpecialAttackCost(void);

	void getPumped(void);
	void attack(Monster* monster);

	~Archer(void) {
		cout << "Thank you for playing!" << endl;
	}
};

#endif
