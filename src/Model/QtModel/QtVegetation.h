#ifndef POMMIER_QTVEGETATION_H
#define POMMIER_QTVEGETATION_H

#include "../Vegetation/Vegetation.h"
#include "../Vegetation/BasicVegetation.h"

class QtVegetation {
private:
    Vegetation *vegetation;
    // When alive : represent the center of the vegetation
    // When dead  : represent the center of one small side of the rectangle
    double positionX;
    double positionY;
    // For the death of the vegetation the orientation of the dead tree
    double orientation;

public:
    QtVegetation() : QtVegetation(new BasicVegetation(), 0, 0, 0) {};

    QtVegetation(double posX, double posY, double _orientation) : QtVegetation(
            new BasicVegetation(), posX, posY, _orientation) {};

    QtVegetation(Vegetation *_vegetation, double posX, double posY,
                 double _orientation);

    ~QtVegetation();

    double getPositionX() const;

    void setPositionX(double positionX);

    double getPositionY() const;

    void setPositionY(double positionY);

    double getOrientation() const;

    void setOrientation(double orientation);

    bool isDead() const;

    // Temporary function !!
    bool die() { vegetation->setTimeOfDeath(1); };

    // TODO update function maybe
};


#endif //POMMIER_QTVEGETATION_H
