#include "Platform.h"

Platform::Platform(sf::Vector2f pos)
{
    setOrigin(5,5);
    setPosition(pos.x, pos.y);
    setRadius(10);
    setFillColor(sf::Color::White);
}
Platform::Platform (const Platform & p)
{
    setOrigin(5,5);
    setPosition(p.getPosition().x,p.getPosition().y);
    setRadius(10);
    setFillColor(sf::Color::White);
}

bool Platform::operator== (const Platform& p2)
{
    return getPosition().x == p2.getPosition().x && getPosition().y == p2.getPosition().y;
}

bool Platform::operator== (const sf::Vector2f& p2)
{
    return getPosition().x == p2.x && getPosition().y == p2.y;
}
