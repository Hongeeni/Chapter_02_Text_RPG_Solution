#ifndef _THIEF_H_
#define _THIEF_H_

#include "character.h"

class Thief : public Player {
	int specialAttackCost = 13;

public:
	Thief(const string name, const int stats[]);

	//setter
	const void setSpecialAttackCost(int cost);
	//getter
	int getSpecialAttackCost(void);

	void getPumped(void);
	void attack(Monster* monster);

	~Thief(void) {
		cout << "Thank you for playing!" << endl;
	}
};

#endif
