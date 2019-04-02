//
// Created by chris on 20/02/19.
//

#include "../World/Square.h"
#include "Vegetation.h"

double Vegetation::getTimeOfBirth() const {
    return timeOfBirth;
}

void Vegetation::setTimeOfBirth(double timeOfBirth) {
    Vegetation::timeOfBirth = timeOfBirth;
}

double Vegetation::getTimeOfDeath() const {
    return timeOfDeath;
}

void Vegetation::setTimeOfDeath(double timeOfDeath) {
    Vegetation::timeOfDeath = timeOfDeath;
}

