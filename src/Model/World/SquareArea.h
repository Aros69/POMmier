#ifndef PROJECTDOGE_SQUAREAREA_H
#define PROJECTDOGE_SQUAREAREA_H

#include <cassert>
#include <iostream>
#include "Square.h"

// Reminder : SquareArea[x][y] == SquareArea[x*SizeY+y]
class CompleteSquareArea;

class SquareArea {
protected:
    std::vector <Square> squares;
public:

    int sizeOfArea () {return squares.size();};

    SquareArea(int x, int y);

    SquareArea(unsigned int length, unsigned int width);

    ~SquareArea();

    Square getSquare(int x, int y);

    void setSquare(unsigned int x, unsigned int y, Square *square);

    SquareArea *
    getPartOfSquareArea(int xCenter, int yCenter, int radius);
};

/*class CompleteSquareArea : public SquareArea {

public:
    CompleteSquareArea(unsigned int length, unsigned int width)
            : SquareArea(length, width) {};

    /*virtual ~CompleteSquareArea() override {
        for (unsigned int i = 0; i < length; ++i) {
            for (unsigned int j = 0; j < width; ++j) {
                delete (squares[i * width + j]);
                squares[i * width + j] = nullptr;
            }
        }
    };
};
*/

#endif //PROJECTDOGE_SQUAREAREA_H
