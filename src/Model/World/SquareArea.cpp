#include "SquareArea.h"

SquareArea::SquareArea(unsigned int length, unsigned int width) {
    this->length = length;
    this->width = width;
    squares = new Square *[length * width];
    for (unsigned int i = 0; i < length; ++i) {
        for (unsigned int j = 0; j < width; ++j) {
            squares[i * width + j] = new Square();
        }
    }
}

SquareArea::~SquareArea() {
    delete[](squares);
    squares = nullptr;
}

Square *SquareArea::getSquare(int x, int y) {
    if (x >= length || x < 0 || y >= width || y < 0) {
        return nullptr;
    } else {
        return squares[x * width + y];
    }
}

void SquareArea::setSquare(unsigned int x, unsigned int y, Square *square) {
    delete getSquare(x, y);
    squares[x * width + y] = square;
}

SquareArea *SquareArea::getPartOfSquareArea(int xCenter,
                                            int yCenter,
                                            int radius) {
    assert(radius >= 0);
    assert(xCenter >= 0 && xCenter < length);
    assert(yCenter >= 0 && yCenter < width);
    SquareArea *partOfSquareArea = new SquareArea(2 * radius + 1,
                                                  2 * radius + 1);

    for (int i = 0; i < 2 * radius + 1; ++i) {
        for (int j = 0; j < 2 * radius + 1; ++j) {
            partOfSquareArea->setSquare(i, j,
                                        getSquare(i + (xCenter - radius),
                                                  j + (yCenter - radius)));
        }
    }
    return partOfSquareArea;
}