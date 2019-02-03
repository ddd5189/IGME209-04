// main.cpp : Defines the entry point for the console application.
//
#include "stdafx.h";
#include "hangman.h";
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	// the word
	char word[20] = {"astronomical"};
	// variable to either keep the game loop going or display Win/Loss
	int gameEnd = 0;
	// intro
	cout << "Welcome to Hangman! Start the game by guessing a letter!" << endl;
	while (gameEnd == 0)
	{
		// create guess char
		char guess[10];
		cout << "Your guess: ";
		// recieve player input
		cin.getline(guess, 10);
		// use player input to see if the char is in the word
		// showSolved returns a int, to determine if the game is over
		gameEnd = showSolved(word, guess);
	}
	
	// once showSolved returns something other than 0
	if (gameEnd == 1) {
		cout << "Congrats You Win!" << endl;
	}
	else {
		cout << "You Lose, Try Again!" << endl;
	}

    return 0;
}

