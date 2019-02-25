#pragma once
#include "Rocket.h"
#include "Position.h"

class GoalieRocket :
	public Rocket, public Position
{
public:
	GoalieRocket();
	virtual ~GoalieRocket();
};

