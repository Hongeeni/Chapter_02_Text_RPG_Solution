#include "monster.h"

//setter
void Monster::setName(string newName) {
	this->name = newName;
}
void Monster::setExp(int newExp) {
	this->expReward = newExp;
}
void Monster::setHP(int newHP) {
	this->hp = newHP;
}
void Monster::setPower(int newPower) {
	this->power = newPower;
}
void Monster::setDefence(int newDefence) {
	this->defence = newDefence;
}
void Monster::setDropItemName(string newDropItemName) {
	this->dropItemName = newDropItemName;
}
void Monster::setDropItemPrice(int newDropItemPrice) {
	this->dropItemPrice = newDropItemPrice;
}

//getter
const string Monster::getName(void) {
	return name;
}
const int Monster::getExp(void) {
	return expReward;
}
const int Monster::getHP(void) {
	return hp;
}
const int Monster::getPower(void) {
	return power;
}
const int Monster::getDefence(void) {
	return defence;
}
const string Monster::getDropItemName(void) {
	return dropItemName;
}
const int Monster::getDropItemPrice(void) {
	return dropItemPrice;
}