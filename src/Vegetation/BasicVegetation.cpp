//
// Created by chris on 20/02/19.
//

#include "../../include/Vegetation/BasicVegetation.h"


bool BasicVegetation::death (double currentTime) {
    return ((halfLife - (currentTime - birth)) <= 0)? true : false;
}

void BasicVegetation::growth (bool b) {
    if (b) stateOfPlant++;
}

void BasicVegetation::changeModel() {
    stateOfPlantPath = listStateOfPlant[stateOfPlant];
}

bool BasicVegetation::testGrowth (Square **neighborhood) {
    return (!neighborhood[0]->getGround().getResources().empty())? true : false;
}

void BasicVegetation::changeResources (Square **neighborhood, int change) {
    neighborhood[0]->getGround().setResources(change);
}