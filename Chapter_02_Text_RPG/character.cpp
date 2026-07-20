#include "character.h"

Player::Player(const string name, const int stats[]) {
	this->name = name;
	this->currentHP = stats[0];	// currentHP
	this->currentMP = stats[1];	// currentMP
	this->stats[0] = stats[0];	// maxHP
	this->stats[1] = stats[1];	// maxMP
	this->stats[2] = stats[2];	// ATK
	this->stats[3] = stats[3];	// DEF
	setPotions();				// Hp and Mp potions
}


//setter
void Player::setName(string newName) {
	this->name = newName;
}
void Player::setJob(string newJob) {
	this->job = newJob;
}
void Player::setLv(int newLv) {
	this->level = newLv;
}
void Player::setCurrentHP(int newHP) {
	this->currentHP = newHP;
}
void Player::setCurrentMP(int newMP) {
	this->currentMP = newMP;
}
void Player::setDefAttackCost(int cost) {
	this->defAttackCost = cost;
}
void Player::setMaxHP(int newHP) {
	this->stats[0] = newHP;
}
void Player::setMaxMP(int newMP) {
	this->stats[1] = newMP;
}
void Player::setPower(int newPower) {
	this->stats[2] = newPower;
}
void Player::setDefence(int newDefence) {
	this->stats[3] = newDefence;
}
void Player::pushItem(Item item) {
	this->inventory.push_back(item);
}
void Player::popItem(Item item) {
	this->inventory.pop_back();
}
void Player::setPotions(int defaultPotions = 5) {
	Item hpPotion = { "HP Potion", defaultPotions, 50 };
	Item mpPotion = { "MP Potion", defaultPotions, 50 };
	this->inventory.push_back(hpPotion);
	this->inventory.push_back(mpPotion);
}

//getter
const string Player::getName(void) {
	return this->name;
}
const string Player::getJob(void) {
	return this->job;
}
const int Player::getLv(void) {
	return this->level;
}
const int Player::getCurrentHP(void) {
	return this->currentHP;
}
const int Player::getCurrentMP(void) {
	return this->currentMP;
}
const int Player::getDefAttackCost(void) {
	return this->defAttackCost;
}
const int Player::getMaxHP(void) {
	return this->stats[0];
}
const int Player::getMaxMP(void) {
	return this->stats[1];
}
const int Player::getPower(void) {
	return this->stats[2];
}
const int Player::getDefence(void) {
	return this->stats[3];
}
const vector<Item> Player::getInventory(void) {
	return this->inventory;
}

const void Player::printPlayerStatus(void) {
	cout << "===========================================" << endl;
	cout << "Name: " << this->name << " | Job: " << this->job << "\nLv." << this->level << " | Exp: " << this->exp << " / " << this->maxExp << endl;
	cout << "HP: " << this->currentHP << " / " << this->stats[0] << " | MP: " << this->currentMP << " / " << this->stats[1] << "\nAttack: " << this->stats[2] << " | Defence: " << this->stats[3] << endl;
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
				this->setCurrentHP(this->getCurrentHP() + 20);
				cout << "* HP increased by 20. (HP Potion used: " << this->getInventoryItem("HP Potion").numOfItems << " left)\n" << endl;
			}
			else if (this->inventory[inputItem].name == "MP Potion") {
				this->setInventoryItem("MP Potion", (this->getInventoryItem("MP Potion").numOfItems - 1));
				this->setCurrentMP(this->getCurrentMP() + 20);
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
			this->inventory.erase(this->inventory.begin() + i);
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
		cout << "	=> +" << expReward - (this->exp - this->maxExp) << " EXP! (EXP: " << this->maxExp << "/" << this->maxExp << ")\n\n	=> Level UP! (Lv." << this->level << " => Lv." << (this->level) + 1 << ")" << endl;
		cout << "	=> HP +" << this->stats[0] / 2 << ", MP +" << this->stats[1] / 2 << ", Attack +" << (this->stats[2]) / 4 << ", Defence +" << (this->stats[3]) / 4 << endl;

		for (int i = 0; i < 2; i++) {
			this->stats[i] += this->stats[i] / 3;
			this->stats[i + 2] += (this->stats[i + 2]) / 5;
		}
		this->currentHP = this->stats[0];
		this->currentMP = this->stats[1];
		this->exp = 0;
		this->maxExp = (maxExp * 4) / 3;
		this->level++;
	}
	else {
		cout << "	=> +" << expReward << " EXP! (EXP: " << this->exp << "/" << this->maxExp << ")" << endl;
	}
}