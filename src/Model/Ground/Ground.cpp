#include "Ground.h"

Ground::Ground() {
    altitude = 0;
    resources.push_back(Resource());
}

Ground::Ground(int altitude) {
    this->altitude = altitude;
}

Ground::~Ground() {
    resources.clear();
}