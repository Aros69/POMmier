#include "WorldController.h"

WorldController::WorldController(unsigned int length, unsigned int width) {
    world = new World(length, width);
}

WorldController::~WorldController() {
    delete (world);
}