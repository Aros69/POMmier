#ifndef POMMIER_SQUARE_H
#define POMMIER_SQUARE_H

#include "../Sky/Sky.h"
#include "../Ground/Ground.h"
#include "../Vegetation/Vegetation.h"

// TODO Find Better Name ?
class Square {
private:
    Sky sky;
    Ground *ground;
    std::vector<Vegetation> *vegetation;

public:
    Square() = default;

    bool isFreeSquare();
};


#endif //POMMIER_SQUARE_H
