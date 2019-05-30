#include <QtWidgets/QGraphicsEllipseItem>
#include <iostream>
#include <cmath>
#include "QtVegetationView.h"


QtVegetationView::QtVegetationView(std::list<Vegetation *> *_vegetations)
        : vegetations(_vegetations) {
}

void QtVegetationView::advance(int step) {
// Function I don't use so we don't care
}

QRectF QtVegetationView::boundingRect() const {
    // Function I don't use so we don't care but need to be here
    return QRectF(1, 1, 1, 1);
}

void QtVegetationView::paint(QPainter *painter,
                             const QStyleOptionGraphicsItem *option,
                             QWidget *widget) {
    // TODO add point to show the initial place of the tree
    for (auto vegetation : *vegetations) {
        if (vegetation != nullptr) {
            if (vegetation->isDead()) {
                painter->setBrush(QColor(220, 20, 60));
                painter->drawPolygon(createGoodRect(vegetation));
            } else {
                painter->setBrush(QColor(0, 255, 0));
                painter->drawEllipse(vegetation->getPosX() -
                                     vegetation->getStateOfPlant() / 2,
                                     vegetation->getPosY() -
                                     vegetation->getStateOfPlant() / 2,
                                     vegetation->getStateOfPlant(),
                                     vegetation->getStateOfPlant());
            }
        }
    }
}

QPainterPath QtVegetationView::shape() const {
    // Function I don't use so we don't care but need to be here
    QPainterPath path;
    path.addRect(1, 1, 1, 1);
    return path;
}

QPolygonF QtVegetationView::createGoodRect(Vegetation *vegetation) const {
    auto points = vegetation->getDeadVegetationModel();
    QVector<QPointF> vec;
    for(auto point : points) {
        vec.push_front(QPointF(point.x, point.y));
    }
    auto poly = QPolygonF(vec);
    return poly;
}