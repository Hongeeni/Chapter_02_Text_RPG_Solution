#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "character.h"

class Monster {
protected:
	string name = "None";
	int hp = 0;
	int power = 0;
	int defence = 0;

	string dropItemName = "None";
	int dropItemPrice = 0;

public:
	Monster(string inputName = "Slime", int inputHP = 100, int inputPower = 200, int inputDefence = 70, string inputDropItemName = "Slime Jelly", int inputDropItemPrice = 5)
		: name(inputName), hp(inputHP), power(inputPower), defence(inputDefence), dropItemName(inputDropItemName), dropItemPrice(inputDropItemPrice) {}

	//setter
	void setName(string newName) {
		this->name = newName;
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

	void attack(Player* player);

	~Monster() {
		cout << "Proceed Next turn!\n" << endl;
	}
};

void Monster::attack(Player* player) {
	bool isPlayerTurn = rand() % 2;

	int tempHP = 0;

	int playerATK = 0;
	if (this->getPower() - this->getDefence() <= 0) {
		playerATK = 1;
	}
	else {
		playerATK = this->getPower() - this->getDefence();
	}

	int monsterATK = 0;
	if (this->getPower() - player->getDefence() <= 0) {
		monsterATK = 1;
	}
	else {
		monsterATK = this->getPower() - player->getDefence();
	}

	cout << "[ Battle Start! ] " << player->getName() << "(" << player->getJob() << ") VS " << this->getName() << endl;
	cout << endl;

	do {
		if (isPlayerTurn) {
			cout << "--- Player's Turn ---" << endl;
			player->attack();
			cout << playerATK << " damage to " << this->getName() << " !" << endl;

			tempHP = this->getHP();
			this->setHP(this->getHP() - playerATK);

			if (this->getHP() > 0) {
				cout << this->getName() << " HP: " << tempHP << " => " << this->getHP() << endl;
			}
			else {
				Item item;
				item.name = this->getDropItemName();
				item.price = this->getDropItemPrice();

				cout << this->getName() << " HP: " << tempHP << " => " << this->getHP() << " (Dead)\n" << endl;
				cout << "* Victory!" << endl;
				cout << "	=> Got: " << this->getDropItemName() << "!" << endl;

				if (player->getInventory().size() < 10) {
					player->pushItem(item);
					cout << "	=> Saved to inventory." << endl;
				}
				else {
					cout << "	=> Inventory is full." << endl;
				}
			}

			isPlayerTurn = !isPlayerTurn;
		}
		else {
			cout << "--- Monster's Turn ---" << endl;
			cout << "The slime lunged!" << endl;
			cout << monsterATK << " damage to " << player->getName() << " !" << endl;

			tempHP = player->getHP();
			player->setHP(player->getHP() - monsterATK);

			if (player->getHP() > 0) {
				cout << player->getName() << " HP: " << tempHP << " => " << player->getHP() << endl;
			}
			else {
				cout << player->getName() << " HP: " << tempHP << " => " << player->getHP() << " (Dead)\n" << endl;
				cout << "* The End..." << endl;

				player->setHP(0);
			}

			isPlayerTurn = !isPlayerTurn;
		}

		cout << endl;
	} while (player->getHP() > 0 && this->getHP() > 0);
}

#endif
