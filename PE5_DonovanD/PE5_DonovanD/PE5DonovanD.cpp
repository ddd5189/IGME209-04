// PE5DonovanD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define SFML_STATIC
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	
		window.clear(sf::Color::White);
	
		sf::CircleShape circle1(50);
		circle1.setFillColor(sf::Color(100, 250, 50));
		circle1.setPosition(10, 50);

		sf::CircleShape circle2(80);
		circle2.setFillColor(sf::Color(10, 300, 50));
		circle2.setPosition(200, 300);

		sf::RectangleShape rectangle1(sf::Vector2f(120, 50));
		rectangle1.setFillColor(sf::Color(300, 150, 50));
		rectangle1.setPosition(400, 230);

		sf::RectangleShape rectangle2(sf::Vector2f(80, 220));
		rectangle2.setFillColor(sf::Color(100, 500, 20));
		rectangle2.setPosition(600, 200);

		window.draw(circle1);
		window.draw(circle2);
		window.draw(rectangle1);
		window.draw(rectangle2);
	
		window.display();
	}

    return 0;
}

