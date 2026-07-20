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

	const void printInfo(void);
};

struct PotionRecipe {
	string potionName = "None";
	string ingredient[2] = {"None", "None"};

	const void printRecipe(void);
};

#endif
