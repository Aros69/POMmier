#include <iostream>
#include "SimulationModel.h"

SimulationModel::SimulationModel(int length, int heigth) {
    lengthModel = length;
    heightModel = heigth;
    vegetations = std::list<QtVegetation*>();
}

SimulationModel::~SimulationModel() {
    for(QtVegetation* vegetation : vegetations){
        delete(vegetation);
        vegetation = nullptr;
    }
}

void SimulationModel::addVegetation(QtVegetation *vegetation) {
    if (vegetation->getPositionX() > lengthModel) {
        vegetation->setPositionX(lengthModel);
    } else if (vegetation->getPositionX() < 0) {
        vegetation->setPositionX(0);
    }
    if (vegetation->getPositionY() > heightModel) {
        vegetation->setPositionY(heightModel);
    } else if (vegetation->getPositionY() < 0) {
        vegetation->setPositionY(0);
    }
    vegetations.push_back(vegetation);
}

const std::list<QtVegetation*> &SimulationModel::getVegetations() const {
    return vegetations;
}

int SimulationModel::getLengthModel() const {
    return lengthModel;
}

int SimulationModel::getHeightModel() const {
    return heightModel;
}

void SimulationModel::update() {
    for(QtVegetation *vegetation : vegetations){
        vegetation->die();
    }
    std::cout<<"Model Updated\n";
    //TODO !!!!!
}