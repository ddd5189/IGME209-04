// PE9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Player.h"
#include "Fighter.h"
#include <iostream>
using namespace std;

int main()
{
	char name[10] = "Bard";

	// creating players on the stack
	Player player1 = Player();
	Player player2 = Player(name, 23, 19, 8);
	// creating players on the heap
	Player* player3 = new Player();
	Player* player4 = new Player(name, 40, 2, 15);

	Fighter fighter1 = Fighter();
	Fighter fighter2 = Fighter(name, 32, 11, 6, 18);

	cout << "Player on the stack with default constructor" << endl;
	player1.printPlayer();
	cout << "\nPlayer on the stack with parameterized constructor" << endl;
	player2.printPlayer();
	cout << "\nPlayer on the heap with default constructor" << endl;
	player3->printPlayer();
	cout << "\nPlayer on the heap with parameterized constructor" << endl;
	player4->printPlayer();
	cout << "\nFighter with deafault constructor" << endl;
	fighter1.printFighter();
	cout << "\nFighter with parameterized constructor" << endl;
	fighter2.printFighter();

	delete player3;
	delete player4;
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
