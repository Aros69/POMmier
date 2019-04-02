#include "Square.h"

//#include "../../include/Vegetation/Vegetation.h"

Square::Square(Vegetation *veg) {
    vegetation = veg;
}

bool Square::isFreeSquare() {
    return true;
}

const Sky &Square::getSky() const {
    return sky;
}

Ground &Square::getGround() {
    return *ground;
}

Vegetation *Square::getVegetation() const {
    return vegetation;
}

