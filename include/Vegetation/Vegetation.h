//
// Created by chris on 20/02/19.
//

#ifndef PROJECTDOGE_VEGETATION_H
#define PROJECTDOGE_VEGETATION_H

#include <string>

//#include "../World/Square.h"

class Square;

class Vegetation {
protected:
    double halfLife;
    double birth;
    int stateOfPlant;
    std::string stateOfPlantPath;
    std::string listStateOfPlant [2] = {"pathToModel1", "pathToModel2"};

    virtual bool death (double currentTime) = 0; // checks if the plant must die

    virtual void growth (bool b) = 0; // if b true -> plant grows and changes it's state to bigger plant with a new model

    virtual void changeModel () = 0; // changes the plants path to switch model

    virtual bool testGrowth (Square **neighborhood) = 0; // tests if the plant can grow

    virtual void changeResources (Square **neighborhood, int change) = 0;
};


#endif //PROJECTDOGE_VEGETATION_H
