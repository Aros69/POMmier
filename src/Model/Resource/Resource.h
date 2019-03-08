#ifndef POMMIER_RESOURCE_H
#define POMMIER_RESOURCE_H


class Resource {
protected:
    double concentration;
public:
    double getConcentration() const;

    void setConcentration(double concentration);
};


#endif //POMMIER_RESOURCE_H
