
#include <cmath>
#include "BasicVegetation.h"

BasicVegetation::BasicVegetation(unsigned int x, unsigned int y,
                                 double birthTime) {
    posX = x;
    posY = y;
    timeOfBirth = birthTime;
    halfLife = 50.0;
    timeOfDeath = 0.0;
    orientation = rand() % 360;
}

bool BasicVegetation::testDeath(double currentTime) {
    return ((halfLife - (currentTime - timeOfBirth)) <= 0) ? true : false;
}

void BasicVegetation::growth(bool b) {
    if (b) stateOfPlant++;
}

void BasicVegetation::decomposition() {
    stateOfDecomposition++;
}

bool BasicVegetation::checkTimeBetweenStates(double timeBetween,
                                             double currentTime) {
    if ((currentTime - LastStateChange) > timeBetween) {
        LastStateChange = currentTime;
        return true;
    } else {
        return false;
    }
}

bool BasicVegetation::contain(double x, double y) {
    if (timeOfDeath == 0) { // if the vegetation is not dead
        if (sqrt(pow(x - posX, 2) + pow(y - posY, 2)) <= stateOfPlant) {
            return true;
        } else {
            return false;
        }
    } else {
        // Test de collison a amélioerer (changer de repère)
        auto pointsOfDeadModel = getDeadVegetationModel();
        // Some real bad code, just don't look
        double Xmax = fmax(pointsOfDeadModel[0].x,
                           fmax(pointsOfDeadModel[1].x,
                                fmax(pointsOfDeadModel[2].x,
                                     pointsOfDeadModel[3].x)));
        double Xmin = fmin(pointsOfDeadModel[0].x,
                           fmin(pointsOfDeadModel[1].x,
                                fmin(pointsOfDeadModel[2].x,
                                     pointsOfDeadModel[3].x)));
        double Ymax = fmax(pointsOfDeadModel[0].y,
                           fmax(pointsOfDeadModel[1].y,
                                fmax(pointsOfDeadModel[2].y,
                                     pointsOfDeadModel[3].y)));
        double Ymin = fmin(pointsOfDeadModel[0].y,
                           fmin(pointsOfDeadModel[1].y,
                                fmin(pointsOfDeadModel[2].y,
                                     pointsOfDeadModel[3].y)));
        if (x >= Xmin && x <= Xmax && y >= Ymin && y <= Ymax) {
            return true;
        }
        return false;
    }
}

bool BasicVegetation::collideWith(Vegetation *vegetation) {
    if (timeOfDeath == 0) { // if the vegetation is not dead
        if (!vegetation->isDead() &&
            sqrt(pow(vegetation->getPosX() - posX, 2) +
                 pow(vegetation->getPosY() - posY, 2)) <=
            vegetation->getStateOfPlant() + stateOfPlant) {
            return true;
        } else {
            //TODO Si je suis en vie face à une plante morte
            return false;
        }
    } else {
        if (vegetation->isDead()) {
            // if both are dead, we don't care
            return false;
        } else {
            // First Method : check if one of the 4 point of the rectangle are in the vegetation if yes kill it
            auto pointsOfDeadModel = getDeadVegetationModel();
            bool isColliding = false;
            int i = 0;
            do {
                isColliding = vegetation->contain(pointsOfDeadModel[i].x,
                                                  pointsOfDeadModel[i].y);
                ++i;
            } while (!isColliding && i < 4);
            return isColliding;
        }
        return false;
    }
}

void BasicVegetation::incrementStateOfPlant(Ground *ground) {
    if (ground->getResources(posX, posY) > stateOfPlant / 1000) {
        for (int i = 0; i < stateOfPlant; ++i) {
            ground->takeResource(posX, posY);
        }
        stateOfPlant++;
    }
}

void BasicVegetation::decrementStateOfPlant(Ground *ground) {
    if (stateOfPlant > 0) {
        // Two simulation option here : if i=0, we give to much resource and
        // the world will be over resourced after a while, if i=1, there is
        // always not enough resource ans not many vegetation while grown
        // we can say : i=0 is like a forest and i=1 is like a desert
        for (int i = 0; i < stateOfPlant; ++i) {
            ground->addResource(posX, posY);
        }
        stateOfPlant--;
    }
}

std::vector<PointCartesien> BasicVegetation::getDeadVegetationModel() {
    auto a = PointCartesien(-getStateOfPlant() / 4.0, 0);
    auto d = PointCartesien(getStateOfPlant() / 4.0,
                            getStateOfPlant() * 2);
    auto b = PointCartesien(getStateOfPlant() / 4.0, 0);
    auto c = PointCartesien(-getStateOfPlant() / 4.0,
                            getStateOfPlant() * 2);
    auto aPolaire = PointPolaire(a);
    auto bPolaire = PointPolaire(b);
    auto cPolaire = PointPolaire(c);
    auto dPolaire = PointPolaire(d);
    aPolaire.teta += PointPolaire::degreesToRadian(getOrientation());
    bPolaire.teta += PointPolaire::degreesToRadian(getOrientation());
    cPolaire.teta += PointPolaire::degreesToRadian(getOrientation());
    dPolaire.teta += PointPolaire::degreesToRadian(getOrientation());
    a.convertWithPolar(aPolaire.r, aPolaire.teta);
    b.convertWithPolar(bPolaire.r, bPolaire.teta);
    c.convertWithPolar(cPolaire.r, cPolaire.teta);
    d.convertWithPolar(dPolaire.r, dPolaire.teta);
    a.x += posX;
    b.x += posX;
    c.x += posX;
    d.x += posX;
    a.y += posY;
    b.y += posY;
    c.y += posY;
    d.y += posY;
    std::vector<PointCartesien> res;
    res.push_back(a);
    res.push_back(b);
    res.push_back(d);
    res.push_back(c);
    return res;
}