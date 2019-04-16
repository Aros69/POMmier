#ifndef POMMIER_SKY_H
#define POMMIER_SKY_H


class Sky {
protected:
    double luminosity;

public:
    Sky () {luminosity = 1;};

    void setLuminosity(double luminosity) {
        Sky::luminosity = luminosity;
    }

    double getLuminosity() const {
        return luminosity;
    };
};


#endif //POMMIER_SKY_H
