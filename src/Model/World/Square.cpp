#include <iostream>
#include <src/Model/Vegetation/BasicVegetation.h>
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
    return ground;
}

Vegetation *Square::getVegetation() {
    return vegetation;
}

int Square::getX() const {
    return x;
}

int Square::getY() const {
    return y;
}

void Square::setSky(const Sky &sky) {
    Square::sky = sky;
}

void Square::setGround(Ground ground) {
    Square::ground = ground;
}

void Square::setVegetation(Vegetation *vegetation) {
    Square::vegetation = vegetation;
}

void Square::setX(int x) {
    Square::x = x;
}

void Square::setY(int y) {
    Square::y = y;
}

