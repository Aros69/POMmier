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
}

void SimulationQt::initScene() {
    // TODO Find a better way to define the size of the window
    // Use a rectangle at the border of the window to define his size
    QGraphicsRectItem *temp =
            new QGraphicsRectItem(0, 0, controller->getWorld()->getLength() * 4,
                                  controller->getWorld()->getWidth() * 4);
    temp->setPen(Qt::NoPen);
    scene.addItem(temp);
    /*view->resize(controller->getWorld()->getLength() * 4,
                 controller->getWorld()->getWidth() * 4);*/

    SquareArea *world = controller->getWorld();
    for (int i = 0; i < controller->getWorld()->getLength(); i++) {
        for (int j = 0; j < controller->getWorld()->getWidth(); j++) {
            if (world->getSquare(i, j).getVegetation() != nullptr) {
                vegetationViews.push_back(new QtVegetationView(
                        world->getSquare(i, j).getVegetation(), i, j));
                scene.addItem(vegetationViews.back());
            }
        }
    }
    /*for (const QtVegetationView view : vegetationViews) {
        view.draw();
    }*/
}

void SimulationQt::updateTest() {
    int quit = 0;
    while (quit < 10000) {
        // Update each second
        sleep(1);
        std::cout << "Update : " << quit << "\n";
        controller->worldStep();
        scene.update(0, 0, controller->getWorld()->getLength() * 4,
                     controller->getWorld()->getWidth() * 4);
        ++quit;
    }
}

int SimulationQt::launchSimulation() {
    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "POMmier"));
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    std::thread t(&SimulationQt::updateTest, this);
    QTimer timer;

    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(1000 / 33);
    view->show();

    app->exec();
}
