#ifndef POMMIER_SQUARECONTROLLER_H
#define POMMIER_SQUARECONTROLLER_H


#include "../Model/World/Square.h"
#include "VegetationController.h"

class SquareController {
    Square *square;

    SquareController() = default;
    ~SquareController();

    void initializeSquare(); // initialize Square
    void initializeSquare(Vegetation *veg); // initialize Square with a predefined Vegetation
};


#endif POMMIER_SQUARECONTROLLER_H
