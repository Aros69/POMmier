#include "../../include/World/World.h"

World::World(unsigned int length, unsigned int width) {
    this->length = length;
    this->width = width;
    squares = new Square *[length * width];
    for (unsigned int i = 0; i < length; ++i) {
        for (unsigned int j = 0; j < width; ++j) {
            squares[i * width + j] = new Square;
        }
    }
}

World::~World() {
    for (unsigned int i = 0; i < length; ++i) {
        for (unsigned int j = 0; j < width; ++j) {
            delete (squares[i * width + j]);
            squares[i * width + j] = nullptr;
        }
    }
    delete[](squares);
    squares = nullptr;
}

Square* World::getSquare(unsigned int x, unsigned int y) {
    return squares[x*width+y];
}