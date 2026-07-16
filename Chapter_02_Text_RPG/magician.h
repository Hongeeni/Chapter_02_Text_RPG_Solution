#ifndef _MAGICIAN_H_
#define _MAGICIAN_H_

#include "character.h"

class Magician : public Player {
public:
	Magician(const string name, const int stats[]) : Player(name, stats) {
		cout << "* You became a Mage! (MP +30)" << endl;
		this->job = "Mage";
		this->stats[1] += 30;
	}

	void getPumped(void);
	void attack(Monster* monster);

	~Magician(void) {
		cout << "Thank you for playing!" << endl;
	}
};

//Functions
void Magician::getPumped(void) {
	cout << "* Fires fireball!" << endl;
}

void Magician::attack(Monster* monster) {
	bool isPlayerTurn = rand() % 2;

	string userInput = "None";
	int inputMenu = 0;
	int tempHP = 0;

	system("cls");
	do {
		cout << "===========================================" << endl;
		cout << "[ Battle! ] " << this->getName() << "(" << this->getJob() << ") VS " << monster->getName() << endl;
		cout << endl;
		cout << this->getName() << " HP: " << this->getHP() << endl;
		cout << monster->getName() << " HP: " << monster->getHP() << endl;
		cout << "===========================================\n" << endl;
		if (isPlayerTurn) {
			int randomNum = (rand() % 5);
			int playerATK = (this->getPower() - monster->getDefence());
			cout << "-------------- Player's Turn --------------\n" << endl;
			cout << "1. Attack the monster\n2. Uses a defensive spell.\n3. Use item." << endl;
			cout << "-------------------------------------------" << endl;
			cout << "Choose: ";
			cin >> userInput;
			system("cls");
			if (userInput > "0" && userInput <= "4") {
				inputMenu = stoi(userInput);
			}
			else {
				do {
					cout << "===========================================" << endl;
					cout << "[ Battle! ] " << this->getName() << "(" << this->getJob() << ") VS " << monster->getName() << endl;
					cout << endl;
					cout << this->getName() << " HP: " << this->getHP() << endl;
					cout << monster->getName() << " HP: " << monster->getHP() << endl;
					cout << "===========================================\n" << endl;
					cout << "-------------- Player's Turn --------------\n" << endl;
					cout << "1. Attack the monster\n2. Uses a defensive spell.\n3. Use item." << endl;
					cout << "-------------------------------------------" << endl;
					cout << "Invalid input. Try again.\n\nChoose: ";
					cin >> userInput;
					system("cls");
				} while (userInput <= "0" || userInput >= "4");
				inputMenu = stoi(userInput);
			}
			cout << "===========================================" << endl;
			cout << "[ Battle! ] " << this->getName() << "(" << this->getJob() << ") VS " << monster->getName() << endl;
			cout << endl;
			cout << this->getName() << " HP: " << this->getHP() << endl;
			cout << monster->getName() << " HP: " << monster->getHP() << endl;
			cout << "===========================================\n" << endl;
			switch (inputMenu) {
			case 1:
				if (playerATK < 2) {
					playerATK = 1;
				}
				cout << "-------------- Player's Turn --------------" << endl;
				this->getPumped();
				cout << playerATK << " damage to " << monster->getName() << " !" << endl;
				tempHP = monster->getHP();
				monster->setHP(monster->getHP() - playerATK);

				if (monster->getHP() > 0) {
					cout << monster->getName() << " HP: " << tempHP << " => " << monster->getHP() << endl;
				}
				else {
					Item item = { monster->getDropItemName(), 1, monster->getDropItemPrice() };

					cout << monster->getName() << " HP: " << tempHP << " => " << monster->getHP() << " (Dead)\n" << endl;
					cout << "* Victory!" << endl;
					this->gainExp(monster->getExp());
					cout << "\n	=> Got: " << item.name << "!" << endl;

					if (this->getInventory().size() < 10) {
						int tempNumOfItem = this->getInventoryItem(item).numOfItems;
						this->setInventoryItem(item, tempNumOfItem + 1);
						cout << "	=> Saved to inventory." << endl;
					}
					else {
						cout << "	=> Inventory is full." << endl;
					}
				}
				isPlayerTurn = !isPlayerTurn;
				break;
			case 2:
				if (playerATK < 2) {
					playerATK = 1;
				}
				cout << "* Used a defensive spell.\n" << endl;
				if (randomNum > 1) {
					cout << "-------------- Monster's Turn --------------" << endl;
					cout << "The " << monster->getName() << " lunged!\n" << endl;
					cout << "* The " << monster->getName() << "'s attack was blocked!\n" << endl;

					if (this->getPower() - monster->getDefence() < 2) {
						playerATK = 1;
					}
					else {
						playerATK = this->getPower() - monster->getDefence();
					}

					cout << "-------------- Player's Turn --------------" << endl;
					this->getPumped();
					cout << playerATK << " damage to " << monster->getName() << " !" << endl;

					tempHP = monster->getHP();
					monster->setHP(monster->getHP() - playerATK);

					if (monster->getHP() > 0) {
						cout << monster->getName() << " HP: " << tempHP << " => " << monster->getHP() << endl;
					}
					else {
						Item item = { monster->getDropItemName(), 1, monster->getDropItemPrice() };

						cout << monster->getName() << " HP: " << tempHP << " => " << monster->getHP() << " (Dead)\n" << endl;
						cout << "* Victory!" << endl;
						this->gainExp(monster->getExp());
						cout << "\n	=> Got: " << item.name << "!" << endl;

						if (this->getInventory().size() < 10) {
							int tempNumOfItem = this->getInventoryItem(item).numOfItems;
							this->setInventoryItem(item, tempNumOfItem + 1);
							cout << "	=> Saved to inventory." << endl;
						}
						else {
							cout << "	=> Inventory is full." << endl;
						}
					}
				}
				else {
					int monsterATK = 0;
					cout << "-------------- Monster's Turn --------------" << endl;
					cout << "The " << monster->getName() << " lunged!" << endl;
					cout << "* Failed to block the attack." << endl;

					if (monster->getPower() - this->getDefence() <= 0) {
						monsterATK = 1;
					}
					else {
						monsterATK = monster->getPower() - this->getDefence();
					}
					cout << monsterATK << " damage to " << this->getName() << " !" << endl;

					tempHP = this->getHP();
					this->setHP(this->getHP() - monsterATK);

					if (this->getHP() > 0) {
						cout << this->getName() << " HP: " << tempHP << " => " << this->getHP() << endl;
					}
					else {
						cout << this->getName() << " HP: " << tempHP << " => " << this->getHP() << " (Dead)\n" << endl;
						cout << "* The End..." << endl;

						this->setHP(0);
					}
				}
				break;
			case 3:
				this->useItem();
				break;
			}
		}
		else {
			cout << "-------------- Monster's Turn --------------" << endl;
			cout << "The " << monster->getName() << " lunged!" << endl;

			int monsterATK = 0;
			if (monster->getPower() - this->getDefence() <= 0) {
				monsterATK = 1;
			}
			else {
				monsterATK = monster->getPower() - this->getDefence();
			}
			cout << monsterATK << " damage to " << this->getName() << " !" << endl;

			tempHP = this->getHP();
			this->setHP(this->getHP() - monsterATK);

			if (this->getHP() > 0) {
				cout << this->getName() << " HP: " << tempHP << " => " << this->getHP() << endl;
			}
			else {
				cout << this->getName() << " HP: " << tempHP << " => " << this->getHP() << " (Dead)\n" << endl;
				cout << "* The End..." << endl;

				this->setHP(0);
			}
			isPlayerTurn = !isPlayerTurn;
		}
		cout << endl;
		system("pause");
		system("cls");
	} while (this->getHP() > 0 && monster->getHP() > 0);
}

#endif
