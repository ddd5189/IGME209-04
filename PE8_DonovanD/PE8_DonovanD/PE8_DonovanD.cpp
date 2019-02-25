// PE8_DonovanD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

void ChangeVariable(int& number) {
	// by using 'int&' whatever I change the variable to in this function is kept outside of it aswell.
	int num = number;
	number = number * 3;
	cout << "Your original number was: " << num << ", and ChangeVariable() changed it to: " << number << endl;
}

void ChangePointer(int *number) {
	// using '*' it takes the data the pointer is referencing and changing that.
	int num = *number;
	*number = 23;
	cout << "Your original number was: " << num << ", and ChangePointer() changed it to: " << *number << endl;
}

int getLengthArray(int ary[]) {
	int length = 0;
	bool end = false;
	int i = 0;
	while (!end) {

		if (ary[i] == -1) {
			end = true;
		}
		else {
			length++;
			i++;
		}
	}

	return length;
}

int getLengthPointer(int* ary) {
	int length = 0;
	bool end = false;
	int i = 0;
	while (!end) {

		if (*ary == -1) {
			end = true;
		}
		else {
			length++;
			ary++;
		}
	}

	return length;
}

int* createStackArray() {
	int ary[5] = { 0,1,2,3,4 };

	return ary;
}

int* createHeapArray(int size) {
	int* ary = new int[size];
	int ele = 0;
	for (size_t i = 0; i < size; i++)
	{
		*ary = ele;
		ary++;
		ele++;
	}
	return ary;
	//delete[] ary;
}

int main()
{
	int val = 5;
	ChangeVariable(val);
	int *val2 = &val;
	ChangePointer(val2);
	int ary[7] = { 1,2,3,4,5,6,-1 };
	int* arrayPointer = ary;

	cout << "Using an array: " << getLengthArray(ary) << endl;
	cout << "Using a pointer: " << getLengthArray(arrayPointer) << endl;

	cout << "Using pointer arithmatic: " << getLengthPointer(arrayPointer) << endl;

	int* stackAry = createStackArray();
	int* heapAry = createHeapArray(5);

	cout << "Stack Array:" << endl;
	for (size_t i = 0; i < 5; i++)
	{
		cout << stackAry[i] << endl;
	}
	cout << "Heap Array: " << endl;
	for (size_t i = 0; i < 5; i++)
	{
		cout << heapAry[i] << endl;
	}


	delete[] heapAry;
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
