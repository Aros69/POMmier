#include "World.h"

World::World(unsigned int length, unsigned int width) {
    v_length = length;
    v_width = width;
    numberOfSteps = 0;
    sky = new Sky;
    ground = new BasicGround;
    worldGeneration();
}

World::~World() {
    for (auto vegetation : vegetations) {
        delete vegetation;
        vegetation = nullptr;
    }
    delete sky;
    sky = nullptr;
    delete ground;
    ground = nullptr;
}

void World::worldGeneration() {
    for (int i = 0; i < v_length; i++) {
        for (int j = 0; j < v_width; j++) {
            /*getWorld()->getSquare(i, j).getSky().setLuminosity(1);
            getWorld()->getSquare(i, j).getGround().setAltitude(1);
            getWorld()->getSquare(i, j).getGround().setResources(1);*/
            // TODO C++11 Random
            if (rand() % 1000 == 0) {
                vegetations.push_front(
                        new BasicVegetation(i, j, numberOfSteps));
            }
        }
    }
}

void World::worldStep() {
    numberOfSteps++;
    // TODO CHECK IF SQUARE IS OUT OF BOUND OF SQUARE AREA
    // when doing x+1, you can be out of bound :(
    // same for x+1, x-1, y-1 and y+1
    std::list<Vegetation *> deadVegetations;
    for (auto vegetation : vegetations) {
        //kill plants
        if (rand() % 55 + vegetation->getHalfLife() > 100
            && vegetation->getTimeOfDeath() == 0) {
            treeFall(vegetation);
        }
        // TODO CHECK IF WE CAN CREATE PLANT WITH THAT LOOKS SUSPICIOUS
        // On dirait que tu crée une plante seuement s'il y en a une a coté !!!
        // create new plants
        // TODO REDO This part !
        if (vegetation->getTimeOfDeath() == 0
            && vegetation->getTimeOfBirth() < numberOfSteps) {
            for (int x = vegetation->getPosX();
                 x < vegetation->getPosX() + 2; x++) {
                for (int y = vegetation->getPosY();
                     y < vegetation->getPosY() + 2; y++) {
                    if (rand() % 4 > 3) {
                        vegetation->setTimeOfBirth(numberOfSteps);
                        vegetation->setTimeOfDeath(0);
                    }
                }
            }
        }
        //grow plants or decompose them (if dead)
        if (vegetation->getTimeOfDeath() == 0) {
            vegetation->incrementStateOfPlant();
        } else {
            vegetation->decrementStateOfPlant();
            if (vegetation->getStateOfPlant() == 0) {
                deadVegetations.push_front(vegetation);
            }
        }
    }
    // Destroy plants who has been totaly decompose
    for (auto deadVegetation : deadVegetations) {
        vegetations.remove(deadVegetation);
        delete deadVegetation;
    }
}

// TODO False, should be done depending on a tree, when it falls it pushes other tree if they are other tree
// TODO parameter should be an angle (rotation of the fall of the tree) and a vegetation (the vegetation dying)
void World::treeFall(Vegetation *vegetationDying) {
    if (vegetationDying != nullptr) {
        vegetationDying->setTimeOfDeath(numberOfSteps);
    }
    /*int directionOfFall =
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
    }*/
}
