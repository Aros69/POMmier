#ifndef POMMIER_WORLDCONTROLLER_H
#define POMMIER_WORLDCONTROLLER_H


#include "../Model/World/World.h"
#include "SquareController.h"
#include "VegetationController.h"

class WorldController {
protected:
    World *world;

public:
    WorldController() : WorldController(10, 10) {};

    WorldController(unsigned int length, unsigned int width);

    ~WorldController();

    World *getWorld() const { return world; };

    Square *getSquare(unsigned int x,
                      unsigned int y) const { return world->getSquare(x, y); }
};


#endif POMMIER_WORLDCONTROLLER_H
