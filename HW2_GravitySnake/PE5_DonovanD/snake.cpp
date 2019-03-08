#include "stdafx.h"
#define SFML_STATIC
#include "snake.h"
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Box2D/Box2D.h"
#include <conio.h>
using namespace std;

int key = 0;

void update() {
	
}

void display() {

}

void applyForces() {
	//cout << "Apply forces was called" << endl;

	if (_kbhit()) {
		key = _getch();
		if (key == 'w') {
			cout << "W was Pressed" << endl;
			//body.ApplyForceToCenter(b2Vec2(0, 50), true);
		}
		else if (key == 's') {
			cout << "S was Pressed" << endl;
			//body.ApplyForceToCenter(b2Vec2(0, -50), true);
		}
		else if (key == 'a') {
			cout << "A was Pressed" << endl;
			//body.ApplyForceToCenter(b2Vec2(-50, 0), true);
		}
		else if (key == 'd') {
			cout << "D was Pressed" << endl;
			//body.ApplyForceToCenter(b2Vec2(50, 0), true);
		}
	}
}

void moveTarget(float& xPos, float& yPos) {
	srand(time(NULL));
	int randNumX = rand() % (770 + 1);
	int randNumY = rand() % (770 + 1);

	xPos = randNumX;
	yPos = randNumY;

	cout << "X:" << xPos << endl;
	cout << "Y:" << yPos << endl;
}