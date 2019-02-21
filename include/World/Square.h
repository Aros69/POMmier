#ifndef POMMIER_SQUARE_H
#define POMMIER_SQUARE_H

#include "../Sky/Sky.h"
#include "../Ground/Ground.h"
#include "../Vegetation/Vegetation.h"  //Dependance cyclique resolus


// TODO Find Better Name ?
class Square {
protected:
    Sky sky;
    Ground ground;
    Vegetation **vegetation;

    bool isFreeSquare();

public:
    Square();

    const Sky &getSky() const;

    Ground &getGround();

    Vegetation **getVegetation() const;
};


#endif //POMMIER_SQUARE_H
