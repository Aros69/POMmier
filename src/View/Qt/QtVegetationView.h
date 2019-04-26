#ifndef POMMIER_QTVEGETATIONVIEW_H
#define POMMIER_QTVEGETATIONVIEW_H


#include <QtWidgets/QGraphicsScene>
#include <src/Model/QtModel/QtVegetation.h>

class QtVegetationView {
private:
    QtVegetation *vegetation;
    QGraphicsScene *scene;
    QGraphicsItem *item;

public:
    QtVegetationView() = delete;

    QtVegetationView(QtVegetation *_vegetation, QGraphicsScene *_scene);

    void draw() const;
};


#endif //POMMIER_QTVEGETATIONVIEW_H
