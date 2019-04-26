#include <QtWidgets/QGraphicsEllipseItem>
#include <iostream>
#include "QtVegetationView.h"


QtVegetationView::QtVegetationView(QtVegetation *_vegetation,
                                   QGraphicsScene *_scene)
        : vegetation(_vegetation), scene(_scene) {
    item = new QGraphicsEllipseItem();
}

void QtVegetationView::draw() const {
    if (scene == nullptr || vegetation == nullptr) { return; }
    else {
        // TODO Add Color in plant representation
        // TODO Add Death representation of plant
        if (vegetation->isDead()) {
            QGraphicsRectItem *temp = new QGraphicsRectItem(
                    vegetation->getPositionX(), vegetation->getPositionY(), 100,
                    100);
            temp->setBrush(QBrush(Qt::red));
            scene->addItem(temp);
        } else {
            QGraphicsEllipseItem *temp = new QGraphicsEllipseItem(
                    vegetation->getPositionX(), vegetation->getPositionY(), 100,
                    100);
            temp->setBrush(QBrush(Qt::green));
            scene->addItem(temp);
        }
    }
}