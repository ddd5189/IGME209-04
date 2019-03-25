#include "pch.h"
#include "Car.h"


Car::Car(string name)
{
	typeName = name;
	cout << "car ctor" << typeName << endl;
}


Car::~Car()
{
	cout << "car dtor" << typeName << endl;
}
