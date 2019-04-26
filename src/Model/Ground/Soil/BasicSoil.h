#ifndef PROJECTDOGE_BASICSOIL_H
#define PROJECTDOGE_BASICSOIL_H


#include "../Ground.h"

class BasicSoil : public Ground {
    BasicSoil(int altitude);
    void setAvailableResources();
};


#endif //PROJECTDOGE_BASICSOIL_H
