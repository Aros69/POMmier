#ifndef POMMIER_SQUARE_H
#define POMMIER_SQUARE_H

#include "../Sky/Sky.h"
#include "../Ground/Ground.h"
#include "../Vegetation/Vegetation.h"  //Dependance cyclique resolus


// TODO Find Better Name ?
class Square {
protected:
    Sky sky;
    Ground *ground;
    Vegetation *vegetation;

protected:

    bool isFreeSquare();

public:
    Square() = default;
    Square(Vegetation *veg);

    Sky &getSky();

    Ground &getGround();

    Vegetation *getVegetation();
};


#endif //POMMIER_SQUARE_H
