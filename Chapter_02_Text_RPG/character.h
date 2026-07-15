#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "monster.h"

class Player {
protected:
	string name = "None";
	string job = "None";

	int level = 1;
	int exp = 0;
	int maxExp = 100;
	//stats[0] = HP, stats[1] = MP, stats[2] = ATK, stats[3] = DEF
	int stats[4] = { 0 };
	//potions[0] = HP_Potion, potions[1] = MP_Potion
	int potions[2] = { 5, 5 };

	//inventory
	vector<Item> inventory;

public:
	Player(const string name, const int stats[], const int potions[]) {
		this->name = name;
		this->stats[0] = stats[0];	// HP
		this->stats[1] = stats[1];	// MP
		this->stats[2] = stats[2];	// ATK
		this->stats[3] = stats[3];	// DEF
		this->potions[0] = potions[0];	// HP_Potion
		this->potions[1] = potions[1];	// MP_Potion
	}

	//setter
	void setName(string newName) {
		this->name = newName;
	}
	void setJob(string newJob) {
		this->job = newJob;
	}
	void setLv(int newLv) {
		this->level = newLv;
	}
	void setHP(int newHP) {
		this->stats[0] = newHP;
	}
	void setMP(int newMP) {
		this->stats[1] = newMP;
	}
	void setPower(int newPower) {
		this->stats[2] = newPower;
	}
	void setDefence(int newDefence) {
		this->stats[3] = newDefence;
	}
	void setHpPotion(int hpPotion) {
		this->potions[0] = hpPotion;
	}
	void setMpPotion(int mpPotion) {
		this->potions[1] = mpPotion;
	}
	void pushItem(Item item) {
		this->inventory.push_back(item);
	}
	void popItem(Item item) {
		this->inventory.pop_back();
	}

	//getter
	const string getName(void) {
		return this->name;
	}
	const string getJob(void) {
		return this->job;
	}
	const int getLv(void) {
		return this->level;
	}
	const int getHP(void) {
		return this->stats[0];
	}
	const int getMP(void) {
		return this->stats[1];
	}
	const int getPower(void) {
		return this->stats[2];
	}
	const int getDefence(void) {
		return this->stats[3];
	}
	const int getHpPotion(void) {
		return this->potions[0];
	}
	const int getMpPotion(void) {
		return this->potions[1];
	}
	const vector<Item> getInventory(void) {
		return this->inventory;
	}

	//Player Information
	const void printPlayerStatus(void);
	const void printInventory(void);
	//Player Level
	void gainExp(int expReward);

	virtual void getPumped(void) = 0;
	virtual void attack(Monster* monster) = 0;

	virtual ~Player() {
		cout << "Exiting the game." << endl;
	}
};

const void Player::printPlayerStatus(void) {
	cout << "===========================================" << endl;
	cout << "Name: " << this->name << " | Job: " << this->job << " | Lv." << this->level << " | Exp: " << this->exp << endl;
	cout << "HP: " << this->stats[0] << " | MP: " << this->stats[1] << " | Attack: " << this->stats[2] << " | Defence: " << this->stats[3] << endl;
	cout << "===========================================" << endl;

	cout << endl;
}

const void Player::printInventory(void) {
	cout << "===========================================\n	[ " << this->name << "'s Inventory " << this->inventory.size() << "/10 ]\n===========================================" << endl;

	for (int i = 0; i < 10; i++) {
		if (i < this->inventory.size()) {
			cout << (i + 1) << ". ";
			this->inventory[i].printInfo();
		}
		else {
			cout << (i + 1) << ". Empty" << endl;
		}
	}

	cout << "===========================================\n" << endl;
}
void Player::gainExp(int expReward) {
	this->exp += expReward;

	if (this->exp >= this->maxExp) {
		cout << "	=> +" << expReward - (this->exp - this->maxExp) << " EXP! (EXP: " << this->maxExp << "/" << this->maxExp << ")\n\n	=> Level UP! (Lv." << this->level << " => Lv." << (this->level)+1 << ")" << endl;
		cout << "	=> HP +" << this->stats[0] << ", MP +" << this->stats[1] << ", Attack +" << (this->stats[2])/2 << ", Defence +" << (this->stats[3])/2 << endl;

		for (int i = 0; i < 2; i++) {
			this->stats[i] *= 2;
			this->stats[i + 2] += (this->stats[i + 2]) / 2;
		}
		this->exp = 0;
		this->maxExp *= 4 / 3;
		this->level++;
	}
	else {
		cout << "	=> +" << expReward << " EXP! (EXP: " << this->exp << "/" << this->maxExp << ")" << endl;
	}
}
#endif