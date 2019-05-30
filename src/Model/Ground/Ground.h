#ifndef POMMIER_GROUND_H
#define POMMIER_GROUND_H

class Ground {
protected:
    int v_altitude;

public:
    Ground(): Ground(0){};

    Ground(int altitude){v_altitude = altitude;};

    int getAltitude() const { return v_altitude; }

    virtual double getResources() const = 0;

    virtual double getResources(unsigned int x,
                                unsigned int y) const = 0;

    void setAltitude(int altitude) { v_altitude = altitude; };

    /**
     * Decrement resources
     * @param x point location parameter
     * @param y point location parameter
     * @return true if there is enough resource
     */
    virtual bool takeResource(unsigned int x, unsigned int y) = 0;

    /**
     * Increment resources
     * @param x point location parameter
     * @param y point location parameter
     * @return true if there is not too much resource
     */
    virtual bool addResource(unsigned int x, unsigned int y) = 0;
};


#endif //POMMIER_GROUND_H
