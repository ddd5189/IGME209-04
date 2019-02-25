#include "stdafx.h"
#include "hangman.h"
#include <iostream>
#include <cstring>
using namespace std;

// string that displays the wrong guesses for the player to see
char wrongGuesses[100] = "";
// string that displays the right guesses for the player to see
char correct[100] = "_ _ _ _ _ _ _ _ _ _ _ _";
// int to make sure the gallows change stage
int gallowCount = 0;
// bool to facilitate end game
bool gallowEnd = false;
// int to track correct guesses to facilitate end game
int corGuesses = 0;
int charLeft = 12;

void showGallows(int guessLimit)
{
	// guessLimit is what stage of the gallow it should be in
	// this is depends on if the player guesses a wrong letter
	// each if draws the gallows at the correct stage
	if (guessLimit == 0)
	{
		cout << "\n___________\n|     |\n|\n|\n|\n|\n|\n|\n" << endl;
	}
	if (guessLimit == 1)
	{
		cout << "\n___________\n|     |\n|     O\n|\n|\n|\n|\n|\n" << endl;
	}
	if (guessLimit == 2)
	{
		cout << "\n___________\n|     |\n|     O\n|     |\n|\n|\n|\n|\n" << endl;
	}
	if (guessLimit == 3)
	{
		cout << "\n___________\n|     |\n|     O\n|     |\\\n|\n|\n|\n|\n" << endl;
	}
	if (guessLimit == 4)
	{
		cout << "\n___________\n|     |\n|     O\n|    /|\\\n|\n|\n|\n|\n" << endl;
	}
	if (guessLimit == 5)
	{
		cout << "\n___________\n|     |\n|     O\n|    /|\\\n|     |\n|\n|\n|\n" << endl;
	}
	if (guessLimit == 6)
	{
		cout << "\n___________\n|     |\n|     O\n|    /|\\\n|     |\n|      \\\n|\n|\n" << endl;
	}
	if (guessLimit == 7)
	{
		cout << "\n___________\n|     |\n|     O\n|    /|\\\n|     |\n|    / \\\n|\n|\n" << endl;
		// this variable is to indicate that the player has lost
		gallowEnd = true;
	}
}

int showSolved(char word[], char guess[])
{
	// test the word and char to see if the char is in the word
	if (strchr(word, guess[0])) {
		// i know doing it this way is not good. I just don't understand how to use strchr to find the position to change the correct string.
		// When I use strchr it returns the string from the position of the search char. so if looking for 'r' it returns "ronomical"

		// each if checks what the guess is and if the spot its trying to take is open
		// then changes the correct spot(s) to the guess and adds 1 to corGuesses
		if (guess[0] == 'a' && correct[0] == '_') {
			correct[0] = 'a';
			correct[20] = 'a';
			corGuesses++;
			charLeft - 2;
		}
		else if (guess[0] == 's' && correct[2] == '_') {
			correct[2] = 's';
			corGuesses++;
			charLeft--;
		}
		else if (guess[0] == 't' && correct[4] == '_') {
			correct[4] = 't';
			corGuesses++;
			charLeft--;
		}
		else if (guess[0] == 'r' && correct[6] == '_') {
			correct[6] = 'r';
			corGuesses++;
			charLeft--;
		}
		else if (guess[0] == 'o' && correct[8] == '_') {
			correct[8] = 'o';
			correct[12] = 'o';
			corGuesses++;
			charLeft - 2;
		}
		else if (guess[0] == 'n' && correct[10] == '_') {
			correct[10] = 'n';
			corGuesses++;
			charLeft--;
		}
		else if (guess[0] == 'm' && correct[14] == '_') {
			correct[14] = 'm';
			corGuesses++;
			charLeft--;
		}
		else if (guess[0] == 'i' && correct[16] == '_') {
			correct[16] = 'i';
			corGuesses++;
			charLeft--;
		}
		else if (guess[0] == 'c' && correct[18] == '_') {
			correct[18] = 'c';
			corGuesses++;
			charLeft--;
		}
		else if (guess[0] == 'l' && correct[22] == '_'){
			correct[22] = 'l';
			corGuesses++;
			charLeft--;
		}
	}
	else {
		// if the player guesses a repeat char
		if (strchr(wrongGuesses, guess[0])) {
			cout << "\nYou have already guessed that!" << endl;
		}
		else {
			// if it isn't, add the char guesses to the wrongGuesses string
			strcat_s(wrongGuesses, guess);
			// add one to gallowCount to change stage
			gallowCount++;
		}

	}
	// show the gallows
	showGallows(gallowCount);

	// display wrongGuesses string
	cout << "Wrong Guesses: " << wrongGuesses << endl;
	// display correct string
	cout << "Your word: " << correct << "\n" << endl;

	// if the word has been solved return 1 so that main displays Win
	if (corGuesses == 10) {
		return 1;
	}
	// if the word has not been solved after the last stage of the gallows return 2 so that main displays Loss
	else if (gallowEnd == true) {
		return 2;
	}
	// if the word has not been solved return 0 so that main continues the game loop
	else {
		return 0;
	}



}