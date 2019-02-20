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

    void growth (Square **neighborhood);
};


#endif //PROJECTDOGE_BASICVEGETATION_H
