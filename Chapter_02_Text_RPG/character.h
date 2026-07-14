#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <iostream>
#include <string>

using namespace std;

class Player {
protected:
	string name = "None";
	string job = "None";

	int level = 1;
	//stats[0] = HP, stats[1] = MP, stats[2] = ATK, stats[3] = DEF
	int stats[4] = { 0 };
	//potions[0] = HP_Potion, potions[1] = MP_Potion
	int potions[2] = { 5, 5 };

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

	//getter
	const string getName(void) {
		return this->name;
	}
	const string getJob(void) {
		return this->job;
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

	const void printPlayerStatus(void);

	virtual void attack() = 0;

	virtual ~Player() {
		cout << "Exiting the game." << endl;
	}
};

const void Player::printPlayerStatus(void) {
	cout << "-------------------------------------------" << endl;
	cout << "Name: " << this->name << " | Job: " << this->job << " | Lv." << this->level << endl;
	cout << "HP: " << this->stats[0] << " | MP: " << this->stats[1] << " | Attack: " << this->stats[2] << " | Defence: " << this->stats[3] << endl;
	cout << "===========================================" << endl;

	cout << endl;
}

#endif
