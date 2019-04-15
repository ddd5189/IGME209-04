// HW5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Stack.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Stack using double data type: " << endl;
	// creating stack
	Stack<double> stackDoub;
	// checking if it is empty 
	if (stackDoub.IsEmpty())
	{
		cout << "The stack is empty" << endl;
	}
	else
	{
		cout << "The stack has data" << endl;
	}
	// pushing data into stack
	stackDoub.Push(5.7);
	stackDoub.Push(1.2);
	stackDoub.Push(7.4);
	stackDoub.Push(19.12);
	stackDoub.Push(4.34);
	stackDoub.Push(9.56);
	cout << "Pushed Data" << endl;
	// checking agian if it is empty
	if (stackDoub.IsEmpty())
	{
		cout << "The stack is empty" << endl;
	}
	else
	{
		cout << "The stack has data" << endl;
	}
	// printing size of the stack, and the data inside
	cout << "Size: " << stackDoub.GetSize() << endl;
	stackDoub.Print();
	// popping out some of the data, and printing size and data again
	stackDoub.Pop();
	stackDoub.Pop();
	stackDoub.Pop();
	cout << "Size: " << stackDoub.GetSize() << endl;
	stackDoub.Print();

	cout << "\nStack using bool data type: " << endl;
	// creating stack
	Stack<bool> stackBool;
	// checking if it is empty 
	if (stackBool.IsEmpty())
	{
		cout << "The stack is empty" << endl;
	}
	else
	{
		cout << "The stack has data" << endl;
	}
	// pushing data into stack
	stackBool.Push(true);
	stackBool.Push(true);
	stackBool.Push(false);
	stackBool.Push(true);
	stackBool.Push(false);
	stackBool.Push(false);
	cout << "Pushed Data" << endl;
	// checking agian if it is empty
	if (stackBool.IsEmpty())
	{
		cout << "The stack is empty" << endl;
	}
	else
	{
		cout << "The stack has data" << endl;
	}
	// printing size of the stack, and the data inside
	cout << "Size: " << stackBool.GetSize() << endl;
	stackBool.Print();
	// popping out some of the data, and printing size and data again
	stackBool.Pop();
	stackBool.Pop();
	stackBool.Pop();
	cout << "Size: " << stackBool.GetSize() << endl;
	stackBool.Print();

	cout << "\nStack using char data type: " << endl;
	// creating stack
	Stack<bool> stackChar;
	// checking if it is empty 
	if (stackChar.IsEmpty())
	{
		cout << "The stack is empty" << endl;
	}
	else
	{
		cout << "The stack has data" << endl;
	}
	// pushing data into stack
	stackChar.Push('A');
	stackChar.Push('B');
	stackChar.Push('C');
	stackChar.Push('D');
	stackChar.Push('E');
	stackChar.Push('F');
	cout << "Pushed Data" << endl;
	// checking agian if it is empty
	if (stackChar.IsEmpty())
	{
		cout << "The stack is empty" << endl;
	}
	else
	{
		cout << "The stack has data" << endl;
	}
	// printing size of the stack, and the data inside
	cout << "Size: " << stackChar.GetSize() << endl;
	stackChar.Print();
	// popping out some of the data, and printing size and data again
	stackChar.Pop();
	stackChar.Pop();
	stackChar.Pop();
	cout << "Size: " << stackChar.GetSize() << endl;
	stackChar.Print();
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
