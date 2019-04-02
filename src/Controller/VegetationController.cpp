#include <algorithm>
#include "VegetationController.h"

void VegetationController::addVegetation(Vegetation *veg) {
    vegetation = veg;
}

void VegetationController::deleteVegetation() {
    delete(vegetation);
}

Vegetation* VegetationController::getVegetation() {
    return vegetation;
}