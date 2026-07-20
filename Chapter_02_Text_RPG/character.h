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
	int currentHP = 100;
	int currentMP = 100;
	int defAttackCost = 7;
	//stats[0] = maxHP, stats[1] = maxMP, stats[2] = ATK, stats[3] = DEF
	int stats[4] = { 0 };

	//inventory
	vector<Item> inventory;

public:
	Player(const string name, const int stats[]);

	//setter
	void setName(string newName);
	void setJob(string newJob);
	void setLv(int newLv);
	void setCurrentHP(int newHP);
	void setCurrentMP(int newMP);
	void setDefAttackCost(int cost);
	void setMaxHP(int newHP);
	void setMaxMP(int newMP);
	void setPower(int newPower);
	void setDefence(int newDefence);
	void pushItem(Item item);
	void popItem(Item item);
	void setPotions(int defaultPotions = 5);

	//getter
	const string getName(void);
	const string getJob(void);
	const int getLv(void);
	const int getCurrentHP(void);
	const int getCurrentMP(void);
	const int getDefAttackCost(void);
	const int getMaxHP(void);
	const int getMaxMP(void);
	const int getPower(void);
	const int getDefence(void);
	const vector<Item> getInventory(void);

	//Player Information
	const void printPlayerStatus(void);
	const void printPlayerCondition(void);
	const void printInventory(void);
	//Player Inventory
	void useItem(void);
	void inventoryItemDelete(string itemName);
	void inventoryItemDelete(Item item);
	void setInventoryItem(string itemName, int numberOfItems);
	void setInventoryItem(Item item, int numberOfItems);
	const Item getInventoryItem(string itemName);
	const Item getInventoryItem(Item itemObject);
	//Player Level
	void gainExp(int expReward);

	virtual void getPumped(void) = 0;
	virtual void attack(Monster* monster) = 0;

	virtual ~Player() {
		cout << "See you!" << endl;
	}
};

#endif
