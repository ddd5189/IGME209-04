#include "pch.h"
#include "MovableObject.h"



MovableObject::MovableObject()
{
}


MovableObject::~MovableObject()
{
}

void MovableObject::SetPosition(int x, int y)
{
	xPosition = x;
	yPosition = y;
}

void MovableObject::Display() 
{
	cout << "x: " << xPosition << " y: " << yPosition << endl;
}
