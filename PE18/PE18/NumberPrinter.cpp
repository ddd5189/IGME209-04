#include "pch.h"
#include "NumberPrinter.h"
#include <iostream>
using namespace std;

NumberPrinter::NumberPrinter(int num)
{
	number = num;
}


NumberPrinter::~NumberPrinter()
{
}

void NumberPrinter::Print()
{
	cout << number << number << number << number << number << number << number << number << number << number << endl;
}
