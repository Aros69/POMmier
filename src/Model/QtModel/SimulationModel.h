#ifndef POMMIER_SIMULATIONMODEL_H
#define POMMIER_SIMULATIONMODEL_H

#include <list>
#include "QtVegetation.h"

class SimulationModel {
private:
    int lengthModel;
    int heightModel;
    std::list<QtVegetation*> vegetations;
    // TODO add stuff for ground and ressources simulation

public:
    SimulationModel() : SimulationModel(1000, 1000){};

    SimulationModel(int length, int heigth);

    ~SimulationModel();

    void addVegetation(QtVegetation *vegetation);

    void update();
    // TODO add update function and some cool stuff :)

    int getLengthModel() const;

    int getHeightModel() const;

    const std::list<QtVegetation*> &getVegetations() const;

};


#endif //POMMIER_SIMULATIONMODEL_H
