#include "warrior.h"
#include "magician.h"
#include "thief.h"
#include "archer.h"
#include "monster.h"

#include <cstdlib>
#include <ctime>

PotionRecipe hpPotion = { "HP Potion", { "Herb", "Clear Water" } };
PotionRecipe mpPotion = { "MP Potion", { "Herb", "Berry" } };
vector<PotionRecipe> recipeBook = { hpPotion , mpPotion };

Monster slime("Slime", 12, 130, 100, 30, "Slime's Jelly", 7);
Monster wolf("Wolf", 48, 175, 160, 50, "Wolf's Fur", 23);
Monster golem("Golem", 83, 300, 210, 100, "Golem's Stone", 74);
vector<Monster> monsterType = { slime , wolf , golem };

void setPotions(int defaultPotions, int* p_HpPotion, int* p_MpPotion);
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

		//stats[0] = HP, stats[1] = MP, stats[2] = ATK, stats[3] = DEF
		int stats[statsSize] = { 0 };
		//potions[0] = HP_Potion, potions[1] = MP_Potion
		int potions[2] = { 0 };
		setPotions(5, &potions[0], &potions[1]);

		setStatus(&name, &stats);
		printStatus(name, stats);

		//select < Character Upgrade > menu and Game Start
		characterUpgrade(&potions, name, &stats);

		//select < Job Selection > menu
		selectJob(&player, name, stats, potions);
		player->getPumped();
		player->printPlayerStatus();
		system("pause");
		system("cls");
	}

	//start Game
	adventure(player);

	delete player;
	return 0;
}

// Functions
void setPotions(int defaultPotions, int* p_HpPotion, int* p_MpPotion) {
	*p_HpPotion = defaultPotions;
	*p_MpPotion = defaultPotions;
}

void setStatus(string* name, int (*stats)[]) {
	cout << "===========================================" << "\n	[Dungeon Escape Text RPG]\n" << "===========================================" << endl;
	cout << "Enter your hero's name: ";
	cin >> *name;

	cout << endl;

	cout << "(HP and MP input range : 100 ~ 500)\nEnter HP and MP: ";
	cin >> (*stats)[0] >> (*stats)[1];
	cout << endl;
	cout << "(Attack and Defence input range : 50 ~ 200)\nEnter Attack and Defence: ";
	cin >> (*stats)[2] >> (*stats)[3];

	cout << endl;

	// check HP and MP
	if (((*stats)[0] < 99 || (*stats)[1] < 99) || ((*stats)[0] > 501 || (*stats)[1] > 501)) {
		do {
			cout << "HP or MP is outside The input range. Try again." << endl;
			cout << "Enter HP and MP: ";
			cin >> (*stats)[0] >> (*stats)[1];

			cout << endl;
		} while (((*stats)[0] < 99 || (*stats)[1] < 99) || ((*stats)[0] > 501 || (*stats)[1] > 501));
	}

	// check ATK and DEF
	if (((*stats)[2] < 49 || (*stats)[3] < 49) || ((*stats)[2] > 201 || (*stats)[3] > 201)) {
		do {
			cout << "Attack or Defense is outside The input range. Try again." << endl;
			cout << "Enter Attack and Defence: ";
			cin >> (*stats)[2] >> (*stats)[3];

			cout << endl;
		} while (((*stats)[2] < 49 || (*stats)[3] < 49) || ((*stats)[2] > 201 || (*stats)[3] > 201));
	}
}

void printStatus(const string name, const int stats[]) {
	cout << "===========================================\n	" << name << "'s Stats\n" << "===========================================" << endl;
	cout << "HP: " << stats[0] << "		MP: " << stats[1] << endl;
	cout << "Attack: " << stats[2] << "	Defence: " << stats[3] << endl;
	cout << "===========================================" << endl;

	system("pause");
	system("cls");
}

