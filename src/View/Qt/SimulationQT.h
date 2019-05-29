#ifndef POMMIER_SIMULATIONQT_H
#define POMMIER_SIMULATIONQT_H

#include <iostream>
#include <thread>
#include <unistd.h>

#include <QApplication>
#include <QTimer>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsRectItem>

#include "../../Controller/WorldController.h"
#include "QtVegetationView.h"

class SimulationQt : public QObject{
private:
    QApplication *app;
    QGraphicsView *view;
    QGraphicsScene scene;
    QtVegetationView * vegetationView;

    WorldController * controller;

    void initModel();

    void initScene();

public:
    SimulationQt() = delete;

    SimulationQt(QApplication* _app);

    ~SimulationQt();

    int launchSimulation();

    int updateSimulation();

    void updateTest();
};

#endif //POMMIER_SIMULATIONQT_H