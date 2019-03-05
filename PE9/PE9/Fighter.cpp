#include "pch.h"
#include "Fighter.h"
#include <iostream>
using namespace std;

Fighter::Fighter()
{
	weaponSkill = 0;
}

Fighter::Fighter(char* nameI, int strengthI, int dexterityI, int carryCapI, int weaponSkillI)
{
	weaponSkill = weaponSkillI;
	Player(nameI, strengthI, dexterityI, carryCapI);
}

void Fighter::printFighter() {
	printPlayer();
	cout  << "Weapon Skill: " << weaponSkill << endl;;
}

Fighter::~Fighter()
{
}
