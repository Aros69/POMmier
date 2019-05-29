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
    controller = new WorldController(1024, 512);
    std::cout << "Alloc ok\n";
    std::cout << "Init ok\n";
}

void SimulationQt::initScene() {
    // TODO Find a better way to define the size of the window
    // Use a rectangle at the border of the window to define his size
    QGraphicsRectItem *temp =
            new QGraphicsRectItem(0, 0, controller->getWorld()->getLength(),
                                  controller->getWorld()->getWidth());
    temp->setPen(Qt::NoPen);
    scene.addItem(temp);
    /*view->resize(controller->getWorld()->getLength() * 4,
                 controller->getWorld()->getWidth() * 4);*/

    //World *world = controller->getWorld();
    vegetationView = new QtVegetationView(controller->getWorld()->getVegetations());
    scene.addItem(vegetationView);
    /*for (auto vegetation : world->getVegetations()) {
        vegetationViews.push_front(new QtVegetationView(vegetation));
        scene.addItem(vegetationViews.front());
    }*/
}

void SimulationQt::updateTest() {
    int quit = 0;
    while (quit < 100) {
        // Update each second
        //sleep(1);
        // Update note each second (quicker) I would say 4 times per second
        usleep(250000);
        std::cout << "Update : " << quit << "\n";
        controller->worldStep();
        scene.update(0, 0, controller->getWorld()->getLength(),
                     controller->getWorld()->getWidth());
        ++quit;
    }
}

int SimulationQt::launchSimulation() {
    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "POMmier"));
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    std::thread t(&SimulationQt::updateTest, this);
    QTimer timer;

    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    // Update the scene to have 30 fps
    timer.start(1000 / 33);
    view->show();

    app->exec();
}
