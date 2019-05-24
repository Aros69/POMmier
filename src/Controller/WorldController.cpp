#include <src/Model/Vegetation/BasicVegetation.h>
#include <cmath>
#include "WorldController.h"

WorldController::WorldController(unsigned int length, unsigned int width) {
    world = new SquareArea(static_cast<int>(length), static_cast<int>(width));
    numberOfSteps = 0;
}

WorldController::~WorldController() {
    delete (world);
}

void WorldController::worldGeneration() {
    for (int i = 0; i < getWorld()->getLength(); i++) {
        for (int j = 0; j < getWorld()->getWidth(); j++) {
            getWorld()->getSquare(i, j).getSky().setLuminosity(1);
            getWorld()->getSquare(i, j).getGround().setAltitude(1);
            getWorld()->getSquare(i, j).getGround().setResources(1);
            // TODO C++11 Random
            if (rand() % 100 == 0) {
                getWorld()->getSquare(i, j).setVegetation(
                        new BasicVegetation());
                getWorld()->getSquare(i, j).getVegetation()->setTimeOfBirth(
                        numberOfSteps);
                getWorld()->getSquare(i, j).getVegetation()->setTimeOfDeath(0);
            }
        }
    }
}

void WorldController::worldStep() {
    numberOfSteps++;
    // TODO CHECK IF SQUARE IS OUT OF BOUND OF SQUARE AREA
    // when doing x+1, you can be out of bound :(
    // same for x+1, x-1, y-1 and y+1
    for (int i = 0; i < getWorld()->getLength(); i++) {
        for (int j = 0; j < getWorld()->getWidth(); j++) {
            //kill plants
            if (getWorld()->getSquare(i, j).getVegetation() != nullptr) {
                if (rand() % 100 +
                    getWorld()->getSquare(i, j).getVegetation()->getHalfLife() >
                    100
                    &&
                    getWorld()->getSquare(i,
                                          j).getVegetation()->getTimeOfDeath() ==
                    0) {
                    treeFall(rand() % getWorld()->getLength(),
                             rand() % getWorld()->getWidth());
                }
                //create new plants
                if (getWorld()->getSquare(i,
                                          j).getVegetation()->getTimeOfDeath() ==
                    0
                    &&
                    getWorld()->getSquare(i,
                                          j).getVegetation()->getTimeOfBirth() <
                    numberOfSteps) {
                    for (int x = i; x < i + 2; x++) {
                        for (int y = j; y < j + 2; y++) {
                            if (rand() % 4 > 3) {
                                getWorld()->getSquare(x,
                                                      y).getVegetation()->setTimeOfBirth(
                                        numberOfSteps);
                                getWorld()->getSquare(x,
                                                      y).getVegetation()->setTimeOfDeath(
                                        0);
                                getWorld()->getSquare(x,
                                                      y).getGround().setAltitude(
                                        1);
                                getWorld()->getSquare(x,
                                                      y).getGround().setResources(
                                        1);
                                getWorld()->getSquare(x,
                                                      y).getSky().setLuminosity(
                                        1);
                            }
                        }
                    }
                }
                //grow plants
                if (getWorld()->getSquare(i,
                                          j).getVegetation()->getTimeOfDeath() ==
                    0) {
                    getWorld()->getSquare(i,
                                          j).getVegetation()->incrementStateOfPlant();
                }
            }
        }
    }
}


void WorldController::treeFall(int x, int y) {
    if (world->getSquare(x, y).getVegetation() != nullptr) {
        world->getSquare(x, y).getVegetation()->setTimeOfDeath(numberOfSteps);
    }
    int directionOfFall =
            rand() % 8; // 0 up, 1 left, 2 down, 3 right, 4 top-left...

    if (rand() % 20 == 0) {
        if (directionOfFall == 0) {
            if (world->getSquare(x, y + 1).getVegetation() != nullptr &&
                world->getSquare(x, y + 1).getVegetation()->getTimeOfDeath() ==
                0) {
                treeFall(x, y + 1);
            }
        } else if (directionOfFall == 1) {
            if (world->getSquare(x - 1, y).getVegetation() != nullptr &&
                world->getSquare(x - 1, y).getVegetation()->getTimeOfDeath() ==
                0) {
                treeFall(x - 1, y);
            }
        } else if (directionOfFall == 2) {
            if (world->getSquare(x, y - 1).getVegetation() != nullptr &&
                world->getSquare(x, y - 1).getVegetation()->getTimeOfDeath() ==
                0) {
                treeFall(x, y - 1);
            }
        } else if (directionOfFall == 3) {
            if (world->getSquare(x + 1, y).getVegetation() != nullptr &&
                world->getSquare(x + 1, y).getVegetation()->getTimeOfDeath() ==
                0) {
                treeFall(x + 1, y);
            }
        } else if (directionOfFall == 4) {
            if (world->getSquare(x - 1, y + 1).getVegetation() != nullptr &&
                world->getSquare(x - 1,
                                 y + 1).getVegetation()->getTimeOfDeath() ==
                0) {
                treeFall(x - 1, y + 1);
            }
        } else if (directionOfFall == 5) {
            if (world->getSquare(x - 1, y - 1).getVegetation() != nullptr &&
                world->getSquare(x - 1,
                                 y - 1).getVegetation()->getTimeOfDeath() ==
                0) {
                treeFall(x - 1, y - 1);
            }
        } else if (directionOfFall == 6) {
            if (world->getSquare(x + 1, y - 1).getVegetation() != nullptr &&
                world->getSquare(x + 1,
                                 y - 1).getVegetation()->getTimeOfDeath() ==
                0) {
                treeFall(x + 1, y - 1);
            }
        } else {
            if (world->getSquare(x + 1, y + 1).getVegetation() != nullptr &&
                world->getSquare(x + 1,
                                 y + 1).getVegetation()->getTimeOfDeath() ==
                0) {
                treeFall(x + 1, y + 1);
            }
        }
    }
}