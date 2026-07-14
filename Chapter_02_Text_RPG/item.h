#ifndef _ITEM_H_
#define _ITME_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Item {
	string name = "None";
	int price = 0;

	const void printInfo(void) const;
};

struct PotionRecipe {
	string potionName = "None";
	string ingredient[2] = {"None", "None"};

	const void printRecipe(void) const;
};

const void Item::printInfo(void) const {
	cout << this->name << " (" << this->price << "G)" << endl;
}

const void PotionRecipe::printRecipe(void) const {
	cout << this->potionName << " ( " << this->ingredient[0] << ", " << this->ingredient[1] << " )" << endl;
}

#endif
