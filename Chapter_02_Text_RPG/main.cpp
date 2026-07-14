#include "warrior.h"
#include "magician.h"
#include "thief.h"
#include "archer.h"
#include "monster.h"

#include <cstdlib>
#include <ctime>

vector<PotionRecipe> recipeBook;
PotionRecipe hpPotion = { "HPpotion", { "Herb", "Clear Water" } };
PotionRecipe mpPotion = { "MPpotion", { "Herb", "Berry" } };

void setStatus(string* name, int (*stats)[]);
void printStatus(const string name, const int stats[]);
void characterUpgrade(int (*potions)[], const string name, int (*stats)[]);
void characterUpgrade(Player* player);
void selectJob(Player** player, const string name, const int stats[], const int potions[]);
void potionWorkshop(void);
void showAllRecipes(void);
void searchByName(string potionName);
void searchByIngredient(string ingredient);
void adventure(Player* player);

int main(void) {
	srand(static_cast<unsigned int>(time(NULL)));

	//Player Class
	Player* player = nullptr;

	//Player Default Settings
	{
		string name = "None";
		const int statsSize = 4;
		const int potionsSize = 2;

		//stats[0] = HP, stats[1] = MP, stats[2] = ATK, stats[3] = DEF
		int stats[statsSize] = { 0 };
		//potions[0] = HP_Potion, potions[1] = MP_Potion
		int potions[potionsSize] = { 5, 5 };

		setStatus(&name, &stats);
		printStatus(name, stats);

		//select < Character Upgrade > menu and Game Start
		characterUpgrade(&potions, name, &stats);

		//select < Job Selection > menu
		selectJob(&player, name, stats, potions);
		player->attack();
		player->printPlayerStatus();
	}
	recipeBook.push_back(hpPotion);
	recipeBook.push_back(mpPotion);

	//start Game
	adventure(player);

	delete player;
	return 0;
}

// Functions
void setStatus(string* name, int (*stats)[]) {
	cout << "===========================================" << "\n	[Dungeon Escape Text RPG]\n" << "===========================================" << endl;
	cout << "Enter your hero's name: ";
	cin >> *name;

	cout << endl;

	cout << "Enter HP and MP: ";
	cin >> (*stats)[0] >> (*stats)[1];
	cout << "Enter Attack and Defence: ";
	cin >> (*stats)[2] >> (*stats)[3];

	cout << endl;

	// check HP and MP
	if ((*stats)[0] < 50 || (*stats)[1] < 50) {
		do {
			cout << "HP or MP is too low. Try again." << endl;
			cout << "Enter HP and MP: ";
			cin >> (*stats)[0] >> (*stats)[1];

			cout << endl;
		} while ((*stats)[0] < 50 || (*stats)[1] < 50);
	}

	// check ATK and DEF
	if ((*stats)[2] < 50 || (*stats)[3] < 50) {
		do {
			cout << "Attack or Defense is too low. Try again." << endl;
			cout << "Enter Attack and Defence: ";
			cin >> (*stats)[2] >> (*stats)[3];

			cout << endl;
		} while ((*stats)[2] < 50 || (*stats)[3] < 50);
	}
}

void printStatus(const string name, const int stats[]) {
	cout << "===========================================\n	" << name << "'s Stats\n" << "===========================================" << endl;
	cout << "HP: " << stats[0] << "		MP: " << stats[1] << endl;
	cout << "Attack: " << stats[2] << "	Defence: " << stats[3] << endl;
	cout << "===========================================" << endl;

	cout << endl;
}

