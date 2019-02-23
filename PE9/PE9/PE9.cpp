// PE9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Player.h"
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

	player1.printPlayer();
	player2.printPlayer();
	player3->printPlayer();
	player4->printPlayer();

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
