#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "item.h"

class Monster {
protected:
	string name = "None";
	int expReward = 0;
	int hp = 0;
	int power = 0;
	int defence = 0;

	string dropItemName = "None";
	int dropItemPrice = 0;

public:
	Monster(string inputName = "Ghost", int inputExp = 10, int inputHP = 100, int inputPower = 100, int inputDefence = 10, string inputDropItemName = "Fragment of The Soul", int inputDropItemPrice = 5);

	//setter
	void setName(string newName);
	void setExp(int newExp);
	void setHP(int newHP);
	void setPower(int newPower);
	void setDefence(int newDefence);
	void setDropItemName(string newDropItemName);
	void setDropItemPrice(int newDropItemPrice);

	//getter
	const string getName(void);
	const int getExp(void);
	const int getHP(void);
	const int getPower(void);
	const int getDefence(void);
	const string getDropItemName(void);
	const int getDropItemPrice(void);

	~Monster() {}
};

#endif
