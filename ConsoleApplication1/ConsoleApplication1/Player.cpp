#include "pch.h"
#include "Player.h"
#include <string>
#include <iostream>
using namespace std;

Player::Player()
{
}

// paramaterized ctor to set name and weapon vars
Player::Player(string Name, string Weapon)
{
	name = Name;
	weapon = Weapon;
}

// print method that returns a string, so it can be used with ofstream
string Player::Print()
{
	string print = name  + " has a " + weapon;
	return print;
}

Player::~Player()
{
}
