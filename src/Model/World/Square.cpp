#include "Square.h"

//#include "../../include/Vegetation/Vegetation.h"

Square::Square(Vegetation *veg) {
    vegetation = veg;
}

bool Square::isFreeSquare() {
    return true;
}

Sky &Square::getSky() {
    return sky;
}

Ground &Square::getGround() {
    return *ground;
}

Vegetation *Square::getVegetation() {
    return vegetation;
}

