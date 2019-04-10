#pragma once
#include "MovableObject.h"
#include <iostream>
using namespace std;
class Ogre :
	public MovableObject
{
public:
	Ogre();
	~Ogre();

	void Display();
};

