#ifndef TRAFFICMANAGER_H
#define TRAFFICMANAGER_H
#include"road.h"
#include"Vehicle.hpp"
#include<vector>
#include"Logger.h"
#include<memory>


class TrafficManager
{
    public:

        TrafficManager(std::shared_ptr<Logger>& l, sf::Vector2u windowSize, unsigned numberOfLines = 5, std::vector<Road> roads = {});
        void run();
        std::vector<std::shared_ptr<Vehicle>> getVehicles();
        std::vector<Platform> getPlatforms();
        void step();
        int getFinishedCount();




    private:
        std::vector<std::shared_ptr<Vehicle>> vehicleList;
        std::vector<Road> connectionList;
        void selectNewDestination(std::shared_ptr<Vehicle>& v);
        void changeRoadStatus();
        void moveVehicles();
        std::shared_ptr<Logger> logger;

};

#endif // TRAFFICMANAGER_H
