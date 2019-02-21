#ifndef POMMIER_WORLD_H
#define POMMIER_WORLD_H

#include "SquareArea.h"

class World {
private:
    SquareArea squareArea;

public:

    World() : squareArea(10, 10) {};

    World(unsigned int length, unsigned int width);

};


#endif //POMMIER_WORLD_H
