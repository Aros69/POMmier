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

protected:
    bool death (double currentTime);

    void growth (bool b);

    void changeModel ();

    bool testGrowth (Square **neighborhood);

    void changeResources (Square **neighborhood, int change);
};


#endif //PROJECTDOGE_BASICVEGETATION_H
