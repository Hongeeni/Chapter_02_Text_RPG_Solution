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
	//stats[0] = maxHP, stats[1] = maxMP, stats[2] = ATK, stats[3] = DEF
	int stats[4] = { 0 };

	//inventory
	vector<Item> inventory;

public:
	Player(const string name, const int stats[]) {
		this->name = name;
		this->stats[0] = stats[0];	// maxHP
		this->stats[1] = stats[1];	// maxMP
		this->stats[2] = stats[2];	// ATK
		this->stats[3] = stats[3];	// DEF
		setPotions();				// Hp and Mp potions
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
	void pushItem(Item item) {
		this->inventory.push_back(item);
	}
	void popItem(Item item) {
		this->inventory.pop_back();
	}
	void setPotions(int defaultPotions = 5) {
		Item hpPotion = { "HP Potion", defaultPotions, 50 };
		Item mpPotion = { "MP Potion", defaultPotions, 50 };
		this->inventory.push_back(hpPotion);
		this->inventory.push_back(mpPotion);
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
	const vector<Item> getInventory(void) {
		return this->inventory;
	}

	//Player Information
	const void printPlayerStatus(void);
	const void printInventory(void);
	//Player Inventory
	void useItem(void);
	void inventoryItemDelete(string itemName);
	void inventoryItemDelete(Item item);
	void setInventoryItem(string itemName, int numberOfItems);
	void setInventoryItem(Item item, int numberOfItems);
	const Item getInventoryItem(string itemName);
	const Item getInventoryItem(Item item);
	//Player Level
	void gainExp(int expReward);

	virtual void getPumped(void) = 0;
	virtual void attack(Monster* monster) = 0;

	virtual ~Player() {
		cout << "See you!" << endl;
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
	for (int i = 0; i < this->inventory.size(); i++) {
		if (this->inventory[i].numOfItems == 0) {
			this->inventoryItemDelete(this->inventory[i]);
		}
	}

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
void Player::useItem(void) {
	string userInput = "None";
	int inputItem = 0;

	do {
		this->printInventory();
		cout << "Choose Item Number: ";
		cin >> userInput;
		cout << endl;

		if (userInput > "0" && userInput <= "9") {
			inputItem = stoi(userInput) - 1;
		}
		else if (userInput == "10") {
			inputItem = 9;
		}
		else {
			cout << "Invalid input. Try again.\n" << endl;
			continue;
		}

		if (inputItem >= 0 && inputItem < this->inventory.size()) {
			if (this->inventory[inputItem].name == "HP Potion") {
				this->setInventoryItem("HP Potion", (this->getInventoryItem("HP Potion").numOfItems - 1));
				this->setHP(this->getHP() + 20);
				cout << "* HP increased by 20. (HP Potion used: " << this->getInventoryItem("HP Potion").numOfItems << " left)\n" << endl;
			}
			else if (this->inventory[inputItem].name == "MP Potion") {
				this->setInventoryItem("MP Potion", (this->getInventoryItem("MP Potion").numOfItems - 1));
				this->setMP(this->getMP() + 20);
				cout << "* MP increased by 20. (MP Potion used: " << this->getInventoryItem("MP Potion").numOfItems << " left)\n" << endl;
			}
			else {
				cout << "That item is currently unavailable.\n" << endl;
				inputItem = 0;
			}
		}
		else {
			cout << "No items in that slot.\n" << endl;
			inputItem = 0;
		}
	} while (inputItem < 0 && inputItem >= 10);
}
void Player::inventoryItemDelete(string itemName) {
	for (int i = 0; i < this->inventory.size(); i++) {
		if (this->inventory[i].name == itemName) {
			this->inventory.erase(this->inventory.begin()+i);
			break;
		}
	}
}
void Player::inventoryItemDelete(Item item) {
	for (int i = 0; i < this->inventory.size(); i++) {
		if (this->inventory[i].name == item.name) {
			this->inventory.erase(this->inventory.begin() + i);
			break;
		}
	}
}
void Player::setInventoryItem(string itemName, int numberOfItems) {
	bool isItem = false;
	for (int i = 0; i < this->inventory.size(); i++) {
		if (this->inventory[i].name == itemName) {
			this->inventory[i].numOfItems = numberOfItems;
			isItem = true;
			break;
		}
	}
	if (!isItem) {
		cout << "You don't have item in your inventory." << endl;
	}
}
void Player::setInventoryItem(Item item, int numberOfItems) {
	bool isItem = false;
	for (int i = 0; i < this->inventory.size(); i++) {
		if (this->inventory[i].name == item.name) {
			this->inventory[i].numOfItems = numberOfItems;
			isItem = true;
			break;
		}
	}
	if (!isItem) {
		this->inventory.push_back(item);
	}
}
const Item Player::getInventoryItem(string itemName) {
	bool isItem = false;
	for (int i = 0; i < this->inventory.size(); i++) {
		if (this->inventory[i].name == itemName) {
			return this->inventory[i];
		}
	}
	if (!isItem) {
		Item item;
		return item;
	}
}
const Item Player::getInventoryItem(Item item) {
	bool isItem = false;
	for (int i = 0; i < this->inventory.size(); i++) {
		if (this->inventory[i].name == item.name) {
			return this->inventory[i];
		}
	}
	if (!isItem) {
		Item item;
		return item;
	}
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