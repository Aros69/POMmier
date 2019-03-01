#ifndef PROJECTDOGE_SQUAREAREA_H
#define PROJECTDOGE_SQUAREAREA_H

#include <cassert>
#include <iostream>
#include "Square.h"

// Reminder : squareArea[x][y] == SquareArea[x*SizeY+y]
class CompleteSquareArea;

class SquareArea {
protected:
    unsigned int length;
    unsigned int width;
    Square **squares;

    SquareArea() : SquareArea(10, 10) {};

    SquareArea(unsigned int length, unsigned int width);

    virtual ~SquareArea();

public:
    Square *getSquare(int x, int y);

    void setSquare(unsigned int x, unsigned int y, Square *square);

    CompleteSquareArea *
    getPartOfSquareArea(int xCenter, int yCenter, int radius);
};

class CompleteSquareArea : public SquareArea {

public:
    CompleteSquareArea(unsigned int length, unsigned int width)
            : SquareArea(length, width) {};

    virtual ~CompleteSquareArea() override {
        for (unsigned int i = 0; i < length; ++i) {
            for (unsigned int j = 0; j < width; ++j) {
                delete (squares[i * width + j]);
                squares[i * width + j] = nullptr;
            }
        }
    };
};


#endif //PROJECTDOGE_SQUAREAREA_H
