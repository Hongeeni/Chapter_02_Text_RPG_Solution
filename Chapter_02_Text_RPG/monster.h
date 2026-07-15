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
	Monster(string inputName = "Ghost",int inputExp = 10, int inputHP = 100, int inputPower = 100, int inputDefence = 10, string inputDropItemName = "Fragment of The Soul", int inputDropItemPrice = 5)
		: name(inputName),expReward(inputExp), hp(inputHP), power(inputPower), defence(inputDefence), dropItemName(inputDropItemName), dropItemPrice(inputDropItemPrice) {}

	//setter
	void setName(string newName) {
		this->name = newName;
	}
	void setExp(int newExp) {
		this->expReward = newExp;
	}
	void setHP(int newHP) {
		this->hp = newHP;
	}
	void setPower(int newPower) {
		this->power = newPower;
	}
	void setDefence(int newDefence) {
		this->defence = newDefence;
	}
	void setDropItemName(string newDropItemName) {
		this->dropItemName = newDropItemName;
	}
	void setDropItemPrice(int newDropItemPrice) {
		this->dropItemPrice = newDropItemPrice;
	}

	//getter
	const string getName(void) {
		return name;
	}
	const int getExp(void) {
		return expReward;
	}
	const int getHP(void) {
		return hp;
	}
	const int getPower(void) {
		return power;
	}
	const int getDefence(void) {
		return defence;
	}
	const string getDropItemName(void) {
		return dropItemName;
	}
	const int getDropItemPrice(void) {
		return dropItemPrice;
	}

	~Monster() {}
};

#endif
