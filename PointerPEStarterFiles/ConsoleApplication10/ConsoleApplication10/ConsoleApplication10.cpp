// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	//Monster *boss = new Monster();
	//Player *pOne = new Player();
	MovableObject *boss = new Monster();
	MovableObject *pOne = new Player();
	Monster *fakeMonster = (Monster*)pOne;

	// add code here
	cout << &boss << endl;
	cout << &pOne << endl;
	cout << &fakeMonster << endl;

	boss->xPos = 43;
	boss->yPos = 5;

	pOne->xPos = 198;
	pOne->yPos = 654;

	fakeMonster->xPos = 57;
	fakeMonster->yPos = 541;

	boss->PrintPos();
	pOne->PrintPos();
	fakeMonster->PrintPos();


	delete boss;
	delete pOne;
	// the reason I beleive this doe not work, is because it is a pointed to pOne, and because that is being deleted before this, 
	// fakeMonster isn't pointing to anything and so it cant be deleted
	fakeMonster = nullptr;

	_getch();
    return 0;
}

