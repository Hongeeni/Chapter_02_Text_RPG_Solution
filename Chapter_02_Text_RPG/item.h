#ifndef _ITEM_H_
#define _ITME_H_

#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

struct Item {
	string name = "Fragment of The Soul";
	int numOfItems = 0;
	int price = 5;

	const void printInfo(void) const;
};

struct PotionRecipe {
	string potionName = "None";
	string ingredient[2] = {"None", "None"};

	const void printRecipe(void) const;
};

//struct Item
const void Item::printInfo(void) const {
	cout << this->name << " (" << this->price << "G)" << " x" << this->numOfItems << endl;
}

//struct PotionRecipe
const void PotionRecipe::printRecipe(void) const {
	cout << this->potionName << " ( " << this->ingredient[0] << ", " << this->ingredient[1] << " )" << endl;
}

#endif
