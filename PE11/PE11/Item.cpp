#include "pch.h"
#include "Item.h"

#include <iostream>
#include <string>
using namespace std;

Item::Item()
{
}

Item::Item(string nameI, int damageI, int weightI)
{
	name = nameI;
	damage = damageI;
	weight = weightI;
}


Item::~Item()
{
}

void Item::print() 
{
	cout << "The name of your weapon is: " << name << endl;
	cout << "Your weapons damage is: " << damage << endl;
	cout << "Your weapons weight is: " << weight << endl;
}