#include <iostream>
#include "QtVegetation.h"

QtVegetation::QtVegetation(Vegetation *_vegetation, double posX, double posY,
                           double _orientation) {
    vegetation = _vegetation;
    positionX = posX;
    positionY = posY;
    orientation = _orientation;
}

QtVegetation::~QtVegetation() {
    delete vegetation;
    vegetation = nullptr;
}

double QtVegetation::getPositionX() const {
    return positionX;
}

void QtVegetation::setPositionX(double positionX) {
    QtVegetation::positionX = positionX;
}

double QtVegetation::getPositionY() const {
    return positionY;
}

void QtVegetation::setPositionY(double positionY) {
    QtVegetation::positionY = positionY;
}

double QtVegetation::getOrientation() const {
    return orientation;
}

void QtVegetation::setOrientation(double orientation) {
    QtVegetation::orientation = orientation;
}

bool QtVegetation::isDead() const {
    return vegetation->getTimeOfDeath() != -1;
}


