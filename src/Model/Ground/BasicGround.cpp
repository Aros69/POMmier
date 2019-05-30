#include "BasicGround.h"

bool BasicGround::takeResource(unsigned int x, unsigned int y) {
    if(resourceConcentration==0){
        return false;
    } else {
        resourceConcentration-=0.001;
        return true;
    }
};

bool BasicGround::addResource(unsigned int x, unsigned int y) {
    if(resourceConcentration==1){
        return false;
    } else {
        resourceConcentration+=0.001;
        return true;
    }
};