//select < Character Upgrade > menu and Game Start
void characterUpgrade(int (*potions)[], const string name, int (*stats)[]) {
	bool isGameStart = false;
	int userInputMenu = 0;

	cout << "* You received " << (*potions)[0] << " HP Potions and " << (*potions)[1] << " MP Potions." << endl;
	cout << "============================================" << endl;
	cout << "< Character Upgrade >" << endl;
	cout << "1. HP UP	2. MP UP	3. Attack x2" << endl;
	cout << "4. Defence x2  5. Show Stats  0. Start Game" << endl;
	cout << "============================================" << endl;

	while (!isGameStart) {
		cout << "Choose: ";
		cin >> userInputMenu;
		cout << endl;

		switch (userInputMenu) {
		case 0:
			cout << "Starting the game!\n" << endl;
			isGameStart = true;
			break;
		case 1:
			if ((*potions)[0] > 0) {
				(*potions)[0] -= 1;
				(*stats)[0] += 20;
				cout << "* HP increased by 20. (HP Potion used: " << (*potions)[0] << " left)\n" << endl;
			}
			else {
				cout << "* You don't have an HP Potion.\n" << endl;
			}
			break;
		case 2:
			if ((*potions)[1] > 0) {
				(*potions)[1] -= 1;
				(*stats)[1] += 20;
				cout << "* MP increased by 20. (MP Potion used: " << (*potions)[1] << " left)\n" << endl;
			}
			else {
				cout << "* You don't have an MP Potion.\n" << endl;
			}
			break;
		case 3:
			cout << "* Attack has dobled.\n" << endl;
			(*stats)[2] *= 2;
			break;
		case 4:
			cout << "* Defence has dobled.\n" << endl;
			(*stats)[3] *= 2;
			break;
		case 5:
			printStatus(name, (*stats));
			break;
		default:
			cout << "Invalid input. Try again.\n" << endl;
			break;
		}
	}
}

void characterUpgrade(Player* player) {
	bool isGameStart = false;
	int userInputMenu = 0;

	cout << "* You received " << player->getHpPotion() << " HP Potions and " << player->getMpPotion() << " MP Potions." << endl;
	cout << "============================================" << endl;
	cout << "< Character Upgrade >" << endl;
	cout << "1. HP UP	2. MP UP	3. Attack x2" << endl;
	cout << "4. Defence x2	0. Go back" << endl;
	cout << "============================================" << endl;

	while (!isGameStart) {
		cout << "Choose: ";
		cin >> userInputMenu;

		switch (userInputMenu) {
		case 0:
			cout << "Get ready for The next battle!\n" << endl;
			isGameStart = true;
			break;
		case 1:
			if (player->getHpPotion() > 0) {
				player->setHpPotion(player->getHpPotion() - 1);
				player->setHP(player->getHP() + 20);
				cout << "* HP increased by 20. (HP Potion used: " << player->getHpPotion() << " left)" << endl;
			}
			else {
				cout << "* You don't have an HP Potion." << endl;
			}
			break;
		case 2:
			if (player->getMpPotion() > 0) {
				player->setMpPotion(player->getMpPotion() - 1);
				player->setMP(player->getMP() + 20);
				cout << "* MP increased by 20. (MP Potion used: " << player->getMpPotion() << " left)" << endl;
			}
			else {
				cout << "* You don't have an MP Potion." << endl;
			}
			break;
		case 3:
			cout << "* Attack has dobled." << endl;
			player->setPower(player->getPower() * 2);
			break;
		case 4:
			cout << "* Defence has dobled." << endl;
			player->setDefence(player->getDefence() * 2);
			break;
		case 5:
			cout << endl;
			player->printPlayerStatus();
			break;
		default:
			cout << "Invalid input. Try again.\n" << endl;
			break;
		}
	}
}

void selectJob(Player** player, const string name, const int stats[], const int potions[]) {
	bool isSelect = false;
	int userInputMenu = 0;

	cout << "============================================\n	< Job Selection >\n" << name << ", choose your job!" << endl;
	cout << "1. Warrior   2. Mage   3. Rogue   4. Archer" << endl;
	cout << "============================================" << endl;

	while (!isSelect) {
		cout << "Choose: ";
		cin >> userInputMenu;
		cout << endl;

		switch (userInputMenu) {
		case 1:
			*player = new Warrior(name, stats, potions);
			isSelect = true;
			break;
		case 2:
			*player = new Magician(name, stats, potions);
			isSelect = true;
			break;
		case 3:
			*player = new Thief(name, stats, potions);
			isSelect = true;
			break;
		case 4:
			*player = new Archer(name, stats, potions);
			isSelect = true;
			break;
		default:
			cout << "Invalid input. Try again.\n" << endl;
			break;
		}
	}
}

