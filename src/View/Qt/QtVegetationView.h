#ifndef POMMIER_QTVEGETATIONVIEW_H
#define POMMIER_QTVEGETATIONVIEW_H


#include <QtWidgets/QGraphicsScene>
#include <QPainter>
#include <src/Model/Vegetation/Vegetation.h>

class QtVegetationView : public QGraphicsItem {
private:
    std::list<Vegetation*>* vegetations;

public:
    QtVegetationView() = delete;

    QtVegetationView(std::list<Vegetation *>* _vegetations);

    void advance(int advance);

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    QPolygonF createGoodRect(Vegetation* vegetation) const;
};


#endif //POMMIER_QTVEGETATIONVIEW_H
