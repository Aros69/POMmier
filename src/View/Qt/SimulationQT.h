#ifndef POMMIER_SIMULATIONQT_H
#define POMMIER_SIMULATIONQT_H

#include <iostream>
#include <thread>
#include <QApplication>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>

#include "../../Model/QtModel/SimulationModel.h"
#include "QtVegetationView.h"

class SimulationQt {
private:
    QApplication *app;
    QGraphicsView *view;
    QGraphicsScene scene;

    SimulationModel model;
    std::list<QtVegetationView> vegetationViews;

    void initModel();

    void initScene();

public:
    SimulationQt() = delete;

    SimulationQt(QApplication* _app);

    ~SimulationQt();

    void createVegetation(double posX, double posY, double orientation);

    int launchSimulation();

    int updateSimulation();
};

#endif //POMMIER_SIMULATIONQT_H