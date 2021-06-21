#ifndef ROADMAP_H
#define ROADMAP_H
#include "road.h"
#include "platform.h"
#include <vector>



class RoadMap
{
    public:
        RoadMap();
        std::vector<Road> getRoads();
        std::vector<Platform> getPlatforms();
        std::vector<sf::RectangleShape> getLines();


    private:
        std::vector<Road> roads;
        std::vector<Platform> platforms;
        void createRoad();
        std::vector<sf::RectangleShape>lines;
        void setLineColor(sf::RectangleShape & line, int i);

};

#endif // ROADMAP_H
