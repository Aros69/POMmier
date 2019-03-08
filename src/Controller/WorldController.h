#ifndef POMMIER_WORLDCONTROLLER_H
#define POMMIER_WORLDCONTROLLER_H


#include "../Model/World/World.h"

class WorldController {
protected:
    World* world;

public:
    WorldController() : WorldController(10, 10) {};

    WorldController(unsigned int length, unsigned int width);

    ~WorldController();

    World* getWorld() const { return world; };
};


#endif //POMMIER_WORLDCONTROLLER_H
