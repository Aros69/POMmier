#ifndef POMMIER_WORLD_H
#define POMMIER_WORLD_H

#include "Square.h"
// Remider : world[x][y] == world[x*SizeY+y]

class World {
private:
    unsigned int length;
    unsigned int width;
    Square **squares;

public:
    World() : World(10,10){};

    World(unsigned int length, unsigned int width);

    ~World();

    Square* getSquare(unsigned int x, unsigned int y);
};


#endif //POMMIER_WORLD_H
