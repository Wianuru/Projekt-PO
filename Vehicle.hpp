#ifndef VEHICLE_H
#define VEHICLE_H
#include <SFML/Graphics.hpp>
#include <iostream>
class Vehicle: public sf::RectangleShape{
private:
short n;

int lineNumber;
sf::Vector2f previousStop;
bool didFinish;


protected:
float speed;
sf::Vector2f destination;

public:
Vehicle(float speed, float x, float y, short n = -1, int lineNumber = -1);
Vehicle(float speed, sf::Vector2f p, short n = -1, int lineNumber = -1);
bool hasFinished();
bool finished();
sf::Vector2f getDestination();
virtual void move();
void setDestination(float x, float y);
void setDestination(sf::Vector2f p);
int getLineNumber();
int getNumber();
sf::Vector2f getPreviousStop();

};

#endif // VEHICLE_H
