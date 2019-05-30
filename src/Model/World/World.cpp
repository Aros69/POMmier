#include "World.h"

World::World(unsigned int length, unsigned int width) {
    v_length = length;
    v_width = width;
    numberOfSteps = 0;
    sky = new Sky;
    ground = new BasicGround;

    //worldGeneration();
    demoWorldGeneration();
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
    nbMaxVege = 0;
    for (int i = 0; i < v_length; i++) {
        for (int j = 0; j < v_width; j++) {
            // TODO C++11 Random
            if (rand() % 1000 == 0) {
                vegetations.push_front(
                        new BasicVegetation(i, j, numberOfSteps));
            }
        }
        ++nbMaxVege;
    }
}

void World::demoWorldGeneration(){
    auto tempVege2 = new BasicVegetation(50, 100, numberOfSteps);
    tempVege2->setStateOfPlant(10);
    vegetations.push_front(tempVege2);
    auto tempVege1 = new BasicVegetation(50, 50, numberOfSteps);
    tempVege1->setStateOfPlant(25);
    tempVege1->setOrientation(0);
    vegetations.push_front(tempVege1);
}

void World::worldStep() {
    numberOfSteps++;
    for (int i = vegetations.size(); i < nbMaxVege; ++i) {
        int x, y;
        do {
            x = rand() % v_length;
            y = rand() % v_width;
        } while (placeTaken(x, y));
        // If there is enough resource and some luck we add a new vegetal
        if (ground->getResources(x, y) / (rand() % 100) > 0.7) {
            //std::cout << "Spawned vegetation at : " << x << ", " << y << "\n";
            vegetations.push_front(new BasicVegetation(x, y, numberOfSteps));
        }
    }
    std::list<Vegetation *> deadVegetations;
    for (auto vegetation : vegetations) {
        //kill plants
        if (rand() % 55 + vegetation->getHalfLife() > 100
            && vegetation->getTimeOfDeath() == 0) {
            treeFall(vegetation);
        }
        //grow plants or decompose them (if dead)

        if (vegetation->getTimeOfDeath() == 0) {
            if (!placeTaken(vegetation)) {
                vegetation->incrementStateOfPlant(ground);
            }
        } else {
            vegetation->decrementStateOfPlant(ground);
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
    for (auto vegetation : vegetations) {
        if (vegetationDying != vegetation) {
            if(vegetationDying->collideWith(vegetation)) {
                /*vegetation->setOrientation(vegetationDying->getOrientation());
                treeFall(vegetation);*/
            }
        }
    }
}

bool World::placeTaken(unsigned int x, unsigned int y) {
    bool placeIsTaken;
    auto vegetationIterator = vegetations.begin();
    do {
        placeIsTaken = vegetationIterator.operator*()->contain(x, y);
        vegetationIterator++;
    } while (!placeIsTaken && vegetationIterator != vegetations.end());
    return placeIsTaken;
}

bool World::placeTaken(Vegetation *vegetation) {
    bool placeIsTaken;
    auto vegetationIterator = vegetations.begin();
    do {
        if (*vegetationIterator != vegetation) {
            placeIsTaken = vegetationIterator.operator*()->collideWith(
                    vegetation);
        }
        vegetationIterator++;
    } while (!placeIsTaken && vegetationIterator != vegetations.end());
    return placeIsTaken;
}