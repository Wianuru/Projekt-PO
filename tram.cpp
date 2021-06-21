#include "Tram.h"

Tram::Tram(float speed, float x, float y, short n, int lineNumber):
    Vehicle(speed, x ,y,n, lineNumber)
{
    if(lineNumber==0)
        setFillColor(sf::Color::Green);
    else if(lineNumber==1)
        setFillColor(sf::Color::Red);
    else if(lineNumber==2)
        setFillColor(sf::Color::Blue);
    else if(lineNumber==3)
        setFillColor(sf::Color(255,51,255));
    else if(lineNumber==4)
        setFillColor(sf::Color::Yellow);
    else if(lineNumber==5)
       setFillColor(sf::Color(200,200,200));
    setOutlineThickness(2);
    setOutlineColor(sf::Color::Black);
    setSize(sf::Vector2f(10,10));
}


void Tram::moveX() {
	if (getPosition().x > destination.x)
	{
		setPosition(getPosition().x - 1, getPosition().y);
	}
	else if (getPosition().x < destination.x)
	{
		setPosition(getPosition().x + 1, getPosition().y);
	}
}

void Tram::moveY() {
	if (getPosition().y > destination.y)
	{
		setPosition(getPosition().x, getPosition().y - 1);
	}
	else if (getPosition().y < destination.y)
	{
		setPosition(getPosition().y, getPosition().y + 1);
	}
}


void Tram::move()
{
	for (float i = 0; i < speed; i += 0.5) {
		if (getPosition().y < destination.y)
		{
			setPosition(getPosition().x, getPosition().y + 1);
		} if (getPosition().y > destination.y)
		{
			moveX();
		} if (getPosition().y == destination.y)
		{
			moveX();
		} if (getPosition().x == destination.x)
		{
			moveY();
		}
	}
}
