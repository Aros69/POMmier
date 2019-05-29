
#include "BasicVegetation.h"

BasicVegetation::BasicVegetation(unsigned int x, unsigned int y,
                                 double birthTime) {
    posX = x;
    posY = y;
    timeOfBirth = birthTime;
    halfLife = 50.0;
    timeOfDeath = 0.0;
    orientation = rand()%360;
}

bool BasicVegetation::testDeath (double currentTime) {
    return ((halfLife - (currentTime - timeOfBirth)) <= 0)? true : false;
}

void BasicVegetation::growth (bool b) {
    if (b) stateOfPlant++;
}

void BasicVegetation::changeModel(std::string *list, int state) {
    stateOfPlantPath = list[state];
}

bool BasicVegetation::testGrowth (Square **neighborhood) {
    return (!neighborhood[0]->getGround().getResources().empty())? true : false;
}

void BasicVegetation::changeResources (Square **neighborhood, int change) {
    neighborhood[0]->getGround().setResources(change);
}

bool BasicVegetation::testGermination(Square **neighborhood) {
    return (neighborhood[0]->getVegetation() == nullptr)? true : false;
}

void BasicVegetation::decomposition () {
        stateOfDecomposition++;
}

bool BasicVegetation::checkTimeBetweenStates (double timeBetween, double currentTime) {
    if ((currentTime - LastStateChange) > timeBetween) {
        LastStateChange = currentTime;
        return true;
    } else {
        return false;
    }
}