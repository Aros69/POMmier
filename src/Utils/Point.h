#ifndef POMMIER_POINT_H
#define POMMIER_POINT_H

#include <cmath>
#include <iostream>

class PointCartesien {
public:
    double x;
    double y;

    PointCartesien() {
        x = 0;
        y = 0;
    }

    PointCartesien(double _x, double _y) {
        x = _x;
        y = _y;
    }

    void convertWithPolar(double rPolaire, double tetaPolaire) {
        x = rPolaire * cos(tetaPolaire);
        y = rPolaire * sin(tetaPolaire);
    }
};

class PointPolaire {
public:
    double r;
    double teta; // Between 0 and 2*pi

    PointPolaire() {
        r = 0;
        teta = 0;
    }

    PointPolaire(PointCartesien p) {
        r = sqrt(p.x * p.x + p.y * p.y);
        if (p.x > 0 && p.y >= 0) {
            teta = atan(p.y / p.x);
        } else if (p.x > 0 && p.y < 0) {
            teta = atan(p.y / p.x) + 2 * M_PI;
        } else if (p.x < 0) {
            teta = atan(p.y / p.x) + M_PI;
        } else if (p.x == 0 && p.y > 0) {
            teta = M_PI / 2;
        } else if (p.x == 0 && p.y < 0) {
            teta = 3 * M_PI / 2;
        } else {
            teta = 0;
        }
    }

    static double degreesToRadian(const double &angle) {
        return angle * M_PI / 180;
    };

    static double radianToDegrees(const double &angle) {
        return angle * 180 / M_PI;
    };
};

#endif //POMMIER_POINT_H
