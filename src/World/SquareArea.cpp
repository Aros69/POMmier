#include "../../include/World/SquareArea.h"

SquareArea::SquareArea(unsigned int length, unsigned int width) {
    this->length = length;
    this->width = width;
        squares = std::make_shared<Square*>(length*width);
    //squares = new std::shared_ptr<Square> [length * width];
    for (unsigned int i = 0; i < length; ++i) {
        for (unsigned int j = 0; j < width; ++j) {
            squares[i * width + j] = new Square();
        }
    }
}

SquareArea::~SquareArea() {
    for (unsigned int i = 0; i < length; ++i) {
        for (unsigned int j = 0; j < width; ++j) {
            delete (squares[i * width + j]);
            squares[i * width + j] = nullptr;
        }
    }
    delete[](squares);
    squares = nullptr;
}

Square *SquareArea::getSquare(unsigned int x, unsigned int y) {
    assert(x < length);
    assert(y < width);
    return squares[x * width + y];
}