#ifndef PROJECTDOGE_VEGETATION_H
#define PROJECTDOGE_VEGETATION_H

#include <vector>
#include "../Ground/Ground.h"
#include "../../Utils/Point.h"

class Vegetation {

public:
    double getHalfLife() const;

    int getStateOfPlant() const;

    void setStateOfPlant(int stateOfPlant);

    virtual void incrementStateOfPlant(Ground *ground);

    virtual void decrementStateOfPlant(Ground *ground);

    void setLastStateChange(double LastStateChange);

    double getLastStateChange() const;

    unsigned int getPosX() { return posX; }

    unsigned int getPosY() { return posY; }

    unsigned int getOrientation() { return orientation; };

    void
    setOrientation(unsigned int _orientation) { orientation = _orientation; };

    virtual ~Vegetation() = default;

    double getTimeOfBirth() const;

    void setTimeOfBirth(double timeOfBirth);

    double getTimeOfDeath() const;

    void setTimeOfDeath(double timeOfDeath);

    bool isDead() const;

    /**
     * Check if the point (x,y) is in the vegetation
     * @param x point location parameter
     * @param y point location parameter
     * @return true if the point is in the vegetation
     */
    virtual bool contain(double x, double y) = 0;

    /**
     * Check if the to vegetation are colliding
     * @param vegetation the other vegetation tested
     * @return true if the two vegetation are colliding
     */
    virtual bool collideWith(Vegetation *vegetation) = 0;

    virtual std::vector<PointCartesien> getDeadVegetationModel() = 0;

protected:
    double halfLife;
    double timeOfBirth;
    double timeOfDeath = 0;
    double LastStateChange = timeOfBirth;
    unsigned int posX;
    unsigned int posY;
    unsigned int orientation = 0;
    // TODO maybe add a bool to reprensent the impossibility of growing ??
    int stateOfPlant = 0;
    int stateOfDecomposition = 0;

    virtual bool
    testDeath(double currentTime) = 0; // checks if the plant must die

    virtual void
    growth(bool b) = 0; // if b true -> plant grows and changes it's state to bigger plant with a new model

    /*virtual bool
    testGrowth(Square **neighborhood) = 0; // tests if the plant can grow

    virtual void changeResources(Square **neighborhood,
                                 int change) = 0; // increases or decreases the resources in the area

    virtual bool testGermination(
            Square **neighborhood) = 0; // tests if plant can be born in it's location*/

    virtual void decomposition() = 0; // incremente stateOfDecomposition

    virtual bool checkTimeBetweenStates(double timeBetween,
                                        double currentTime) = 0;   // returns true if timeBetween <
    // currentTime - the time of the
    // previous change of state
};


#endif //PROJECTDOGE_VEGETATION_H