void potionWorkshop(void) {
	int userInputMenu = 0;
	string userInputName = "None";
	string userInputIngredient = "None";

	do {
		cout << "============================================\n	< Potion Workshop >\n============================================" << endl;
		cout << "1. Show all recipes\n2. Search by potion name\n3. Search by ingredient\n0. Go back" << endl;
		cout << "============================================" << endl;

		cout << "Choose: ";
		cin >> userInputMenu;
		cout << endl;

		switch (userInputMenu) {
		case 0:
			break;
		case 1:
			showAllRecipes();
			cout << endl;
			break;
		case 2:
			cout << "Search potion name: ";
			cin >> userInputName;
			cout << endl;
			searchByName(userInputName);
			break;
		case 3:
			cout << "Search potion name: ";
			cin >> userInputIngredient;
			cout << endl;
			searchByIngredient(userInputIngredient);
			break;
		default:
			cout << "Invalid input. Try again.\n" << endl;
			break;
		}
	} while (userInputMenu != 0);
}

void showAllRecipes(void) {
	cout << "=========== < All recipes > ===========" << endl;
	for (PotionRecipe recipe : recipeBook) {
		cout << "=> ";
		recipe.printRecipe();
	}
}

void searchByName(string potionName) {
	bool isFound = false;

	for (PotionRecipe recipe : recipeBook) {
		if (potionName == recipe.potionName) {
			isFound = true;
			cout << "=> ";
			recipe.printRecipe();
			cout << endl;
			break;
		}
	}

	if (!isFound) {
		cout << "Potion can't be found.\n" << endl;
	}
}

void searchByIngredient(string potionIngredient) {
	bool isFound = false;

	for (PotionRecipe recipe : recipeBook) {
		if (potionIngredient == recipe.ingredient[0] || potionIngredient == recipe.ingredient[1]) {
			isFound = true;
			cout << "=> ";
			recipe.printRecipe();
			cout << endl;
		}
	}

	if (!isFound) {
		cout << "Potion can't be found.\n" << endl;
	}
}

void adventure(Player* player) {
	int userInputMenu = 0;

	do {
		Monster monster;

		cout << "============================================\n	< Select Action >" << endl;
		cout << "1. Adventure!	2. Rest	3. Show Stats" << endl;
		cout << "4. Show Inventory	5. Potion Shop	0. Exit Game" << endl;
		cout << "============================================" << endl;

		cout << "Choose: ";
		cin >> userInputMenu;
		cout << endl;

		switch (userInputMenu) {
		case 0:
			cout << "The hero returned home after finishing the adventure." << endl;
			break;
		case 1:
			monster.attack(player);

			if (player->getHP() <= 0) {
				cout << "============================================\n	< Select Action >" << endl;
				cout << "1. Rest	0. Exit Game" << endl;
				cout << "============================================\n" << endl;

				cout << "Choose: ";
				cin >> userInputMenu;

				switch (userInputMenu) {
				case 0:
					cout << "The hero returned home after finishing the adventure." << endl;
					break;
				case 1:
					cout << "I have recovered." << endl;
					characterUpgrade(player);
					break;
				default:
					cout << "Invalid input. Try again.\n" << endl;
					break;
				}
			}
			break;
		case 2:
			characterUpgrade(player);
			break;
		case 3:
			player->printPlayerStatus();
			break;
		case 4:
			player->printInventory();
			break;
		case 5:
			potionWorkshop();
			break;
		default:
			cout << "Invalid input. Try again.\n" << endl;
			break;
		}
	} while (userInputMenu != 0);
}