#ifndef ROAD_H
#define ROAD_H
#include <vector>
#include "platform.h"

class Road
{
    public:
        Road(Platform p1, Platform p2, std::vector<int> lines = {}, bool open = true, int number=-1);
        Road(const Road & r);
        void changeStatus(bool status);
        bool isRoadOpen();
        bool isLineServed(int n);
        Platform getConnectedPlatform(Platform n2);
        Platform getPlatform();
        bool isPlatformOnRoad(Platform n1);
        std::vector<int> getLinesServed();
        int getNumber();
    private:
        int num;
        Platform p1;
        Platform p2;
        std::vector<int> linesServed;
        bool isOpen;
};

#endif // ROAD_H
