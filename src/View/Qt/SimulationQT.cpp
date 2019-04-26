#include <QtWidgets/QGraphicsRectItem>
#include <cmath>
#include "SimulationQT.h"

SimulationQt::SimulationQt(QApplication *_app) {
    app = _app;
    initModel();
    initScene();

    view = new QGraphicsView(&scene);
}

SimulationQt::~SimulationQt() {
    delete (controller);
    controller = nullptr;
    delete (view);
    view = nullptr;
}

void SimulationQt::initModel() {
    // TODO Do a better function
    controller = new WorldController(256, 128);
    std::cout << "Alloc ok\n";
    controller->worldGeneration();
    std::cout << "Init ok\n";
    //model = SimulationModel(1000, 500);
    /*createVegetation(100, 100, 0);
    createVegetation(200, 0, 90);
    createVegetation(0, 300, 180);*/
}

void SimulationQt::initScene() {
    // TODO Find a better way to define the size of the window
    // Use a rectangle at the border of the window to define his size
    /*QGraphicsRectItem *temp = new QGraphicsRectItem(0, 0,
                                                    model.getLengthModel(),
                                                    model.getHeightModel());*/
    QGraphicsRectItem *temp = new QGraphicsRectItem(0, 0,
                                                    controller->getWorld()->getLength()*4,
                                                    controller->getWorld()->getWidth()*4);
    temp->setPen(Qt::NoPen);
    scene.addItem(temp);

    SquareArea *world = controller->getWorld();
    for (int i = 0; i < controller->getWorld()->getLength(); i++) {
        for (int j = 0; j < controller->getWorld()->getWidth(); j++) {
            if (world->getSquare(i, j).getVegetation() != nullptr) {
                vegetationViews.push_back(QtVegetationView(
                        new QtVegetation(world->getSquare(i, j).getVegetation(),
                                         i, j, 0), &scene));
            }
        }
    }
    /*for (const QtVegetationView view : vegetationViews) {
        view.draw();
    }*/
}

/*void
SimulationQt::createVegetation(double posX, double posY, double orientation) {
    QtVegetation *temp = new QtVegetation(posX, posY, orientation);
    model.addVegetation(temp);
    vegetationViews.push_back(QtVegetationView(temp, &scene));
}*/

int SimulationQt::launchSimulation() {
    view->show();
    //std::thread t(&SimulationQt::updateSimulation, this);
    updateSimulation();
    for (const QtVegetationView view : vegetationViews) {
        view.draw();
    }
    app->exec();

}

int SimulationQt::updateSimulation() {
    int quit = 0;
    while (quit < 100) {
        //model.update();
        controller->worldStep();
        /*for (const QtVegetationView view : vegetationViews) {
            view.draw();
        }*/
        ++quit;
        //scene.update(0,0, model.getLengthModel(), model.getHeightModel());
    }

}
