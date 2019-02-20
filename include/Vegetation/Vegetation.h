//
// Created by chris on 20/02/19.
//

#ifndef PROJECTDOGE_VEGETATION_H
#define PROJECTDOGE_VEGETATION_H


#include "../World/Square.h"

class Vegetation {
protected:
    double halfLife;
    double birth;

    virtual bool death (double currentTime) = 0;

    virtual void growth (Square **neighborhood) = 0;
};


#endif //PROJECTDOGE_VEGETATION_H
