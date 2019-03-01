#ifndef POMMIER_GROUND_H
#define POMMIER_GROUND_H


#include <vector>
#include "../Resource/Resource.h"

class Ground {
protected:
    int altitude;
    std::vector<Resource> resources;

public:
    explicit Ground(int altitude);

    int getAltitude() const {return altitude;}
    const std::vector <Resource> &getResources() const {return resources;}

    void setAltitude(int altitude) {this->altitude = altitude;}
    void setResources(int resources) {this->resources.at(0).setConcentration(resources);}
};


#endif //POMMIER_GROUND_H
