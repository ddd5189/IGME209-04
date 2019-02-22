#pragma once
class Player
{
public:
	Player();
	Player(char* nameI, int strengthI, int dexterityI, int carryCapI);
	void printPlayer();

	virtual ~Player();

private:
	const char* name;
	int strength;
	int dexterity;
	int carryCap;
};

