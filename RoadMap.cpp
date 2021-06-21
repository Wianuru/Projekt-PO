#include "RoadMap.h"
#include <cmath>
#include <random>
RoadMap::RoadMap()
{
    Platform p1 =  Platform(sf::Vector2f(105,116));
    Platform p2 =  Platform(sf::Vector2f(200,300));
    Platform p3 =  Platform(sf::Vector2f(315,135));
    Platform p4 =  Platform(sf::Vector2f(390,285));
    Platform p5 =  Platform(sf::Vector2f(700,90));
    Platform p6 =  Platform(sf::Vector2f(660,270));
    Platform p7 =  Platform(sf::Vector2f(560,420));
    Platform p8 =  Platform(sf::Vector2f(440,400));
    Platform p9 =  Platform(sf::Vector2f(310,470));
    Platform p10 = Platform(sf::Vector2f(130,500));
    Platform p11 = Platform(sf::Vector2f(500,550));
    Platform p12 = Platform(sf::Vector2f(750,540));
    platforms = {p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12};

    roads.push_back( Road(p2, p1,{1,2},true, 1));
    roads.push_back( Road(p2, p3,{1,2},true,2));
    roads.push_back( Road(p3, p5,{1},true,3));
    roads.push_back( Road(p5, p6,{1,3,5},true,4));
    roads.push_back( Road(p4, p5,{4},true,5));
    roads.push_back( Road(p3, p4,{2},true,6));
    roads.push_back( Road(p10, p4,{3},true,7));
    roads.push_back( Road(p10, p9,{5},true,8));
    roads.push_back( Road(p9, p4,{3},true,9));
    roads.push_back( Road(p9, p8,{3,5},true,10));
    roads.push_back( Road(p4, p8,{2,4},true,11));
    roads.push_back( Road(p8, p7,{2,3,4},true,12));
    roads.push_back( Road(p8, p11,{5},true,13));
    roads.push_back( Road(p11, p12,{1,5},true,14));
    roads.push_back( Road(p7, p12,{2,4},true,15));
    roads.push_back( Road(p7, p6,{3},true,16));
    roads.push_back( Road(p6, p12,{1,5},true,17));

    auto rng = std::default_random_engine {};
    std::shuffle(roads.begin(), roads.end(), rng);

    createRoad();
}
std::vector<Road> RoadMap::getRoads()
{
    return roads;
}
std::vector<Platform> RoadMap::getPlatforms()
{
    return platforms;
}
std::vector<sf::RectangleShape> RoadMap::getLines()
{
    return lines;
}
void RoadMap::createRoad()
{
    for(Road r : roads)
    {
        for (int i : r.getLinesServed())
        {

        Platform p1=r.getPlatform();
        Platform p2=r.getConnectedPlatform(p1);
        sf::RectangleShape horizontalLine= sf::RectangleShape(sf::Vector2f(abs(p1.getPosition().x - p2.getPosition().x),
                                                                  2));
        sf::RectangleShape verticalLine= sf::RectangleShape(sf::Vector2f(2,
                                                                  abs(p1.getPosition().y - p2.getPosition().y)));
        if(p1.getPosition().x < p2.getPosition().x)
        {
            if(p1.getPosition().y < p2.getPosition().y)
            {
                verticalLine.setPosition(std::min(p1.getPosition().x,p2.getPosition().x)+i*2,std::min(p1.getPosition().y,p2.getPosition().y)+i*2);
            } else{
              verticalLine.setPosition(std::max(p1.getPosition().x,p2.getPosition().x)+i*2,std::min(p1.getPosition().y,p2.getPosition().y)+i*2);
            }

        } else
        {
            if(p1.getPosition().y < p2.getPosition().y)
            {
            verticalLine.setPosition(std::max(p1.getPosition().x,p2.getPosition().x)+i*2,std::min(p1.getPosition().y,p2.getPosition().y)+i*2);
            }else {
                verticalLine.setPosition(std::min(p1.getPosition().x,p2.getPosition().x)+i*2,std::min(p1.getPosition().y,p2.getPosition().y)+i*2);

            }
        }
        horizontalLine.setPosition(std::min(p1.getPosition().x,p2.getPosition().x)+i*2,std::max(p1.getPosition().y,p2.getPosition().y)+i*2);




        setLineColor(horizontalLine,i);
        setLineColor(verticalLine,i);
        lines.push_back(horizontalLine);
        lines.push_back(verticalLine);
        }
    }
}

void RoadMap::setLineColor( sf::RectangleShape & line, int lineNumber)
{
    if(lineNumber==0)
        line.setFillColor(sf::Color::Green);
    else if(lineNumber==1)
        line.setFillColor(sf::Color::Red);
    else if(lineNumber==2)
        line.setFillColor(sf::Color::Blue);
    else if(lineNumber==3)
        line.setFillColor(sf::Color(255,51,255));
    else if(lineNumber==4)
        line.setFillColor(sf::Color::Yellow);
    else if(lineNumber==5)
       line.setFillColor(sf::Color(200,200,200));
}
