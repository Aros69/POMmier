#include <src/Model/Vegetation/BasicVegetation.h>
#include <cmath>
#include "WorldController.h"

WorldController::WorldController(unsigned int length, unsigned int width) {
    world = new World(static_cast<int>(length), static_cast<int>(width));
}

WorldController::~WorldController() {
    delete (world);
}


void WorldController::worldStep() {
    world->worldStep();
}