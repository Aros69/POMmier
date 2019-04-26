#ifndef POMMIER_GROUND_H
#define POMMIER_GROUND_H


#include "../Resource/Resource.h"
#include <list>

class Ground {
protected:
    int altitude;
    std::list<Resource> resources;

public:
    Ground();

    explicit Ground(int altitude);

    ~Ground();

    int getAltitude() const { return altitude; }

    const std::list<Resource> &getResources() const { return resources; }

    void setAltitude(int altitude) { this->altitude = altitude; }

    void setResources(int resources) {
        this->resources.front().setConcentration(resources);
    }

    //set the available resources in the terrain
    void setAvailableResources() { setResources(1); };
};


#endif //POMMIER_GROUND_H
