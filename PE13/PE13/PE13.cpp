// PE13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int resultRec = 0;

//four hands even numbered seats (e.g.  2, 4, 6) 
//three hands odd numbered seats (e.g.  1, 3, 5).  
int Iteration(int seats)
{
	int result = 0;
	for (size_t i = 1; i < seats + 1; i++)
	{
		// even
		if (i % 2 == 0) {
			result += 4;
		}
		// odd
		else
		{
			result += 3;
		}
	}
	return result;
}

int Recursion(int seats)
{
	if (seats != 0)
	{
		if (seats % 2 == 0) {
			resultRec += 4;
			int seat = seats;
			seat--;
			Recursion(seat);
		}
		// odd
		else
		{
			resultRec += 3;
			int seat = seats;
			seat--;
			Recursion(seat);
		}
	}
	else
	{
		int resultRecFinal = resultRec;
		resultRec = 0;
		return resultRecFinal;
	}

}

int Formula(int seats)
{
	int seatsForm = ((4+3) * seats)/2;
	return seatsForm;
}

int main()
{
	std::cout << "Solution for '30' trough Iteration: " << Iteration(30) << std::endl;
	std::cout << "Solution for '30' trough Recursion: " << Recursion(30) << std::endl;
	std::cout << "Solution for '30' trough Formula: " << Formula(30) << std::endl;

	std::cout << "\nSolution for '5' trough Iteration: " << Iteration(5) << std::endl;
	std::cout << "Solution for '5' trough Recursion: " << Recursion(5) << std::endl;
	std::cout << "Solution for '5' trough Formula: " << Formula(5) << std::endl;

	std::cout << "\nSolution for '17' trough Iteration: " << Iteration(17) << std::endl;
	std::cout << "Solution for '17' trough Recursion: " << Recursion(17) << std::endl;
	std::cout << "Solution for '17' trough Formula: " << Formula(17) << std::endl;
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
