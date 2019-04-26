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
                getWorld()->getSquare(i, j).getVegetation()->setTimeOfDeath(numberOfSteps);
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
