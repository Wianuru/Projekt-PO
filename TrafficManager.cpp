#include "TrafficManager.h"
#include"tram.h"
#include <stdlib.h>
#include <iostream>
#include"road.h"
#include"platform.h"
#include <algorithm>
#include"RoadMap.h"
TrafficManager::TrafficManager(std::shared_ptr<Logger>& l, sf::Vector2u windowSize, unsigned numberOfLines, std::vector<Road> roads ):
    connectionList(roads)
{;
        logger = l;

       for(int i=0;i<15;i++){
        unsigned lineNumber = (rand() % numberOfLines) +1;
        std::vector<Road> suitableRoads{};
       for (Road r : connectionList)
       {
        if (r.isLineServed(lineNumber))
        {
            suitableRoads.push_back(r);
        }
       }
        Road r = suitableRoads.at(rand()%suitableRoads.size());
        float x  = r.getPlatform().getPosition().x;
        float y  = r.getPlatform().getPosition().y;
        float speed = 0.5 + static_cast<float> (rand()) / static_cast <float> (RAND_MAX);
        std::shared_ptr<Tram> t = std::make_shared<Tram>(speed,
                      x,
                      y,
                      i,
                      lineNumber);

        vehicleList.push_back(t);
    }

}
std::vector<std::shared_ptr<Vehicle>> TrafficManager::getVehicles()
{
    return vehicleList;
}


void TrafficManager::step()
{
    changeRoadStatus();
    moveVehicles();
}


void TrafficManager::changeRoadStatus()
{
    for(Road &r : connectionList)
        {
            unsigned l = rand()%1000;
            if(l<=2)
            {
                r.changeStatus(!r.isRoadOpen());
                logger->log("Road "+ std::to_string(r.getNumber())+ " status changed to "+ (r.isRoadOpen() ?"open" : "closed"));
            }
        }
}

void TrafficManager::moveVehicles()
{
    for (std::shared_ptr<Vehicle>& v : vehicleList)
    {
        if(v->getDestination() == v->getPosition()&&(!v->hasFinished()))
        {


                logger->log(std::to_string(v->getNumber())+ " Reached destination at point "+ std::to_string((int)v->getPosition().x) + " " + std::to_string((int)v->getPosition().y));

            selectNewDestination(v);
        }
        if(v->getPreviousStop() == v->getPosition())
           {
                auto road = std::find_if(connectionList.begin(), connectionList.end(), [&] (Road r)
                                {
                                    return r.isPlatformOnRoad(Platform(v->getPosition())) &&
                                           r.isPlatformOnRoad(Platform(v->getDestination()));
                                });
                if (road != connectionList.end() && road->isRoadOpen())
                {
                    v->move();
                    logger->log(std::to_string(v->getNumber())+" started moving on road "+std::to_string(road->getNumber()));
                }

           } else
           {
            v->move();
           }

    }
}
void TrafficManager::selectNewDestination(std::shared_ptr<Vehicle>& v)
{
    std::vector<Road> roads {};
    for (Road r : connectionList)
    {
        if(r.isLineServed(v->getLineNumber()) && r.isPlatformOnRoad(v->getPosition()))
        {
            roads.push_back(r);
        }
    }
    bool hasChanged = false;
    for (Road r : roads)
    {
        if(!hasChanged &&!(r.getConnectedPlatform(Platform(v->getPosition())) == v->getPreviousStop()))
        {
            hasChanged = true;

            sf::Vector2f pos = r.getConnectedPlatform(Platform(v->getPosition())).getPosition();
            v->setDestination(r.getConnectedPlatform(Platform(v->getPosition())).getPosition());
            logger->log(" New destination set for "+std::to_string(v->getNumber())+ " "+ std::to_string((int)v->getDestination().x) + " " + std::to_string((int)v->getDestination().y));
        }
    }
    if(!hasChanged)
    {
        v->finished();
        logger->log(std::to_string(v->getNumber())+" has finished");
    }
}
int TrafficManager::getFinishedCount()
{
    int counter = 0;
    for(std::shared_ptr<Vehicle> v: vehicleList)
    {
        if (v->hasFinished())
            counter++;
    }
    return counter;
}
