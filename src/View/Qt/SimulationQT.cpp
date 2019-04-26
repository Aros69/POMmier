#include <QtWidgets/QGraphicsRectItem>
#include "SimulationQT.h"

SimulationQt::SimulationQt(QApplication *_app) {
    app = _app;
    initModel();
    initScene();

    view = new QGraphicsView(&scene);
}

SimulationQt::~SimulationQt() {
    delete (view);
    view = nullptr;
}

void SimulationQt::initModel() {
    // TODO Do a better function
    model = SimulationModel(1000, 500);
    createVegetation(100, 100, 0);
    createVegetation(200, 0, 90);
    createVegetation(0, 300, 180);
    /*model.addVegetation(new QtVegetation(100, 100, 0));
    model.addVegetation(new QtVegetation(200, 0, 90));
    model.addVegetation(new QtVegetation(0, 300, 180));*/
}

void SimulationQt::initScene() {
    // TODO Find a better way to define the size of the window
    // Use a rectangle at the border of the window to define his size
    QGraphicsRectItem *temp = new QGraphicsRectItem(0, 0,
                                                    model.getLengthModel(),
                                                    model.getHeightModel());
    temp->setPen(Qt::NoPen);
    scene.addItem(temp);
    for (const QtVegetationView view : vegetationViews) {
        view.draw();
    }
}

void
SimulationQt::createVegetation(double posX, double posY, double orientation) {
    QtVegetation *temp = new QtVegetation(posX, posY, orientation);
    model.addVegetation(temp);
    vegetationViews.push_back(QtVegetationView(temp, &scene));
}

int SimulationQt::launchSimulation() {
    view->show();
    //std::thread t(&SimulationQt::updateSimulation, this);
    app->exec();

}

int SimulationQt::updateSimulation() {
    int quit = 0;
    std::cout<<"ok\n";
    while (quit == 0) {
        model.update();
        for (const QtVegetationView view : vegetationViews) {
            view.draw();
        }
        //scene.update(0,0, model.getLengthModel(), model.getHeightModel());
    }
}
