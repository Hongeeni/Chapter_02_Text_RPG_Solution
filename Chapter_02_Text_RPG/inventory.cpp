//#include "inventory.h"

/*
template <typename T>
Inventory<T>::Inventory(void) {
	this->pItems = new T[this->capacity];
	addPotions();
}
*/

//getter
/*
template <typename T>
const int Inventory<T>::getCapacity(void) {
	return this->capacity;
}
template <typename T>
const int Inventory<T>::getInventorySize(void) {
	return this->inventorySize;
}
*/


//functional
/*
template <typename T>
void Inventory<T>::addInventoryItem(T item) {
	this->pItems[this->inventorySize] = item;
	this->inventorySize += 1;
}
template <typename T>
void Inventory<T>::removeInventoryItem(string itemName) {
	for (int x = 0; x < this->inventorySize; x++) {
		this->temp = (Item)this->pItems[x];
		if (this->temp->name == itemName) {
			for (int y = (x + 1); y < this->inventorySize; y++) {
				this->pItems[y - 1] = this->pItems[y];
			}
			this->inventorySize--;
			break;
		}
	}
	this->temp = nullptr;
}
template <typename T>
void Inventory<T>::setInventoryItem(string itemName, int numberOfItems) {
	bool isItem = false;
	for (int i = 0; i < this->InventorySize; i++) {
		this->temp = (Item)this->pItems[i];
		if (this->temp->name == itemName) {
			this->temp->numOfItems = numberOfItems;
			isItem = true;
			break;
		}
	}
	this->temp = nullptr;

	if (!isItem) {
		cout << "You don't have item in your inventory." << endl;
	}
}
*/

/*
template <typename T>
const T Inventory<T>::getInventoryItem(string itemName) {
	for (int i = 0; i < this->inventorySize; i++) {
		this->temp = (Item)this->pItems[i];
		if (this->temp->name == itemName) {
			this->temp = nullptr;
			return this->pItems[i];
		}
	}
	this->temp = nullptr;
	T nullItem = nullptr;
	return nullItem;
}
template <typename T>
const void Inventory<T>::printInventory(string playerName) {
	for (int i = 0; i < this->inventorySize; i++) {
		this->temp = (Item)this->pItems[i];
		if (this->temp->numOfItems == 0) {
			this->removeInventoryItem(this->temp->name);
		}
	}

	cout << "===========================================\n	[ " << playerName << "'s Inventory " << this->inventorySize << "/" << this->capacity << " ]\n===========================================" << endl;
	for (int i = 0; i < this->inventorySize; i++) {
		this->temp = (Item)this->pItems[i];
		cout << (i + 1) << ". ";
		this->temp[i].printInfo();
	}
	cout << "===========================================\n" << endl;

	this->temp = nullptr;
}
*/

/*
template <typename T>
const bool Inventory<T>::checkIndexItem(int itemIndex, string itemName) {
	this->temp = (Item)this->pItems[itemIndex];
	if (this->temp->name == itemName) {
		this->temp = nullptr;
		return true;
	}
	else {
		this->temp = nullptr;
		return false;
	}
}
template <typename T>
void Inventory<T>::addPotions(int defaultPotions) {
	Item hpPotion = { "HP Potion", defaultPotions, 50 };
	Item mpPotion = { "MP Potion", defaultPotions, 50 };
	this->addInventoryItem(hpPotion);
	this->addInventoryItem(mpPotion);
}
*/