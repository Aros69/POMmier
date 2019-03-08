#include "SimulationTxt.h"

SimulationTxt::SimulationTxt() {
    termClear();
    //worldController = WorldController(25, 25);
    /*worldView = new CompleteSquareAreaView(
            worldController.getWorld().getCompleteSquareArea());
    window = new WinTXT(
            worldController.getWorld().getCompleteSquareArea()->getLength() + 2,
            worldController.getWorld().getCompleteSquareArea()->getLength()
            + 4);*/
}

SimulationTxt::~SimulationTxt() {
    /*delete (worldView);
    worldView = nullptr;
    delete (window);
    window = nullptr;*/
}

void SimulationTxt::startSimulation() {
    worldView->print(*window);
}


