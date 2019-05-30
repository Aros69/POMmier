
#ifndef POMMIER_BASICGROUND_H
#define POMMIER_BASICGROUND_H


#include "Ground.h"

class BasicGround : public Ground {
private:
    double resourceConcentration;
public:
    BasicGround() : Ground() { resourceConcentration = 1; }

    double getResources() const { return resourceConcentration; };

    double getResources(unsigned int x,
                        unsigned int y) const { return resourceConcentration; };

    bool takeResource(unsigned int x, unsigned int y);
    bool addResource(unsigned int x, unsigned int y);
};


#endif //POMMIER_BASICGROUND_H
