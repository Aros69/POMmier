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
    int x;
    int y;
public:
    void setSky(const Sky &sky);

    void setGround(Ground *ground);

    void setVegetation(Vegetation *vegetation);

    void setX(int x);

    void setY(int y);

    int getX() const;

    int getY() const;

    bool isFreeSquare();

    Square() = default;
    Square(Vegetation *veg);

    Sky &getSky();

    Ground &getGround();

    Vegetation *getVegetation();
};


#endif //POMMIER_SQUARE_H
