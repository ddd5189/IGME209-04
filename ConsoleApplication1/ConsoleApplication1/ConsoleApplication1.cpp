// FinalExam.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Drew Donovan, section 4, FinalExam

#include "pch.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <string>
#include "Player.h"
using namespace std;

// global vectors to assist with collection data from the files
vector<string> weapons;
vector<string> players;

// function for reading from the weapons file to be called by the specific thread
void weaponFile()
{
	ifstream weaponStream;
	string line;

	weaponStream.open("Weapons.txt");

	if (weaponStream.is_open())
	{
		while (getline(weaponStream, line))
		{
			// push the data to the vector to be used for later
			weapons.push_back(line);
		}
		weaponStream.close();
	}
}

// function for reading from the players file to be called by the specific thread
void playerFile()
{
	ifstream playerStream;
	string line;

	playerStream.open("Players.txt");

	if (playerStream.is_open())
	{
		while (getline(playerStream, line))
		{
			// push the data to the vector to be used for later
			players.push_back(line);
		}
		playerStream.close();
	}
}

int main()
{
	// vector for players to represent both player and weapon
	vector<Player> playerAndWeapon;

	// threads for reading both files
	thread weaponThread(weaponFile);
	thread playerThread(playerFile);
	// making sure they are synchronized
	weaponThread.join();
	playerThread.join();

	// manually creating 10 players with the players and weapons vectors
	Player p1 = Player(players[0], weapons[0]);
	Player p2 = Player(players[1], weapons[1]);
	Player p3 = Player(players[2], weapons[2]);
	Player p4 = Player(players[3], weapons[3]);
	Player p5 = Player(players[4], weapons[4]);
	Player p6 = Player(players[5], weapons[5]);
	Player p7 = Player(players[6], weapons[6]);
	Player p8 = Player(players[7], weapons[7]);
	Player p9 = Player(players[8], weapons[8]);
	Player p10 = Player(players[9], weapons[9]);

	// manually pushing all 10 players into the collective vector
	playerAndWeapon.push_back(p1);
	playerAndWeapon.push_back(p2);
	playerAndWeapon.push_back(p3);
	playerAndWeapon.push_back(p4);
	playerAndWeapon.push_back(p5);
	playerAndWeapon.push_back(p6);
	playerAndWeapon.push_back(p7);
	playerAndWeapon.push_back(p8);
	playerAndWeapon.push_back(p9);
	playerAndWeapon.push_back(p10);

	// creating ofstream variable to create a txt file to output the combined variables
	ofstream pawFile;
	pawFile.open("PlayersAndWeapons.txt");

	for (size_t i = 0; i < playerAndWeapon.size(); i++)
	{
		// variable to assist with priting out the right number
		int realI = i + 1;
		// using the player classes print, printing out each combo
		cout << "Player " << realI << " " << playerAndWeapon[i].Print() << endl;
		if (pawFile.is_open())
		{
			// also outputting the same string to the created file
			pawFile << "Player " << realI << " " << playerAndWeapon[i].Print() + "\n";
		}
	}
	// when loop is done, close the file
	pawFile.close();

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
