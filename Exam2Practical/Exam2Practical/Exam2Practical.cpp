// Exam2Practical.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "MovableObject.h"
#include "Ogre.h"
#include "Orc.h"
#include <vector>
#include <time.h>
using namespace std;

int main()
{
	// MovableObject vector
	vector<MovableObject*> mObecjts;

	// child pointers
	Orc* orc1 = new Orc();
	Orc* orc2 = new Orc();
	Ogre* ogre1 = new Ogre();
	Ogre* ogre2 = new Ogre();
	Ogre* ogre3 = new Ogre();

	// make these random
	srand(time(NULL));
	// setting positions for all and adding them to the vector
	orc1->SetPosition((rand() % 200) - 100, (rand() % 200) - 100);
	mObecjts.push_back(orc1);
	orc2->SetPosition((rand() % 200) - 100, (rand() % 200) - 100);
	mObecjts.push_back(orc2);
	ogre1->SetPosition((rand() % 200) - 100, (rand() % 200) - 100);
	mObecjts.push_back(ogre1);
	ogre2->SetPosition((rand() % 200) - 100, (rand() % 200) - 100);
	mObecjts.push_back(ogre2);
	ogre3->SetPosition((rand() % 200) - 100, (rand() % 200) - 100);
	mObecjts.push_back(ogre3);

	cout << "My Horde consists of..." << endl;
	// using display on all objects in vector
	for (size_t i = 0; i < mObecjts.size(); i++)
	{
		mObecjts[i]->Display();
	}

	// delete
	delete orc1;
	delete orc2;
	delete ogre1;
	delete ogre2;
	delete ogre3;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
