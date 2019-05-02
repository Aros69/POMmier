#ifndef POMMIER_QTVEGETATIONVIEW_H
#define POMMIER_QTVEGETATIONVIEW_H


#include <QtWidgets/QGraphicsScene>
#include <QPainter>
#include <src/Model/Vegetation/Vegetation.h>

class QtVegetationView : public QGraphicsItem{
private:
    Vegetation *vegetation;
    // When alive : represent the center of the vegetation
    // When dead  : represent the center of one small side of the rectangle
    int posX;
    int posY;
    // For the death of the vegetation the orientation of the dead tree
    double orientation;

public:
    QtVegetationView() = delete;

    QtVegetationView(Vegetation *_vegetation, int positionX, int positionY);

    void advance(int advance);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
};


#endif //POMMIER_QTVEGETATIONVIEW_H
