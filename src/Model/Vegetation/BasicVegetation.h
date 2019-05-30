#ifndef POMMIER_BASICVEGETATION_H
#define POMMIER_BASICVEGETATION_H


#include <list>
#include "Vegetation.h"
#include "../World/Square.h"

class BasicVegetation : public Vegetation {
public:
    BasicVegetation() { halfLife = 50.0; };

    BasicVegetation(unsigned int x, unsigned int y, double birthTime);

    virtual ~BasicVegetation() = default;

protected:
    bool testDeath(double currentTime);

    void growth(bool b);

    void decomposition();

    bool checkTimeBetweenStates(double timeBetween, double currentTime);

    bool contain(double x, double y);

    bool collideWith(Vegetation *vegetation);

    void incrementStateOfPlant(Ground *ground);

    void decrementStateOfPlant(Ground *ground);

    std::vector<PointCartesien> getDeadVegetationModel();
};


#endif //POMMIER_BASICVEGETATION_H
