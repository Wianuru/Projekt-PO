#include <SFML/Graphics.hpp>
#include"Logger.h"
#include"Vehicle.hpp"
#include"Tram.h"
#include"Platform.h"
#include"Road.h"
#include"TrafficManager.h"
#include<time.h>
#include <stdlib.h>
#include <iostream>
#include"RoadMap.h"
#include<memory>
int main()
{
    srand (time(NULL));
    std::shared_ptr<Logger> l = std::make_shared<Logger>();
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    RoadMap roadMap;
    TrafficManager manager=TrafficManager(l, window.getSize(), 5 , roadMap.getRoads());
    sf::Clock timer;
    timer.restart();
    int k;
    std::cout<<"Podaj liczbe pojazdow jaka ma skonczyc swoja trase aby zakocznyc dzialanie programu: "<<std::endl;
    std::cin>>k;
    l->log("Liczba tramwajów to: " + std::to_string(k));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
           if (event.type == sf::Event::Closed)
                window.close();
        }
        if(k>manager.getFinishedCount())
        {

        if (timer.getElapsedTime() >= sf::seconds(0.02))
        {
            timer.restart();
             manager.step();
        }

        window.clear();
        for(sf::RectangleShape r : roadMap.getLines()){
            window.draw(r);
        }
        for(Platform p : roadMap.getPlatforms()){
            window.draw(p);
        }

        for(std::shared_ptr<Vehicle> v : manager.getVehicles()){
            window.draw(*v);
        }
        } else
        {
            std::cout << "FINISHED" <<std::endl;
        }
        window.display();
    }
    l->saveToFile("logs.txt");

    return 0;
}
