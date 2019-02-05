// PE6_Donovan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstring>
#include <string>
#include <time.h>
using namespace std;

void generateRandom(int numberOfRands) 
{
	srand(time(NULL));

	for (int i = 0; i < numberOfRands; i++) 
	{
		if (i == 0) 
		{
			cout << "This is the " << i + 1 << "st random number is " << rand() << endl;
		}														
		else if (i == 1)										
		{														
			cout << "This is the " << i + 1 << "nd random number is " << rand() << endl;
		}														
		else {													
			cout << "This is the " << i + 1 << "th random number is " << rand() << endl;
		}
	}
}

char* reverseString(char* inputString)
{
	char newString[256] = "";
	int len = strlen(inputString);
	for (int i = 0; i < len; i++)
	{
		char c = inputString[i];
		newString[len - i] = c;
	}
	strcpy_s(inputString, 128, (const char*)newString);
	return inputString;
}

int main()
{

	char numberChr[100];
    cout << "How many random numbers would you like to generate: ";
	cin.getline(numberChr, 100);
	
	generateRandom(stoi(numberChr));

	char input[256];
	cout << "\n\nPlease type something: ";
	cin.getline(input, 256);
	
	cout << reverseString(input);

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
