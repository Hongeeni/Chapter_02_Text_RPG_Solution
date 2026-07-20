#ifndef _MAGICIAN_H_
#define _MAGICIAN_H_

#include "character.h"

class Magician : public Player {
private:
	int specialAttackCost = 12;

public:
	Magician(const string name, const int stats[]);

	//setter
	const void setSpecialAttackCost(int cost);
	//getter
	int getSpecialAttackCost(void);

	void getPumped(void);
	void attack(Monster* monster);

	~Magician(void) {
		cout << "Thank you for playing!" << endl;
	}
};

#endif
