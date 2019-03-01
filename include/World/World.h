#ifndef POMMIER_WORLD_H
#define POMMIER_WORLD_H

#include "SquareArea.h"

class World {
private:
    CompleteSquareArea squareArea;

public:

    World() : squareArea(10, 10) {};

    World(unsigned int length, unsigned int width);

    Square *getSquare(unsigned int x, unsigned int y);

    SquareArea *getPartOfSquareArea(int xCenter, int yCenter, int radius);
};


#endif //POMMIER_WORLD_H
