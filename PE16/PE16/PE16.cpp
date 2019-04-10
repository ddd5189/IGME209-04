// PE16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream outFile;
	ifstream inFile("test.txt", ios::binary);

	

	outFile.open("test.txt");
	string line;

	if (outFile.is_open()) {
		outFile << "This is the first line in the test file\n";
		outFile << "This is the second line in the test file\n";
		outFile.close();
	}

	char* fileContents = nullptr;

	if (inFile.is_open())
	{
		inFile.seekg(0, ios::end);
		int length = (int)inFile.tellg();

		inFile.seekg(0, ios::beg);

		fileContents = new char[length + 1];

		inFile.read(fileContents, length);
		fileContents[length] = 0;
	}
	inFile.close();

	std::cout << fileContents;
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
