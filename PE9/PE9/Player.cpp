#include "pch.h"
#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
	strength = 10;
	dexterity = 10;
	carryCap = 10;
	name = "Unkown";
}

Player::Player(char* nameI, int strengthI, int dexterityI, int carryCapI)
{
	strength = strengthI;
	dexterity = dexterityI;
	carryCap = carryCapI;
	name = nameI;
}

void Player::printPlayer() {
	cout << "Player Name: " << name << "\nStrength: " << strength << "\nDexterity: " << dexterity << "\nCarry Capacity: " << carryCap << endl;
}

Player::~Player()
{
}
