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

vector<b2Vec2> targetLocations;
b2Vec2 currentLocation;

float revGrav = .5f;
int amntOfTargets;
int target = 0;

void processInput() 
{

}

void ApplyForceUp(b2Body& player) 
{
	player.ApplyForceToCenter(b2Vec2(0, 0.1f), true);
}

void ApplyForceDown(b2Body& player) 
{
	player.ApplyForceToCenter(b2Vec2(0, -0.1f), true);
}

void ApplyForceLeft(b2Body& player) 
{
	player.ApplyForceToCenter(b2Vec2(0.1f, 0), true);
}

void ApplyForceRight(b2Body& player) 
{
	player.ApplyForceToCenter(b2Vec2(-0.1f, 0), true);
}

void StopMoving(b2Body& player) 
{
	b2Vec2 stop(0.0f, 0.0f);
	player.SetLinearVelocity(stop);
}

void ReverseGravity(b2World& world) 
{
	revGrav *= -1;
	b2Vec2 revGravity(0.0f, revGrav);
	world.SetGravity(revGravity);
}

void setupTargets()
{
	cout << "\nHow many targets would you like to have (No less than 10): " << endl;
	cin >> amntOfTargets;
	if (amntOfTargets < 10) {
		while (amntOfTargets < 10) {
			cout << "Please input a number greater than 10" << endl;
			cin >> amntOfTargets;
		}
	}
	else {
		targetLocations.resize(amntOfTargets + 1);
		for (size_t i = 0; i < amntOfTargets + 1; i++)
		{
			if (i < amntOfTargets) {
				targetLocations[i] = b2Vec2(setTargetX(), setTargetY());
				//cout << "X: " << targetLocations[i].x << " Y: " << targetLocations[i].y << endl;
			}
			else {
				targetLocations[i] = b2Vec2(-1000, -1000);
			}
		}
	}
}

bool selectNextTarget()
{
	//cout << "X: " << targetLocations[target].x << " Y: " << targetLocations[target].y << endl;
	if (targetLocations[target] == b2Vec2(-1000, -1000)) {
		return false;
	}
	else {
		currentLocation = targetLocations[target];
		target++;
		return true;
	}
}

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

	cout << ("Welcome to Gravity Snake!\nTo play, use WASD to apply force IN that direction.\nTo stop the snake press 'Space'\nTo reverse gravity press 'F'\nMake sure to not go to far out of the screen or the game will end!\nDon't be surprised if the score is really high! But Remember smaller is better!") << endl;

	// Define the gravity vector.
	b2Vec2 gravity(0.0f, -.5f);

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
	//moveTarget(targetX, targetY);

	setupTargets();

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

			sf::CircleShape snake;
			snake.setRadius(30);
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

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
						//cout << "Escape loop" << endl;
						window.close();
						loop = false;
					}
					//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
					//	moveTarget(targetX, targetY);
					//}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						ReverseGravity(world);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
						//cout << "W was Pressed" << endl;
						StopMoving(*snakeBody);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
						//cout << "W was Pressed" << endl;
						ApplyForceUp(*snakeBody);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
						//cout << "S was Pressed" << endl;
						ApplyForceDown(*snakeBody);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
						//cout << "A was Pressed" << endl;
						ApplyForceLeft(*snakeBody);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
						//cout << "D was Pressed" << endl;
						ApplyForceRight(*snakeBody);
					}
					//printf("%4.2f %4.2f\n", sfmlPosX, sfmlPosY);


				// collision detection between target and snake
				if ((sfmlPosX - 20 < targetX + 20) && (sfmlPosX + 20 > targetX - 20) && (sfmlPosY - 20 < targetY + 20) && (sfmlPosY + 20> targetY -20))
				{
					selectNextTarget();

					// I tried using the -1000,-1000 point but it just wouldnt work
					if (targetHit > amntOfTargets) {
						cout << "Game Over\nFinal Score: " << score << endl;
						window.close();
						loop = false;
						targetHit = 0;
					}
					else {
						//cout << "IT HIT" << endl;
						targetX = currentLocation.x;
						targetY = currentLocation.y;
						targetHit++;
						// print the score
						cout << "Score: " << score << endl;
						//cout << targetHit << endl;
					}
				}

				// check to see if too far out of bounds, then close the game
				if ((sfmlPosX > 850) || (sfmlPosX < -100) || (sfmlPosY < -300)) {
					window.close();
					cout << "TOO FAR OUT OF THE SCREEN!" << endl;
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

//if (_kbhit()) {
//	key = _getch();
//	if (key == 'p') {
//		cout << "Escape loop" << endl;
//		loop = false;
//	}
//	else if (key == 'l') {
//		moveTarget(targetX, targetY);
//	}
//	else if (key == 'w') {
//		//cout << "W was Pressed" << endl;
//		ApplyForceUp(*snakeBody);
//	}
//	else if (key == 's') {
//		//cout << "S was Pressed" << endl;
//		ApplyForceDown(*snakeBody);
//	}
//	else if (key == 'a') {
//		//cout << "A was Pressed" << endl;
//		ApplyForceLeft(*snakeBody);
//	}
//	else if (key == 'd') {
//		//cout << "D was Pressed" << endl;
//		ApplyForceRight(*snakeBody);
//	}
//	printf("%4.2f %4.2f\n", sfmlPosX, sfmlPosY);
//	//printf("%4.2f %4.2f\n", targetX, targetY);
//	//cout << "Score: " << score << endl;
//}

