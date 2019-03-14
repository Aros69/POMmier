#ifndef POMMIER_WORLD_H
#define POMMIER_WORLD_H

#include "SquareArea.h"

class World {
private:
    CompleteSquareArea completeSquareArea;

public:

    World() : completeSquareArea(10, 10) {};

    World(unsigned int length, unsigned int width);

    const CompleteSquareArea *
    getCompleteSquareArea() const { return &completeSquareArea; };

    Square *getSquare(unsigned int x, unsigned int y);

    SquareArea *getPartOfSquareArea(int xCenter, int yCenter, int radius);

    unsigned int
    getLength() const { return getCompleteSquareArea()->getLength(); }

    unsigned int
    getWidth() const { return getCompleteSquareArea()->getWidth(); }
};


#endif //POMMIER_WORLD_H
