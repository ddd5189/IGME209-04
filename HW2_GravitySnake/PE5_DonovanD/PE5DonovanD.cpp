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


// NOTE
// as you will be able to tell, all of the code is in main, besides moveTarget. When I first started, I was having problems understanding how to get the funtions to work, 
// so instead of dwelling on that I wanted to make sure that I could get it working properly then go back and see if I can get the functions working properly.
int main()
{
	// variable for while loop
	bool loop = true;
	// variable to help with key inputs
	char key;

	// the sfml positions of the box2d snake
	float sfmlPosX;
	float sfmlPosY;
	
	// target x and y
	float targetX = 0;
	float targetY = 0;

	// counting the target hits
	int targetHit = 0;

	int score = 0;

	cout << ("Welcome to Gravity Snake!\nTo play, use WASD to apply force IN that direction.\nIn order for the game to work, you must be in the input window\nFor optimal play, shrink the input window so that the play window is visable\n\nScore is like golf, the lower the better.\nDon't be surprised if the score is really high!") << endl;

	// Define the gravity vector.
	b2Vec2 gravity(0.0f, -.1f);

	// Construct a world object, which will hold and simulate the rigid bodies.
	b2World world(gravity);

	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -250.0f);

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	b2Body* groundBody = world.CreateBody(&groundBodyDef);

	// Define the ground box shape.
	b2PolygonShape groundBox;

	// The extents are the half-widths of the box.
	groundBox.SetAsBox(10000.0f, 0.0f);

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

	// set the first target in the screen
	moveTarget(targetX, targetY);

	while (loop)
	{

		sf::RenderWindow window(sf::VideoMode(800, 800), "My window");

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
					loop = false;
				}
			}
		
			window.clear(sf::Color::White);

			// create the snake and target in the window

			sf::RectangleShape target(sf::Vector2f(25, 25));
			target.setFillColor(sf::Color(100, 0, 0));
			target.setPosition(targetX, targetY);

			sf::RectangleShape snake(sf::Vector2f(50, 50));
			snake.setFillColor(sf::Color(10, 150, 50));
			snake.setPosition(400, 400);

		// This is our little game loop.
		for (int32 i = 0; i < 60; ++i)
		{
			// Instruct the world to perform a single step of simulation.
			// It is generally best to keep the time step and iterations fixed.
			world.Step(timeStep, velocityIterations, positionIterations);

			// Now print the position and angle of the body.
			b2Vec2 position = snakeBody->GetPosition();

			// converting box2d positions to work in the sfml window
			sfmlPosX = -position.x;
			sfmlPosY = -position.y + 500;

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
						//cout << "W was Pressed" << endl;
						snakeBody->ApplyForceToCenter(b2Vec2(0, 0.5f), true);
					}
					else if (key == 's') {
						//cout << "S was Pressed" << endl;
						snakeBody->ApplyForceToCenter(b2Vec2(0, -0.5f), true);
					}
					else if (key == 'a') {
						//cout << "A was Pressed" << endl;
						snakeBody->ApplyForceToCenter(b2Vec2(0.5f, 0), true);
					}
					else if (key == 'd') {
						//cout << "D was Pressed" << endl;
						snakeBody->ApplyForceToCenter(b2Vec2(-0.5f, 0), true);
					}
					printf("%4.2f %4.2f\n", sfmlPosX, sfmlPosY);
					//printf("%4.2f %4.2f\n", targetX, targetY);
					//cout << "Score: " << score << endl;
				}


				// collision detection between target and snake
				if ((sfmlPosX - 20 < targetX + 20) && (sfmlPosX + 20 > targetX - 20) && (sfmlPosY - 20 < targetY + 20) && (sfmlPosY + 20> targetY -20))
				{
					if (targetHit > 10) {
						cout << "Game Over" << endl;
						window.close();
						loop = false;
					}
					else {
						cout << "IT HIT" << endl;
						moveTarget(targetX, targetY);
						targetHit++;
						cout << targetHit << endl;
					}
				}

				// check to see if too far out of bounds, then close the game
				if ((sfmlPosX > 850) || (sfmlPosX < -100) || (sfmlPosY < -100)) {
					window.close();
					loop = false;
				}

				// if the snake is sitting on the ground, add score
				if (sfmlPosY > 748) {
					score++;
				}

				// drawing target and snake in the window
				window.clear(sf::Color::White);
				
				snake.setPosition(sfmlPosX, sfmlPosY);
				window.draw(target);
				window.draw(snake);

				//printf("%4.2f %4.2f\n", position.x, position.y);


			window.display();
			}
		}

	}

	return 0;
}

