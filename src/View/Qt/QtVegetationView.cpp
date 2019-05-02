#include <QtWidgets/QGraphicsEllipseItem>
#include <iostream>
#include "QtVegetationView.h"


QtVegetationView::QtVegetationView(Vegetation *_vegetation, int positionX,
                                   int positionY)
        : vegetation(_vegetation), posX(positionX), posY(positionY) {
    // TODO get real orientation (in the model)
    orientation = 0;
}

void QtVegetationView::advance(int step) {

}

QRectF QtVegetationView::boundingRect() const {
    return QRectF(posX * 4, posY * 4, 8, 8);
}

void QtVegetationView::paint(QPainter *painter,
                             const QStyleOptionGraphicsItem *option,
                             QWidget *widget) {
    // TODO add point to show the initial place of the tree
    // TODO check big memory leak (QtVegetation and initScence)
    if (vegetation != nullptr) {
        if (vegetation->isDead()) {
            painter->setBrush(QColor(255, 0, 0));
            // TODO add orientation to dead tree
            painter->drawRect(posX * 4, posY * 4,
                              vegetation->getStateOfPlant(),
                              vegetation->getStateOfPlant());
        } else {
            painter->setBrush(QColor(0, 255, 0));
            painter->drawEllipse(posX * 4, posY * 4,
                                 vegetation->getStateOfPlant(),
                                 vegetation->getStateOfPlant());
        }
    }
}

QPainterPath QtVegetationView::shape() const {
    QPainterPath path;
    path.addRect(posX * 4, posY * 4, 8, 8);
    return path;
}