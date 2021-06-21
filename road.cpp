#include "Road.h"
#include <algorithm>
Road::Road(Platform p1, Platform p2, std::vector<int> lines, bool open, int number):
    p1(p1),
    p2(p2),
    num(number)
{
    linesServed = lines;
    isOpen = open;
}

Road::Road(const Road & r):
    p1(r.p1),
    p2(r.p2){
    linesServed = r.linesServed;
    isOpen = r.isOpen;
    num = r.num;
    }

void Road::changeStatus(bool status) {
    isOpen = status;
}

bool Road::isRoadOpen() {
    return isOpen;
}

bool Road::isLineServed(int n){
    return std::find (linesServed.begin(), linesServed.end(),n) != linesServed.end();
}

Platform Road::getConnectedPlatform(Platform n2){
    if(p1 == n2)
        return p2;
    else if (p2 == n2)
        return p1;
    else return Platform({-1,-1});
}

Platform Road::getPlatform(){
    return p1;
}

bool Road::isPlatformOnRoad(Platform n1)
{
    return p1 == n1 || p2 ==n1;
}

std::vector<int> Road::getLinesServed()
{
    return linesServed;
}
int Road::getNumber()
{
    return num;
}
