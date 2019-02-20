#ifndef POMMIER_SQUARE_H
#define POMMIER_SQUARE_H

#include "../Sky/Sky.h"
#include "../Ground/Ground.h"
//#include "../Vegetation/Vegetation.h"  Dependance cyclique

// TODO Find Better Name ?
class Square {
private:
    Sky sky;
    Ground ground;
    //Vegetation **vegetation;

    bool isFreeSquare();

public:
    Square();
};


#endif //POMMIER_SQUARE_H
