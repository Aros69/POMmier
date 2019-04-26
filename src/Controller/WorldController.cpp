#include "WorldController.h"

WorldController::WorldController(unsigned int length, unsigned int width) {
    numberOfSteps = 0;
}

WorldController::~WorldController() {
    delete (world);
}

void WorldController::worldGeneration() {
    for (int i = 0; i < getWorld()->sizeOfArea()/2; i++) {
        for (int j = 0; j < getWorld()->sizeOfArea()/2; j++){
            if (rand()) {
                getWorld()->getSquare(i, j).getSky().setLuminosity(1);
                getWorld()->getSquare(i, j).getGround().setAltitude(1);
                getWorld()->getSquare(i, j).getGround().setResources(1);
                getWorld()->getSquare(i, j).getVegetation()->setTimeOfBirth(numberOfSteps);
                getWorld()->getSquare(i, j).getVegetation()->setTimeOfDeath(0);
            }
        }
    }
}

void WorldController::worldStep() {
    numberOfSteps++;

    for (int i = 0; i < getWorld()->sizeOfArea()/2; i++) {
        for (int j = 0; j < getWorld()->sizeOfArea()/2; j++) {
            //kill plants
            if (rand() % 100 + getWorld()->getSquare(i, j).getVegetation()->getHalfLife() > 100
            && getWorld()->getSquare(i, j).getVegetation()->getTimeOfDeath() == 0){
                treeFall(rand()%world->sizeOfArea(), rand()%world->sizeOfArea());
            }
            //create new plants
            if (getWorld()->getSquare(i, j).getVegetation()->getTimeOfDeath() == 0
            && getWorld()->getSquare(i, j).getVegetation()->getTimeOfBirth() < numberOfSteps) {
                for (int x = i; x < i+2; x++) {
                    for (int y = j; y < j+2; y++) {
                        if (rand() % 4 > 3) {
                            getWorld()->getSquare(x, y).getVegetation()->setTimeOfBirth(numberOfSteps);
                            getWorld()->getSquare(x, y).getVegetation()->setTimeOfDeath(0);
                            getWorld()->getSquare(x, y).getGround().setAltitude(1);
                            getWorld()->getSquare(x, y).getGround().setResources(1);
                            getWorld()->getSquare(x, y).getSky().setLuminosity(1);
                        }
                    }
                }
            }
            //grow plants
            if (getWorld()->getSquare(i, j).getVegetation()->getTimeOfDeath() == 0) {
                getWorld()->getSquare(i, j).getVegetation()->incrementStateOfPlant();
            }
        }
    }
}


void WorldController::treeFall(int x, int y) {
    world->getSquare(x, y).getVegetation()->setTimeOfDeath(numberOfSteps);
    int directionOfFall = rand() % 8; // 0 up, 1 left, 2 down, 3 right, 4 top-left...

    if (rand() % 20 == 0) {
        if (directionOfFall == 0) {
            if (world->getSquare(x, y+1).getVegetation()->getTimeOfDeath() == 0) {
                treeFall(x, y + 1);
            }
        }
        else if (directionOfFall == 1) {
            if (world->getSquare(x - 1, y).getVegetation()->getTimeOfDeath() == 0) {
                treeFall(x - 1, y);
            }
        }
        else if (directionOfFall == 2) {
            if (world->getSquare(x, y - 1).getVegetation()->getTimeOfDeath() == 0) {
                treeFall(x, y - 1);
            }
        }
        else if (directionOfFall == 3) {
            if (world->getSquare(x + 1, y).getVegetation()->getTimeOfDeath() == 0) {
                treeFall(x + 1, y);
            }
        }
        else if (directionOfFall == 4) {
            if (world->getSquare(x - 1, y + 1).getVegetation()->getTimeOfDeath() == 0) {
                treeFall(x-1, y + 1);
            }
        }
        else if (directionOfFall == 5) {
            if (world->getSquare(x - 1, y -1 ).getVegetation()->getTimeOfDeath() == 0) {
                treeFall(x - 1, y - 1);
            }
        }
        else if (directionOfFall == 6) {
            if (world->getSquare(x + 1, y - 1).getVegetation()->getTimeOfDeath() == 0) {
                treeFall(x + 1, y - 1);
            }
        }
        else {
            if (world->getSquare(x + 1, y + 1).getVegetation()->getTimeOfDeath() == 0) {
                treeFall(x + 1, y + 1);
            }
        }
    }
}