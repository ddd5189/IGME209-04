#pragma once
#include <iostream>
using namespace std;

class MovableObject
{
public:
	MovableObject();
	virtual ~MovableObject();

	void SetPosition(int x, int y);
	//virtual display
	virtual void Display();

	//protected variables
protected:
	int xPosition;
	int yPosition;
};

