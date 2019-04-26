#ifndef POMMIER_WORLDCONTROLLER_H
#define POMMIER_WORLDCONTROLLER_H


#include "../Model/World/World.h"
#include "SquareController.h"
#include "VegetationController.h"

class WorldController {
protected:
    SquareArea *world;
    int numberOfSteps;

public:
    time_t getTimer() const;

public:
    WorldController() : WorldController(10, 10) {};

    WorldController(unsigned int length, unsigned int width);

    ~WorldController();

    SquareArea *getWorld() const { return world; };

    Square getSquare(unsigned int x,
                      unsigned int y) const { return world->getSquare(x, y); }

    void worldGeneration(); // generate the world at random

    void worldStep(); // the next step in the world, more vegetation is born, grows or dies

    void treeFall (int x, int y); // kill plant and chance of killing more plants
};


#endif POMMIER_WORLDCONTROLLER_H
