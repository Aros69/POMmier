#include "../../include/World/Square.h"

//#include "../../include/Vegetation/Vegetation.h"

bool Square::isFreeSquare() {
    return true;
}

const Sky &Square::getSky() const {
    return sky;
}

Ground &Square::getGround() {
    return ground;
}

Vegetation **Square::getVegetation() const {
    return vegetation;
}
