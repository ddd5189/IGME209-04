#pragma once
#include <iostream>
#include <string>
using namespace std;
class GamePlay
{
public:
	GamePlay(string n);
	~GamePlay();
	void Update();
private:
	string name;
};

