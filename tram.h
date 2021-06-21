#ifndef TRAM_H
#define TRAM_H
#include "Vehicle.hpp"
#include <iostream>
class Tram : public Vehicle
{
    public:
        Tram(float speed, float x, float y, short n = -1, int lineNumber = -1);
		void move();

    private:
		void moveX();
		void moveY();

};

#endif // TRAM_H
