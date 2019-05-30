#include "../World/Square.h"
#include "Vegetation.h"

double Vegetation::getTimeOfBirth() const {
    return timeOfBirth;
}

void Vegetation::setTimeOfBirth(double timeOfBirth) {
    this->timeOfBirth = timeOfBirth;
}

double Vegetation::getTimeOfDeath() const {
    return timeOfDeath;
}

void Vegetation::setTimeOfDeath(double timeOfDeath) {
    this->timeOfDeath = timeOfDeath;
}

double Vegetation::getHalfLife() const {
    return halfLife;
}

void Vegetation::setLastStateChange(double LastStateChange) {
    this->LastStateChange = LastStateChange;
}

double Vegetation::getLastStateChange() const {
    return LastStateChange;
}

int Vegetation::getStateOfPlant() const {
    return stateOfPlant;
}

void Vegetation::setStateOfPlant(int stateOfPlant) {
    this->stateOfPlant = stateOfPlant;
}

void Vegetation::incrementStateOfPlant(Ground* ground) {
    this->stateOfPlant++;
}

void Vegetation::decrementStateOfPlant(Ground* ground) {
    if (stateOfPlant > 0) {
        this->stateOfPlant--;
    }
}

bool Vegetation::isDead() const {
    return getTimeOfDeath() != 0;
}