//select < Character Upgrade > menu and Game Start
void characterUpgrade(int (*potions)[], const string name, int (*stats)[]) {
	bool isGameStart = false;
	string userInput = "None";
	int inputMenu = 0;

	while (!isGameStart) {
		cout << "* You received " << (*potions)[0] << " HP Potions and " << (*potions)[1] << " MP Potions." << endl;
		cout << "============================================" << endl;
		cout << "< Character Upgrade >" << endl;
		cout << "1. HP UP	2. MP UP	3. Attack x2" << endl;
		cout << "4. Defence x2  5. Status  0. Start Game" << endl;
		cout << "============================================" << endl;
		cout << "Choose: ";
		cin >> userInput;
		cout << endl;

		if (userInput >= "0" && userInput <= "9") {
			inputMenu = stoi(userInput);
		}
		else {
			cout << "Invalid input. Try again.\n" << endl;
			inputMenu = 9;

			system("pause");
			system("cls");
			continue;
		}

		switch (inputMenu) {
		case 0:
			cout << "Starting the game!\n" << endl;
			isGameStart = true;
			system("pause");
			system("cls");
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
			system("pause");
			system("cls");
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
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "* Attack has dobled.\n" << endl;
			(*stats)[2] *= 2;
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "* Defence has dobled.\n" << endl;
			(*stats)[3] *= 2;
			system("pause");
			system("cls");
			break;
		case 5:
			printStatus(name, (*stats));
			break;
		default:
			cout << "Invalid input. Try again.\n" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void characterUpgrade(Player* player) {
	bool isGameStart = false;
	string userInput = "None";
	int inputMenu = 0;

	while (!isGameStart) {
		cout << "* You received " << player->getHpPotion() << " HP Potions and " << player->getMpPotion() << " MP Potions." << endl;
		cout << "============================================" << endl;
		cout << "< Character Upgrade >" << endl;
		cout << "1. HP UP	2. MP UP	3. Attack x2" << endl;
		cout << "4. Defence x2	0. Go back" << endl;
		cout << "============================================" << endl;
		cout << "Choose: ";
		cin >> userInput;

		if (userInput >= "0" && userInput <= "9") {
			inputMenu = stoi(userInput);
		}
		else {
			cout << "Invalid input. Try again.\n" << endl;
			inputMenu = 9;

			system("pause");
			system("cls");
			continue;
		}

		switch (inputMenu) {
		case 0:
			cout << "Get ready for The next battle!\n" << endl;
			isGameStart = true;
			system("pause");
			system("cls");
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
			system("pause");
			system("cls");
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
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "* Attack has dobled." << endl;
			player->setPower(player->getPower() * 2);
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "* Defence has dobled." << endl;
			player->setDefence(player->getDefence() * 2);
			system("pause");
			system("cls");
			break;
		case 5:
			player->printPlayerStatus();
			system("pause");
			system("cls");
			break;
		default:
			cout << "Invalid input. Try again.\n" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void selectJob(Player** player, const string name, const int stats[], const int potions[]) {
	bool isSelect = false;
	string userInput = "None";
	int inputMenu = 0;

	while (!isSelect) {
		cout << "============================================\n	< Job Selection >\n" << name << ", choose your job!" << endl;
		cout << "1. Warrior   2. Mage   3. Rogue   4. Archer" << endl;
		cout << "============================================" << endl;

		cout << "Choose: ";
		cin >> userInput;
		cout << endl;

		if (userInput >= "0" && userInput <= "9") {
			inputMenu = stoi(userInput);
		}
		else {
			cout << "Invalid input. Try again.\n" << endl;
			inputMenu = 9;

			system("pause");
			system("cls");
			continue;
		}

		switch (inputMenu) {
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
			system("pause");
			system("cls");
			break;
		}
	}
}

void potionWorkshop(void) {
	int inputMenu = 0;
	string userInput = "None";
	string lowerByUserInput = "None";

	do {
		cout << "============================================\n	< Potion Workshop >\n============================================" << endl;
		cout << "1. Show all recipes\n2. Search by potion name\n3. Search by ingredient\n0. Go back" << endl;
		cout << "============================================" << endl;

		cout << "Choose: ";
		cin >> userInput;
		cout << endl;

		if (userInput >= "0" && userInput <= "9") {
			inputMenu = stoi(userInput);
		}
		else {
			cout << "Invalid input. Try again.\n" << endl;
			inputMenu = 9;

			system("pause");
			system("cls");
			continue;
		}

		switch (inputMenu) {
		case 0:
			system("pause");
			system("cls");
			break;
		case 1:
			showAllRecipes();
			cout << endl;
			break;
		case 2:
			cout << "Search potion name: ";
			cin >> userInput;
			cout << endl;

			lowerByUserInput = userInput;
			for (int i = 0; i < lowerByUserInput.size(); i++) {
				lowerByUserInput[i] = tolower(lowerByUserInput[i]);
			}
			searchByName(lowerByUserInput);
			break;
		case 3:
			cout << "Search potion Ingredient: ";
			cin >> userInput;
			cout << endl;

			lowerByUserInput = userInput;
			for (int i = 0; i < lowerByUserInput.size(); i++) {
				lowerByUserInput[i] = tolower(lowerByUserInput[i]);
			}
			searchByIngredient(lowerByUserInput);
			break;
		default:
			cout << "Invalid input. Try again.\n" << endl;
			break;
		}
	} while (inputMenu != 0);
}

void showAllRecipes(void) {
	cout << "=========== < All recipes > ===========" << endl;
	for (PotionRecipe recipe : recipeBook) {
		cout << "=> ";
		recipe.printRecipe();
	}
	system("pause");
	system("cls");
}

void searchByName(string potionName) {
	bool isFound = false;
	string tempName = "None";

	for (PotionRecipe recipe : recipeBook) {
		tempName = recipe.potionName;
		remove(tempName.begin(), tempName.end(), ' ');
		tempName.pop_back();


		for (int i = 0; i < tempName.size(); i++) {
			tempName[i] = tolower(tempName[i]);
		}

		if (potionName == tempName) {
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

	system("pause");
	system("cls");
}

void searchByIngredient(string potionIngredient) {
	bool isFound = false;
	string tempIngredient[2] = { "None", "None" };

	for (PotionRecipe recipe : recipeBook) {
		for (int x = 0; x < 2; x++) {
			tempIngredient[x] = recipe.ingredient[x];

			for (int y = 0; y < tempIngredient[x].size(); y++) {
				(tempIngredient[x])[y] = tolower((tempIngredient[x])[y]);
			}
		}

		if (potionIngredient == tempIngredient[0] || potionIngredient == tempIngredient[1]) {
			isFound = true;
			cout << "=> ";
			recipe.printRecipe();
			cout << endl;
		}
	}

	if (!isFound) {
		cout << "Potion can't be found.\n" << endl;
	}

	system("pause");
	system("cls");
}

void adventure(Player* player) {
	string userInput = "None";
	int inputMenu = 0;

	do {
		Monster monster;

		int randomMonsterIndex = rand() % 3;
		monster = monsterType[randomMonsterIndex];

		cout << "============================================\n	< Select Action >" << endl;
		cout << "1. Adventure!	2. Rest	3. Status" << endl;
		cout << "4. Inventory	5. Potion Shop	0. Exit Game" << endl;
		cout << "============================================" << endl;

		cout << "Choose: ";
		cin >> userInput;
		cout << endl;

		if (userInput >= "0" && userInput <= "9") {
			inputMenu = stoi(userInput);
		}
		else {
			cout << "Invalid input. Try again.\n" << endl;
			inputMenu = 9;

			system("pause");
			system("cls");
			continue;
		}

		switch (inputMenu) {
		case 0:
			cout << "The hero returned home after finishing the adventure." << endl << endl;
			break;
		case 1:
			player->attack(&monster);

			system("pause");
			system("cls");

			if (player->getHP() <= 0) {
				cout << "* Your HP is very low. You need to rest." << endl;
				cout << "============================================\n	< Select Action >" << endl;
				cout << "1. Rest	0. Exit Game" << endl;
				cout << "============================================\n" << endl;

				cout << "Choose: ";
				cin >> userInput;

				if (userInput >= "0" && userInput <= "9") {
					inputMenu = stoi(userInput);
				}
				else {
					cout << "Invalid input. Try again.\n" << endl;
					inputMenu = 9;

					continue;
				}

				switch (inputMenu) {
				case 0:
					cout << "The hero returned home after finishing the adventure." << endl;
					break;
				case 1:
					characterUpgrade(player);
					break;
				default:
					cout << "Invalid input. Try again.\n" << endl;
					break;
				}
			}
			break;
		case 2:
			system("cls");
			characterUpgrade(player);
			break;
		case 3:
			player->printPlayerStatus();
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");

			player->printInventory();
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			potionWorkshop();
			break;
		default:
			cout << "Invalid input. Try again.\n" << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (inputMenu != 0);
}