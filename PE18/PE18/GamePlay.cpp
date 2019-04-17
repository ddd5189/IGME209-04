#include "pch.h"
#include "GamePlay.h"


GamePlay::GamePlay(string n)
{
	name = n;
}


GamePlay::~GamePlay()
{
}

void GamePlay::Update()
{
	for (size_t i = 0; i < 10; i++)
	{
		cout << name << ": " << i * 10 << "% Complete" << endl;
	}
}
