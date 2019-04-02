#ifndef POMMIER_VEGETATIONCONTROLLER_H
#define POMMIER_VEGETATIONCONTROLLER_H


#include <vector>
#include "../Model/Vegetation/Vegetation.h"

class VegetationController {
    std::vector<Vegetation> vegetation;

    void addVegetation (Vegetation veg); // add a plant to the list vegetation

    void deleteVegetation (Vegetation veg); // delete a plant from the list vegetation
    void deleteVegetation (int it); // delete a plant from the list vegetation
};


#endif POMMIER_VEGETATIONCONTROLLER_H
