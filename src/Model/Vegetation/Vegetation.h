#ifndef PROJECTDOGE_VEGETATION_H
#define PROJECTDOGE_VEGETATION_H

#include <string>

class Square;

class Vegetation {
protected:
    double halfLife;
    double timeOfBirth;
    double timeOfDeath = -1;
    double LastStateChange = timeOfBirth;
public:
    double getHalfLife() const;

    int getStateOfPlant() const;

    void setStateOfPlant(int stateOfPlant);

    void incrementStateOfPlant();

    void setLastStateChange(double LastStateChange);

    double getLastStateChange() const;

protected:

    int stateOfPlant = 0;
    std::string listStateOfPlant [2] = {"pathToModel1", "pathToModel2"};
    std::string stateOfPlantPath;
    int stateOfDecomposition = 0;
    std::string listStateOfDecomposition [2] = {"pathToModel1", "pathToModel2"};

    virtual bool testDeath (double currentTime) = 0; // checks if the plant must die

    virtual void growth (bool b) = 0; // if b true -> plant grows and changes it's state to bigger plant with a new model

    virtual void changeModel (std::string *list, int state) = 0; // changes the plants path to switch model

    virtual bool testGrowth (Square **neighborhood) = 0; // tests if the plant can grow

    virtual void changeResources (Square **neighborhood, int change) = 0; // increases or decreases the resources in the area

    virtual bool testGermination (Square **neighborhood) = 0; // tests if plant can be born in it's location

    virtual void decomposition () = 0; // incremente stateOfDecomposition

    virtual bool checkTimeBetweenStates (double timeBetween, double currentTime) = 0;   // returns true if timeBetween <
                                                                                        // currentTime - the time of the
                                                                                        // previous change of state

public:

    virtual ~Vegetation() = default;
    double getTimeOfBirth() const;
    void setTimeOfBirth(double timeOfBirth);

    double getTimeOfDeath() const;
    void setTimeOfDeath(double timeOfDeath);
};


#endif //PROJECTDOGE_VEGETATION_H
