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
	int hp = 0;
	int mp = 0;
	int power = 0;
	int defence = 0;

public:
	Player(const string name, const int stats[]) {
		this->name = name;
		this->hp = stats[0];
		this->mp = stats[1];
		this->power = stats[2];
		this->defence = stats[3];
	}

	//setter
	void setName(string newName) {
		this->name = newName;
	}
	void setJob(string newJob) {
		this->job = newJob;
	}
	void setHP(int newHP) {
		this->hp = newHP;
	}
	void setMP(int newMP) {
		this->mp = newMP;
	}
	void setPower(int newPower) {
		this->power = newPower;
	}
	void setDefence(int newDefence) {
		this->defence = newDefence;
	}

	//getter
	const string getName(void) {
		return this->name;
	}
	const string getJob(void) {
		return this->job;
	}
	const int getHP(void) {
		return this->hp;
	}
	const int getMP(void) {
		return this->mp;
	}
	const int getPower(void) {
		return this->power;
	}
	const int getDefence(void) {
		return this->defence;
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
	cout << "HP: " << this->hp << " | MP: " << this->mp << " | Attack: " << this->power << " | Defence: " << this->defence << endl;
	cout << "===========================================" << endl;

	cout << endl;
}

#endif
