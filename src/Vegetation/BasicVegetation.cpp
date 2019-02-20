//
// Created by chris on 20/02/19.
//

#include "../../include/Vegetation/BasicVegetation.h"


bool BasicVegetation::death (double currentTime) {
    return ((halfLife - (currentTime - birth)) <= 0)? true : false;
}

void BasicVegetation::growth (Square **neighborhood) {

}