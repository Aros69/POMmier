
#ifndef POMMIER_BASICGROUND_H
#define POMMIER_BASICGROUND_H


#include "Ground.h"

class BasicGround : public Ground{
private:
    double ressourceConcentration;
public:
    BasicGround() : Ground() {ressourceConcentration = 1;}

};


#endif //POMMIER_BASICGROUND_H
