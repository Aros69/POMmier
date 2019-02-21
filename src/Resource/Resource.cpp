#include "../../include/Resource/Resource.h"

double Resource::getConcentration() const {
    return concentration;
}

void Resource::setConcentration(double concentration) {
    Resource::concentration = concentration;
}