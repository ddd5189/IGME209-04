#pragma once
#include "pch.h"
#include <string>
#include <iostream>
using namespace std;

class Player
{
public:
	Player();
	Player(string Name, string Weapon);
	string Print();
	~Player();
	
	// name variables
	string name;
	string weapon;
};

