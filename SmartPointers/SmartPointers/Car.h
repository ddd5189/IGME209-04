#pragma once
class Car
{
public:
	Car(string name);
	~Car();

	string typeName;
	int currentSpeed;
	int maxSpeed;
	bool caught;
	vector<string> Cargo;
	vector<string> Abilities;
};

