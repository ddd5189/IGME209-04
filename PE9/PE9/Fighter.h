#pragma once
#include "Player.h"
class Fighter :
	public Player
{
public:
	Fighter();
	Fighter(char* nameI, int strengthI, int dexterityI, int carryCapI, int weaponSkillI);
	void printFighter();

	~Fighter();

private:
	int weaponSkill;
};

