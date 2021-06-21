#include"Vehicle.hpp"
#include <iostream>
#include <random>
Vehicle::Vehicle(float speed, float x, float y, short n, int lineNumber):
    destination(x,y),
    previousStop(x,y)
{
    this->lineNumber = lineNumber;
    this->speed = speed;
    this->n = n;
    setPosition(x,y);
	didFinish = false;

}

Vehicle::Vehicle(float speed, sf::Vector2f p, short n, int lineNumber):
    destination(p),
    previousStop(p.x, p.y)
{
    this->lineNumber = lineNumber;
    this->speed = speed;
    this->n = n;
    setPosition(p.x,p.y);
	didFinish = false;
}

sf::Vector2f Vehicle::getDestination()
{
    return destination;
}

void Vehicle::setDestination(float x, float y)
{
    destination = sf::Vector2f(x,y);
}

void Vehicle::setDestination(sf::Vector2f p)
{
    previousStop = destination;
    destination = p;
}

int Vehicle::getLineNumber()
{
    return lineNumber;
}
sf::Vector2f Vehicle::getPreviousStop()
{
    return previousStop;
}
bool Vehicle::hasFinished()
{
    return didFinish;
}
bool Vehicle::finished()
{
    didFinish =true;
	return didFinish;
}
int Vehicle::getNumber()
{
    return n;
}

void Vehicle::move()
{
	setPosition(getPosition().x, getPosition().y + 1);
}