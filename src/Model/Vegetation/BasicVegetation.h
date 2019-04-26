//
// Created by chris on 20/02/19.
//

#ifndef PROJECTDOGE_BASICVEGETATION_H
#define PROJECTDOGE_BASICVEGETATION_H


#include "Vegetation.h"
#include "../World/Square.h"

class BasicVegetation : public Vegetation{
public:
    BasicVegetation() {halfLife = 1.0;};

    virtual ~BasicVegetation() = default;

protected:
    bool testDeath (double currentTime);

    void growth (bool b);

    void changeModel (std::string *list, int state);

    bool testGrowth (Square **neighborhood);

    void changeResources (Square **neighborhood, int change);

    bool testGermination (Square **neighborhood);

    void decomposition ();

    bool checkTimeBetweenStates (double timeBetween, double currentTime);
};


#endif //PROJECTDOGE_BASICVEGETATION_H
