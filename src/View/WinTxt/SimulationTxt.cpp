#include "SimulationTxt.h"

SimulationTxt::SimulationTxt() {
    termClear();
    worldController = new WorldController(25, 25);
    worldView = new CompleteSquareAreaView(
            worldController->getWorld()->getCompleteSquareArea(), 1, 1);
    squareView = new SquareView(worldController->getSquare(0, 0),
                                worldView->getSizeX() + 5, 1);
    window = new WinTXT(
            worldController->getWorld()->getLength() + 3 + 30,
            worldController->getWorld()->getWidth() + 5);
}

SimulationTxt::~SimulationTxt() {
    termClear();
    delete (worldController);
    worldController = nullptr;
    delete (worldView);
    worldView = nullptr;
    delete (window);
    window = nullptr;
}

void SimulationTxt::printEnteteWindow() const {
    std::string simulation = "Simulation :";
    window->print(0, 0, simulation);
    std::string squareDetail =
            "Square details : (" + to_string(squareIndexX) + ";" +
            to_string(squareIndexY) + ")";
    unsigned int offset =
            worldController->getWorld()->getLength() +
            5;
    window->print(offset, 0, squareDetail);
}

void SimulationTxt::printSimulation() const {
    window->clear();
    printEnteteWindow();
    worldView->print(*window);
    squareView->print(*window);

    window->draw();
}

void SimulationTxt::startSimulation() {
    char c;
    bool ok = true;
    do {
        printSimulation();

#ifdef _WIN32
        Sleep(100);
#else
        usleep(100000);
#endif // WIN32
        c = window->getCh();
        switch (c) {
            case 'z': {
                if (squareIndexY >= 1) {
                    --squareIndexY;
                    squareView->setSquare(
                            worldController->getSquare(squareIndexX,
                                                       squareIndexY));
                }
                break;
            }
            case 's': {
                if (squareIndexY <
                    worldController->getWorld()->getWidth() - 1) {
                    ++squareIndexY;
                    squareView->setSquare(
                            worldController->getSquare(squareIndexX,
                                                       squareIndexY));
                }
                break;
            }
            case 'q': {
                if (squareIndexX >= 1) {
                    --squareIndexX;
                    squareView->setSquare(
                            worldController->getSquare(squareIndexX,
                                                       squareIndexY));
                }
                break;
            }
            case 'd': {
                if (squareIndexX <
                    worldController->getWorld()->getLength() - 1) {
                    ++squareIndexX;
                    squareView->setSquare(
                            worldController->getSquare(squareIndexX,
                                                       squareIndexY));
                }
                break;
            }
            case 'p': {
                ok = false;
                break;
            }
            case '\e': {
                ok = false;
                break;
            }
        }
    } while (ok);
}


