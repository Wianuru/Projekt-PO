#ifndef PLATFORM_H
#define PLATFORM_H


#include <SFML/Graphics.hpp>


class Platform : public sf::CircleShape
{
    public:
        Platform(sf::Vector2f pos);
        Platform (const Platform & p);
        bool operator==(const Platform & p2);
        bool operator==(const sf::Vector2f & p2);



};

#endif // PLATFORM_H
