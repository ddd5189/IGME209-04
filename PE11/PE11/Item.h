#pragma once
#include <iostream>
using namespace std;

struct Item
{
public:
	Item();
	Item(string nameI, int damageI, int weightI);
	~Item();

	void print();

private:
	string name;
	int damage;
	int weight;
};

