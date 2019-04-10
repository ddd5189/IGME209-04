#include "pch.h"
#include "Ogre.h"


Ogre::Ogre()
{
}


Ogre::~Ogre()
{
}

// ogre specific display
void Ogre::Display()
{
	cout << "Ogre " << "x:" << xPosition << " y:" << yPosition << endl;
}
