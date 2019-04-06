#pragma once
#include "MovableObject.h"
#include <iostream>
using namespace std;
class Orc :
	public MovableObject
{
public:
	Orc();
	~Orc();

	void Display();
};

