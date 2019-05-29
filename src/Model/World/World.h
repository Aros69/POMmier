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

public:

    World() = delete;

    World(unsigned int length, unsigned int width);

    ~World();

    unsigned int getLength() const { return v_length; };

    unsigned int getWidth() const { return v_width; };

    std::list<Vegetation *>* getVegetations() { return &vegetations; };

    void worldGeneration();

    void worldStep();

    void treeFall(Vegetation *vegetationDying);

    //const CompleteSquareArea * getCompleteSquareArea() const { return &completeSquareArea; };

    //Square *getSquare(unsigned int x, unsigned int y);

    //SquareArea *getPartOfSquareArea(int xCenter, int yCenter, int radius);

    //unsigned int
    //getLength() const { return getCompleteSquareArea()->getLength(); }

    //unsigned int
    //getWidth() const { return getCompleteSquareArea()->getWidth(); }*/
};


#endif //POMMIER_WORLD_H
