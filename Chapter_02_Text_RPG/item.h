#ifndef _ITEM_H_
#define _ITME_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Item {
	string name;
	int price;

	void printInfo(void) const;
};

void Item::printInfo(void) const {
	cout << this->name << " (" << this->price << "G)" << endl;
}

#endif
