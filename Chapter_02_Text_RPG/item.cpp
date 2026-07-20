#include "item.h"

//struct Item
const void Item::printInfo(void) {
	cout << this->name << " (" << this->price << "G)" << " x" << this->numOfItems << endl;
}

//struct PotionRecipe
const void PotionRecipe::printRecipe(void) {
	cout << this->potionName << " ( " << this->ingredient[0] << ", " << this->ingredient[1] << " )" << endl;
}