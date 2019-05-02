#include <iostream>
#include <QApplication>
#include <src/View/Qt/SimulationQT.h>

int main(int argc, char *argv[]) {
    std::cout << "main Qt !\n";

    QApplication app(argc, argv);

    SimulationQt simulationQt(&app);
    int res = simulationQt.launchSimulation();

    return res;
}
