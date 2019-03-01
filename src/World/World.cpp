#include "../../include/World/World.h"

World::World(unsigned int length, unsigned int width)
        : squareArea(length, width) {}

Square *World::getSquare(unsigned int x, unsigned int y) {
    return squareArea.getSquare(x, y);
}

SquareArea *World::getPartOfSquareArea(int xCenter, int yCenter, int radius) {
    return squareArea.getPartOfSquareArea(xCenter, yCenter, radius);
};