#ifndef POMMIER_VEGETATIONCONTROLLER_H
#define POMMIER_VEGETATIONCONTROLLER_H


#include "../Model/Vegetation/Vegetation.h"

class VegetationController {
    Vegetation *vegetation;

    void addVegetation (Vegetation *veg); // add a plant to the list vegetation

    void deleteVegetation (); // delete the plant

    Vegetation* getVegetation (); // returns a pointer on vegetation
};


#endif //POMMIER_VEGETATIONCONTROLLER_H
