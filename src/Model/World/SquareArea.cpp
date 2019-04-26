#include "SquareArea.h"



SquareArea::SquareArea(int x, int y) {
    for (int i = 0; i < x*y; i++) {
        squares.push_back(Square());
    }
}

SquareArea::~SquareArea() {
    squares.empty();
}

Square SquareArea::getSquare(int x, int y) {
    for (int i = 0; i < squares.size(); i++) {
        if (squares.at(i).getX() == x
        && squares.at(i).getY() == y) {
            return squares.at(i);
        }
    }
}
/*
Square SquareArea::getSquare(int x, int y) {
    if (x >= length || x < 0 || y >= width || y < 0) {
        return nullptr;
    } else {
        return squares[x * width + y];
    }
}
 */
/*
void SquareArea::setSquare(unsigned int x, unsigned int y, Square *square) {
    delete getSquare(x, y);
    squares[x * width + y] = square;
}

SquareArea SquareArea::getPartOfSquareArea(int xCenter,
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
 */