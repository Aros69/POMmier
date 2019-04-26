#include "SquareController.h"

SquareController::~SquareController() {
    delete(square);
}

void SquareController::initializeSquare() {
    square = new Square();
}

void SquareController::initializeSquare(Vegetation *veg) {
    square = new Square(veg);
}