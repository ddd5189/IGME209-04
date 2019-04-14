// HW5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Stack.h"
#include <iostream>
using namespace std;

int main()
{
	Stack<double> stack;
	stack.Push(5.7);
	stack.Push(1.2);
	stack.Push(7.4);
	stack.Push(19.12);
	stack.Push(4.34);
	stack.Push(9.56);
	if (stack.IsEmpty())
	{
		cout << "Tis empty" << endl;
	}
	else
	{
		cout << "Something be inside" << endl;
	}
	cout << "Size: " << stack.GetSize() << endl;
	stack.Print(); 
	stack.Pop();
	stack.Pop();
	stack.Pop();
	stack.Pop();
	stack.Print();
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
