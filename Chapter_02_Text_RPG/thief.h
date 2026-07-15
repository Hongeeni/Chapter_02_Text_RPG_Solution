#ifndef _THIEF_H_
#define _THIEF_H_

#include "character.h"

class Thief : public Player {
public:
	Thief(const string name, const int stats[], const int potions[]) : Player(name, stats, potions) {
		cout << "* You became a Rogue! (Attack +30)" << endl;
		this->job = "Rogue";
		this->stats[2] += 30;
	}

	void getPumped(void);
	void attack(Monster* monster);

	~Thief(void) {
		cout << "See you!" << endl;
	}
};

//Functions
void Thief::getPumped(void) {
	cout << "* Stabs dagger!" << endl;
}

void Thief::attack(Monster* monster) {
	bool isPlayerTurn = rand() % 2;

	string userInput = "None";
	int inputMenu = 0;
	int tempHP = 0;

	cout << "[ Battle Start! ] " << this->getName() << "(" << this->getJob() << ") VS " << monster->getName() << endl;
	cout << endl;

	do {
		if (isPlayerTurn) {
			int playerATK = 0;
			int randomNum = (rand() % 2);
			cout << "-------------- Player's Turn --------------" << endl;
			cout << "* Choose between attacking and dodging" << endl;
			cout << "-------------------------------------------\n	< Select Action >" << endl;
			cout << "1. Attack the monster\n2. Hide and attack from behind." << endl;
			cout << "-------------------------------------------" << endl;
			cout << "Choose: ";
			cin >> userInput;
			cout << endl;

			if (userInput >= "0" && userInput <= "9") {
				inputMenu = stoi(userInput);
			}
			else {
				do {
					system("cls");
					cout << "-------------- Player's Turn --------------" << endl;
					cout << "* Choose between attacking and dodging" << endl;
					cout << "-------------------------------------------\n	< Select Action >" << endl;
					cout << "1. Attack the monster\n2. Hide and attack from behind." << endl;
					cout << "-------------------------------------------" << endl;
					cout << "Invalid input. Try again.\n\nChoose: ";
					cin >> userInput;
				} while (userInput <= "0" || userInput >= "9");

				inputMenu = stoi(userInput);
			}

			switch (inputMenu) {
			case 1:
				if (this->getPower() - monster->getDefence() < 2) {
					playerATK = 1;
				}
				else {
					playerATK = this->getPower() - monster->getDefence();
				}

				this->getPumped();
				cout << playerATK << " damage to " << monster->getName() << " !" << endl;

				tempHP = monster->getHP();
				monster->setHP(monster->getHP() - playerATK);

				if (monster->getHP() > 0) {
					cout << monster->getName() << " HP: " << tempHP << " => " << monster->getHP() << endl;
				}
				else {
					Item item;
					item.name = monster->getDropItemName();
					item.price = monster->getDropItemPrice();

					cout << monster->getName() << " HP: " << tempHP << " => " << monster->getHP() << " (Dead)\n" << endl;
					cout << "* Victory!" << endl;

					this->gainExp(monster->getExp());
					cout << "\n	=> Got: " << monster->getDropItemName() << "!" << endl;

					if (this->getInventory().size() < 10) {
						this->pushItem(item);
						cout << "	=> Saved to inventory." << endl;
					}
					else {
						cout << "	=> Inventory is full." << endl;
					}
				}
				isPlayerTurn = !isPlayerTurn;
				break;
			case 2:
				cout << "* Disappeared into the bushes.\n" << endl;
				if (randomNum) {
					cout << "* Attack successful!" << endl;
					cout << "-------------- Player's Turn --------------" << endl;
					this->getPumped();
					cout << (playerATK * 3 / 2) << " damage to " << monster->getName() << " !" << endl;

					tempHP = monster->getHP();
					monster->setHP(monster->getHP() - (playerATK * 3 / 2));

					if (monster->getHP() > 0) {
						cout << monster->getName() << " HP: " << tempHP << " => " << monster->getHP() << endl;
					}
					else {
						Item item;
						item.name = monster->getDropItemName();
						item.price = monster->getDropItemPrice();

						cout << monster->getName() << " HP: " << tempHP << " => " << monster->getHP() << " (Dead)\n" << endl;
						cout << "* Victory!" << endl;

						this->gainExp(monster->getExp());
						cout << "\n	=> Got: " << monster->getDropItemName() << "!" << endl;

						if (this->getInventory().size() < 10) {
							this->pushItem(item);
							cout << "	=> Saved to inventory." << endl;
						}
						else {
							cout << "	=> Inventory is full." << endl;
						}
					}
				}
				else {
					int monsterATK = 0;
					cout << "* Attack failed." << endl;
					cout << "-------------- Monster's Turn --------------" << endl;
					cout << "The " << monster->getName() << " lunged!" << endl;

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
			default:
				cout << "Invalid input. Try again.\n" << endl;
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
	} while (this->getHP() > 0 && monster->getHP() > 0);
}

#endif
