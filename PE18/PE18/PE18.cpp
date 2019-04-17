// PE18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "NumberPrinter.h"
#include "GamePlay.h"
#include <iostream>
#include <thread>
#include <vector>
using namespace std;

int main()
{
	// quick call and response to determine what part of the PE gets run
	char response = NULL;
	cout << "Enter '1' for part 1 or Enter '2' for part 2" << endl;
	cin >> response;
	if (response == '1')
	{
		for (size_t i = 0; i < 50; i++)
		{
			NumberPrinter *numPrint = new NumberPrinter(i);
			//numPrint.Print();
			// only created 10, becuase 50 would break
			thread t1(&NumberPrinter::Print, numPrint);
			thread t2(&NumberPrinter::Print, numPrint);
			thread t3(&NumberPrinter::Print, numPrint);
			thread t4(&NumberPrinter::Print, numPrint);
			thread t5(&NumberPrinter::Print, numPrint);
			thread t6(&NumberPrinter::Print, numPrint);
			thread t7(&NumberPrinter::Print, numPrint);
			thread t8(&NumberPrinter::Print, numPrint);
			thread t9(&NumberPrinter::Print, numPrint);
			thread t10(&NumberPrinter::Print, numPrint);

			t1.join();
			t2.join();
			t3.join();
			t4.join();
			t5.join();
			t6.join();
			t7.join();
			t8.join();
			t9.join();
			t10.join();
		}
	}
	else 
	{
		// 5 GamePlay objects
		GamePlay *g1 = new GamePlay("Physics");
		GamePlay *g2 = new GamePlay("Graphics");
		GamePlay *g3 = new GamePlay("Audio");
		GamePlay *g4 = new GamePlay("Models");
		GamePlay *g5 = new GamePlay("DLC");

		// vecotr of thread pointers
		vector<thread*> threads;

		// creating each thread using the objects Update method
		thread t1(&GamePlay::Update, g1);
		thread t2(&GamePlay::Update, g2);
		thread t3(&GamePlay::Update, g3);
		thread t4(&GamePlay::Update, g4);
		thread t5(&GamePlay::Update, g5);

		// adding all the threads to the vector
		threads.push_back(&t1);
		threads.push_back(&t2);
		threads.push_back(&t3);
		threads.push_back(&t4);
		threads.push_back(&t5);

		// join works to make sure they all run before the cout below, but all of the threads are still overlapping
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		t5.join();

		// when all the threads are done, print this out
		cout << "Update Complete! Time to Draw" << endl;
	}
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
