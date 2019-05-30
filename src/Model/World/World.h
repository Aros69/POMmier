#ifndef POMMIER_WORLD_H
#define POMMIER_WORLD_H

#include <list>
#include "SquareArea.h"
#include "../Sky/Sky.h"
#include "../Ground/BasicGround.h"
#include "../Vegetation/BasicVegetation.h"

class World {
private:
    std::list<Vegetation *> vegetations;
    Ground *ground;
    Sky *sky;
    unsigned int v_length;
    unsigned int v_width;
    unsigned int numberOfSteps;
    unsigned int nbMaxVege;

public:

    World() = delete;

    World(unsigned int length, unsigned int width);

    ~World();

    unsigned int getLength() const { return v_length; };

    unsigned int getWidth() const { return v_width; };

    std::list<Vegetation *> *getVegetations() { return &vegetations; };

    void worldGeneration();

    void demoWorldGeneration();

    void worldStep();

    void treeFall(Vegetation *vegetationDying);

    /**
     * Test if the point is already taken by another vegetation
     * @param x point location parameter
     * @param y point location parameter
     * @return true if there is already a vegetation at this point
     */
    bool placeTaken(unsigned int x, unsigned int y);

    /**
     * Test if the vegetation is colliding with anoter one in the world
     * @param vegetation the vegetation tested
     * @return true if the vegetation is collinding with another
     */
    bool placeTaken(Vegetation* vegetation);
};


#endif //POMMIER_WORLD_H
