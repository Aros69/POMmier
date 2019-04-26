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
        // TODO use item variable instead of creating new item
        // TODO add point to show the initial place of the tree
        // TODO add orientation to dead tree
        // TODO check big memory leak (QtVegetation and initScence)
        if (vegetation->isDead()) {
            QGraphicsRectItem *temp = new QGraphicsRectItem(
                    vegetation->getPositionX()*4, vegetation->getPositionY()*4, 8,
                    8);
            temp->setBrush(QBrush(Qt::red));
            scene->addItem(temp);
        } else {
            QGraphicsEllipseItem *temp = new QGraphicsEllipseItem(
                    vegetation->getPositionX()*4, vegetation->getPositionY()*4, 8,
                    8);
            temp->setBrush(QBrush(Qt::green));
            scene->addItem(temp);
        }
    }
}