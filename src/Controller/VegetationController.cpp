#include <algorithm>
#include "VegetationController.h"

void VegetationController::addVegetation(Vegetation veg) {
    vegetation.push_back(veg);
}

void VegetationController::deleteVegetation(Vegetation veg) {
    std::vector<Vegetation>::iterator it = std::find(vegetation.begin(), vegetation.end(), veg);
    vegetation.erase(it);
}

void VegetationController::deleteVegetation(int it) {
    vegetation.erase(vegetation.begin() + it);
}