#ifndef PROJECTDOGE_SQUAREAREA_H
#define PROJECTDOGE_SQUAREAREA_H

#include <cassert>
#include <bits/shared_ptr.h>
#include "Square.h"

// Reminder : squareArea[x][y] == SquareArea[x*SizeY+y]

class SquareArea {
private:
    unsigned int length;
    unsigned int width;
    std::shared_ptr<Square*> squares;

public:
    SquareArea() : SquareArea(10, 10) {};

    SquareArea(unsigned int length, unsigned int width);

    ~SquareArea();

    Square *getSquare(unsigned int x, unsigned int y);

    //void setSquare(unsigned int x, unsigned int y, Square* );

    SquareArea getPartOfSquareArea(unsigned int xCenter, unsigned int yCenter,
                                   unsigned int radius);
};


#endif //PROJECTDOGE_SQUAREAREA_H
