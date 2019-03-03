// PE5DonovanD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define SFML_STATIC
#include "snake.h"
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "Box2D/Box2D.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{


	// variable for while loop
	bool loop = true;
	char key;
	
	float targetX = 0;
	float targetY = 0;

	int targetHit = 0;

	cout << ("Welcome to Gravity Snake!\nTo play, use WASD to apply force IN that direction.") << endl;

	// Define the gravity vector.
	b2Vec2 gravity(0.0f, -.1f);

	// Construct a world object, which will hold and simulate the rigid bodies.
	b2World world(gravity);

	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	b2Body* groundBody = world.CreateBody(&groundBodyDef);

	// Define the ground box shape.
	b2PolygonShape groundBox;

	// The extents are the half-widths of the box.
	groundBox.SetAsBox(100.0f, 0.0f);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);

	// Define the dynamic body. We set its position and call the body factory.
	b2BodyDef snakeBodyDef;
	snakeBodyDef.type = b2_dynamicBody;
	snakeBodyDef.position.Set(0.0f, 10.0f);
	b2Body* snakeBody = world.CreateBody(&snakeBodyDef);

	// Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	// Define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;

	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = 0.005f;

	// Override the default friction.
	fixtureDef.friction = 0.9f;

	// Add the shape to the body.
	snakeBody->CreateFixture(&fixtureDef);

	// Prepare for simulation. Typically we use a time step of 1/60 of a
	// second (60Hz) and 10 iterations. This provides a high quality simulation
	// in most game scenarios.
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	//sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

	moveTarget(targetX, targetY);

	while (loop)
	{
		// This is our little game loop.
		for (int32 i = 0; i < 60; ++i)
		{
			// Instruct the world to perform a single step of simulation.
			// It is generally best to keep the time step and iterations fixed.
			world.Step(timeStep, velocityIterations, positionIterations);

			// Now print the position and angle of the body.
			b2Vec2 position = snakeBody->GetPosition();

			//while (window.isOpen())
			//{
			//	sf::Event event;
			//	while (window.pollEvent(event)) {
			//		if (event.type == sf::Event::Closed) {
			//			window.close();
			//		}
			//	}
			//
			//	window.clear(sf::Color::Green);

			// key press if - if p (don't know char for ESC) exit loop, if l move target (will get removed when collision is figured out), if wsad apply force in that direction
				if (_kbhit()) {
					key = _getch();
					if (key == 'p') {
						cout << "Escape loop" << endl;
						loop = false;
					}
					else if (key == 'l') {
						moveTarget(targetX, targetY);
					}
					else if (key == 'w') {
						cout << "W was Pressed" << endl;
						snakeBody->ApplyForceToCenter(b2Vec2(0, 1), true);
					}
					else if (key == 's') {
						cout << "S was Pressed" << endl;
						snakeBody->ApplyForceToCenter(b2Vec2(0, -1), true);
					}
					else if (key == 'a') {
						cout << "A was Pressed" << endl;
						snakeBody->ApplyForceToCenter(b2Vec2(-1, 0), true);
					}
					else if (key == 'd') {
						cout << "D was Pressed" << endl;
						snakeBody->ApplyForceToCenter(b2Vec2(1, 0), true);
					}
					printf("%4.2f %4.2f\n", position.x, position.y);
				}


				// one is snake
				// two is target
				// if ((oneXmin < twoXmax) && (oneXmax > twoXmin) && (oneYmin < twoYmax) && (oneYmax > twoYmin))


				// collision detection between target and snake
				if ((position.x < targetX) && (position.x > targetX) && (position.y < targetY) && (position.y > targetY))
				{
					if (targetHit > 2) {
						cout << "Game Over" << endl;
						loop = false;
					}
					else {
						cout << "IT HIT" << endl;
						moveTarget(targetX, targetY);
						targetHit++;
					}
				}

				//printf("%4.2f %4.2f\n", position.x, position.y);

			//	sf::RectangleShape rectangle1(sf::Vector2f(120, 50));
			//	rectangle1.setFillColor(sf::Color(300, 150, 50));
			//	rectangle1.setPosition(targetX, targetY);
			//
			//	window.display();
			//}
		}

	}

	return 0;

	//sf::CircleShape circle1(50);
	//circle1.setFillColor(sf::Color(100, 250, 50));
	//circle1.setPosition(10, 50);
	//
	//sf::CircleShape circle2(80);
	//circle2.setFillColor(sf::Color(10, 300, 50));
	//circle2.setPosition(200, 300);
	//
	//sf::RectangleShape rectangle1(sf::Vector2f(120, 50));
	//rectangle1.setFillColor(sf::Color(300, 150, 50));
	//rectangle1.setPosition(400, 230);
	//
	//sf::RectangleShape rectangle2(sf::Vector2f(80, 220));
	//rectangle2.setFillColor(sf::Color(100, 500, 20));
	//rectangle2.setPosition(600, 200);
	//
	//window.draw(circle1);
	//window.draw(circle2);
	//window.draw(rectangle1);
	//window.draw(rectangle2);

	//// Define the ground body.
	//b2BodyDef snakeBodyDef;
	//snakeBodyDef.position.Set(0.0f, -10.0f);
	//
	//// Call the body factory which allocates memory for the ground body
	//// from a pool and creates the ground box shape (also from a pool).
	//// The body is also added to the world.
	//b2Body* snakeBody = world.CreateBody(&snakeBodyDef);
	//
	//// Define the ground box shape.
	//b2PolygonShape snakeBox;
	//
	//// The extents are the half-widths of the box.
	//snakeBox.SetAsBox(50.0f, 10.0f);
	//
	//// Add the ground fixture to the ground body.
	//snakeBody->CreateFixture(&snakeBox, 0.0f);

}

